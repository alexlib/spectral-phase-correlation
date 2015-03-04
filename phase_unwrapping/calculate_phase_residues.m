function PHASE_RESIDUE_MATRIX = calculate_phase_residues(WRAPPED_PHASE_PLANE)
% This function calculates the phase residues about 2x2?pixel loops
% in a wrapped phase plane.

% Calculate the width and height of the phase plane.
[height, width] = size(WRAPPED_PHASE_PLANE);

% Allocate the phase residue matrix
PHASE_RESIDUE_MATRIX = zeros(height, width);

% Loop over all the pixels except the last row and column
% The last row and column are left out because the convention is
% to sum about a counter-clockwise loop starting at the top-left
% pixel of a 2x2 group of pixels.
for r = 1 : height - 1
    for c = 1 : width - 1
        
        % This line extracts the four pixels including,
        % and to the right and down from, the pixel
        % located at (r, c)
        % Also, the fifth (and last) element is the same as the
        % first element so that the phase difference
        % around the entire loop is calculated,
        % i.e., so that the vector of phase differences
        % contains four (and not three) values.
        phase_samples = [
                          WRAPPED_PHASE_PLANE(r, c); ...
                          WRAPPED_PHASE_PLANE(r + 1, c); ...
                          WRAPPED_PHASE_PLANE(r + 1, c + 1);
                          WRAPPED_PHASE_PLANE(r, c + 1);
                          WRAPPED_PHASE_PLANE(r, c)
                         ];
        
        % This line calculates the wrapped sum of
        % the wrapped phase differences around the
        % 2x2 loop of pixels defined by phase_samples
        PHASE_RESIDUE_MATRIX(r, c) = integrate_wrapped_phase_differences(phase_samples);
        
    end
end

% Truncate residue values to those whose magnitudes
% are greater than pi, to deal with machine precision errors.
PHASE_RESIDUE_MATRIX(abs(PHASE_RESIDUE_MATRIX) < pi) = 0;

end








