function PHASE_PLANE_WRAPPED_COMPLEX_FILT = ...
    svd_phase_filter_2D(PHASE_PLANE_WRAPPED_COMPLEX)
% This function unwraps the dominant modes of the SVD of a 2D complex phase
% plane into two 1D phase-angle vectors.

% Calculate the SVD modes of the complex phase plane.
% Returned values are complex.
[svd_rows, eigen_vals, svd_cols] = svd(PHASE_PLANE_WRAPPED_COMPLEX);

% Calculate the (wrapped) phase angles of the dominant modes of each SVD matrix.
% The angle() function inherently sets the range of these 
% vectors to (-pi, pi)
svd_complex_rows = (svd_rows(:, 1));
svd_complex_cols = (svd_cols(:, 1));

% Reconstruct the complex phase 
PHASE_PLANE_WRAPPED_COMPLEX_FILT = svd_complex_rows * eigen_vals(1,1) ...
    * (svd_complex_cols)';

end