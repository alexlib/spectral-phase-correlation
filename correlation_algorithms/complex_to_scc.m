function [TRANSLATION_Y, TRANSLATION_X, SPATIAL_CORRELATION_PLANE] = ...
    complex_to_scc(COMPLEX_CORRELATION, PEAK_FIT_METHOD)

% INPUTS
%   COMPLEX_CORRELATION = 2D Complex cross correlation.
%
% OUTPUTS
%   TRANSLATION_X = Most probable horizontal translation (in pixels) relating the two images
%
%   TRANSLATION_Y = Most probable vertical translation (in pixels) relating the two images

% Calculate size of interrogation regions (homogeneous) (pixels)
[height, width] = size(COMPLEX_CORRELATION);

% Inverse-FFT the spectral correlation to get the SCC plane
SPATIAL_CORRELATION_PLANE = abs(real(fftshift(ifft2(COMPLEX_CORRELATION))));

% surf(SPATIAL_CORRELATION_PLANE ./ max(SPATIAL_CORRELATION_PLANE(:)));
% pause(0.01);

% Prana subplixel implmentation
[TRANSLATION_X, TRANSLATION_Y] = ...
    subpixel(SPATIAL_CORRELATION_PLANE, ...
    width, height, ones(size(SPATIAL_CORRELATION_PLANE)), PEAK_FIT_METHOD, ...
    0, sqrt(8) * [1, 1]);

end


