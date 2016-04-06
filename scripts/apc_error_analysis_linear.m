% Get repository path
repo_path = getpath('spectral-phase-correlation');

% Add paths
addpath(fullfile(repo_path, 'correlation_algorithms'));
addpath(fullfile(repo_path, 'phase_unwrapping'));
addpath(fullfile(repo_path, 'filtering'));
addpath(fullfile(repo_path, 'jobfiles'));
addpath(fullfile(repo_path, 'scripts'));

set_type = 'lin';
region_height = 128;
region_width = 128;
heightstr = num2str(region_height);
widthstr = num2str(region_width);

image_noise = 0.20;

% case_name = ['piv_test_micro_noise_' num2str(image_noise, '%0.2f')];
case_name = ['piv_test_micro_diffusion_0_5'];

region_str = [heightstr 'x' widthstr];

image_path = ['~/Desktop/piv_test_images/analysis/' ...
    'data/synthetic/' set_type '/' case_name '/' region_str ...
    '/raw/' set_type '_h' heightstr '_w' widthstr '_00001/raw/' ...
    'raw_image_matrix_' set_type '_h' heightstr '_w' widthstr ...
    '_seg_000001_001000.mat'];

% image_path = '~/Desktop/fullfieldRegions.mat';


parameters_path = ['~/Desktop/piv_test_images/analysis/' ...
    'data/synthetic/' set_type '/' case_name '/' region_str ...
    '/raw/' set_type '_h' heightstr '_w' widthstr '_00001/parameters/' ...
    'imageParameters_' set_type '_h' heightstr '_w' widthstr ...
    '_seg_000001_001000.mat'];

% Apc phase mask method
apc_phase_mask_method = 'gaussian';

% Load the images.
load(image_path);

% Load parameters;
load(parameters_path);

% Number of images to skip
skip = 1;

% Measure images
[region_height, region_width, num_images_full] = size(imageMatrix1);

% Kernel size
apc_kernel_radius = 5;

% Ensemble length
ensemble_radius = 10;

% Image numbers
image_nums = ensemble_radius + 1 : skip : num_images_full - ensemble_radius;

% Measure true translations
tx_true = Parameters.Translation.X(image_nums);
ty_true = -1 * Parameters.Translation.Y(image_nums);

% Diffusion
diffusion_true = Parameters.Diffusion(image_nums);

% Number of images that will be correlated
num_images = length(image_nums);
% num_images = 1000;

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

% Make the apodization filter
region_window = gaussianWindowFilter(...
    [region_height, region_width], [0.5, 0.5], 'fraction');

% Allocate the APC filter matrix
apc_filter = zeros(region_height, region_width, num_images);

% Do the correlations
for k = 1 : num_images

        % Inform the user
        fprintf('Processing image %d of %d...\n', k, num_images);
        
        % Number of the central image
        n = image_nums(k);
        
        % Extract the blocks from the region matrix
        region_block_01 = imageMatrix1(:, :, n - ensemble_radius : n + ensemble_radius);
        region_block_02 = imageMatrix2(:, :, n - ensemble_radius : n + ensemble_radius);
        
        % Calculate the phase filter
        [apc_filter(:, :, k), phase_quality, phase_angle] = ...
            calculate_apc_phase_mask_from_images(region_block_01,...
            region_block_02, region_window, apc_kernel_radius, ...
            apc_phase_mask_method);
        
        % Read the first image
        region_01_raw = double(imageMatrix1(:, :, n));
		        
        % Read the second image
        region_02_raw = double(imageMatrix2(:, :, n));
	 
        % Zero-mean
        region_01 = region_01_raw - mean(region_01_raw(:));
        region_02 = region_02_raw - mean(region_02_raw(:));
        
        % RPC correlation
        [TY_RPC(k), TX_RPC(k), rpc_plane] = RPC(...
            region_01 .* region_window, ...
            region_02 .* region_window, ...
            rpc_filter, 1);
        

        
        
        
        % APC correlation
        [TY_APC(k), TX_APC(k), apc_plane] = RPC(...
            region_01 .* region_window, ...
            region_02 .* region_window, ...
            apc_filter(:, :, k), 1);
        
        % SCC
        [TY_SCC(k), TX_SCC(k), scc_plane] = SCC(...
             region_01 .* region_window, ...
             region_02 .* region_window, 1);
        
        % GCC
        [TY_GCC(k), TX_GCC(k), gcc_plane] = RPC(...
            region_01 .* region_window, ...
            region_02 .* region_window,...
            gcc_filter, 1);
        
        subplot(2, 2, 1);
        imagesc(phase_angle); axis image;
        caxis([-pi, pi]);
        title('Phase angle');
        axis off
        
        subplot(2, 2, 2);
        imagesc(apc_filter(:, :, k));
        axis image;
        title(sprintf('APC Filter, Diffusion: %0.3f', Parameters.Diffusion(n)));
        axis off
        p = get(gca, 'position');
        p(1) = 0.4;
        set(gca, 'position', p);
        
        subplot(2, 2, 3);
        mesh(rpc_plane ./ max(rpc_plane(:)), 'edgecolor', 'black'); axis square
        title('RPC');
        xlim([1 region_width]);
        ylim([1 region_height]);
        axis off;
        p = get(gca, 'position');
        p(2) = 0.15;
        set(gca, 'position', p);
        
        subplot(2, 2, 4);
        mesh(apc_plane ./ max(apc_plane(:)), 'edgecolor', 'black'); axis square
        title('APC');
        xlim([1 region_width]);
        ylim([1 region_height]);
        axis off
        p = get(gca, 'position');
        p(1) = 0.4;
        p(2) = 0.15;
        set(gca, 'position', p);
        print(1, '-dpng', '-r250', sprintf('~/Desktop/plots/%06d.png', k));

        
