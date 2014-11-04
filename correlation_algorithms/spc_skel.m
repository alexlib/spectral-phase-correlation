function [TY_SPC, TX_SPC, TY_RPC, TX_RPC] = spc_skel(REGION1, REGION2, RPC_FILTER, SPC_FILTER);
% Variable k is a counter, used temporarily for debugging.

% Dimensions of the regions
[regionHeight, regionWidth] = size(REGION1);

% Cast regions as doubles.
% Maybe make singles for speed?
region1 = double(REGION1);
region2 = double(REGION2);

% Phase only correlaiton of images
% Returns complex plane
phase_plane_wrapped = fftshift(phaseOnlyFilter(fftn(double(region2), [regionHeight, regionWidth]) .* conj(fftn(double(region1), [regionHeight, regionWidth]))));

% Phase angle plane (wrapped)
phase_angle_plane = angle(phase_plane_wrapped);

% Spatial RPC plane (for peak fit)
rpc_plane_spatial = freq2space(phase_plane_wrapped .* RPC_FILTER, regionHeight, regionWidth);

% Peak fitting of RPC plane
[TY_RPC, TX_RPC, ~, ~, ~] = subpixel(rpc_plane_spatial, ones(size(rpc_plane_spatial)), 1, 0);

% Unwrapped phase plane
phase_plane_unwrapped = spc_unwrap_analytical(phase_angle_plane, TY_RPC, TX_RPC);

% Zero frequency pixel coordinates
uc =  regionWidth/2 + 1 - 0.5 * mod(regionWidth, 2);
vc =  regionHeight/2 + 1 - 0.5 * mod(regionHeight, 2);

% 1-D u vector
u_1d = (1-uc : regionWidth - uc);
v_1d = (1 - vc : regionHeight - vc)';

% Weighted least squares fit to the plane.
p = polyfitweighted2(u_1d,v_1d, phase_plane_unwrapped', 1, SPC_FILTER');

% SPC estimates of translations
TY_SPC = -p(2) * regionHeight / (2 * pi);
TX_SPC = -p(3) * regionWidth  / (2 * pi);

end






























