load ~/Desktop/piv_test_images/analysis/data/synthetic/lin/piv_test_constant_diffusion_dry_run/128x128/apc/errorAnalysis_lin_apc_h128_w128_00006.mat;



tx_err_scc = (TX_TRUE - tx_scc);
ty_err_scc = (TY_TRUE - ty_scc);
err_mag_scc = sqrt(ty_err_scc.^2 + tx_err_scc.^2);

tx_err_rpc = (TX_TRUE - tx_rpc);
ty_err_rpc = (TY_TRUE - ty_rpc);
err_mag_rpc = sqrt(ty_err_rpc.^2 + tx_err_rpc.^2);

tx_err_apc = (TX_TRUE - tx_apc);
ty_err_apc = (TY_TRUE - ty_apc);
err_mag_apc = sqrt(ty_err_apc.^2 + tx_err_apc.^2);

plot(err_mag_scc, '-k', 'linewidth', 2);
hold on
plot(err_mag_rpc, '-r', 'linewidth', 2);
plot(err_mag_apc, '-b', 'linewidth', 2);
hold off
