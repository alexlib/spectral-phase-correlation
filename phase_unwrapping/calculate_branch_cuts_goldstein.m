function [branch_cut_matrix, flags_matrix] = calculate_branch_cuts_goldstein(RESIDUE_MATRIX, MAX_BOX_SIZE);

% Determine matrix height and width
[height, width] = size(RESIDUE_MATRIX);

% Create a branch cut matrix
branch_cut_matrix = zeros(height, width);

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

% This should really be done in the object-oriented sense
% where all these flags are attributes of a residue object.
% But when I tested this, creating arrays of phase objects
% was extremely slow. Perhaps only the creation is slow but
% after that the array could be passed around efficiently?
% It's only needs to be created once.
flags_matrix = make_flags_matrix(RESIDUE_MATRIX);

% Determine the locations of the residues
residue_locs = find(abs(RESIDUE_MATRIX) > 0);

% Number of residues identified
num_residues = length(residue_locs);

% Loop over the residue locations.
for k = 1 : num_residues

    % Set the "been searched" flag to zero for the whole field.
    flags_matrix = bitset(flags_matrix, been_searched_bit_position, 0);
    
    % Determine the row and column position of the residue.
    % The following lines are equivalent to (but faster than):
    % [r, c] = ind2sub([height, width], residue_locs(k));
    r = rem(residue_locs(k) - 1, height) + 1;
    c = (residue_locs(k) - r) / height + 1;
    
    % Check if the pixel is already balanced.
    isBalanced = bitget(flags_matrix(r, c), balanced_charge_bit_position);

    % Ignore the pixel if it's already balanced.
    % or conversely, only continue if the charge isn't already balanced.
    if ~isBalanced
    
        % Mark the residue as "active."
        flags_matrix(r, c) = bitset(flags_matrix(r, c), active_residue_bit_position, 1);
        
        % Calculate the residue charge.
        net_charge = get_charge(RESIDUE_MATRIX(r, c));
        
        % Loop over each box size.
        for box_size =  initial_box_size : 2 : MAX_BOX_SIZE
            
            % Determine the extents of the search box.
            [box_rows_01, box_cols_01] = find_box_coordinates([r, c], ...
                [height, width], box_size);
            
            % Count the number of residues in the box
            num_residues_in_box = count_residues( ...
            flags_matrix(box_rows_01(1) : box_rows_01(end), ...
                         box_cols_01(1) : box_cols_01(end)));
                     
            % Determine the positions of all of the residues in the box. 
            % The "_local" name here is meant to indicate that these
            % are the coordinates in the frame of the box, not in the
            % overall residue matrix.
             [residue_box_rows, residue_box_cols] = ...
                 find_residue_positions(RESIDUE_MATRIX...
                 (box_rows_01(1) : box_rows_01(end), ...
                         box_cols_01(1) : box_cols_01(end)), [r, c]);
                                  
            % Loop over the number of residues contained in the box.
            for n = 1 : num_residues_in_box
                
                % Set the anchor pixel to the n'th residue detected in the
                % box
                row_anchor = residue_box_rows(n);
                col_anchor = residue_box_cols(n);
                
                % Determine the extents of the search box centered
                % at the current anchor pixel.
                [box_rows, box_cols] = ...
                    find_box_coordinates([row_anchor, col_anchor], ...
                    [height, width], box_size);
                               
                % Determine the number of box pixels.
                num_box_pixels = length(box_rows);
                
                % Set all the "been searched" bit flags to zero.
                flags_matrix = bitset(flags_matrix, been_searched_bit_position, 0);
            
            % Loop over the box pixels.
                for p = 1 : num_box_pixels
                    
                    % Get the flags for the box pixel
                    flag_vals = flags_matrix(box_rows(p), box_cols(p));
                    
                    if ~bitget(flag_vals, been_searched_bit_position)
                
                        % Check if box pixel is a border pixel.
                        if bitget(flag_vals, image_border_bit_position);

                            % Set the residue to balanced
                            % if the box contains a border pixel.
                            flags_matrix(row_anchor, col_anchor) = ...
                                bitset(flags_matrix(row_anchor, col_anchor), ...
                                balanced_charge_bit_position, 1);

                            % Set the net charge in the box to zero
                            % if the box contains a border pixel.
                            net_charge = 0;

                            % Place a branch cut between the active pixel
                            % and the box (border) pixel
                            branch_cut_matrix = ...
                                place_branch_cut(branch_cut_matrix, ...
                                [box_rows(p), box_cols(p)],...
                                [row_anchor, col_anchor]); 

                        % Check if the box pixel is both a residue and not already active   
                        elseif (bitget(flag_vals, positive_residue_bit_position) ...
                                || bitget(flag_vals, negative_residue_bit_position));

                            % Check if the pixel is balanced.
                            isBalanced = ...
                                bitget(flags_matrix(box_rows(p), box_cols(p)), ...
                                balanced_charge_bit_position);

                            % If the pixel is not already balanced, add its
                            % polarity to to the net charge and mark as balanced.
                            if ~isBalanced

                                % Add the pixel's charge to the net charge.
                                net_charge = net_charge + ...
                                    get_charge(RESIDUE_MATRIX( ...
                                    box_rows(p), box_cols(p)));

                                % Set the pixel to balanced.
                                flags_matrix(box_rows(p), box_cols(p)) = ...
                                    bitset(flags_matrix(box_rows(p), ...
                                    box_cols(p)), ...
                                    balanced_charge_bit_position, 1); 
                            end % End checking for balanced charge.

                            % Set the pixel to active.
                            flags_matrix(box_rows(p), box_cols(p)) = ...
                               bitset(flags_matrix(box_rows(p), ...
                               box_cols(p)), ...
                                active_residue_bit_position, 1);

                            % Place a branch cut between that pixel 
                            % and the residue at which the box is centered.
                            branch_cut_matrix = ...
                                place_branch_cut(branch_cut_matrix, ...
                                [row_anchor, col_anchor],...
                                [box_rows(p), box_cols(p)]);

                        end % End box pixel conditions

                        % Break the loop-over-box-pixels loop
                        % if the net charge is zero.
                        if net_charge == 0
                            break;
                        end

                    end % End (if pixel has not been searched)
                    
                end % End looping over box pixels.
                
                % Break the loop if the net charge goes to zero.
                if net_charge == 0
                    break
                end
                
            end % End (for n = 1 : num_residues_in_box)
            
            % Break the loop if the net charge is zero.
            if net_charge == 0
                break
            end
                        
        end % End looping over box size.
        
        % If the max box size is reached, place a branch cut from the 
        % active pixel to the nearest border.
        if net_charge ~= 0
            
            % branch_cut_to_edge
            branch_cut_matrix = branch_cut_to_edge(branch_cut_matrix, [r, c]);
            
        end
    end
            
