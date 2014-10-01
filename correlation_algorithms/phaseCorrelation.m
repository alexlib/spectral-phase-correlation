function spectralPhaseCorr = phaseCorrelation(A, B)
% phaseCorrelation performs a phase-only filtered correlation of two 2-D signals and returns the output in the spectral domain. 
% 
% INPUTS
%   A = First signal to be correlated. This signal remains stationary during the correlaiton. 
%   B = Second signal to be correlated. This signal is shifted during the correlation. 
% 
% OUTPUTS
%   spatialPhaseCorr = phase-only filtered correlation of A and B in the spatial domain.
% 
% SEE ALSO
%   crossCorrelation, freq2space, phaseOnlyFilter

% Perform standard cross correlation
spectralCrossCorr = crossCorrelation(A, B);

% Perform phase-only filtering
spectralPhaseCorr = phaseOnlyFilter(spectralCrossCorr);

end
