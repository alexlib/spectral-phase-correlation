function [TY_SPC, TX_SPC, TY_RPC, TX_RPC] = spc(REGION1, REGION2, RPC_FILTER, SPC_FILTER, PHASE_UNWRAP_ALGORITHM);
% Variable k is a counter, used temporarily for debugging.
% To do: Get rid of RPC output

% Default to analytical unwrap
if nargin < 5
    PHASE_UNWRAP_ALGORITHM = 'UNWRAP_PHASE_ANALYTICAL';
end

% Dimensions of the regions
[regionHeight, regionWidth] = size(REGION1);

% Cast regions as doubles.
% Maybe make singles for speed?
region1 = double(REGION1);
region2 = double(REGION2);

% Phase only correlaiton of images
% Returns complex plane
phase_plane_wrapped_complex = fftshift(phaseOnlyFilter(fftn(double(region2), [regionHeight, regionWidth]) .* conj(fftn(double(region1), [regionHeight, regionWidth]))));

% Phase angle plane (wrapped)
phase_angle_plane_wrapped = angle(phase_plane_wrapped_complex);

% Decide which phase unwrapping algorithm to use.
switch PHASE_UNWRAP_ALGORITHM
    
    % Analytical unwrapping algorithm
    case 'UNWRAP_PHASE_ANALYTICAL'
        
        % Spatial RPC plane (for peak fit)
        rpc_plane_spatial = freq2space(phase_plane_wrapped_complex .* RPC_FILTER, regionHeight, regionWidth);

        % Peak fitting of RPC plane
        [TY_RPC, TX_RPC, ~, ~, ~] = subpixel(rpc_plane_spatial, ones(size(rpc_plane_spatial)), 1, 0);

        % Unwrapped phase plane.
        phase_plane_unwrapped = spc_unwrap_analytical(phase_angle_plane_wrapped, TY_RPC, TX_RPC);
    
        % Prana SVD phase unwrapping algorithm
    case 'UNWRAP_PHASE_SVD_1D'
        
        % Calculate the SVD modes of the complex phase plane.
        % Returned values are complex.
        [U, ~, V] = svd(phase_plane_wrapped_complex);
        
        % Calculate the (wrapped) phase angles of the dominant modes of each SVD matrix.
        phase_angle_wrapped_V = angle(V(:, 1));
        phase_angle_wrapped_U = angle(U(:, 1));
        
        % Unwrap the dominant modes
        phase_angle_unwrapped_V = unwrap(phase_angle_wrapped_V);
        phase_angle_unwrapped_U = unwrap(phase_angle_wrapped_U);
        
        
        
        
      
        
        % Set RPC outputs to zero to prevent crash
        % To do: Remove the RPC translation estimates from the
        % outputs of this function
        TX_RPC = 0;
        TY_RPC = 0;

end

% Perform the 2D weighted least squares fit to the unwrapped phase plane.
p = polyfitweighted2(1 : regionWidth, 1 : regionHeight, phase_plane_unwrapped', 1, SPC_FILTER');

% SPC estimates of translations
TY_SPC = -p(2) * regionHeight / (2 * pi);
TX_SPC = -p(3) * regionWidth  / (2 * pi);

end






























