function [TRANSLATION_Y, TRANSLATION_X, SPATIAL_CORRELATION_PLANE] = ...
    complex_to_filtered_phase_correlation(COMPLEX_CORRELATION, FILTER, PEAK_FIT_METHOD)

% Measure the correlation dimensions
[height, width] = size(COMPLEX_CORRELATION);

% Calculate the RPC plane between the two images.
% This line is all done at once to increase speed by not writing variables at intermediate steps. 
SPATIAL_CORRELATION_PLANE = abs(real(fftshift(ifft2(...
    phaseOnlyFilter(COMPLEX_CORRELATION) .* FILTER))));

% Prana subpixel implmentation of the sub-pixel fit
[TRANSLATION_X, TRANSLATION_Y] = ...
    subpixel(SPATIAL_CORRELATION_PLANE, ...
    width, height, ones(size(SPATIAL_CORRELATION_PLANE)), PEAK_FIT_METHOD, ...
    0, sqrt(8) * [1, 1]);

end


