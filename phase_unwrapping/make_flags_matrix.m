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

% Branch cut bit position
branch_cut_bit_position = 3;

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
        FLAGS_MATRIX(k) = bitset(FLAGS_MATRIX(k), branch_cut_bit_position, 1);
    elseif RESIDUE_MATRIX(k) < 0
        FLAGS_MATRIX(k) = bitset(FLAGS_MATRIX(k), negative_residue_bit_position, 1);
        FLAGS_MATRIX(k) = bitset(FLAGS_MATRIX(k), branch_cut_bit_position, 1);
    end 
end


end