end

% Set branch cut pixels to one.
branch_cut_matrix(branch_cut_matrix > 0) = 1;

end


function charge = get_charge(residue)
% This function calculates the charge of a residue as +/- 1
    charge = 1 - (2 * (residue < 0));
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

% Row pixels in the branch cut
BRANCH_CUT_ROWS = round(r1 + (0 : euc_distance) * sin(residue_angle));

% Column pixels in the branch cut
BRANCH_CUT_COLS = round(c1 + (0 : euc_distance) * cos(residue_angle));

% % Form into vectors
% BRANCH_CUT_ROWS = BRANCH_CUT_ROWS(:);
% BRANCH_CUT_COLS = BRANCH_CUT_COLS(:);

end

function BRANCH_CUT_MATRIX = place_branch_cut(BRANCH_CUT_MATRIX,...
    POINTS_01, POINTS_02)
% This function places a branch cut in the branch cut matrix.

% Determine size of matrix
height = size(BRANCH_CUT_MATRIX, 1);

% Find the pixels corresponding to the branch cut
[branch_cut_rows, branch_cut_cols] = find_branch_cut_pixels(POINTS_01, ...
                                                            POINTS_02);
% Find the indices of the branch cut pixels.
% branch_cut_indices = sub2ind([height, width], ...
%     branch_cut_rows, branch_cut_cols);
branch_cut_indices = branch_cut_rows + (branch_cut_cols - 1) * height;
                                                        
% Set those pixels to one in the branch cut matrix.
BRANCH_CUT_MATRIX(branch_cut_indices) = 1;
                                                        
end


function FLAGS_MATRIX = make_flags_matrix(RESIDUE_MATRIX)

% Height and width of the matrix
[height, width] = size(RESIDUE_MATRIX);

% Initialize the eight-bit flags matrix as zeros.
FLAGS_MATRIX = zeros(height, width, 'uint8');

% Image border flag bit position and byte-value-if-true
image_border_bit_position = 4;