%         % Plots
%         subplot(1, 4, 1);
%         mesh(scc_plane ./ max(scc_plane(:)), 'edgecolor', 'black');
%         xlim([1 region_width]);
%         ylim([1 region_height]);
%         zlim([0, 1])
%         axis square
%         
%         subplot(1, 4, 2);
%         mesh(gcc_plane ./ max(gcc_plane(:)), 'edgecolor', 'black');
%         xlim([1 region_width]);
%         ylim([1 region_height]);
%         zlim([0, 1])
%         axis square
%         
%         subplot(1, 4, 3);
%         mesh(rpc_plane ./ max(rpc_plane(:)), 'edgecolor', 'black');
%         xlim([1 region_width]);
%         ylim([1 region_height]);
%         zlim([0, 1])
%         axis square
%         
%         subplot(1, 4, 4);
%         mesh(apc_plane ./ max(apc_plane(:)), 'edgecolor', 'black');
%         xlim([1 region_width]);
%         ylim([1 region_height]);
%         zlim([0, 1])
%         axis square
%         
%     
%         
end

% True translation magnitude
t_mag_true = sqrt(tx_true .^2 + ty_true .^2);

% Measure errors
err_rpc_x = TX_RPC - tx_true;
err_rpc_y = TY_RPC - ty_true;
err_rpc_mag = sqrt(err_rpc_x.^2 + err_rpc_y.^2);

err_scc_x = TX_SCC - tx_true;
err_scc_y = TY_SCC - ty_true;
err_scc_mag = sqrt(err_scc_x.^2 + err_scc_y.^2);

err_apc_x = TX_APC - tx_true;
err_apc_y = TY_APC - ty_true;
err_apc_mag = sqrt(err_apc_x.^2 + err_apc_y.^2);

err_gcc_x = TX_GCC - tx_true;
err_gcc_y = TY_GCC - ty_true;
err_gcc_mag = sqrt(err_gcc_x.^2 + err_gcc_y.^2);

% figure(1);
% subplot(1, 4, 1);
% plot(t_mag_true, err_scc_mag, '.k');
% axis square;
% grid on;
% title('SCC');
% ylim([0 1]);
% 
% 
% subplot(1, 4, 2);
% plot(t_mag_true, err_gcc_mag, '.k');
% axis square;
% grid on;
% title('GCC');
% ylim([0 1]);
% 
% 
% subplot(1, 4, 3);
% plot(t_mag_true, err_rpc_mag, '.k');
% axis square;
% grid on;
% title('RPC');
% ylim([0 1]);
% 
% subplot(1, 4, 4);
% plot(t_mag_true, err_apc_mag, '.k');
% axis square;
% grid on;
% title('APC');
% ylim([0 1]);
% 

% Non outlier indices
valid_ind_rpc = find(err_rpc_mag < (mean(err_rpc_mag) + 2 * std(err_rpc_mag)));
valid_ind_apc = find(err_apc_mag < (mean(err_apc_mag) + 2 * std(err_apc_mag)));
valid_ind_scc = find(err_scc_mag < (mean(err_scc_mag) + 2 * std(err_scc_mag)));
valid_ind_gcc = find(err_gcc_mag < (mean(err_gcc_mag) + 2 * std(err_gcc_mag)));


