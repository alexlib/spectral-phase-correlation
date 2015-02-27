function PHASE_RESIDUE = integrate_wrapped_phase_differences(PHASE_SAMPLES)
% This function calculates the phase residue along a path
% of pixels.
% The algorithm follows that described as Itoh's method on Page 21 of 
% the book "Two-Dimensional Phase Unwrapping" by Ghiglia & Pritt.

% Difference of phase samples
% running in a counterclockwise loop
phase_difference = diff(PHASE_SAMPLES);

% Wrapped difference of the phase samples
% This is step 2 in Itoh's method.
wrapped_phase_difference = atan2(sin(phase_difference),...
                                 cos(phase_difference));

% Sum of phase differences
PHASE_RESIDUE = sum(wrapped_phase_difference);

end