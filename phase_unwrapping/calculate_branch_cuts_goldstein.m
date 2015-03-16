function [branch_cut_matrix, FLAGS_MATRIX] = calculate_branch_cuts_goldstein(FLAGS_MATRIX, MAX_BOX_SIZE);

% Create a matrix containing the residue flags
% This matrix contains [height, width] 8-bit values
% where the first seven bits of each byte refer in
% little-endian order to the values of the following
% flags at each pixel: 
% 2^0 bit = 1 if positive residue, 0 if not positive residue.
% 2^1 bit = 1 if negative residue, 0 if not negative residue.
% 2^2 bit = 1 if the pixel lies on a branch cut, 0 if not.
% 2^3 bit = 1 if the pixel lies on the image border (I think??), 0 if not.
% 2^4 bit = 1 if the pixel represents a balanced residue, 0 if not.
% 2^5 bit = 1 if the pixel represnts an "active residue," i.e.
%   if the pixel is "connected to the current set of branch cuts."
%   I think this means that the pixel is on a branch cut within
%   an active search window.
% 2^6 bit = 1 if the pixel has been unwrapped.

% Define values for the different flags...
% Note that matlab indexes bit positions the same way
% it does arrays, e.g., little-endian bit 1 corresponds to 2^0.
% Positive residue flag bit-position and byte-value-if-true
positive_residue_bit_position = 1;

% Negative residue flag bit position and byte-value-if-true
negative_residue_bit_position = 2;

% Branch cut flag bit position and byte-value-if-true
branch_cut_bit_position = 3;

% Image border flag bit position and byte-value-if-true
image_border_bit_position = 4;

% Balanced residue flag bit position and byte-value-if-true
balanced_charge_bit_position = 5;

% Active residue flag bit position and byte-value-if-true
active_residue_bit_position = 6;

% Unwrapped pixel flag bit position and byte-value-if-true
unwrapped_pixel_bit_position = 7;

% Flag specifying whether a search box has been centered on the
% pixel.
been_searched_bit_position = 8;

% Initial box size
initial_box_size = 3;

% Determine matrix height and width
[height, width] = size(FLAGS_MATRIX);

% Add any existing branch cuts to the branch cut matrix
branch_cut_matrix = bitget(FLAGS_MATRIX, branch_cut_bit_position);
 
% Determine the locations of the residues
residue_locs = find(bitget(FLAGS_MATRIX, positive_residue_bit_position) ...
    | bitget(FLAGS_MATRIX, negative_residue_bit_position));

% Number of residues identified
num_residues = length(residue_locs);

