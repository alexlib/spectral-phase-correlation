function [TY, TX, COEFFS] = spc_plane_fit(PHASE_PLANE_UNWRAPPED, WEIGHTING_MATRIX)

% Get rid of the border pixels on the phase plane
p = PHASE_PLANE_UNWRAPPED;
w = WEIGHTING_MATRIX;

% Dimensions of the regions
[region_height, region_width] = size(p);

% Degree of the polynomial fit.
% This should always be 1 in this function. 
% Included for legibility.
polynomial_fit_degree = 1;

% Perform the 2D weighted least squares fit to the unwrapped phase plane.
COEFFS = polyfitweighted2(1 : region_width, 1 : region_height, ...
    p, polynomial_fit_degree, w);

% SPC estimates of translations
% TY = -COEFFS(3) * (region_height) / (2 * pi) + pi /(2*region_height);
% TX = -COEFFS(2) * (region_width)  / (2 * pi) + pi / (2 * region_width);

TY = -COEFFS(3) * (region_height) / (2 * pi);
TX = -COEFFS(2) * (region_width)  / (2 * pi);

end