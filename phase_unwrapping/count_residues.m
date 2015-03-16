function NUM_RESIDUES = count_residues(FLAGS_MATRIX)
% This function counts the total number of residues contained
% in a matrix of residue flags, and also returns the net charge in the
% region.

% Bit positions of positive and negative residue flags.
positive_residue_bit_position = 1;
negative_residue_bit_position = 2;

% NUM_RESIDUES = sum(abs(RESIDUE_MATRIX(:)) > 0);
NUM_RESIDUES = sum(bitget(FLAGS_MATRIX(:), ...
    positive_residue_bit_position)) + sum(bitget(FLAGS_MATRIX(:), ...
    negative_residue_bit_position));

end
