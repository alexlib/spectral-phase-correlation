function [TRANSLATION_Y, TRANSLATION_X, SPATIAL_RPC_PLANE, CORR_HEIGHT, CORR_DIAMETER] = RPC(IMAGE1, IMAGE2, CORR_SPECTRALFILTER)
% [TRANSLATION_Y, TRANSLATION_X, SPATIAL_RPC_PLANE, CORR_HEIGHT, CORR_DIAMETER] = RPC(IMAGE1, IMAGE2, CORR_SPECTRALFILTER)
%   calculates the robust phase correlation between two images
%
% INPUTS
%   IMAGE1 = First image
%   IMAGE2 = Second image
%   CORR_SPECTRALFILTER = RPC Spectral energy filter to apply to the spectral correlation between IMAGE1 and IMAGE2
%
% OUTPUTS
%   TRANSLATION_X = Most probable horizontal translation (in pixels) relating the two images
%
%   TRANSLATION_Y = Most probable vertical translation (in pixels) relating the two images
%
%   SPATIAL_RPC_PLANE = Spatial correlation plane of the RPC between the two images
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
SPATIAL_RPC_PLANE = freq2space(fftshift(phaseOnlyFilter(fftn(double(IMAGE2), [height, width]) .* conj(fftn(double(IMAGE1), [height, width])))) .* double(CORR_SPECTRALFILTER), height, width);

% Prana subplixel implmentation
[TRANSLATION_Y, TRANSLATION_X, CORR_HEIGHT, CORR_DIAMETER] = subpixel(SPATIAL_RPC_PLANE, ones(size(SPATIAL_RPC_PLANE)), 1, 0); % Subpixel peak location (poorly commented function taken from Prana) 
 
end


