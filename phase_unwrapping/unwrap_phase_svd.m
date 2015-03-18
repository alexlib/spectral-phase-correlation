function [PHASE_ANGLE_UNWRAPPED_ROWS, PHASE_ANGLE_UNWRAPPED_COLS] = ...
    unwrap_phase_svd(PHASE_PLANE_WRAPPED_COMPLEX)
% This function unwraps the dominant modes of the SVD of a 2D complex phase
% plane into two 1D phase-angle vectors.

% Calculate the SVD modes of the complex phase plane.
% Returned values are complex.
[svd_rows, E, svd_cols] = svd(PHASE_PLANE_WRAPPED_COMPLEX);

% Calculate the (wrapped) phase angles of the dominant modes of each SVD matrix.
% The angle() function inherently sets the range of these 
% vectors to (-pi, pi)
phase_angle_wrapped_rows = angle(svd_rows(:, 1));
phase_angle_wrapped_cols = angle(svd_cols(:, 1));

% Unwrap the dominant modes. 
% Use the default jump tolerance of 2pi because the 
% range of the wrapped phase angle vectors is automatically
% set to (-pi, pi) by the angle() function
PHASE_ANGLE_UNWRAPPED_ROWS = unwrap(phase_angle_wrapped_rows);
PHASE_ANGLE_UNWRAPPED_COLS = unwrap(phase_angle_wrapped_cols);

end