% Loop over the residue locations.
for k = 1 : num_residues
   
    % Determine the row and column position of the residue.
    % The following lines are equivalent to (but faster than):
    % [r, c] = ind2sub([height, width], residue_locs(k));
    r = rem(residue_locs(k) - 1, height) + 1;
    c = (residue_locs(k) - r) / height + 1;
    
    % Check if the pixel is already balanced.
    isBalanced = bitget(FLAGS_MATRIX(r, c), balanced_charge_bit_position);

    % Ignore the pixel if it's already balanced.
    % or conversely, only continue if the charge isn't already balanced.
    if ~isBalanced
    
        % Mark the residue as "active."
        FLAGS_MATRIX(r, c) = bitset(FLAGS_MATRIX(r, c), active_residue_bit_position, 1);
        
        % Set to balanced
        FLAGS_MATRIX(r, c) = bitset(FLAGS_MATRIX(r, c), balanced_charge_bit_position, 1);
        
        % Calculate the residue charge.
        if bitget(FLAGS_MATRIX(r, c), positive_residue_bit_position)
            net_charge =  1;
        else
            net_charge = -1;
        end

        % Loop over each box size.
        for box_size =  initial_box_size : 2 : MAX_BOX_SIZE
                      
            % Determine the extents of the search box.
            [box_rows_01, box_cols_01] = find_box_coordinates([r, c], ...
                [height, width], box_size);
            
            % Count the number of residues in the box
            num_residues_in_box = count_residues( ...
            FLAGS_MATRIX(min(box_rows_01) : max(box_rows_01), ...
                         min(box_cols_01) : max(box_cols_01)));
             
             % Find the coordinates of all the residues in the box.
             [residue_box_rows, residue_box_cols] = ...
                 find_residue_positions(FLAGS_MATRIX, ...
                 box_rows_01, box_cols_01, residue_locs(k), ...
                    num_residues_in_box);
        
            % Determine the positions of all of the residues in the box. 
            % The "_local" name here is meant to indicate that these
            % are the coordinates in the frame of the box, not in the
            % overall residue matrix.       
                                  
            % Loop over the number of residues contained in the box.
            for n = 1 : num_residues_in_box
                
                % Set the anchor pixel to the n'th residue detected in the
                % box
                row_anchor = residue_box_rows(n);
                col_anchor = residue_box_cols(n);
                
                % Determine the extents of the search box centered
                [box_rows, box_cols] = ...
                    find_box_coordinates([row_anchor, col_anchor], ...
                    [height, width], box_size);

                % Determine the number of box pixels.
                num_box_pixels = length(box_rows);
            
                % Loop over the box pixels.
                for p = 1 : num_box_pixels
                    
                    % Get the flags for the box pixel
                    flag_vals = FLAGS_MATRIX(box_rows(p), box_cols(p));
                    
                        % Check if box pixel is a border pixel.
                        if bitget(flag_vals, image_border_bit_position);

                            % Set the residue to balanced
                            % if the box contains a border pixel.
                            FLAGS_MATRIX(row_anchor, col_anchor) = ...
                                bitset(FLAGS_MATRIX(row_anchor, col_anchor), ...
                                balanced_charge_bit_position, 1);

                            % Set the net charge in the box to zero
                            % if the box contains a border pixel.
                            net_charge = 0;

                            % Place a branch cut between the active pixel
                            % and the box (border) pixel
                            [branch_cut_matrix, FLAGS_MATRIX] = ...
                                place_branch_cut(branch_cut_matrix, ...
                                FLAGS_MATRIX, [box_rows(p), box_cols(p)],...
                                [row_anchor, col_anchor]); 

                        % Check if the box pixel is both a residue and not already active   
                        elseif (bitget(flag_vals, positive_residue_bit_position) ...
                                || bitget(flag_vals, negative_residue_bit_position));

                            % Check if the pixel is balanced.
                            isBalanced = ...
                                bitget(FLAGS_MATRIX(box_rows(p), box_cols(p)), ...
                                balanced_charge_bit_position);

                            % If the pixel is not already balanced, add its
                            % polarity to to the net charge and mark as balanced.
                            if ~isBalanced

                                % Add the pixel's charge to the net charge.
                                net_charge = net_charge + ...
                                    get_flags_charge(FLAGS_MATRIX( ...
                                    box_rows(p), box_cols(p)));
                               
                                % Set the pixel to balanced.
                                FLAGS_MATRIX(box_rows(p), box_cols(p)) = ...
                                    bitset(FLAGS_MATRIX(box_rows(p), ...
                                    box_cols(p)), ...
                                    balanced_charge_bit_position, 1); 
                            end % End checking for balanced charge.

                            % Set the pixel to active.
                            FLAGS_MATRIX(box_rows(p), box_cols(p)) = ...
                               bitset(FLAGS_MATRIX(box_rows(p), ...
                               box_cols(p)), ...
                                active_residue_bit_position, 1);

                            % Place a branch cut between that pixel 
                            % and the residue at which the box is centered.
                            [branch_cut_matrix, FLAGS_MATRIX] = ...
                                place_branch_cut(branch_cut_matrix, ...
                                FLAGS_MATRIX, ...
                                [row_anchor, col_anchor],...
                                [box_rows(p), box_cols(p)]);

                        end % End box pixel conditions

                        % Break the loop-over-box-pixels loop
                        % if the net charge is zero.
                        if net_charge == 0
                            break;
                        end
                        
                end % End looping over box pixels.
                
                % Break the loop if the net charge goes to zero.
                if net_charge == 0
                    break
                end
            end
            
            % Break the loop if the net charge is zero.
            if net_charge == 0
                break
            end
                        
        end % End looping over box size.
        
        % If the max box size is reached, place a branch cut from the 
        % active pixel to the nearest border.
        if net_charge ~= 0
              
            % branch_cut_to_edge
            [branch_cut_matrix, FLAGS_MATRIX] = ...
                branch_cut_to_edge(branch_cut_matrix, FLAGS_MATRIX, ...
                [r, c]);
            
        end
    end  
    
