
set_type = 'lin';
region_height = 128;
region_width = 128;
heightstr = num2str(region_height);
widthstr = num2str(region_width);


region_str = [heightstr 'x' widthstr];

image_path = ['~/Desktop/piv_test_images/analysis/' ...
    'data/synthetic/' set_type '/piv_test_micro/' region_str ...
    '/raw/' set_type '_h' heightstr '_w' widthstr '_00001/raw/' ...
    'raw_image_matrix_' set_type '_h' heightstr '_w' widthstr ...
    '_seg_000001_010000.mat'];

parameters_path = ['~/Desktop/piv_test_images/analysis/' ...
    'data/synthetic/' set_type '/piv_test_micro/' region_str ...
    '/raw/' set_type '_h' heightstr '_w' widthstr '_00001/parameters/' ...
    'imageParameters_' set_type '_h' heightstr '_w' widthstr ...
    '_seg_000001_010000.mat'];

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
apc_kernel_radius = 3;

% Ensemble length
ensemble_radius = 1;

% Image numbers
image_nums = ensemble_radius + 1 : skip : num_images_full - ensemble_radius;

% Measure true translations
tx_true = Parameters.Translation.X(image_nums);
ty_true = Parameters.Translation.Y(image_nums);

% Number of images that will be correlated
num_images = length(image_nums);

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

% Do the correlations
parfor k = 1 : num_images

        % Inform the user
        fprintf('Processing image %d of %d...\n', k, num_images);
        
        % Number of the central image
        n = image_nums(k);
        
        % Extract the blocks from the region matrix
        region_block_01 = imageMatrix1(:, :, n - ensemble_radius : n + ensemble_radius);
        region_block_02 = imageMatrix2(:, :, n - ensemble_radius : n + ensemble_radius);
        
        % Calculate the phase filter
        [apc_filter, phase_quality, phase_angle] = ...
            calculate_apc_phase_mask_from_images(region_block_01,...
            region_block_02, region_window, apc_kernel_radius, ...
            apc_phase_mask_method);
        
        % Read the first image
        region_01_raw = imageMatrix1(:, :, n);
		        
        % Read the second image
        region_02_raw = imageMatrix2(:, :, n);
	 
        % Zero-mean
        region_01 = region_01_raw - mean(region_01_raw(:));
        region_02 = region_02_raw - mean(region_02_raw(:));
        
        % RPC correlation
        [TY_RPC(k), TX_RPC(k), rpc_plane] = RPC(region_01, region_02, rpc_filter, 1);
        
        % APC correlation
        [TY_APC(k), TX_APC(k), apc_plane] = RPC(region_01, region_02, apc_filter, 1);
        
        % SCC
        [TY_SCC(k), TX_SCC(k), scc_plane] = SCC(region_01, region_02, 1);
        
        % GCC
        [TY_GCC(k), TX_GCC(k), gcc_plane] = RPC(region_01, region_02, gcc_filter, 1);
        
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
%         pause();
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

diffusion_std = mean(Parameters.Diffusion);

fSize = 16;
figure(2);
% Make a cdf plot
h = cdfplot(err_scc_mag);
set(h, 'LineWidth', 2);
hold on;
h = cdfplot(err_gcc_mag);
set(h, 'LineWidth', 2);
h = cdfplot(err_rpc_mag);
set(h, 'LineWidth', 2);
h = cdfplot(err_apc_mag);
set(h, 'LineWidth', 2);
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
    ['Diffusion Std dev: ' num2str(diffusion_std, '%0.2f') ' pix/frame']}, ...
    'FontSize', 12);

xlabel('Error magnitude (pixels)', 'FontSIze', fSize);
ylabel('Cumulative probability', 'FontSize', fSize);
set(gcf, 'color', 'white');


shear = Parameters.Shear.XZ(image_nums);

plot_name = ['error_cdf_' region_str '_diffusion_'...
    num2str(diffusion_std, '%0.2f') '.png'];

plot_dir = '~/Desktop/cdfplots';
plot_path = fullfile(plot_dir, plot_name);

print(2, '-dpng', plot_path);
% % Read the shear
% figure(3);
% subplot(3, 1, 1);
% plot(shear, err_scc_mag, '.k',  'markersize', 20);
% xlabel('\sigma_{13}', 'FontSize', 16);
% ylabel('Error magnitude (pixels)', 'FontSize', 16);
% xlim([0, 1]);
% ylim([0, 10]);
% axis square
% grid on;
% title('SCC', 'FontSize', 16);
% 
% subplot(3, 1, 2);
% plot(shear, err_rpc_mag, '.k',  'markersize', 20);
% xlabel('\sigma_{13}', 'FontSize', 16);
% ylabel('Error magnitude (pixels)', 'FontSize', 16);
% xlim([0, 1]);
% ylim([0, 10]);
% axis square
% grid on;
% title('RPC', 'FontSize', 16);
% 
% subplot(3, 1, 3);
% plot(shear, err_apc_mag, '.k',  'markersize', 20);
% xlabel('\sigma_{13}', 'FontSize', 16);
% ylabel('Error magnitude (pixels)', 'FontSize', 16);
% xlim([0, 1]);
% ylim([0, 10]);
% axis square
% grid on;
% title('APC', 'FontSize', 16);

% plot(shear, err_scc_mag, '.k',  'markersize', 20);
% hold on
% plot(shear, err_rpc_mag, '.r', 'markersize', 20);

% hold off




















