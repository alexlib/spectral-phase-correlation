
% Add paths
addpath ../correlation_algorithms/
addpath ../filtering/
addpath ../phase_unwrapping/
addpath ../jobfiles/

% close all

% Plot font size
fSize = 12;

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

% Threshold for im2bw operation in the phase quality thresholding operation
phase_mask_threshold = 0.9;

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

% Zero frequency pixel
xc = region_height / 2 + 1 - mod(region_height, 2);
yc = region_height / 2 + 1 - mod(region_height, 2);


phase_mask_threshold = 0.3;

img_num = 19;

% Loop over images
for k = img_num : img_num;
	
	% Inform the user
	fprintf('On image %d of %d...\n', k, num_images);
	
	% Load the images
	region_01_raw = double(imageMatrix1(:, :, k));
	region_02_raw = double(imageMatrix2(:, :, k));

	% Windowed regions
	region_01 = (region_01_raw - mean(region_01_raw(:))) .* g;
	region_02 = (region_02_raw - mean(region_02_raw(:))) .* g;
	
	% Standard CC
	scc_spectral = crossCorrelation(region_01, region_02);

	% phase correlation
	phase_corr_spectral = fftshift(phaseCorrelation(region_01, region_02));
	
	% Median filter the phase correlation
	phase_corr_mean = phase_mean_filter(phase_corr_spectral, [5, 5]);
	
	% Wrapped phase angle plane
	wrapped_phase_angle_plane = angle(phase_corr_mean);
	
	% Calculate the phase quality and the resulting phase mask.
	[phase_mask, phase_quality] = ...
	calculate_phase_mask(wrapped_phase_angle_plane, phase_mask_threshold);
	
	% Phase angle plane
	spc_spectral = angle(phase_corr_spectral);

	% Invert the FT of the SCC
	scc = fftshift(abs(real(ifftn(scc_spectral))));

	% Invert the FT of the GCC
	gcc = fftshift(abs(real(ifftn(phase_corr_spectral,...
	    [region_height, region_width]))));
		
	% Invert the FT of the APC
	apc = fftshift(abs(real(ifftn(phase_mask .* phase_corr_spectral,...
	    [region_height, region_width]))));

	% SCC to plot
	scc_plot = scc(1 : Skip : end, 1 : Skip : end);

	% GCC to plot
	gcc_plot = gcc(1 : Skip : end, 1 : Skip : end);
	
	% APC to plot
	apc_plot = apc(1 : Skip : end, 1 : Skip : end);
		
	% Plot the phase angle plane.
	subplot(2, 3, 1);
	imagesc(spc_spectral); axis image;
	title('SPC plane', 'fontsize', fSize);
	axis off
	
	% Plot the phase quality.
	subplot(2, 3, 2);
	imagesc((phase_quality(2 : end - 1, 2 : end - 1)));
	axis image;
	axis off
	title('Phase quality', 'FontSize', fSize);
	caxis([0, 1]);
	
	% Plot the phase mask.
	subplot(2, 3, 3); 
	imagesc(phase_mask);
	axis image;
	axis off
	title({'Phase mask', ['Threshold = '...
	 num2str(phase_mask_threshold, '%0.2f')]}, ...
	 'FontSize', fSize)
	
	% Plot the SCC.
	subplot(2, 3, 4);
	mesh(scc_plot ./ max(scc_plot(:)), 'EdgeColor', 'black');
	axis square
	xlim([0, region_width]);
	ylim([0, region_height]);
	axis off
	title('SCC', 'FontSize', 12)
	
	 % Plot the GCC.
	subplot(2, 3, 5);
	mesh(gcc_plot ./ max(gcc_plot(:)), 'edgecolor', 'black');
	axis square;
	% xlim([0, region_width/2 - 1]);
	% ylim([0, region_height/2 - 1]);
	xlim([0, region_width]);
	ylim([0, region_height]);
	axis off
	title('GCC', 'FontSize', 12)
	
	% Plot the APC.
	subplot(2, 3, 6); 
	mesh(apc_plot ./ max(apc_plot(:)), 'edgecolor', 'black');
	axis square;
	% xlim([0, region_width/2 - 1]);
	% ylim([0, region_height/2 - 1]);
	xlim([0, region_width]);
	ylim([0, region_height]);
	axis off
	title('APC', 'FontSize', 12)
	
	% Pause
	pause(0.25)

end


