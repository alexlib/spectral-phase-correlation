function spectralPhaseCorr = phaseCorrelation(A, B)
% phaseCorrelation performs a phase-only filtered 
% correlation of two 2-D signals and returns 
% the output in the spectral domain. 
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
% Leave this as a separate function in case we 
% want to modify the correlation kernel, FFT algorithm, etc.
spectralCrossCorr = crossCorrelation(A, B);

% Magnitude of cross correlation in frequency domain
mag = sqrt(spectralCrossCorr .* conj(spectralCrossCorr));

% If the value of the cross correlation is zero, set the magnitude to 1.
% This avoids division by zero when calculating the phase correlation
% below (i.e., when dividing the cross correlation by its magnitude). 
mag(spectralCrossCorr == 0 ) = 1;

% Divide cross correlation by its nonzero magnitude to extract the phase information
spectralPhaseCorr = spectralCrossCorr ./ mag;

end
