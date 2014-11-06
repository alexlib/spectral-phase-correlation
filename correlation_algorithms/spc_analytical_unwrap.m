function [TY_SPC, TX_SPC, TY_RPC, TX_RPC] = spc_analytical_unwrap(REGION_01, REGION_02, RPC_FILTER, SPC_WEIGHTING_MATRIX);
% Variable k is a counter, used temporarily for debugging.
% To do: Get rid of RPC output

% Dimensions of the regions
[region_height, region_width] = size(REGION_01);

% Phase only correlaiton of images
% Returns complex plane
phase_plane_wrapped_complex = fftshift(phaseCorrelation(REGION_01, REGION_02));

% Phase angle plane (wrapped)
phase_angle_plane_wrapped = angle(phase_plane_wrapped_complex);

% Spatial RPC plane (for peak fit)
rpc_plane_spatial = freq2space(phase_plane_wrapped_complex .* RPC_FILTER, region_height, region_width);

% Peak fitting of RPC plane
[TY_RPC, TX_RPC] = subpixel(rpc_plane_spatial, ones(size(rpc_plane_spatial)), 1, 0);

% Unwrapped phase plane.
phase_plane_unwrapped = unwrap_phase_analytical_2D(phase_angle_plane_wrapped, TY_RPC, TX_RPC);

% Degree of the polynomial fit.
% This should always be 1 in this function. 
% Included for legibility.
polynomial_fit_degree = 1;

% Perform the 2D weighted least squares fit to the unwrapped phase plane.
p = polyfitweighted2(1 : region_width, 1 : region_height, phase_plane_unwrapped', polynomial_fit_degree, SPC_WEIGHTING_MATRIX');

% SPC estimates of translations
TY_SPC = -p(2) * region_height / (2 * pi);
TX_SPC = -p(3) * region_width  / (2 * pi);

end






























