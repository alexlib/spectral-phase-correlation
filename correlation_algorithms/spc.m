function spc(REGION1, REGION2, TY_EST, TX_EST, k)
% Variable k is a counter, used temporarily for debugging.

% Calculate region height and width
[regionHeight, regionWidth] = size(REGION1);

% Gaussian window filter
gaussianWindow = gaussianWindowFilter([regionHeight, regionWidth], [0.5 0.5], 'fraction');

% Windowed regions
image1 = double(REGION1);
image2 = double(REGION2);

% Zero frequencies
uc = (regionWidth/2 + 1);
vc = (regionHeight/2 + 1);

% Wavenumber coordinates
[u, v] = meshgrid((1 : regionWidth) - uc, (1 : regionHeight) - vc);
u_1D = u(1, :);

% Phase correlation of windowed images
phaseCorr = angle(fftshift(phaseCorrelation(gaussianWindow .* image1, gaussianWindow .* image2)));

% Theoretical phase plane
phaseCorr_theory = angle(exp(-2 * pi * 1i * ...
    (TX_EST / regionWidth * u + TY_EST / regionHeight * v)));

% Calculate the number of fringes in the theoretical plane
nFringes = countFringes(TY_EST, TX_EST, [regionHeight, regionWidth]);

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

% Print some data to screen.
fprintf('%d\t%0.2f\t%0.2f\t%0.2f\n',k, TY_EST, TX_EST, nFringes);

if nFringes > 0
  for n = -nFringes : nFringes
     
     % Analytical equation for the n'th fringe line
     v_fringes = regionHeight / TY_EST * ...
         ( -TX_EST / regionWidth * u_1D + (2 * n + 1) / 2 );
     
     % Plot fringe lines
     plot(u_1D, v_fringes, '--g', 'linewidth', 2);
  end      
end

% Plot formatting...
grid on;

% Calculate the angle between the horizontal and vertical translations
th = atan2(TY_EST, TX_EST);

% Absolute normalized components of the vector
abs_cos_angle = abs(cos(th));
abs_sin_angle = abs(sin(th));

% Calculate the vector magnitude
if (regionWidth / 2 * abs_sin_angle)  <= (regionHeight / 2 * abs_cos_angle) 
   vectorMagnitude = regionWidth  / (2 * abs_cos_angle);
else
   vectorMagnitude = regionHeight / (2 * abs_sin_angle);
end

% Plot a vector extending from the zero-frequency
% pixel, pointing in the directon perpendicular to the fringe lines
plot([0, vectorMagnitude * cos(th)], [0, vectorMagnitude * sin(th)], '-r', 'linewidth', 2);
plot([0, -vectorMagnitude * cos(th)], [0, -vectorMagnitude * sin(th)], '-b', 'linewidth', 2);
plot(0, 0, 'ok', 'markersize', 10, 'markerfacecolor', 'green');
hold off

xlim(([1 regionWidth] - uc) * 1.1);
ylim(([1 regionHeight] - vc) * 1.1);

end






























