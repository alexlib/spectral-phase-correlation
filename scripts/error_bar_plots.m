m1 = [0.10, 0.16, 0.09, 0.09];
s1 = [0.10, 0.15, 0.09, 0.09];

m2 = [0.29, 0.73, 0.26, 0.18];
s2 = [0.26, 0.81, 0.26, 0.18];

m3 = [0.72, 2.60, 0.56, 0.34];
s3 = [0.72, 7.46, 0.59, 0.33];

xtl = {'SCC', 'GCC', 'RPC', 'APC'};

xt = 1 : 4;
yt = 0 : 0.2 : 2;
yl = ([-0.2, 2]);
xl = ([0, 5]);

fSize = 12;

figure(1);
h = errorbar(m1, s1, 'ok',...
    'markerfacecolor', 'black', ...
    'markersize', 10);
axis square;
grid on;
set(h, 'linewidth', 1);
pbaspect([0.5, 1, 1]);
ylabel(...
    'Displacement error magnitude (pix)', 'FontSize', fSize);
set(gca, 'xtick', xt);
xlim(xl)
ylim(yl);
set(gca, 'xticklabel', xtl);
set(gca, 'ytick', yt);
set(gca, 'fontsize', fSize);
title('1% Noise', 'FontSize', 12);
 set(gca,'yaxislocation','right');

figure(2);
h = errorbar(m2, s2, 'ok',...
    'markerfacecolor', 'black', ...
    'markersize', 10);
axis square;
grid on;
set(h, 'linewidth', 1);
pbaspect([0.5, 1, 1]);
ylabel(...
    'Displacement error magnitude (pix)', 'FontSize', fSize);
set(gca, 'xtick', xt);
xlim(xl)
ylim(yl);
set(gca, 'xticklabel', xtl);
set(gca, 'ytick', yt);
set(gca, 'fontsize', fSize);
title('10% Noise', 'FontSize', 12);
 set(gca,'yaxislocation','right');


figure(3);
h = errorbar(m3, s3, 'ok',...
    'markerfacecolor', 'black', ...
    'markersize', 10);
axis square;
grid on;
set(h, 'linewidth', 1);
pbaspect([0.5, 1, 1]);
ylabel(...
    'Displacement error magnitude (pix)', 'FontSize', fSize);
set(gca, 'xtick', xt);
xlim(xl)
ylim(yl);
set(gca, 'xticklabel', xtl);
set(gca, 'ytick', yt);
set(gca, 'fontsize', fSize);
title('20% Noise', 'FontSize', 12);
 set(gca,'yaxislocation','right');











