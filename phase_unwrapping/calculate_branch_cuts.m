function flags_matrix = calculate_branch_cuts(RESIDUE_MATRIX);

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

% This should really be done in the object-oriented sense
% where all these flags are attributes of a residue object.
% But when I tested this, creating arrays of phase objects
% was extremely slow. Perhaps only the creation is slow but
% after that the array could be passed around efficiently?
% It's only needs to be created once.
flags_matrix = zeros([height, width], 'uint8');

% Determine the locations of the residues
residue_locs = find(abs(RESIDUE_MATRIX) > 0);

% Number of residues identified
num_residues = length(residue_locs);

% Loop over the residue locations.
for k = 1 : num_residues
    
    % Residue location
    loc = residue_locs(k);
    
    if ~bitget(flags_matrix(loc), balanced_charge_bit_position)
   
        % Extract the residue from the matrix of residues.
        residue = RESIDUE_MATRIX(loc);

        % Set the residue to active.
        flags_matrix(loc) = bitset(flags_matrix(loc), active_residue_bit_position, 1);

        % Measure the charge of the residue
        residue_charge = get_charge(residue);

        % Set the net charge of the box-search to the residue charge.
        net_charge = residue_charge;

        % Set the residue charge flag
        if residue_charge > 0
            flags_matrix(loc) = bitset(flags_matrix(loc), positive_residue_bit_position, 1); 
        else
            flags_matrix(loc) = bitset(flags_matrix(loc), negative_residue_bit_position, 1); 
        end

        % Convert residue location from [k] to [r, c, d]
        % These are the coordinates of the anchor pixel.
        [r, c] = ind2sub([height, width], loc);

        % Check to see if the residue lies on a border.
        % If so mark it balanced and lying on a branch cut.
        % Because the original residue search was anchored
        % at the top-left of each 2x2 grid of pixels,
        % there will be no residues located on the bottom
        % or right-side of the images, so we only need to check
        % for residues that lie on r = 1, c = 1, and d = 1.
        if r == 1 || c == 1

            % Set the bit specifying that the pixel does lie on a border.
            flags_matrix(loc) = bitset(flags_matrix(loc), image_border_bit_position, 1);

            % Set the bit specifying that the pixel lies on a branch cut.
            flags_matrix(loc) = bitset(flags_matrix(loc), branch_cut_bit_position, 1);

            % Set the bit specifying that the charge is balanced.
            flags_matrix(loc) = bitset(flags_matrix(loc), balanced_charge_bit_position, 1);

            % Specify a branch cut at that position
            branch_cut_matrix(r, c) = 1;

            % Set the net charge for that pixel to zero
            net_charge = 0;

        end

        % This initializes the size of the residue search box.
        % The box size will be increased by 2 (i.e. to the next odd integer)
        % until the net charge in the box is zero.
        box_size = 3;

        % Iterate the box-search algorithm until the net charge is zero.
        while abs(net_charge) > 0

            % Radius of the box.
            box_radius = (box_size - 1) / 2;

            % Determine the extents of the search box.
            %
            % Min and max rows
            search_box_min_row = r - box_radius;
            search_box_max_row = r + box_radius;

            % Min and max columns
            search_box_min_col = c - box_radius;
            search_box_max_col = c + box_radius;

            % Flag all the border pixels.
            %
            % This else-if deals with the search box 
            % touching the top edge of the image.
            if search_box_min_row <= 1 

                % Draw a branch cut between the anchor pixel
                % and the top edge of the image
                branch_cut_matrix(1 : r, c) = 1;

                % Set the net charge to zero for this search.
                net_charge = 0;

                % Set the residue flag to balanced.
                flags_matrix(loc) = bitset(flags_matrix(loc),...
                    balanced_charge_bit_position, 1);

            % This else-if deals with the search box 
            % touching the bottom edge of the image.
            elseif search_box_max_row >= height

                % Place a branch cut between the anchor pixel
                % and the bottom edge of the image.
                branch_cut_matrix(r : height, c) = 1;

                % Set the net charge to zero for this search.
                net_charge = 0;

                % Set the residue flag to balanced.
                flags_matrix(loc) = bitset(flags_matrix(loc),...
                    balanced_charge_bit_position, 1);

            % This else-if deals with the search box 
            % touching the left edge of the image.   
            elseif search_box_min_col <= 1

                % Place a branch cut between the anchor pixel
                % and the left edge of the image
                branch_cut_matrix(r, 1 : c) = 1;

                % Set the net charge to zero for this search.
                net_charge = 0;

                % Set the residue flag to balanced.
                flags_matrix(loc) = bitset(flags_matrix(loc),...
                    balanced_charge_bit_position, 1);

            % This else-if deals with the search box 
            % touching the right edge of the image.
            elseif search_box_max_col >= width

                % Place a branch cut between the anchor pixel
                % and the right edge of the image.
                branch_cut_matrix(r, c : width) = 1;

                % Set the net charge to zero for this search.
                net_charge = 0;

                % Set the residue flag to balanced.
                flags_matrix(loc) = bitset(flags_matrix(loc),...
                    balanced_charge_bit_position, 1);

            else

                % If no border pixels were detected, then the box region
                % is searched for other residues.
                for m = r - box_radius : r + box_radius
                    for n = c - box_radius : c + box_radius

                        % Only consider the pixel if it was flagged as a residue.
                        if (abs(RESIDUE_MATRIX(m, n)) > 0) ...
                                && (~bitget(flags_matrix(m, n), active_residue_bit_position)) ...
                                && (~bitget(flags_matrix(r, c), balanced_charge_bit_position))

                            % Mark the pixel as active.
                            bitset(flags_matrix(r, c), active_residue_bit_position, 1);

                            % Calculate the coordinates of the branch cut
                            % pixels.
                            % Remember that branch cuts are placed regardless
                            % of whether the pixel has been balanced or not.
                            [branch_row_pixels, branch_col_pixels] = ...
                                find_branch_cut_pixels([r, c], [m, n]);

                            % Set the branch cut pixels to 1 in the branch cut
                            % matrix.
                            branch_cut_matrix(branch_row_pixels, ...
                                branch_col_pixels) = 1;

                            % Check if the residue found in the box has already
                            % been balanced. If it has NOT been balanced, add 
                            % its charge to the net charge                     
                            if ~bitget(flags_matrix(m, n), balanced_charge_bit_position);

                                % Add the residue's charge to the net charge.
                                net_charge = net_charge + get_charge(RESIDUE_MATRIX(m, n));
                                
                                % Break the loop if the net charge is zero
                                if net_charge == 0
                                    % Set the "balanced charge" bit flag to 1
                                    bitset(flags_matrix(m, n), balanced_charge_bit_position, 1);
                                    bitset(flags_matrix(r, c), balanced_charge_bit_position, 1); 
                                end

                                
                            end

                        end
                    end
                end        
            end

            % Grow the box by +2 pixels in each direction
            box_size = box_size + 2;

        end
    end
end



end


function charge = get_charge(residue)
    charge = 1 - (2 * (residue < 0));
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
   
    

end






