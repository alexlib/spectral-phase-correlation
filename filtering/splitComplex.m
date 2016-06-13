function [SPECTRAL_PHASE, SPECTRAL_MAGNITUDE] = splitComplex(COMPLEX_CROSS_CORRELATION_PLANE)
% PHASE_ONLY_CORRELATION_PLANE = phaseOnlyFilter(COMPLEX_CROSS_CORRELATION_PLANE)
% performs phase-only filtering of a spectral-domain cross correlation signal

% Calculate the spectral magnitude of the complex cross correlation
% in the frequency domain
SPECTRAL_MAGNITUDE = abs(COMPLEX_CROSS_CORRELATION_PLANE);

% Set zeros to ones
SPECTRAL_MAGNITUDE(SPECTRAL_MAGNITUDE == 0) = 1;

% Divide cross correlation by its nonzero magnitude to extract the phase information
SPECTRAL_PHASE = COMPLEX_CROSS_CORRELATION_PLANE ./ SPECTRAL_MAGNITUDE;

% Replace infinites with the original complex value.
SPECTRAL_PHASE(isinf(SPECTRAL_PHASE)) = ...
    COMPLEX_CROSS_CORRELATION_PLANE(isinf(SPECTRAL_PHASE));

end