end

% Set branch cut pixels to one.
branch_cut_matrix(branch_cut_matrix > 0) = 1;

end

function [BOX_ROWS, BOX_COLS] = find_box_coordinates(PIXEL_LOC, DIMS, BOX_SIZE);
% This function calculates the extents of a square odd-sized search box.

% Radius of the box. Round to enforce odd-sized boxes.
box_radius = round((BOX_SIZE - 1) / 2);

% Set the top-most row of the box to the 
% anchor pixel row position minus the box radius.
% If this results in a negative position, then set the
% top edge of the box equal to the top edge of the image.
box_rows_min = max(1, PIXEL_LOC(1) - box_radius);

% Set the bottom-most row of the box to the 
% anchor pixel row position plus the box radius.
% If this results in a position greater than the number of rows
% in the image, then set the bottom edge of the box equal
% to the bottom edge of the image.
box_rows_max = min(DIMS(1), PIXEL_LOC(1) + box_radius);

% Set the left-most column of the box to the 
% anchor pixel column position minus the box radius.
% If this results in a negative position, then set the left-edge
% of the box equal to the left edge of the image.
box_cols_min = max(1, PIXEL_LOC(2) - box_radius);

% Set the right-most column of the box to the 
% anchor pixel column position plus the box radius.
% If this results in a position greater than the number of columns
% in the image, then set the right edge of the box equal
% to the right edge of the image.
box_cols_max = min(DIMS(2), PIXEL_LOC(2) + box_radius);

% Create matrices of the box pixel positions 
[BOX_COLS, BOX_ROWS] = meshgrid(box_cols_min : box_cols_max,...
    box_rows_min : box_rows_max);

% Turn the arrays into vectors
BOX_COLS = BOX_COLS(:);
BOX_ROWS = BOX_ROWS(:);

% Index of the anchor pixel in the box rows / columns arrays
anchor_pix_index = find(BOX_COLS == PIXEL_LOC(2) & BOX_ROWS == PIXEL_LOC(1));

% Don't include the anchor pixel in the box coordinates. 
BOX_COLS(anchor_pix_index) = [];
BOX_ROWS(anchor_pix_index) = [];
        
end

function [BRANCH_CUT_ROWS, BRANCH_CUT_COLS] = find_branch_cut_pixels(POINTS_01, POINTS_02)
  
% These are the coordinates of the first point
r1 = POINTS_01(1); % Row
c1 = POINTS_01(2); % Column

% These are the coordinates of the second first point
r2 = POINTS_02(1);
c2 = POINTS_02(2);

% Place a branch cut between the anchor pixel and the 
% residue found in the box.
%
% This is the difference in row positions between the
% two residues.
row_distance = r2 - r1;

% This is the difference in column positions between
% the two residues.
col_distance = c2 - c1;

% Euclidian distance between the two residues
euc_distance = floor(sqrt(row_distance .^2 + col_distance .^2));

% Angle between the residues
residue_angle = atan2(row_distance, col_distance);

% Euclidean distance vector
euc_vector = 0 : euc_distance;

% Row pixels in the branch cut
BRANCH_CUT_ROWS = round(r1 + euc_vector * sin(residue_angle));

% Column pixels in the branch cut
BRANCH_CUT_COLS = round(c1 + euc_vector * cos(residue_angle));

end

function [BRANCH_CUT_MATRIX, FLAGS_MATRIX] = place_branch_cut(BRANCH_CUT_MATRIX,...
    FLAGS_MATRIX, POINTS_01, POINTS_02)
% This function places a branch cut in the branch cut matrix.

