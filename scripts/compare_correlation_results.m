
% Font size of plots
fSize = 16;

% Case name
case_name = '2015-03-20_spc_test_subpixel';

% Parent directory containing all the error analyses
parent_dir = fullfile('~/Desktop/spc_test/analysis/data/synthetic/mc', case_name, '64x64');

% RPC file path
rpc_file_path = fullfile(parent_dir, 'rpc', 'errorAnalysis_mc_rpc_h64_w64_00001.mat');

% SCC file path
scc_file_path = fullfile(parent_dir, 'scc', 'errorAnalysis_mc_scc_h64_w64_00001.mat');

% SPC Goldstein SVD file path
spc_gold_svd_file_path = fullfile(parent_dir, ...
'spc', 'errorAnalysis_mc_spc_h64_w64_unwrap_goldstein_filt_svd_00001.mat');

% SPC SVD file path
spc_gold_mean_file_path = fullfile(parent_dir,...
    'spc', 'errorAnalysis_mc_spc_h64_w64_unwrap_goldstein_filt_mean_00001.mat');

% SPC unfiltered file path
spc_gold_none_file_path = fullfile(parent_dir,...
    'spc', 'errorAnalysis_mc_spc_h64_w64_unwrap_goldstein_filt_none_00001.mat');

% Load the RPC file and calculate the RPC errors
load(rpc_file_path);
ty_err_rpc = TY_EST - TY_TRUE;
tx_err_rpc = TX_EST - TX_TRUE;
err_mag_rpc = sqrt(ty_err_rpc .^ 2 + tx_err_rpc .^ 2);

% Calculate the SCC errors
load(scc_file_path);
ty_err_scc = TY_EST - TY_TRUE;
tx_err_scc = TX_EST - TX_TRUE;
err_mag_scc = sqrt(ty_err_scc .^ 2 + tx_err_scc .^ 2);

% Calculate the SPC-SVD Goldstein errors
load(spc_gold_svd_file_path);
ty_err_gold = TY_EST - TY_TRUE;
tx_err_gold = TX_EST - TX_TRUE;
err_mag_gold_svd = sqrt(ty_err_gold .^ 2 + tx_err_gold .^ 2);

% Calculate the SPC-MeanFilt errors.
load(spc_gold_mean_file_path);
ty_err_mean_filt = TY_EST - TY_TRUE;
tx_err_mean_filt = TX_EST - TX_TRUE;
err_mag_mean_filt= sqrt(ty_err_mean_filt .^ 2 + tx_err_mean_filt .^ 2);

% Calculate the SPC-NoFilt errors.
load(spc_gold_none_file_path);
ty_err_no_filt = TY_EST - TY_TRUE;
tx_err_no_filt = TX_EST - TX_TRUE;
err_mag_no_filt= sqrt(ty_err_no_filt .^ 2 + tx_err_no_filt .^ 2);


% % Make CDF plots.
f1 = cdfplot(err_mag_rpc);
set(f1, 'linewidth', 2);
set(f1, 'color', 'red')

hold on

f2 = cdfplot(err_mag_scc);
set(f2, 'linewidth', 2);
set(f2, 'color', 'blue');

f3 = cdfplot(err_mag_no_filt);
set(f3, 'linewidth', 2);
set(f3, 'color', 0.5 * [1, 1, 1]);

f4 = cdfplot(err_mag_gold_svd);
set(f4, 'linewidth', 2);
set(f4, 'color', 'black')

f5 = cdfplot(err_mag_mean_filt);
set(f5, 'linewidth', 2);
set(f5, 'color', 'black')
set(f5, 'linestyle', '--'); 

hold off

axis square
xlim([0 0.1]);
set(gca, 'fontsize', fSize);

set(gcf, 'color', 'white');

ylabel('Cumulative probability', 'FontSize', fSize);
xlabel('Translation error magnitude (pixels)', 'FontSize', fSize);

title({'CDFs of translation error from Monte Carlo', 'analysis of SCC, RPC, and SPC (10^4 pairs)', ...
    ['|T_X| < ' num2str(max(TX_TRUE), '%0.2f') ', |T_Y| < ' num2str(max(TX_TRUE), '%0.2f')]},...
    'FontSize', fSize, 'interpreter', 'Tex');

% Make a legend
% L = legend('RPC', 'SCC', 'SPC (no unwrap, no filt)', 'SPC (no unwrap, SVD filt)', 'SPC (no unwrap, mean filt)');
L = legend('RPC', 'SCC', 'SPC (Goldstein unwrap, no filt)', 'SPC (Goldstein unwrap, SVD filt)', 'SPC (Goldstein unwrap, mean filt)');
% L = legend('RPC', 'SPC (2-D Goldstein w/SVD filt)');
set(L, 'FontSize', fSize);
set(L, 'location', 'southeast');




