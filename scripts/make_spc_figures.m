
% Region size
region_height = 128;
region_width = 128;


% Domain
[x, y] = meshgrid(1 : region_height, 1 : region_width);

xc = region_width / 2;
yc = region_height / 2;

xp = (x(1, :) - xc) / region_width * 2;
yp = ((y(:, 1))' - yc) / region_height * 2;

% Displacements
sx = 3;
sy = 3;

% Noise magnitude
noise_mag = 5;

% Noise window
noise_win = 1 - gaussianWindowFilter([region_height, region_width], [0.95, 0.95], 'fraction');

% Make noise
real_noise = noise_win .* randn(size(x)) * noise_mag;
imag_noise = noise_win .* randn(size(x)) * noise_mag;

% real_noise = zeros(size(x));
% imag_noise = zeros(size(x));

% Phase plane
phase_plane = exp(2 * pi * 1i * (sx / region_width .* x + sy / region_height .* y)) + real_noise + 1i * imag_noise;

plot(atan(real(phase_plane(yc, :))), '-k', 'linewidth', 1);
axis square


% Extract angle
phase_angle = angle(phase_plane);

% Phase quality
phase_quality = calculate_phase_quality(phase_angle, 3);

phase_quality = phase_quality(4 : end - 3, 4 : end - 3);

q = phase_quality ./ max(phase_quality(:));

q_inv = 1 - q;

[phase_plane_unwrapped] = ...
            GoldsteinUnwrap2D(phase_plane, ...
            7, 0);
        
phase_plane_unwrapped = phase_plane_unwrapped(2 : end - 1, 2 : end - 1) / pi;

% mesh(phase_plane_unwrapped);



% figure(1);
% plot(xp, phase_angle(:, xc) / pi, '-k', 'linewidth', 3)
% ylim(1.1 * [-1, 1]);
% axis square;
% axis off;
% print(1, '-deps', '~/Desktop/phase_angle_plane_wrapped.eps');
% 
% figure(2);
% plot(xp(2 : end - 1), phase_plane_unwrapped(:, xc), '-k', 'LineWidth', 3);
% axis square
% axis off;
% print(2, '-deps', '~/Desktop/phase_angle_plane_unwrapped.eps');
% 
% figure(3)
% plot(q_inv(:, xc), '-k', 'linewidth', 3);
% axis square
% axis off
% print(3, '-deps', '~/Desktop/phase_quality.eps');
% 
% figure(4);
% hold on;
% plot(xp(2 : end - 1), phase_plane_unwrapped(:, xc) ./ max(phase_plane_unwrapped(:)), '-k', 'linewidth', 3);
% plot(xp(4 : end - 3), q_inv(:, xc), '-r', 'linewidth', 3);
% hold off

Skip = 4;

figure(1);
mesh(phase_angle(1 : Skip : end, 1 : Skip : end), 'edgecolor', 'black');
axis square;
axis off;
% set(gca, 'view', [107.3000   14.0000]);
set(gca, 'view', [ 80.9000   10.0000]);
% print(1, '-depsc', '~/Desktop/phase_angle_plane_wrapped_2D.eps');

figure(2);
mesh(phase_plane_unwrapped(1 : Skip : end, 1 : Skip : end), 'edgecolor' ,'black');
axis square
axis off;
% set(gca, 'view', [-37.5000   30.0000]);
set(gca, 'view', [ 80.9000   10.0000]);
% print(2, '-deps', '~/Desktop/phase_angle_plane_unwrapped_2D.eps');

figure(3)
plot(q_inv(:, xc), '-k', 'linewidth', 3);
axis square
axis off
% print(3, '-deps', '~/Desktop/phase_quality_2D.eps');

















