function [spatialCorr] = freq2space(spectralCorrelation, height, width)
% freq2space(spectralCorrelation, height, width) 
% Shifts the zero-frequency component of a correlation in the spectral domain 
% to the center of spectrum, then transforms the correlation into the
% spatial domain.
%
% SEE ALSO:
%   fftshift

% Inverse fft of the correlation plane, then take the absolute value
% of its real part.
spatialCorr = abs(real(ifftn(spectralCorrelation, [height, width], 'symmetric')));

% Calculate the incides of the correlation plane with its zero-frequency
% coordinate shifted to the center of the plane. 
xind = [ceil(width/2)+1:width 1:ceil(width/2)];
yind = [ceil(height/2)+1:height 1:ceil(height/2)];

% Shift the spatial correlation plane. This is equivalent to FFTSHIFT.
spatialCorr = spatialCorr(yind, xind);

end