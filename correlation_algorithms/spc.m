function spc(REGION1, REGION2, TY_EST, TX_EST, k)
% Variable k is a counter, used temporarily for debugging.

% Calculate region height and width
[regionHeight, regionWidth] = size(REGION1);

% Gaussian window filter
gaussianWindow = gaussianWindowFilter([regionHeight, regionWidth], [0.5 0.5], 'fraction');

% Windowed regions
image1 = double(REGION1);
image2 = double(REGION2);

% Zero frequency pixel coordinates
uc =  regionWidth/2 + 1 - 0.5 * mod(regionWidth, 2);
vc = regionHeight/2 + 1 - 0.5 * mod(regionHeight, 2);

% Wavenumber coordinates
[u, v] = meshgrid((1 : regionWidth) - uc, (1 : regionHeight) - vc);
u_1D = (u(1, :))';

% Phase correlation of windowed images
phaseCorr = angle(fftshift(phaseCorrelation(gaussianWindow .* image1, gaussianWindow .* image2)));

% Theoretical phase plane
phaseCorr_theory = angle(exp(-2 * pi * 1i * ...
    (TX_EST / regionWidth * u + TY_EST / regionHeight * v)));

% Plot the phase correlation
subplot(1, 2, 1);
imagesc(u(:), v(:), phaseCorr);
caxis(1.1 * [-pi pi]);
axis image;
colormap gray;

% Plot the theoretical plane
subplot(1, 2, 2);
imagesc(u(:), v(:), phaseCorr_theory);
xlim([u(1) u(end)]);
ylim([v(1) v(end)]);
caxis(1.1 * [-pi pi]);
axis image;
hold on

% Calculate the number of fringes in the theoretical plane
[nFringes_left, nFringes_right] = countFringes(TY_EST, TX_EST, [regionHeight, regionWidth]);

% Total number of fringes
nFringes = nFringes_left + nFringes_right;



% Calculate fringe lines if there are any
if nFringes > 0

    % Fringe coordinate vector
    v_fringes = zeros(length(u_1D), nFringes);

    % fringe vector
    % These are the values of N in the equation
    % for the fringe lines
    fringeVector = -nFringes_left : nFringes_right-1;

    % Calculate the coordinates of each fringe line
    for n = 1 : nFringes
        % Analytical equation for the n'th fringe line
        v_fringes(:, n) = regionHeight / TY_EST * ...
        ( -TX_EST / regionWidth * u_1D + (2 * fringeVector(n) + 1) / 2 );
        
        % Take this out
        % Plot fringe lines
        plot(u_1D, v_fringes(:, n), '--g', 'linewidth', 2);
    end      
end


% Print some data to screen.
fprintf('%d\t%0.2f\t%0.2f\t%0.2f\n',k, TY_EST, TX_EST, nFringes);


% Plot formatting...
grid on;

% Fringe angle
th = atan2(TY_EST, TX_EST);

% Absolute normalized components of the vector
abs_cos_angle = abs(cos(th));
abs_sin_angle = abs(sin(th));

% Calculate the vector magnitude (pixel units)
if (regionWidth / 2 * abs_sin_angle)  <= (regionHeight / 2 * abs_cos_angle) 
   vectorMagnitude_right = (regionWidth - uc)  / abs_cos_angle;
   vectorMagnitude_left = (uc - 1) / abs_cos_angle;
else
   vectorMagnitude_right = (regionHeight - vc) / abs_sin_angle;
   vectorMagnitude_left = (vc - 1) / abs_sin_angle;
end



% Plot a vector extending from the zero-frequency
% pixel, pointing in the directon perpendicular to the fringe lines
plot([0, vectorMagnitude_right * cos(th)], [0, vectorMagnitude_right * sin(th)], '-r', 'linewidth', 2);
plot([0, -vectorMagnitude_left * cos(th)], [0, -vectorMagnitude_left * sin(th)], '-b', 'linewidth', 2);
plot(0, 0, 'ok', 'markersize', 10, 'markerfacecolor', 'green');
hold off

xlim(([1 regionWidth] - uc) * 1.1);
ylim(([1 regionHeight] - vc) * 1.1);

end






























