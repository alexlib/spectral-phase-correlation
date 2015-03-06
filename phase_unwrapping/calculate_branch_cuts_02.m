function flags_matrix = calculate_branch_cuts_02(RESIDUE_MATRIX, MAX_BOX_SIZE);

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

% Initial box size
initial_box_size = 3;

% This should really be done in the object-oriented sense
% where all these flags are attributes of a residue object.
% But when I tested this, creating arrays of phase objects
% was extremely slow. Perhaps only the creation is slow but
% after that the array could be passed around efficiently?
% It's only needs to be created once.
flags_matrix = make_flags_matrix(RESIDUE_MATRIX);

% Create 

% Determine the locations of the residues
residue_locs = find(abs(RESIDUE_MATRIX) > 0);

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
            
            % Loop over active pixels.
            % for n = 1 : num_active_pixels
            %
            %
            % end
            
            % Determine the extents of the search box.
            [box_rows, box_cols] = find_box_coordinates([r, c],...
                [height, width], box_size);
            
            % Determine the number of box pixels.
            num_box_pixels = length(box_rows);
            
            % Loop over the box pixels.
            for p = 1 : num_box_pixels
                
                % Get the flags for the box pixel
                flag_vals = flags_matrix(box_rows(p), box_cols(p));
                
                % Check if box pixel is a border pixel.
                if bitget(flag_vals, image_border_bit_position);
                    
                    % Set the residue to balanced
                    % if the box contains a border pixel.
                    flags_matrix(r, c) = bitset(flags_matrix(r, c), ...
                        balanced_residue_bit_position, 1);
                    
                    % Set the net charge in the box to zero
                    % if the box contains a border pixel.
                    net_charge = 0;
                    
                    % Place a branch cut between the active pixel
                    % and the box (border) pixel
                    branch_cut_matrix = ...
                        place_branch_cut(branch_cut_matrix, ...
                        [box_rows(p), box_cols(p)], [r, c]); 
                    
                % Check if the box pixel is both a residue and not already active   
                elseif (bitget(flag_vals, positive_residue_bit_position) ...
                        || bitget(flag_vals, negative_residue_bit_position)) ...
                        && ~bitget(flag_vals, active_residue_bit_position);
                    
                    % Check if the pixel is balanced.
                    isBalanced = ...
                        bitget(flags_matrix(box_rows(p), box_cols(p)), ...
                        balanced_charge_bit_position);
                    
                    % If the pixel is not already balanced, add its
                    % polarity to to the net charge and mark as balanced.
                    if ~isBalanced
                        
                        % Add the pixel's charge to the net charge.
                        net_charge = net_charge + ...
                            get_charge(RESIDUE_MATRIX(box_rows(p), ...
                            box_cols(p)));
                        
                        % Set the pixel to balanced.
                        flags_matrix(box_rows(p), box_cols(p)) = ...
                            bitset(flags_matrix(box_rows(p), box_cols(p)), ...
                            balanced_charge_bit_position, 1); 
                    end
                    
                    % Set the pixel to active.
                    flags_matrix(box_rows(p), box_cols(p)) = ...
                       bitset(flags_matrix(box_rows(p), box_cols(p)), ...
                        active_residue_bit_position, 1);
                    
                    % Place a branch cut between that pixel and the residue
                    % at which the box is centered.
                    branch_cut_matrix = ...
                        place_branch_cut(branch_cut_matrix, ...
                        [r, c], [box_rows(p), box_cols(p)]);
                    
                end % End box pixel conditions
                
                % Do some plotting
                %%%%%%%%%%%%%
                
                % Plot the phase residue matrix.
                imagesc(RESIDUE_MATRIX + branch_cut_matrix); 
                axis image;
                hold on
                
                % Plot the box extents
                minbr = min(box_rows);
                maxbr = max(box_rows);
                minbc = min(box_cols);
                maxbc = max(box_cols);
                
                % Plot the search box.
                plot([minbc, minbc, maxbc, maxbc, minbc], ...
                     [minbr, maxbr, maxbr, minbr, minbr], '-w');

                % Plot the anchor pixel
                plot(c, r, 'ow', 'markerfacecolor', 'black', 'markersize', 10);

                % Plot the box search pixel.
                plot(box_cols(p), box_rows(p), 'ow', 'markerfacecolor', 'white');

                % Release plot hold
                hold off
                
                % Inform the user of the net charge.
                fprintf('Net charge = %d\n', net_charge);
                
                % Pause
                pause(0.01);
                
                %%%%%%%%%%%%%
                
                % Break the loop-over-box-pixels loop
                % if the net charge is zero.
                if net_charge == 0
                    break;
                end
                
              
            end % End looping over box pixels.
        end % End looping over box size.
    end 
end



end


function charge = get_charge(residue)
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

% Don't include the anchor pixel location
BOX_COLS((BOX_SIZE^2 + 1) / 2) = [];
BOX_ROWS((BOX_SIZE^2 + 1) / 2) = [];
            
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
euc_distance = ceil(sqrt(row_distance .^2 + col_distance .^2));

% Angle between the residues
residue_angle = atan2(row_distance, col_distance);

% Row pixels in the branch cut
BRANCH_CUT_ROWS = round(r1 + (0 : euc_distance) * sin(residue_angle));

% Column pixels in the branch cut
BRANCH_CUT_COLS = round(c1 + (0 : euc_distance) * cos(residue_angle));

% Form into vectors
BRANCH_CUT_ROWS = BRANCH_CUT_ROWS(:);
BRANCH_CUT_COLS = BRANCH_CUT_COLS(:);

end

function BRANCH_CUT_MATRIX = place_branch_cut(BRANCH_CUT_MATRIX,...
    POINTS_01, POINTS_02)
% This function places a branch cut in the branch cut matrix.

% Determine size of matrix
[height, width] = size(BRANCH_CUT_MATRIX);

% Find the pixels corresponding to the branch cut
[branch_cut_rows, branch_cut_cols] = find_branch_cut_pixels(POINTS_01, ...
                                                            POINTS_02);
% Find the indices of the branch cut pixels.
branch_cut_indices = sub2ind([height, width], ...
    branch_cut_rows, branch_cut_cols);
                                                        
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
for k = 1 : length(RESIDUE_MATRIX(:))
    if RESIDUE_MATRIX(k) > 0
        FLAGS_MATRIX(k) = bitset(FLAGS_MATRIX(k), positive_residue_bit_position, 1);
    elseif RESIDUE_MATRIX(k) < 0
        FLAGS_MATRIX(k) = bitset(FLAGS_MATRIX(k), negative_residue_bit_position, 1);
    end 
end


end






