function [TY, TX] = spc_plane_fit(PHASE_PLANE_UNWRAPPED, WEIGHTING_MATRIX)

% Dimensions of the regions
[region_height, region_width] = size(PHASE_PLANE_UNWRAPPED);

% Degree of the polynomial fit.
% This should always be 1 in this function. 
% Included for legibility.
polynomial_fit_degree = 1;

% Perform the 2D weighted least squares fit to the unwrapped phase plane.
p = polyfitweighted2(1 : region_width, 1 : region_height, PHASE_PLANE_UNWRAPPED', polynomial_fit_degree, WEIGHTING_MATRIX');

% SPC estimates of translations
TY = -p(2) * region_height / (2 * pi);
TX = -p(3) * region_width  / (2 * pi);


end