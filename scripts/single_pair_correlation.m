
% Add paths
addpath ../correlation_algorithms/
addpath ../filtering/
addpath ../phase_unwrapping/
addpath ../jobfiles/

% close all

% Image number
% image_num = 1;

% Image directory
file_dir = '/Users/matthewgiarra/Desktop/piv_images/analysis/data/synthetic/lin/test_images/128x128/raw/lin_h128_w128_00001/';

% Case name
case_name = 'lin_h128_w128_seg_000001_000050';

% Name of the raw image matrkx
image_file_name = ['raw_image_matrix_' case_name '.mat'];

% Parameters file name
parameters_file_name = ['imageParameters_' case_name '.mat'];

% imageMatrix1 = img_01;
% imageMatrix2 = img_02;

% Path to the raw image matrix
image_file_path = fullfile(file_dir, 'raw', image_file_name);
parameters_file_path = fullfile(file_dir, 'parameters', parameters_file_name);

% Load the raw image matrix
load(image_file_path);

% Load the parameters
load(parameters_file_path);

% Measure the size of the images
[region_height, region_width, num_images] = size(imageMatrix1);

% Make a Gaussian window. 
g = gaussianWindowFilter([region_height, region_width], [0.5, 0.5], ...
    'fraction');
	
% Mesh plot skipping
Skip = 1;

% Measure the shearing
shear_x = Parameters.ShearX;
shear_y = Parameters.ShearY;

% Zero frequency pixel
xc = region_height / 2 + 1 - mod(region_height, 2);
yc = region_height / 2 + 1 - mod(region_height, 2);

% Loop over images
for k = num_images : num_images;
	
	% Load the images
	region_01_raw = double(imageMatrix1(:, :, k));
	region_02_raw = double(imageMatrix2(:, :, k));

	% Windowed regions
	region_01 = (region_01_raw - mean(region_01_raw(:))) .* g;
	region_02 = (region_02_raw - mean(region_02_raw(:))) .* g;

	% phase correlation
	phase_corr_spectral = phaseCorrelation(region_01, region_02);

	% Real part of the phase correlation
	real_phase_corr = fftshift(real(phase_corr_spectral));

	% Phase angle plane
	spc_spectral = fftshift(angle(phase_corr_spectral));

	% Invert the FT
	gcc = fftshift(abs(real(ifftn(phase_corr_spectral,...
	    [region_height, region_width]))));

	% gcc to plot
	gcc_plot = gcc(1 : Skip : end, 1 : Skip : end);
	
	% Extract the shears
	sx = shear_x(k);
	sy = shear_y(k);
	
	% x_right 
	x_01  =  -region_height/2 * sx + xc;
	x_02 =  region_height/2 * sx + xc;
	
	y_01 = 1;
	y_02 = region_height;

	% Plot

	subplot(1, 4, 1);
	imagesc(region_02_raw);
	axis image;
	hold on;
	plot([x_01, x_02], [y_01, y_02], '-y');
	hold off;
	axis off;
	title('Region', 'FontSize', 12);
	
	% Plot
	subplot(1, 4, 2);
	imagesc(real_phase_corr); axis image;
	axis off
	title('Real part of phase', 'FontSize', 12);


	subplot(1, 4, 3);
	imagesc(spc_spectral); axis image;
	title('SPC plane', 'fontsize', 12);
	axis off
	
	subplot(1, 4, 4); 
	mesh(gcc_plot ./ max(gcc_plot(:)), 'edgecolor', 'black');
	axis square;
	% xlim([0, region_width/2 - 1]);
	% ylim([0, region_height/2 - 1]);
	xlim([0, region_width]);
	ylim([0, region_height]);
	axis off
	title('GCC', 'FontSize', 12)
	
	% Pause
	pause(0.25)

end


