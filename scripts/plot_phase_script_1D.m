addpath(fullfile('..', 'correlation_algorithms'));
addpath(fullfile('..', 'filtering'));

u = 1:64;
L = length(u);

for sx = 0 : 0.01 : 5.0; 
    y = angle(exp(2 * pi * 1i * sx/L * (u))); 
    n = floor(sx);
    
    ud = L * (2 * (0:n) + 1) / (2 * sx);
    yd = angle(exp(2 * pi * 1i * sx/L * (ud))); 
    
    % Phase jumps occur at intervals of (2n + 1) * pi, with n=0, 1, .. floor(sx)
    % so 2 * pi * u * Sx / L = (2 * n + 1) * pi;
    
    
    
    figure(1); 
    plot(u, y, '-k', 'LineWidth', 2);
    
    hold on
    plot(ud(ud <= L), yd(ud <= L), 'ok', 'MarkerSize', 10, 'markerfacecolor', 'red');
    hold off
    ylim(1.1 * [-pi pi]); 
    xlim([1 64]); 
    axis square; pause(0.001);


end;