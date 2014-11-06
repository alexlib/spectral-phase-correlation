function [TY_SPC, TX_SPC] = spc_svd_unwrap(REGION_01, REGION_02, SPC_WEIGHTS_ROWS, SPC_WEIGHTS_COLS);
% Spectral phase correlation using SVD dominant-mode unwrapping.

% Dimensions of the regions
[region_height, region_width] = size(REGION_01);

% Phase only correlaiton of images
% Returns complex plane
phase_plane_wrapped_complex = fftshift(phaseCorrelation(REGION_01, REGION_02));

% Unwrap the dominant modes
[phase_angle_unwrapped_cols, phase_angle_unwrapped_rows] ...
    = unwrap_phase_svd_1D(phase_plane_wrapped_complex);

% Degree of the polynomial fit.
% This should always be 1 in this function. 
% Included for legibility.
polynomial_fit_degree = 1;

% Weighted 1-D least squares fits to the unwrapped phases.
fit_coeff_rows = polyfit3(1 : region_height,phase_angle_unwrapped_rows', polynomial_fit_degree,[], SPC_WEIGHTS_ROWS);
fit_coeff_cols = polyfit3(1 : region_width, phase_angle_unwrapped_cols', polynomial_fit_degree,[], SPC_WEIGHTS_COLS);

% SPC estimates of translations
TY_SPC = -fit_coeff_rows(1) * region_height / (2 * pi);
TX_SPC = fit_coeff_cols(1) * region_width  / (2 * pi);

end






























