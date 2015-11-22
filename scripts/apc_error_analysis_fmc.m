vect_dir = '/Users/matthewgiarra/Desktop/fullfield/vect';
vect_name_rpc = 'image_rpc_grid128x128_region128x128_001_002.mat';
vect_name_scc = 'image_scc_grid128x128_region128x128_001_002.mat';

set_type = 'lin';
region_height = 4096;
region_width  = 4096;
heightstr = num2str(region_height);
widthstr = num2str(region_width);

region_str = [heightstr 'x' widthstr];

% image_path = ['~/Desktop/piv_test_images/analysis/' ...
%     'data/synthetic/' set_type '/piv_test_micro/' region_str ...
%     '/raw/' set_type '_h' heightstr '_w' widthstr '_00001/raw/' ...
%     'raw_image_matrix_' set_type '_h' heightstr '_w' widthstr ...
%     '_seg_000001_001000.mat'];

% parameters_path = ['~/Desktop/piv_test_images/analysis/' ...
%     'data/synthetic/' set_type '/piv_test_micro/' region_str ...
%     '/raw/' set_type '_h' heightstr '_w' widthstr '_00001/parameters/' ...
%     'imageParameters_' set_type '_h' heightstr '_w' widthstr ...
%     '_seg_000001_001000.mat'];


parameters_path = ['~/Desktop/piv_test_images/analysis/' ...
    'data/synthetic/' set_type '/piv_test_micro/' region_str ...
    '/raw/' set_type '_h' heightstr '_w' widthstr '_00001/parameters/' ...
    'imageParameters_' set_type '_h' heightstr '_w' widthstr ...
    '_seg_000001_000001.mat'];

% Load parameters;
load(parameters_path);

diffusion_std = mean(Parameters.Diffusion);

% Measure true translations
tx_true = Parameters.Translation.X;
ty_true = Parameters.Translation.Y;

% Load the RPC file
load(fullfile('/Users/matthewgiarra/Desktop/fullfield/vect/rpc/128x128/cstep_01', vect_name_rpc));

TY_RPC = V{1}(:);
TX_RPC = U{1}(:);

% Load the SCC file
load(fullfile('/Users/matthewgiarra/Desktop/fullfield/vect/scc/128x128/cstep_01', vect_name_scc));

TY_SCC = V{1}(:);
TX_SCC = U{1}(:);

% True translation magnitude
t_mag_true = sqrt(tx_true .^2 + ty_true .^2);

% Measure errors
err_rpc_x = TX_RPC - tx_true;
err_rpc_y = TY_RPC - ty_true;
err_rpc_mag = sqrt(err_rpc_x.^2 + err_rpc_y.^2);

err_scc_x = TX_SCC - tx_true;
err_scc_y = TY_SCC - ty_true;
err_scc_mag = sqrt(err_scc_x.^2 + err_scc_y.^2);

% Non outlier indices
valid_ind_rpc = find(err_rpc_mag < (mean(err_rpc_mag) + 2 * std(err_rpc_mag)));
valid_ind_scc = find(err_scc_mag < (mean(err_scc_mag) + 2 * std(err_scc_mag)));

fSize = 16;
figure(1);
% Make a cdf plot
h = cdfplot(err_scc_mag(valid_ind_scc));
set(h, 'LineWidth', 2);
hold on;
h = cdfplot(err_rpc_mag(valid_ind_rpc));
set(h, 'LineWidth', 2);
set(h, 'Color', 'black');
hold off
L = legend('SCC', 'RPC');
set(L, 'FontSize', 16, 'location', 'southeast');
set(gca, 'FontSize', fSize);
axis square
ylim([0 1]);
xlim([0 1]);
grid on;
title({'CDF of error magnitudes (Prana)', ...
    [ ...
    'Synthetic micro-PIV images'], ...
    ['128x128 regions, 50% Gaussian window']...
    ['Diffusion Std dev: ' num2str(diffusion_std, '%0.2f') ' pix/frame']}, ...
    'FontSize', 12);

xlabel('Error magnitude (pixels)', 'FontSIze', fSize);
ylabel('Cumulative probability', 'FontSize', fSize);
set(gcf, 'color', 'white');

fprintf('Mean errors:\nSCC\tRPC\n%0.3f\t%0.3f\n\n', ...
    mean(err_scc_mag(valid_ind_scc)), ...
    mean(err_rpc_mag(valid_ind_rpc)));

fprintf('Std Dev errors:\nSCC\tRPC\n%0.3f\t%0.3f\n\n', ...
    std(err_scc_mag(valid_ind_scc)), ...
    std(err_rpc_mag(valid_ind_rpc)));
% 
% plot_name = ['error_cdf_' region_str '_diffusion_'...
%     num2str(diffusion_std, '%0.2f') '.png'];
% 
% plot_dir = '~/Desktop/cdfplots';
% plot_path = fullfile(plot_dir, plot_name);
% 
% print(2, '-dpng', plot_path);
% 
% 














