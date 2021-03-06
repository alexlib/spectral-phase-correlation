% Get repository path
repo_path = getpath('spectral-phase-correlation');

% Add paths
addpath(fullfile(repo_path, 'correlation_algorithms'));
addpath(fullfile(repo_path, 'phase_unwrapping'));
addpath(fullfile(repo_path, 'filtering'));
addpath(fullfile(repo_path, 'jobfiles'));
addpath(fullfile(repo_path, 'scripts'));

% Plot font size
fSize = 12;

% Input data directory
% input_dir = '/Users/matthewgiarra/Desktop/ts3_000014';
% input_dir = ['/Users/matthewgiarra/Documents/School' ...
%     '/VT/Research/Aether/spc/analysis/data/xray/mng-2-069-E/raw'];

input_dir = '~/Desktop/schlieren/raw';

% Input data base name 
input_base_name = 'jhu_buoy_turb_';

% Number of digits in the file names.
num_digits = 2; 

% Input data extension
input_extension = '.tif';

% Grid point location (just a single grid point)
grid_col = 512;

grid_row = 512;

% Start image
start_image = 1;

% End image
end_image = 8;

% Frame step
frame_step = 1;

ensemble_radius = 3;

% Color channel to correlate
color_channel = 1;

% Correlation step
correlation_step = 1;

% Region size
region_height = 128;
region_width = 128;

% Window fractions
window_fraction = [0.5, 0.5];

% Correlation method
correlation_method = 'apc';

% APC kernel radius
apc_kernel_radius = 3;

% Apc mask method
apc_mask_method = 'gaussian';

% Chunk size;
apc_ensemble_radius = 3;

% Image numbers
image_numbers_full_01 = start_image : frame_step : end_image;

% Second image numbers
image_numbers_full_02 = image_numbers_full_01 + correlation_step;

% Number of images
num_images_full = length(image_numbers_full_01);

% Number of images after ensemble
image_nums = ensemble_radius + 1 : num_images_full - ensemble_radius;

% Number of images to correlate
num_images = length(image_nums);

% Region rows
region_rows = grid_row + [-region_height/2 : region_height/2 - 1];

% Region columns
region_cols = grid_col +  [-region_width/2 : region_width/2 - 1];

% Create a region window
region_window = gaussianWindowFilter([region_height, region_width], ...
    window_fraction, 'fraction');

% Allocate a correlation plane
cross_correlation = zeros(region_height, region_width, 'double');

% Input data number format
num_format = ['%0' num2str(num_digits) 'd'];

% Allocate matrix
imageMatrix1 = zeros(region_height, region_width, num_images);
imageMatrix2 = zeros(region_height, region_width, num_images);

% RPC filter
rpc_filter = spectralEnergyFilter(region_height, region_width, sqrt(8));
gcc_filter = ones(region_height, region_width);

TY_RPC = zeros(num_images, 1);
TX_RPC = zeros(num_images, 1);

TY_APC = zeros(num_images, 1);
TX_APC = zeros(num_images, 1);

TY_SCC = zeros(num_images, 1);
TX_SCC = zeros(num_images, 1);

TY_GCC = zeros(num_images, 1);
TX_GCC = zeros(num_images, 1);

apc_method = 'gaussian';

% APC filter
for k = 1 : num_images_full
   
    % File name of the first images
    file_name_01 = [input_base_name num2str(image_numbers_full_01(k), num_format) input_extension];
    
    % File name of the second images
    file_name_02 = [input_base_name num2str(image_numbers_full_02(k), num_format) input_extension];
    
    % File paths
    image_01 = double(imread(fullfile(input_dir, file_name_01)));
    image_02 = double(imread(fullfile(input_dir, file_name_02)));
    
    region_01 = image_01(region_rows, region_cols, color_channel);
    region_02 = image_02(region_rows, region_cols, color_channel);
    
    imageMatrix1(:, :, k) = ...
        region_window .* (region_01 - mean(region_01(:)));
    imageMatrix2(:, :, k) = ...
        region_window .* (region_02 - mean(region_02(:)));

end

[apc_filter, phase_quality, phase_angle] = ...
    calculate_apc_phase_mask_from_images(...
    imageMatrix1, imageMatrix2, ...
    apc_kernel_radius, apc_method);


 % SCC correlation
[TY_SCC, TX_SCC, scc_plane] = scc_ensemble(...
    imageMatrix1(:, :, 1), ...
    imageMatrix2(:, :, 1), 1);

 % RPC correlation
[TY_RPC, TX_RPC, rpc_plane] = rpc_ensemble(...
    imageMatrix1(:, :, 1), ...
    imageMatrix2(:, :, 1), ...
    rpc_filter, 1);

 % APC correlation
