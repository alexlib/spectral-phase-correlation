% File directory
data_repo = '~/Desktop/spectral-phase-correlation/analysis/data/synthetic/mc';

% Font size
fSize = 18;

% Flow rate
flow_rate = 50;

% Case names
case_name = sprintf('piv_test_running_ensemble_15_ppf_no_diffusion_q_%0.1f_ul_min', flow_rate);

% Data directory
data_dir = fullfile(data_repo, case_name, '128x128', 'apc');

% Get dir info
dir_data = dir(data_dir);

% Data base name
data_file_base_name = case_name;

% Number of files to plot (user specified)
num_files = length(dir_data);

% If the code below is reached, then
% at least one matching file was found.

% Read the first file to get the number
% of data points it contains.
% Data path
k = 1;

% Define found flag
file_found = 0;

while (file_found == 0) && k < num_files
    % Data name
    data_name = sprintf('%s_%05d.mat', case_name, k);
    
    % Data path
    data_path = fullfile(data_dir, data_name);
    
    % Load the file if it exists
    if(exist(data_path, 'file'))
       
        % Load the data
        load(data_path);
        
        % set flag to found
        file_found = 1;
    end
    
    % Increment counter
    k = k + 1;
    
end


% Measure the length of the data
num_points = length(TX_TRUE);

% Allocate arrays for SCC errors
err_mag_scc_complex = zeros(num_points, 1);
err_mag_scc_signed  = zeros(num_points, 1);
err_mag_scc_abs     = zeros(num_points, 1);

% Allocate arrays for RPC errors
err_mag_rpc_complex = zeros(num_points, 1);
err_mag_rpc_abs     = zeros(num_points, 1);
err_mag_rpc_signed  = zeros(num_points, 1);

% Allocate array for APC errors
err_mag_apc         = zeros(num_points, 1);

% Allocate arrays for SCC squared errors
err_mag_scc_complex_sqr = zeros(num_points, 1);
err_mag_scc_signed_sqr  = zeros(num_points, 1);
err_mag_scc_abs_sqr     = zeros(num_points, 1);

% Allocate arrays for RPC errors
err_mag_rpc_complex_sqr = zeros(num_points, 1);
err_mag_rpc_abs_sqr     = zeros(num_points, 1);
err_mag_rpc_signed_sqr  = zeros(num_points, 1);

% Allocate array for APC errors
err_mag_apc_sqr         = zeros(num_points, 1);


% Number of valid files
num_valid = 0;

for k = 1 : num_files
     % Data name
    file_name = dir_data(k).name;
    
    % Valid file?
    valid_file = ~isempty(regexpi(file_name, '.mat'));
    
    if valid_file
        num_valid = num_valid + 1;
    end
end

% Initialize number loaded
num_loaded = 0;

