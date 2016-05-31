% File directory
data_repo = '~/Desktop/spectral-phase-correlation/analysis/data/synthetic/mc';

% Font size
fSize = 18;

% Flow rate
flow_rate = 10.0;

% Case names
case_name = sprintf('piv_test_running_ensemble_15_ppf_q_%0.1f_ul_min', flow_rate);

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

% Allocate arrays for APC errors
err_mag_apc         = zeros(num_points, 1);

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
        data_path = fullfile(data_dir, data_name);
    
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

        % Calculate the error magnitudes for SCC
        err_mag_scc_complex = err_mag_scc_complex + sqrt(err_tx_scc_complex.^2 + err_ty_scc_complex.^2);
        err_mag_scc_abs  = err_mag_scc_abs + sqrt(err_tx_scc_abs.^2 + err_ty_scc_abs.^2);
        err_mag_scc_signed  = err_mag_scc_signed + sqrt(err_tx_scc_signed.^2 + err_ty_scc_signed.^2);

        % Calculate the error magnitudes for RPC
        err_mag_rpc_complex = err_mag_rpc_complex + sqrt(err_tx_rpc_complex.^2 + err_ty_rpc_complex.^2);
        err_mag_rpc_abs  = err_mag_rpc_abs + sqrt(err_tx_rpc_abs.^2 + err_ty_rpc_abs.^2);
        err_mag_rpc_signed  = err_mag_rpc_signed + sqrt(err_tx_rpc_signed.^2 + err_ty_rpc_signed.^2);

        % Calculate the error magnitudes for APC
        err_mag_apc         = err_mag_apc + sqrt(err_tx_apc.^2 + err_ty_apc.^2);
    end
    
end

% Print the number loaded
fprintf('%d files loaded.\n', num_loaded);

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

figure(1);

% Plot the results
%
% Plot APC errors
plot(err_mean_apc, '-b', 'linewidth', 2);
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
ylim([0, 10]);
set(gca, 'fontsize', fSize);
title('Mean errors', 'FontSize', fSize);






