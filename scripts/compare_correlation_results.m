
% Font size of plots
fSize = 16;

% Parent directory containing all the error analyses
parent_dir = '/Users/matthewgiarra/Desktop/spc_test/analysis/data/synthetic/mc/2015-03-13_spc_test/64x64';

% RPC file path
rpc_file_path = fullfile(parent_dir, 'rpc', 'errorAnalysis_mc_rpc_h64_w64_00001.mat');

% SCC file path
scc_file_path = fullfile(parent_dir, 'scc', 'errorAnalysis_mc_scc_h64_w64_00001.mat');

% SPC Goldstein file path
spc_gold_file_path = fullfile(parent_dir, 'spc', 'errorAnalysis_mc_spc_h64_w64_goldstein_00001.mat');

% SPC SVD file path
spc_svd_file_path = fullfile(parent_dir, 'spc', 'errorAnalysis_mc_spc_h64_w64_svd_00001.mat');


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

% Calculate the SPC Goldstein errors
load(spc_gold_file_path);
ty_err_gold = TY_EST - TY_TRUE;
tx_err_gold = TX_EST - TX_TRUE;
err_mag_gold = sqrt(ty_err_gold .^ 2 + tx_err_gold .^ 2);

% Calculate the SPC SVD errors.
load(spc_svd_file_path);
ty_err_svd = TY_EST - TY_TRUE;
tx_err_svd = TX_EST - TX_TRUE;
err_mag_svd= sqrt(ty_err_svd .^ 2 + tx_err_svd .^ 2);


% Make CDF plots.
f1 = cdfplot(err_mag_scc);
set(f1, 'linewidth', 2);
set(f1, 'color', 'blue')

hold on

f2 = cdfplot(err_mag_rpc);
set(f2, 'linewidth', 2);
set(f2, 'color', 'red')

f3 = cdfplot(err_mag_gold);
set(f3, 'linewidth', 2);
set(f3, 'color', 'black')

f4 = cdfplot(err_mag_svd);
set(f4, 'linewidth', 2);
set(f4, 'color', 'black')
set(f4, 'linestyle', '--'); 

hold off

axis square
xlim([0 0.12]);
set(gca, 'fontsize', fSize);

set(gcf, 'color', 'white');

ylabel('Cumulative probability', 'FontSize', fSize);
xlabel('Translation error magnitude (pixels)', 'FontSize', fSize);

title({'CDFs of translation error from Monte Carlo', 'analysis of SCC, RPC, and SPC (10^4 pairs)'},...
    'FontSize', fSize);

% Make a legend
L = legend('SCC', 'RPC', 'SPC (2-D Goldstein)', 'SPC (1-D SVD)');
set(L, 'FontSize', fSize);
set(L, 'location', 'southeast');




