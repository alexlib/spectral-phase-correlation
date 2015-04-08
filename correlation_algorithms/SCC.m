function [TRANSLATION_Y, TRANSLATION_X, SPATIAL_SCC_PLANE, ...
    CORR_HEIGHT, CORR_DIAMETER, PEAK_ANGLE, PEAK_ECCENTRICITY] = ...
    SCC(IMAGE1, IMAGE2, PEAK_FIT_METHOD)
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
%   PEAK_ANGLE = Angle in radians of the eccentric Gaussian correlation
%       peak with respect to the horizontal axis. This is only
%       output if the nonlinear least squares Gaussian peak-fit method
%       was specified (i.e., PEAK_FIT_METHOD = 3)
%
%   PEAK_ECCENTRICITY = Eccentricity of the eccentric Gaussian correlation
%       peak. This is only output if the nonlinear least squares
%       Gaussian peak-fit method was specified (i.e., PEAK_FIT_METHOD = 3)

% Calculate size of interrogation regions (homogeneous) (pixels)
[height, width] = size(IMAGE1);

% Calculate the RPC plane between the two images.
% This line is all done at once to increase speed by not writing variables at intermediate steps. 
% SPATIAL_SCC_PLANE = freq2space(fftshift(phaseOnlyFilter(fftn(double(IMAGE2), [height, width]) .* conj(fftn(double(IMAGE1), [height, width])))) .* double(CORR_SPECTRALFILTER), height, width);
SPATIAL_SCC_PLANE = freq2space(fftshift(fftn(double(IMAGE2),...
    [height, width]) .* conj(fftn(double(IMAGE1), ...
    [height, width]))), height, width);

% Prana subplixel implmentation
[TRANSLATION_X, TRANSLATION_Y, CORR_HEIGHT, CORR_DIAMETER, ...
    ~, ~, PEAK_ANGLE, PEAK_ECCENTRICITY] = ...
    subpixel(SPATIAL_SCC_PLANE, ...
    width, height, ones(size(SPATIAL_SCC_PLANE)), PEAK_FIT_METHOD, ...
    0, sqrt(8) * [1, 1]);

end