% Sum vector
% Loop over all the files
for k = 1 : num_files

    % Data name
    file_name = dir_data(k).name;
    
    % Valid file?
    valid_file = ~isempty(regexpi(file_name, '.mat'));
    
    % Proceed if file exists.
    if valid_file;
    
        % Data path
        data_path = fullfile(data_dir, file_name);
    
        % Load the data
        load(data_path);
        
        % Increment the number of loaded files
        num_loaded = num_loaded + 1;
        
         % Inform the user
        fprintf(1, 'Loading file %d of %d...\n', num_loaded, num_valid);

        % Calculate the signed displacement errors for SCC
        err_tx_scc_complex = TX_TRUE - tx_scc_complex;
        err_ty_scc_complex = TY_TRUE - ty_scc_complex;
        err_tx_scc_abs     = TX_TRUE - tx_scc_abs;
        err_ty_scc_abs     = TY_TRUE - ty_scc_abs;
        err_tx_scc_signed  = TX_TRUE - tx_scc_signed;
        err_ty_scc_signed  = TY_TRUE - ty_scc_signed;

        % Calculate the signed displacement errors for RPC
        err_tx_rpc_complex = TX_TRUE - tx_rpc_complex;
        err_ty_rpc_complex = TY_TRUE - ty_rpc_complex;
        err_tx_rpc_abs     = TX_TRUE - tx_rpc_abs;
        err_ty_rpc_abs     = TY_TRUE - ty_rpc_abs;
        err_tx_rpc_signed  = TX_TRUE - tx_rpc_signed;
        err_ty_rpc_signed  = TY_TRUE - ty_rpc_signed;

        % Calculate the signed displacement errors for APC
        err_tx_apc         = TX_TRUE - tx_apc;
        err_ty_apc         = TY_TRUE - ty_apc;
        
        % Error magnitudes of the current trial (SCC)
        err_mag_scc_complex_current = sqrt(err_tx_scc_complex.^2 + err_ty_scc_complex.^2);
        err_mag_scc_abs_current     = sqrt(err_tx_scc_abs.^2     + err_ty_scc_abs.^2);
        err_mag_scc_signed_current  = sqrt(err_tx_scc_signed.^2  + err_ty_scc_signed.^2);
        
        % Error magnitudes of the current trial (RPC)
        err_mag_rpc_complex_current = sqrt(err_tx_rpc_complex.^2 + err_ty_rpc_complex.^2);
        err_mag_rpc_abs_current     = sqrt(err_tx_rpc_abs.^2     + err_ty_rpc_abs.^2);
        err_mag_rpc_signed_current  = sqrt(err_tx_rpc_signed.^2  + err_ty_rpc_signed.^2);
        
        % Error magnitude of the current trial (APC)
        err_mag_apc_current = sqrt(err_tx_apc.^2 + err_ty_apc.^2);
        

        % Calculate the error magnitudes for SCC
        err_mag_scc_complex = err_mag_scc_complex + err_mag_scc_complex_current;
        err_mag_scc_abs     = err_mag_scc_abs     + err_mag_scc_abs_current;
        err_mag_scc_signed  = err_mag_scc_signed  + err_mag_scc_signed_current;

        % Calculate the error magnitudes for RPC
        err_mag_rpc_complex = err_mag_rpc_complex + err_mag_rpc_complex_current;
        err_mag_rpc_abs     = err_mag_rpc_abs     + err_mag_rpc_abs_current;
        err_mag_rpc_signed  = err_mag_rpc_signed  + err_mag_rpc_signed_current;
        
        % Calculate the error magnitudes for APC
        err_mag_apc         = err_mag_apc         + err_mag_apc_current;
        
       
        % Squared errors for the standard deviation calculation (SCC)
        err_mag_scc_complex_sqr = err_mag_scc_complex_sqr + err_mag_scc_complex_current.^2;
        err_mag_scc_abs_sqr     = err_mag_scc_abs_sqr     + err_mag_scc_abs_current.^2;
        err_mag_scc_signed_sqr  = err_mag_scc_signed_sqr  + err_mag_scc_signed_current.^2;
        
        % Squared errors for the standard deviation calculation (RPC)
        err_mag_rpc_complex_sqr = err_mag_rpc_complex_sqr + err_mag_rpc_complex_current.^2;
        err_mag_rpc_abs_sqr     = err_mag_rpc_abs_sqr     + err_mag_rpc_abs_current.^2;
        err_mag_rpc_signed_sqr  = err_mag_rpc_signed_sqr  + err_mag_rpc_signed_current.^2;
        
        % Squared errors for the standard deviation calculation (APC)
        err_mag_apc_sqr         = err_mag_apc_sqr         + err_mag_apc_current.^2;
        
    end
    
end

% Print the number loaded
fprintf('%d files loaded.\n', num_loaded);

% Read the diffusion std dev
diffusion_std_dev = JobFile.OtherInfo.DiffusionStdDev;

% Divide each SCC error by the number of files to get the mean errors
err_mean_scc_complex = err_mag_scc_complex / num_loaded;
err_mean_scc_abs     = err_mag_scc_abs / num_loaded;
err_mean_scc_signed  = err_mag_scc_signed  / num_loaded;

% Divide each RPC error by the number of files to get the mean errors
err_mean_rpc_complex = err_mag_rpc_complex / num_loaded;
err_mean_rpc_abs     = err_mag_rpc_abs / num_loaded;
err_mean_rpc_signed  = err_mag_rpc_signed  / num_loaded;

% Divide the APC error by the number of files to get the mean errors
err_mean_apc         = err_mag_apc / num_loaded;


% Calculate the standard deviations of error (SCC)
err_std_scc_complex = sqrt(1 / (num_loaded - 1) * (err_mag_scc_complex_sqr - err_mag_scc_complex.^2 / num_loaded));
err_std_scc_signed  = sqrt(1 / (num_loaded - 1) * (err_mag_scc_signed_sqr  - err_mag_scc_signed .^2 / num_loaded));
err_std_scc_abs     = sqrt(1 / (num_loaded - 1) * (err_mag_scc_abs_sqr     - err_mag_scc_abs .^2    / num_loaded));