% This is the little-endian bit position of the 
% bit in each 8-bit element of the FLAGS_MATRIX array that indicates
% whether or not the pixel lies on a branch cut. 
branch_cut_bit_position = 3;

% Determine size of matrix
height = size(BRANCH_CUT_MATRIX, 1);

% Find the pixels corresponding to the branch cut
[branch_cut_rows, branch_cut_cols] = find_branch_cut_pixels(POINTS_01, ...
                                                            POINTS_02);
% Find the indices of the branch cut pixels.
branch_cut_indices = branch_cut_rows + (branch_cut_cols - 1) * height;

% Set the "branch cut" flag to one at the branch cut indices.
FLAGS_MATRIX(branch_cut_indices) = bitset( ...
    FLAGS_MATRIX(branch_cut_indices), branch_cut_bit_position, 1);
                                                        
% Set those pixels to one in the branch cut matrix.
BRANCH_CUT_MATRIX(branch_cut_indices) = 1;
                                                        
end


% Determine the positions of all of the residues in the box.
function [RESIDUE_BOX_ROWS, RESIDUE_BOX_COLS] = find_residue_positions( ...
    FLAGS_MATRIX, ROWS, COLS, ANCHOR_LOC, NUM_RESIDUES);

% Dimensions of the larger matrix
height = size(FLAGS_MATRIX, 1);

% Residue flags bit positions
positive_residue_bit_position = 1;
negative_residue_bit_position = 2;

% Make vectors out of the row and column positions.
row_vect = min(ROWS(:)) : max(ROWS(:));
col_vect = min(COLS(:)) : max(COLS(:));
num_box_rows = length(row_vect);
num_box_cols = length(col_vect);

% Vector to hold the indices of the residues in the box.
res_inds = zeros(NUM_RESIDUES, 1);

% Start a counter.
res_cnt = 1;

% Loop over all the pixels in the box.
for box_row = 1 : num_box_rows
    for box_col = 1 : num_box_cols

        % Big-array index of box pixel.
        box_ind = row_vect(box_row) + (col_vect(box_col) - 1) * height;

        % If the pixel corresponds to a residue 
        % then add its index to the list of residue indices.
        if sum(bitget(FLAGS_MATRIX(box_ind), ...
                [positive_residue_bit_position,  ...
                negative_residue_bit_position])) > 0; 
            res_inds(res_cnt) = box_ind;
            res_cnt = res_cnt + 1;
        end
        
    end
end

% Find the location of the anchor residue. 
res_anchor_loc = find(res_inds == ANCHOR_LOC);

% Swap the positions of the anchor pixel and the first pixel
% in the list of residue locations.
if max(res_anchor_loc(:)) > 1
    res_inds([1, res_anchor_loc]) = [res_inds(res_anchor_loc), res_inds(1)];
end   

% Convert the index to [row, col]
RESIDUE_BOX_ROWS = rem(res_inds - 1, height) + 1;
RESIDUE_BOX_COLS = (res_inds - RESIDUE_BOX_ROWS) / height + 1;

end

function [BRANCH_CUT_MATRIX, FLAGS_MATRIX] = branch_cut_to_edge(...
    BRANCH_CUT_MATRIX, FLAGS_MATRIX, LOC)

% Measure height and width of the branch cut matrix.
[height, width] = size(BRANCH_CUT_MATRIX);

% Row and column positions of branch cut origin.
row = LOC(1);
col = LOC(2);

% Calculate distance from the pixel to the edges
edge_distances = [row, height - row, col, width - col];

% Edge coordinates: top, bottom, left, right
edge_coords = [1, col; height, col; row, 1; row, width];

% Find the location of the minimum
[~, min_loc] = min(edge_distances);

% Coordinates on border to connect with a branch cut.
border_cut_pos = edge_coords(min_loc, :);

% Place the branch cut.
[BRANCH_CUT_MATRIX, FLAGS_MATRIX] = place_branch_cut(...
    BRANCH_CUT_MATRIX, FLAGS_MATRIX, LOC, border_cut_pos);

end








