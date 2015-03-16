function RESIDUE_LOCS = find_residue_locs(FLAGS_MATRIX)

% Bit positions of positive and negative residue flags.
positive_residue_bit_position = 1;
negative_residue_bit_position = 2;

RESIDUE_LOCS = find(bitget(FLAGS_MATRIX(:), ...
    positive_residue_bit_position) | ...
    bitget(FLAGS_MATRIX(:), negative_residue_bit_position));


end