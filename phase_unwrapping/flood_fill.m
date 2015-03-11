function unwrapped_phase_plane = flood_fill(WRAPPED_PHASE_PLANE, FLAGS_MATRIX, START_LOCATION)

% Branch cut flag bit position and byte-value-if-true
branch_cut_bit_position = 3;

% Image border flag bit position and byte-value-if-true
image_border_bit_position = 4;

% Unwrapped pixel flag bit position and byte-value-if-true
unwrapped_pixel_bit_position = 7;

% Measure the dimensions of the data
[height, width] = size(WRAPPED_PHASE_PLANE);

% Initialize a solution array.
solution_array = zeros(height, width);

% Count the number of non-border, non branch-cut pixels.
num_valid_pix = sum(bitget(FLAGS_MATRIX(:), branch_cut_bit_position)) ...
    + sum(bitget(FLAGS_MATRIX(:), image_border_bit_position));

% Initialize the adjoin list
adjoin_list = zeros(num_valid_pix, 1);

% Extract the starting pixel row and column from the argument vector
start_row = START_LOC(1);
start_col = START_LOC(2);

% Count the number of pixels that have been unwrapped
num_unwrapped = sum(bitget(FLAGS_MATRIX(:), unwrapped_pixel_bit_position));

% Loop until the number of unwrapped pixels is equal the number of 
% unwrappable pixels (i.e., non-border, non-branch-cut pixels).
while num_unwrapped < num_valid_pix
    
    
    
end

end