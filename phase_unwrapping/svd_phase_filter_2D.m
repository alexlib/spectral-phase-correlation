function PHASE_PLANE_WRAPPED_COMPLEX_FILT = ...
    svd_phase_filter_2D(PHASE_PLANE_WRAPPED_COMPLEX, NUM_MODES)
% This function unwraps the dominant modes of the SVD of a 2D complex phase
% plane into two 1D phase-angle vectors.

% Calculate the SVD modes of the complex phase plane.
% Returned values are complex.
[svd_rows, eigen_vals, svd_cols] = svd(PHASE_PLANE_WRAPPED_COMPLEX);

% Eigen values as a row matrix
eigen_vals_diag = (diag(eigen_vals));

% Allocate the reconstructed phase plane
PHASE_PLANE_WRAPPED_COMPLEX_FILT = zeros(size(PHASE_PLANE_WRAPPED_COMPLEX));

% Reconstruct the complex phase 
for k = 1 : NUM_MODES

    % Add each mode to the reconstructed plane.
    PHASE_PLANE_WRAPPED_COMPLEX_FILT = PHASE_PLANE_WRAPPED_COMPLEX_FILT + ...
        svd_rows(:, k) * eigen_vals_diag(k) ...
        * (svd_cols(:, k))';

end

end