function phaseCorr = phaseOnlyFilter(crossCorr)
% rpcFilter performs phase-only filtering of a spectral-domain cross correlation signal

% Magnitude of cross correlation in frequency domain
mag = sqrt(crossCorr .* conj(crossCorr));

% If the value of the cross correlation is zero, set the magnitude to 1.
% This avoids division by zero when calculating the phase correlation
% below (i.e., when dividing the cross correlation by its magnitude). 
mag(crossCorr == 0 ) = 1;

% Divide cross correlation by its nonzero magnitude to extract the phase information
phaseCorr = crossCorr ./ mag;

end