% Calculate the standard deviations of error (RPC)
err_std_rpc_complex = sqrt(1 / (num_loaded - 1) * (err_mag_rpc_complex_sqr - err_mag_rpc_complex.^2 / num_loaded));
err_std_rpc_signed  = sqrt(1 / (num_loaded - 1) * (err_mag_rpc_signed_sqr  - err_mag_rpc_signed .^2 / num_loaded));
err_std_rpc_abs     = sqrt(1 / (num_loaded - 1) * (err_mag_rpc_abs_sqr     - err_mag_rpc_abs .^2    / num_loaded));

% Calculate the standard deviations of error (SCC)
err_std_apc         =  sqrt(1 / (num_loaded - 1) * (err_mag_apc_sqr        - err_mag_apc .^2        / num_loaded));


% Mean Errors
figure(1);
% Plot the results
%
% Plot APC errors
plot(err_mean_apc, '-b', 'linewidth', 4);
hold on

% Plot SCC errors
plot(err_mean_scc_complex, '-k', 'linewidth',  2)
plot(err_mean_scc_abs, '--k', 'linewidth',  2)
plot(err_mean_scc_signed, ':k', 'linewidth',  2)

plot(err_mean_rpc_complex, '-r', 'linewidth',  2)
plot(err_mean_rpc_abs, '--r', 'linewidth',  2)
plot(err_mean_rpc_signed, ':r', 'linewidth',  2)

hold off
axis square
grid on
box on

ylabel('Displacement error (pixels)', 'FontSize', fSize);
xlabel('Number of ensemble pairs', 'FontSize', fSize);
title({'Mean displacement errors', ...
    sprintf('Flow rate $%0.1f \\, \\mu L / \\textrm{min}$', flow_rate), ...
    sprintf('Diffusion std dev %0.2f pix / frame', diffusion_std_dev)}, ...
    'interpreter', 'latex', 'FontSize', fSize);

h = legend('APC',...
    'SCC (complex)', 'SCC (absolute)', 'SCC (signed)', ...
    'RPC (complex)', 'RPC (absolute)', 'RPC (signed)');
set(h, 'FontSize', 12);
% set(h, 'location', 'southeast');
set(h, 'location', 'northeast');
set(gca, 'fontsize', fSize);
ylim([0, 5]);

% % % Std Dev Error
figure(2);

% Plot the results
%
% Plot APC errors
plot(err_std_apc, '-b', 'linewidth', 4);
hold on

% Plot SCC errors
plot(err_std_scc_complex, '-k', 'linewidth',  2)
plot(err_std_scc_abs, '--k', 'linewidth',  2)
plot(err_std_scc_signed, ':k', 'linewidth',  2)

plot(err_std_rpc_complex, '-r', 'linewidth',  2)
plot(err_std_rpc_abs, '--r', 'linewidth',  2)
plot(err_std_rpc_signed, ':r', 'linewidth',  2)

hold off
axis square
grid on
box on

ylabel('Std dev of error (pixels)', 'FontSize', fSize);
xlabel('Number of ensemble pairs', 'FontSize', fSize);
title({'Std deviation of displacement errors', ...
    sprintf('Flow rate $%0.1f \\, \\mu L / \\textrm{min}$', flow_rate), ...
    sprintf('Diffusion std dev %0.2f pix / frame', diffusion_std_dev)}, ...
    'interpreter', 'latex', 'FontSize', fSize);

h = legend('APC',...
    'SCC (complex)', 'SCC (absolute)', 'SCC (signed)', ...
    'RPC (complex)', 'RPC (absolute)', 'RPC (signed)');
set(h, 'FontSize', 12);
% set(h, 'location', 'southeast');
set(h, 'location', 'northeast');
set(gca, 'fontsize', fSize);
ylim([0, 10]);

plot_dir_mean = '~/Desktop/mc_plots/mean';
plot_dir_std = '~/Desktop/mc_plots/std';
plot_name_mean = sprintf('mean_error_q_%0.1f.png', flow_rate);
plot_name_std = sprintf('std_error_q_%0.1f.png', flow_rate);
plot_path_mean = fullfile(plot_dir_mean, plot_name_mean);
plot_path_std = fullfile(plot_dir_std, plot_name_std);
% print(1, '-dpng', '-r300', plot_path_mean);
% print(2, '-dpng', '-r300', plot_path_std);




