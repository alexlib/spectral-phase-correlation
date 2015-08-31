% Create an array

% Region size
region_height = 128;
region_width = 128;

% Create coordinates
[u, v] = meshgrid(1 : region_width, 1 : region_height);

% Pixel Shifts
sy = 1;
sx = 2;


% Centroid locations
uc = region_width/2;
vc = region_height/2;

% Gaussian noise window std dev
std = region_height / 4;

% Noise scale
noise_scale = 1;

% Std scale
std_dev_scale = 1.5;

% Standard deviations
std_x = std_dev_scale * region_width/4;
std_y = std_dev_scale * region_height/4;

% Gaussian
g = 1 - exp(-(u - uc).^2 / (std_x)^2 ...
		-(v - vc).^2 / (std_y)^2);
		
% Create noise
noise_real = 	  noise_scale * g .* randn([region_height, region_width]);
noise_imag = 1i * noise_scale * g .* randn([region_height, region_width]);

% Calculate complex function
complex_phase = exp(-1i*2*pi*(sx/region_width * u + sy / region_height * v)) + noise_real + noise_imag;

% Phase angle
phase_angle = angle(complex_phase);

% Phase quality
phase_quality = calculate_phase_quality(phase_angle, 1);

subplot(1, 3, 1);
mesh(g);
title('Noise window', 'FontSize', 20);

% Mesh plot
subplot(1, 3, 2);
imagesc(phase_angle);
axis image;
title('Phase angle', 'FontSize', 20);

subplot(1, 3, 3);
mesh(phase_quality(2 : end - 1, 2 : end - 1));
axis square;
title('Phase quality', 'FontSize', 20)