[TY_APC, TX_APC, apc_plane] = rpc_ensemble(...
    imageMatrix1(:, :, 1), ...
    imageMatrix2(:, :, 1), ...
    apc_filter, 1);

 % APC correlation
[TY_GCC, TX_GCC, gcc_plane] = rpc_ensemble(...
    imageMatrix1(:, :, 1), ...
    imageMatrix2(:, :, 1), ...
    gcc_filter, 1);

figure(1);
surf(apc_plane ./ max(apc_plane(:)), 'linewidth', 0.1);
axis square
xlim([1 region_width]);
ylim([1 region_height]);
zlim([0, 1]);
set(gca, 'view', [-60   4.4000]);
axis off

figure(2);
surf(scc_plane ./ max(scc_plane(:)), 'linewidth', 0.1);
axis square
xlim([1 region_width]);
ylim([1 region_height]);
zlim([0, 1]);
set(gca, 'view', [-60   4.4000]);
axis off

figure(3);
surf(rpc_plane ./ max(rpc_plane(:)), 'linewidth', 0.1);
axis square
xlim([1 region_width]);
ylim([1 region_height]);
zlim([0, 1]);
set(gca, 'view', [-60   4.4000]);
axis off

figure(4);
surf(gcc_plane ./ max(gcc_plane(:)), 'linewidth', 0.1);
axis square
xlim([1 region_width]);
ylim([1 region_height]);
zlim([0, 1]);
set(gca, 'view', [-60   4.4000]);
axis off

% Do the correlations
for k = 1 : num_images

        % Inform the user
        fprintf('Processing image %d of %d...\n', k, num_images);
        
        % Read the first image
        region_01_raw = imageMatrix1(:, :, k);
		        
        % Read the second image
        region_02_raw = imageMatrix2(:, :, k);
	 
        % Zero-mean
        region_01 = region_01_raw - mean(region_01_raw(:));
        region_02 = region_02_raw - mean(region_02_raw(:));
       
        % RPC correlation
        [TY_RPC(k), TX_RPC(k), rpc_plane] = RPC(...
            region_window .* region_01, ...
            region_window .* region_02, ...
            rpc_filter, 1);
        
        % APC correlation
        [TY_APC(k), TX_APC(k), apc_plane] = RPC(...
            region_window .* region_01, ...
            region_window .* region_02, ...
            apc_filter, 1);
        
        % SCC
        [TY_SCC(k), TX_SCC(k), scc_plane] = SCC(...
            region_window .* region_01, ...
            region_window .* region_02, 1);
        
        % GCC
        [TY_GCC(k), TX_GCC(k), gcc_plane] = RPC(...
            region_window .* region_01, ...
            region_window .* region_02, ...
            gcc_filter, 1);
        
        % Plots
        subplot(1, 4, 1);
        surf(scc_plane ./ max(scc_plane(:)), 'edgecolor', 'black', ...
            'linewidth', 1E-3);
        xlim([1 region_width]);
        ylim([1 region_height]);
        zlim([0, 1])
        axis square
        axis off
        set(gca, 'view', [-132.7000   15.6000]);
        
        subplot(1, 4, 2);
        surf(gcc_plane ./ max(gcc_plane(:)), 'edgecolor', ...
            'black', 'linewidth', 1E-3);
        xlim([1 region_width]);
        ylim([1 region_height]);
        zlim([0, 1])
        axis square
        axis off
        set(gca, 'view', [-132.7000   15.6000]);
        
        subplot(1, 4, 3);
        surf(rpc_plane ./ max(rpc_plane(:)), 'edgecolor', 'black', 'linewidth', 1E-3);
        xlim([1 region_width]);
        ylim([1 region_height]);
        zlim([0, 1])
        axis square
        axis off
         set(gca, 'view', [-132.7000   15.6000]);
        
        subplot(1, 4, 4);
        surf(apc_plane ./ max(apc_plane(:)), 'edgecolor', 'black', 'linewidth', 1E-3);
        xlim([1 region_width]);
        ylim([1 region_height]);
        zlim([0, 1])
        axis square
        axis off
        set(gca, 'view', [-132.7000   15.6000]);
        
        pause(0.1);
        
end
% 


% plot(TX_APC, 'ok', 'markerfacecolor', 'k');
% hold on;
% plot(TX_RPC, 'or', 'markerfacecolor', 'r');
% plot(TX_SCC, 'ob', 'markerfacecolor', 'b');
% ylim([-8 0]);
% hold off
% axis square
% h = legend('APC', 'RPC', 'SCC');
% set(h, 'FontSIze', 16);





















