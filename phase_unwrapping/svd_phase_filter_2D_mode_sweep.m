function [PHASE_PLANE_WRAPPED_COMPLEX_FILT, L2_NORM] = ...
    svd_phase_filter_2D_mode_sweep(PHASE_PLANE_WRAPPED_COMPLEX)
% This function unwraps the dominant modes of the SVD of a 2D complex phase
% plane into two 1D phase-angle vectors.

% Size of the phase plane.
[height, width] = size(PHASE_PLANE_WRAPPED_COMPLEX);

% Inverse transform the complex phase plane.
phase_plane_spatial_raw = (abs(ifftn(PHASE_PLANE_WRAPPED_COMPLEX, [height, width])));

% Calculate the SVD modes of the complex phase plane.
% Returned values are complex.
[svd_rows, eigen_vals, svd_cols] = svd(PHASE_PLANE_WRAPPED_COMPLEX);

% Eigen values as a row matrix
eigen_vals_diag = (diag(eigen_vals));

% Allocate the reconstructed phase plane
PHASE_PLANE_WRAPPED_COMPLEX_FILT = zeros(size(PHASE_PLANE_WRAPPED_COMPLEX));

% Measure the number of modes.
num_modes = size(svd_rows, 1);

% Allocate the L2 norm
L2_NORM = zeros(num_modes, 1);

% Reconstruct the complex phase 
for k = 1 : num_modes

    % Add each mode to the reconstructed plane.
    PHASE_PLANE_WRAPPED_COMPLEX_FILT = PHASE_PLANE_WRAPPED_COMPLEX_FILT + ...
        svd_rows(:, k) * eigen_vals_diag(k) ...
        * (svd_cols(:, k))';
    
    % Invert the SVD-reconstructed phase plane.
    phase_plane_spatial_svd = (abs(ifftn(PHASE_PLANE_WRAPPED_COMPLEX_FILT,...
        [height, width])));
    
    % Calculate the L2 norm between the raw and SVD-filtered inverse
    % transform.
    L2_NORM(k) = sqrt(sum((phase_plane_spatial_raw(:) ...
        - phase_plane_spatial_svd(:)).^2, 1));

end

end