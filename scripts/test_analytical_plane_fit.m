
addpath correlation_algorithms
addpath phase_unwrapping
addpath filtering
addpath scripts
addpath jobfiles

% test_analytical_plane_fit

% Region height and width
region_height = 128;
region_width = 128;

% Displacements in pixels
sx = 10.000;
sy = 3;

% Domain
[x, y] = meshgrid(1 : region_width, 1 : region_height);

% Weights
w = ones(size(x));
w(1, :) = 0;
w(end, :) = 0;
w(:, 1) = 0;
w(:, end) = 0;

% Complex phase correlation (analytical)
p_complex = exp(-1i * 2 * pi * ...
    (sx * x / region_width + sy * y / region_height));

% Unwrap the phase angle
phase_angle_unwrapped = GoldsteinUnwrap2D(p_complex, 9, 1);

% SPC plane fit
[ty, tx, COEFFS] = spc_plane_fit(phase_angle_unwrapped, w);

% Display result
fprintf('tx = %0.7f\tty = %0.7f\n', tx, ty);
