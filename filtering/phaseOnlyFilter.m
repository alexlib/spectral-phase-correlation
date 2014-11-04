function PHASE_ONLY_CORRELATION_PLANE = phaseOnlyFilter(COMPLEX_CROSS_CORRELATION_PLANE)
% PHASE_ONLY_CORRELATION_PLANE = phaseOnlyFilter(COMPLEX_CROSS_CORRELATION_PLANE)
% performs phase-only filtering of a spectral-domain cross correlation signal

% Calculate the spectral magnitude of the complex cross correlation
% in the frequency domain
spectral_magnitude = sqrt(COMPLEX_CROSS_CORRELATION_PLANE .* conj(COMPLEX_CROSS_CORRELATION_PLANE));

% If the value of the cross correlation is zero, set the magnitude to 1.
% This avoids division by zero when calculating the phase correlation
% below (i.e., when dividing the cross correlation by its magnitude). 
spectral_magnitude(COMPLEX_CROSS_CORRELATION_PLANE == 0 ) = 1;

% Divide cross correlation by its nonzero magnitude to extract the phase information
PHASE_ONLY_CORRELATION_PLANE = COMPLEX_CROSS_CORRELATION_PLANE ./ spectral_magnitude;

end



