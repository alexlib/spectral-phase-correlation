



fSize = 12;

q = 50;
file_path = sprintf('~/Desktop/piv_test_images/analysis/data/synthetic/mc/piv_test_running_ensmeble_q_%0.1f_ul_min/128x128/apc/errorAnalysis_mc_apc_h128_w128_00001.mat', q);

% Load the file
load(file_path);

% Diffusion STD
d_std_pix = JobFile.OtherInfo.DiffusionStdDev;

% Calculate the error
tx_err_scc = (TX_TRUE - tx_scc);
ty_err_scc = (TY_TRUE - ty_scc);
err_mag_scc = sqrt(ty_err_scc.^2 + tx_err_scc.^2);

tx_err_rpc = (TX_TRUE - tx_rpc);
ty_err_rpc = (TY_TRUE - ty_rpc);
err_mag_rpc = sqrt(ty_err_rpc.^2 + tx_err_rpc.^2);

tx_err_apc = (TX_TRUE - tx_apc);
ty_err_apc = (TY_TRUE - ty_apc);
err_mag_apc = sqrt(ty_err_apc.^2 + tx_err_apc.^2);

figure;
plot(err_mag_scc, '-k', 'linewidth', 2);
hold on
plot(err_mag_rpc, '-r', 'linewidth', 2);
plot(err_mag_apc, '-b', 'linewidth', 2);
hold off
axis square
grid on
ylim([0, 0.1]);
title({sprintf('$q = %0.1f \\, \\mu L / \\textrm{min}$', q), ...
    sprintf(...
    '$\\sigma_D = %0.2f \\, \\textrm{pix} / \\textrm{frame}$', ...
    d_std_pix)}, 'interpreter', 'latex', ...
    'FontSize', fSize);
h = legend('SCC', sprintf('$RPC \\left( d = \\sqrt{8} \\right)$'), 'APC');
set(h, 'interpreter', 'latex');
set(h, 'FontSize', fSize);
set(gca, 'FontSize', fSize);
xlabel('Ensemble length (pairs)', 'FontSize', fSize);
ylabel('Error magnitude (pixels)', 'FontSIze', fSize);


% figure(2);
% p = cdfplot(err_mag_scc);
% set(p, 'linewidth', 2);
% set(p, 'color', 'k');
% 
% hold on
% 
% p = cdfplot(err_mag_rpc);
% set(p, 'linewidth', 2);
% set(p, 'color', 'r');
% 
% p = cdfplot(err_mag_apc);
% set(p, 'linewidth', 2);
% set(p, 'color', 'b');
% 
% hold off