% Positive residue bit position
positive_residue_bit_position = 1;

% Negative residue bit position
negative_residue_bit_position = 2;

% Set the border pixel flags for the top edge.
FLAGS_MATRIX(1, :) = bitset(FLAGS_MATRIX(1, :), ...
    image_border_bit_position, 1);

% Set the border pixel flags for the bottom edge.
FLAGS_MATRIX(height, :) = bitset(FLAGS_MATRIX(1, :), ...
    image_border_bit_position, 1);

% Set the border pixel flags for the left edge.
FLAGS_MATRIX(:, 1) = bitset(FLAGS_MATRIX(1, :), ...
    image_border_bit_position, 1);

% Set the border pixel flags for the right edge.
FLAGS_MATRIX(:, width) = bitset(FLAGS_MATRIX(1, :), ...
    image_border_bit_position, 1);

% Loop over all the pixels in the residue matrix
% Set the positive residue flags 
FLAGS_MATRIX(FLAGS_MATRIX > 0) = bitset(FLAGS_MATRIX(FLAGS_MATRIX > 0), ...
    positive_residue_bit_position, 1);

FLAGS_MATRIX(FLAGS_MATRIX < 0) = bitset(FLAGS_MATRIX(FLAGS_MATRIX < 0), ...
    negative_residue_bit_position, 1);

end


function [NUM_RESIDUES, NET_CHARGE] = count_residues(FLAGS_MATRIX)
% This function counts the total number of residues contained
% in a matrix of residue flags, and also returns the net charge in the
% region.

% Positive residue bit position
positive_residue_bit_position = 1;
negative_residue_bit_position = 2;

% Number of positive residues
num_positive_residues = sum(bitget(FLAGS_MATRIX(:), ...
    positive_residue_bit_position));

% Number of negative residues
num_negative_residues = sum(bitget(FLAGS_MATRIX(:), ...
    negative_residue_bit_position));

% Count the number of residues
NUM_RESIDUES = num_positive_residues + num_negative_residues;

% Calculate the net charge as the difference between
% the numbers of positive and negative residues.
NET_CHARGE = num_positive_residues - num_negative_residues;

end


% Determine the positions of all of the residues in the box.
function [residue_box_rows, residue_box_cols] = find_residue_positions(RESIDUE_MAT, POS);

% Size of the flags matrix
[height, width] = size(RESIDUE_MAT);

% Find the residues
idx = find(RESIDUE_MAT ~= 0);

% Determine the row and column position of the residue.
% The following lines are equivalent to (but faster than):
% [r, c] = ind2sub([height, width], residue_locs(k));
residue_box_rows_local = rem(idx - 1, height) + 1;
residue_box_cols_local = (idx - residue_box_rows_local) / height + 1;

% Row and col of anchor position
r = POS(1);
c = POS(2);

% Centroid
xc = (width  +  1) / 2 - 0.5 * (1 - mod(width,  2));
yc = (height + 1) / 2 - 0.5 * (1 - mod(height, 2));

% Global position
residue_box_rows = residue_box_rows_local - yc + r;
residue_box_cols = residue_box_cols_local - xc + c;

% Need to always put the centered pixel coordinates first...

% Find the position of the original pixel
I = find(residue_box_rows == r & residue_box_cols == c, 1);

% If more than one residue is detected, 
% then set the coordinates of the first residue
% in the list to correspond to the anchor pixel.
%
% This if-statement is specified by "max(I(:))" rather
% than just (if I > 1) because the code won't compile 
% with the latter statement; the reason for this is 
% apparently that the compiler doesn't know ahead of time
% that I will contain exactly one element, even though
% the call to "find()" above contained an argument specifying
% to return only a single value. And since "max(I(:))" 
% can only ever contain one value, the compiler accepts it
% as a valid conditional statement. 
% TL;DR, I had to do it this way to get it to compile. 
if max(I(:)) > 1
    
    % Swap the positions of the anchor pixel and the first pixel
    % in the list of residue locations.
    residue_box_rows([1, I]) = [residue_box_rows(I), residue_box_rows(1)];
    residue_box_cols([1, I]) = [residue_box_cols(I), residue_box_cols(1)];
    
end

end

function BRANCH_CUT_MATRIX = branch_cut_to_edge(BRANCH_CUT_MATRIX, LOC)

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
BRANCH_CUT_MATRIX = place_branch_cut(BRANCH_CUT_MATRIX, LOC, border_cut_pos);

end