diffusion_std = mean(Parameters.Diffusion);

fSize = 16;
figure(2);
% Make a cdf plot
h = cdfplot(err_scc_mag(valid_ind_scc));
set(h, 'LineWidth', 2);
hold on;
h = cdfplot(err_gcc_mag(valid_ind_gcc));
set(h, 'LineWidth', 2);
h = cdfplot(err_rpc_mag(valid_ind_rpc));
set(h, 'LineWidth', 2);
h = cdfplot(err_apc_mag(valid_ind_apc));
set(h, 'LineWidth', 2);
set(h, 'Color', 'black');
hold off
L = legend('SCC', 'GCC', 'RPC', 'APC');
set(L, 'FontSize', 16, 'location', 'southeast');
set(gca, 'FontSize', fSize);
axis square
ylim([0 1]);
xlim([0 1]);
grid on;
title({'CDF of error magnitudes', ...
    [ num2str(num_images + 2 * ensemble_radius) ...
    ' Synthetic micro-PIV images'], ...
    [region_str ' regions, 50% Gaussian window']...
    ['Diffusion Std dev: ' num2str(diffusion_std, '%0.2f') ' pix/frame, image noise ', num2str(100 * image_noise) '%' ]}, ...
    'FontSize', 12);

xlabel('Error magnitude (pixels)', 'FontSIze', fSize);
ylabel('Cumulative probability', 'FontSize', fSize);
set(gcf, 'color', 'white');

fprintf('Mean errors:\nSCC\tGCC\tRPC\tAPC\n%0.3f\t%0.3f\t%0.3f\t%0.3f\n\n', ...
    mean(err_scc_mag(valid_ind_scc)), mean(err_gcc_mag(valid_ind_gcc)), ...
    mean(err_rpc_mag(valid_ind_rpc)), mean(err_apc_mag(valid_ind_apc)));

fprintf('Std Dev errors:\nSCC\tGCC\tRPC\tAPC\n%0.3f\t%0.3f\t%0.3f\t%0.3f\n\n', ...
    2 * std(err_scc_mag(valid_ind_scc)), 2 * std(err_gcc_mag(valid_ind_gcc)), ...
    2 * std(err_rpc_mag(valid_ind_rpc)), 2 * std(err_apc_mag(valid_ind_apc)));

shear = Parameters.Shear.XZ(image_nums);
noise_std = Parameters.ImageNoise.StdDev(image_nums);

plot_name = ['error_cdf_' region_str '_diffusion_'...
    num2str(diffusion_std, '%0.2f') '_noise_' num2str(image_noise, '%0.2f') '.eps'];

plot_dir = '~/Desktop/cdfplots';
plot_path = fullfile(plot_dir, plot_name);

print(2, '-depsc', plot_path);
% 
% 
% figure(3);
% subplot(1, 4, 1);
% plot(noise_std, err_scc_mag, '.k',  'markersize', 20);
% xlabel('Noise Std Dev', 'FontSize', 16);
% ylabel('Error magnitude (pixels)', 'FontSize', 16);
% xlim([0, 1]);
% ylim([0, 10]);
% axis square
% grid on;
% title('SCC', 'FontSize', 16);
% 
% subplot(1, 4, 2);
% plot(noise_std, err_gcc_mag, '.k',  'markersize', 20);
% xlabel('Noise Std Dev', 'FontSize', 16);
% ylabel('Error magnitude (pixels)', 'FontSize', 16);
% xlim([0, 1]);
% ylim([0, 10]);
% axis square
% grid on;
% title('GCC', 'FontSize', 16);
% 
% subplot(1, 4, 3);
% plot(noise_std, err_rpc_mag, '.k',  'markersize', 20);
% xlabel('Noise Std Dev', 'FontSize', 16);
% ylabel('Error magnitude (pixels)', 'FontSize', 16);
% xlim([0, 1]);
% ylim([0, 10]);
% axis square
% grid on;
% title('RPC', 'FontSize', 16);
% 
% subplot(1, 4, 4);
% plot(noise_std, err_apc_mag, '.k',  'markersize', 20);
% xlabel('Noise Std Dev', 'FontSize', 16);
% ylabel('Error magnitude (pixels)', 'FontSize', 16);
% xlim([0, 1]);
% ylim([0, 10]);
% axis square
% grid on;
% title('APC', 'FontSize', 16);
% 




















