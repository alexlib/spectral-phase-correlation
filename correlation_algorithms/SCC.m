function [TRANSLATION_Y, TRANSLATION_X, SPATIAL_SCC_PLANE, CORR_HEIGHT, CORR_DIAMETER] = SCC(IMAGE1, IMAGE2)
% [TRANSLATION_Y, TRANSLATION_X, SPATIAL_SCC_PLANE, CORR_HEIGHT, CORR_DIAMETER] = SCC(IMAGE1, IMAGE2)
%   calculates the robust phase correlation between two images
%
% INPUTS
%   IMAGE1 = First image
%   IMAGE2 = Second image
%
% OUTPUTS
%   TRANSLATION_X = Most probable horizontal translation (in pixels) relating the two images
%
%   TRANSLATION_Y = Most probable vertical translation (in pixels) relating the two images
%
%   SPATIAL_SCC_PLANE = Spatial correlation plane of the SCC between the two images
%
%   CORR_HEIGHT = Maximum value of SPATIAL_RPC_PLANE
%   
%   CORR_DIAMETER = Diameter of the correlation peak (pixels). 
%       See the function subpixel.m for details on this calculation.
%

% Calculate size of interrogation regions (homogeneous) (pixels)
[height, width] = size(IMAGE1);

% Calculate the RPC plane between the two images.
% This line is all done at once to increase speed by not writing variables at intermediate steps. 
% SPATIAL_SCC_PLANE = freq2space(fftshift(phaseOnlyFilter(fftn(double(IMAGE2), [height, width]) .* conj(fftn(double(IMAGE1), [height, width])))) .* double(CORR_SPECTRALFILTER), height, width);
SPATIAL_SCC_PLANE = freq2space(fftshift(fftn(double(IMAGE2), [height, width]) .* conj(fftn(double(IMAGE1), [height, width]))), height, width);

% Prana subplixel implmentation
[TRANSLATION_Y, TRANSLATION_X, CORR_HEIGHT, CORR_DIAMETER] = subpixel(SPATIAL_SCC_PLANE, ones(size(SPATIAL_SCC_PLANE)), 1, 0); % Subpixel peak location (poorly commented function taken from Prana) 
 
end


