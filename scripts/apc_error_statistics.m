

fSize = 14;


q = 0.5;

switch q
    case 0.5
        ylim_mean = [0, 5];
        ylim_std = [0, 2];
    case 5.0
        ylim_mean = [0, 0.2];
        ylim_std = [0, 0.1];
        
    case 50
      ylim_mean = [0, 0.1];
      ylim_std = [0, 0.1];
    
end


file_base_name = 'errorAnalysis_mc_apc_h128_w128_';

% repo_dir = '~/Documents/School/VT/Research/Aether/apc/apc_mc_translation_errors';
repo_dir = '~/Desktop/mc/complex_ensemble';

is_signed_ensemble = ~isempty(regexpi(repo_dir, 'sig'));
is_complex_ensemble = ~isempty(regexpi(repo_dir, 'complex'));
is_abs_ensemble = ~isempty(regexpi(repo_dir, 'abs'));

if is_signed_ensemble
    title_str = { sprintf('$\\textrm{Signed spatial ensemble} $'), ...
        sprintf('$\\textrm{Abs}\\left( \\sum \\limits_{n} \\mathcal{F}^{-1}\\left( F_1 F_2 \\right)_n \\right)$')};
    plot_dir = '~/Desktop/apc_plots/spatial_signed_ensemble';
elseif is_abs_ensemble
    title_str = { sprintf('$\\textrm{Absolute spatial ensemble}$'), ...
        sprintf('$\\sum \\limits_{n} \\mathrm{Abs} \\left( \\mathcal{F}^{-1}\\left( F_1 F_2 \\right)_n \\right)$')};
    plot_dir = '~/Desktop/apc_plots/spatial_abs_ensemble';
elseif is_complex_ensemble
    title_str = {sprintf('$\\textrm{Complex ensemble}$'), ...
        sprintf('$\\textrm{Abs} \\left( \\mathcal{F}^{-1} \\left( \\sum \\limits_{n} \\left(F_1 F_2 \\right)_n \\right) \\right) $')};
    plot_dir = '~/Desktop/apc_plots/complex_ensemble';
end


data_dir = fullfile(repo_dir, sprintf('q_%0.1f', q));



start_file = 1;
end_file = 99;
skip_file = 1;

pairs_per_set = 1E4;

file_nums = start_file : skip_file : end_file;

num_files = length(file_nums);

% Allocate the error vectors
err_mag_scc = zeros(pairs_per_set, num_files);
err_mag_rpc = zeros(pairs_per_set, num_files);
err_mag_apc = zeros(pairs_per_set, num_files);


for k = 1 : num_files
   
    fprintf(1, 'On %d of %d\n', k, num_files);
    
    % construct the file path
    file_name = sprintf('%s%05d.mat', file_base_name, file_nums(k));
    file_path = fullfile(data_dir, file_name);
    
    % Load the file
    load(file_path);
    
    % Calculate the error
    tx_err_scc = (TX_TRUE - tx_scc);
    ty_err_scc = (TY_TRUE - ty_scc);
    err_mag_scc(:, k) = sqrt(ty_err_scc.^2 + tx_err_scc.^2);

    tx_err_rpc = (TX_TRUE - tx_rpc);
    ty_err_rpc = (TY_TRUE - ty_rpc);
    err_mag_rpc(:, k) = sqrt(ty_err_rpc.^2 + tx_err_rpc.^2);

    tx_err_apc = (TX_TRUE - tx_apc);
    ty_err_apc = (TY_TRUE - ty_apc);
    err_mag_apc(:, k) = sqrt(ty_err_apc.^2 + tx_err_apc.^2);

    
  
end

pair_vect = 1 : length(err_mag_scc);
pair_vect_tick = pair_vect / 10^3;


err_mag_scc_mean = mean(err_mag_scc, 2);
err_mag_rpc_mean = mean(err_mag_rpc,2);
err_mag_apc_mean = mean(err_mag_apc, 2);

err_mag_scc_std = std(err_mag_scc, [], 2);
err_mag_rpc_std = std(err_mag_rpc, [], 2);
err_mag_apc_std = std(err_mag_apc,[], 2);

figure(1);
plot(pair_vect_tick, err_mag_scc_mean, '-k', 'linewidth', 2);
hold on
plot(pair_vect_tick, err_mag_rpc_mean, '-r', 'linewidth', 2);
plot(pair_vect_tick, err_mag_apc_mean, '-b', 'linewidth', 2);
hold off
axis square
title({sprintf('$ \\textrm{Mean error,} \\, q = %0.2f \\, \\mu \\textrm{L} / \\textrm{min}$', q), ...
    title_str{1}, title_str{2}}, ...
    'FontSize', fSize, 'interpreter', 'latex');
h = legend('SCC', sprintf('RPC$\\left( d= \\sqrt{8} \\right)$'), 'APC');
set(h, 'interpreter', 'latex')
set(h, 'fontsize', fSize);
xlabel('Ensemble length (thousands of pairs)', 'FontSize', fSize);
ylabel('Error magnitude (pixels)', 'FontSize', fSize);
set(gca, 'FontSize', fSize);
grid on
ylim(ylim_mean);
% set(gca, 'ytick', 1 * [0 : 5])


figure(2); 
plot(pair_vect_tick, err_mag_scc_std, '-k', 'linewidth', 2);
hold on
plot(pair_vect_tick, err_mag_rpc_std, '-r', 'linewidth', 2);
plot(pair_vect_tick, err_mag_apc_std, '-b', 'linewidth', 2);
hold off
axis square
title({sprintf('$ \\textrm{Std dev error,} \\, q = %0.2f \\, \\mu \\textrm{L} / \\textrm{min}$', q), ...
    title_str{1}, title_str{2}}, ...
    'FontSize', fSize, 'interpreter', 'latex');
h = legend('SCC', sprintf('RPC$\\left( d= \\sqrt{8} \\right)$'), 'APC');
set(h, 'interpreter', 'latex')
set(h, 'fontsize', fSize);
ylim(ylim_std);
% set(gca, 'ytick', 0.1 * [0 : 5])

set(h, 'fontsize', fSize);
xlabel('Ensemble length (thousands of pairs)', 'FontSize', fSize);
ylabel('Error Std Dev (pixels)', 'FontSize', fSize);
set(gca, 'FontSize', fSize);
grid on

std_dev_plot_name = sprintf('apc_std_dev_err_q_%0.1f.png', q);
mean_plot_name = sprintf('apc_mean_err_q_%0.1f.png', q);

std_dev_plot_path = fullfile(plot_dir, std_dev_plot_name);
mean_plot_path = fullfile(plot_dir, mean_plot_name);

print(1, '-dpng', '-r300', mean_plot_path);
print(2, '-dpng', '-r300', std_dev_plot_path);

% 
% 











