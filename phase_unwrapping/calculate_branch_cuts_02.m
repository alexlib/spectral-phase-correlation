function flags_matrix = calculate_branch_cuts_02(RESIDUE_MATRIX);

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
flags_matrix = zeros([height, width], 'uint8');

% Determine the locations of the residues
residue_locs = find(abs(RESIDUE_MATRIX) > 0);

% Number of residues identified
num_residues = length(residue_locs);

% Loop over the residue locations.
for k = 1 : num_residues
    
    % Initialize the box size as 3
    box_size = initial_box_size;
    
    % Determine the row and column position of the residue.
    [r, c] = ind2sub([height, width], residue_locs(k));
    
    % Check if the pixel is already balanced.
    isBalanced = bitget(flags_matrix(r, c), balanced_charge_bit_position);

    % Ignore the pixel if it's already balanced.
    % or conversely, only continue if the charge isn't already balanced.
    if ~isBalanced
    
        % Step 1) If the residue lies on a border pixel, mark it balanced and 
        % mark it as a branch cut.
        is_border = (r <= 1) || (c <= 1) || (r >= height) || (c >= width);
        if is_border
            bitset(flags_matrix(r, c), balanced_charge_bit_position, 1);
            bitset(flags_matrix(r, c), image_border_bit_position, 1);
            bitset(flags_matrix(r, c), branch_cut_bit_position, 1);
        end
        
        % Step 2) If the residue does not lie on a border pixel, 
        % initiate a search in a box. 
        if ~is_border
            
            % Determine the radius of the box.
            box_radius = (box_size - 1) / 2;
            
            % Determine the minimum and maximum extents
            % of the box rows
            box_min_row = r - box_radius;
            box_max_row = r + box_radius;
            
            % Determine the minimum and maximum extents
            % of the box columns
            box_min_col = c - box_radius;
            box_max_col = c + box_radius;
            
            % Determine the number of box pixels
            num_box_pixels = box_size ^ 2;
            
            % Check if the box touches the image edge
            % If the box touches an image edge, then set the 
            % residue to balanced and draw a branch cut.
            if box_min_row <= 1
                bitset(flags_matrix(r, c), balanced_charge_bit_position, 1);
                branch_cut_matrix = branch_cut_matrix + find_branch_cut_pixels([1, c], [r, c]);
            elseif box_max_row >= height
                bitset(flags_matrix(r, c), balanced_charge_bit_position, 1);
                branch_cut_matrix = branch_cut_matrix + find_branch_cut_pixels([r, c], [height, c]);
            elseif box_min_col <= 1
                bitset(flags_matrix(r, c), balanced_charge_bit_position, 1);
                branch_cut_matrix = branch_cut_matrix + find_branch_cut_pixels([r, 1], [r, c]);
            elseif box_max_col >= width
                bitset(flags_matrix(r, c), balanced_charge_bit_position, 1);
                branch_cut_matrix = branch_cut_matrix + find_branch_cut_pixels([r, c], [r, width]);
            end
            
            
            
            
            
            
            
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






