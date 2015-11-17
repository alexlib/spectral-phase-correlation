function test_snr(phase_angle_plane);
    
    [region_height, region_width] = size(phase_angle_plane);

    xv = 1 : region_width;
    yv = 1 : region_height;

    [x, y] = meshgrid(xv, yv);

    xc = region_width  / 2 + 1;
    yc = region_height / 2 + 1;
    

    
    [~, r] = cart2pol(x - xc, y - yc);

    n_steps = 100;
    r_min = 5;
    r_max = min([region_height, region_width]) / 2;
    
    r_vect = linspace(1, 100, n_steps) / 100;
    n_steps = length(r_vect);
    
    weighted_diff = zeros(n_steps, 1);
    
    
    for k = 1 : n_steps

        rk = r_vect(k);

%        mask(r < rk) = 1;
%        mask(r > rk) = 0;

        mask = gaussianWindowFilter([region_height, region_width], ...
        [rk, rk], 'fraction');

        c = polyfitweighted2(xv, yv, phase_angle_plane, 1, mask);

        z = c(2) * x + c(3) * y + c(1);
        
        weighted_diff(k) = sqrt(sum((mask(:).^2) .* (z(:) - phase_angle_plane(:)).^2));
        
        mesh(phase_angle_plane, 'edgecolor', 'black', 'facealpha', 0.3);
        hold on;
        mesh(z, 'edgecolor', 'green', 'facealpha', 0.3);
        hold off;
        zlim([-pi, pi]);
        xlim([1 region_width]);
        ylim([1, region_height]);
        set(gca, 'view', [-90, 0]);
        pause(0.1);

    end

    plot(r_vect, weighted_diff, 'ok', 'markerfacecolor', 'red'); axis square;
% ind = find(meandiff_gaussian == min(meandiff_gaussian));
% d_filt = r_vect(ind);
% g = gaussianWindowFilter([region_height, region_width], d_filt * [1, 1], 'fraction');


    


end


