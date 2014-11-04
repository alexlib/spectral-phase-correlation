function PHASE_PLANE_UNWRAPPED = spc_unwrap_analytical_test(PHASE_PLANE, TY, TX, k)

fSize = 14;

fprintf('%d\t%0.2f\t%0.2f\n', k, TY, TX);

% Size of the wrapped phase plane.
[height, width] = size(PHASE_PLANE);

% This analytically counts the number of
% fringes in the wrapped phase plane.

% Zero frequency pixel coordinates
uc =  width/2 + 1 - 0.5 * mod(width, 2);
vc =  height/2 + 1 - 0.5 * mod(height, 2);

% 1-D u vector
u_1d = (1-uc : width - uc);
v_1d = (1 - vc : height - vc)';

% Coordinate matrices
u_mat = u_1d(ones(height, 1), :);
v_mat = v_1d(:, ones(width, 1));

%% Count fringes
% Number of fringes to the right of the origin.
nFringes_right = floor(abs(TY)/height * (height/2 - (2 * vc - height - 1)) ...
    + abs(TX)/width * (width/2 - (2 * uc - width - 1)) + 1/2);

% Number of fringes to the left of the origin
nFringes_left = floor(abs(TY)/height * (height/2) ...
    + abs(TX)/width * (width/2) + 1/2);

% Total number of fringes
nFringes = nFringes_left + nFringes_right;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Things for debug plotting
% Plot for debugging
% Plot the phase correlation

% Theoretical phase plane
phaseCorr_theory = angle(exp(-2 * pi * 1i * ...
    (TX / width * u_mat + TY / height * v_mat)));

% f = figure;
% set(f, 'visible', 'off');

figure(1);
% Coordinate matrices
s1 = subplot(1, 3, 1);
imagesc(u_mat(:), v_mat(:), PHASE_PLANE);
xlim([u_mat(1) u_mat(end)]);
ylim([v_mat(1) v_mat(end)]);
caxis(1.1 * [-pi pi]);
axis image;
set(gca, 'xtick', -30:15:30);
set(gca, 'ytick', -30:15:30);
colormap gray;
title({'Measured phase' 'angle plane (wrapped)'}, 'FontSize', 10);
hold on;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


if nFringes > 0

    % fringe vector
    % These are the values of N in the equation
    % for the fringe lines. Subtract 1 from the 
    % positive fringes because n=0 corresponds
    % to the first positive fringe line.
    fringe_count_vector = -nFringes_left : nFringes_right-1;

  
    
    % Plot all the fringes
    for n = 1 : nFringes
        % Analytical equation for the n'th fringe line
        v_fringe_mat = (height / TY * ...
        ( -TX / width * u_mat + (2 * fringe_count_vector(n) + 1) / 2 ));
        plot(u_1d, v_fringe_mat(1, :), '--g', 'linewidth', 2);
    end
    
     
end % <--- keep
hold off
ylim([-32 32]);

% Plot the theoretical plane
s2 = subplot(1, 3, 2);
imagesc(u_mat(:), v_mat(:), phaseCorr_theory);
xlim([u_mat(1) u_mat(end)]);
ylim([v_mat(1) v_mat(end)]);
caxis(1.1 * [-pi pi]);
axis image;
set(gca, 'xtick', -30:15:30);
set(gca, 'yticklabel', '');
title({'Theoretical phase' 'angle plane (wrapped)'}, 'FontSize', 10);
xl = (sprintf('TX = %0.2f, TY = %0.2f', TX, TY));
xlabel(xl);
hold on;

% Wrap count matrix
wrapCount = zeros(height, width);

fringe_coords_vect = zeros(length(u_1d), nFringes);

%% Calculate fringe lines
% Calculate fringe lines if there are any
if nFringes > 0

    % fringe vector
    % These are the values of N in the equation
    % for the fringe lines. Subtract 1 from the 
    % positive fringes because n=0 corresponds
    % to the first positive fringe line.
    fringe_count_vector = -nFringes_left : nFringes_right-1;

    % Wrap count matrix
    wrapCount = zeros(height, width);    
    
    % Plot all the fringes
    for n = 1 : nFringes
        % Analytical equation for the n'th fringe line
        v_fringe_mat = (height / TY * ...
        ( -TX / width * u_mat + (2 * fringe_count_vector(n) + 1) / 2 ));
        
        fringe_coords_vect(:, n) = v_fringe_mat(1, :);
        plot(u_1d, fringe_coords_vect(:, n), '--g', 'linewidth', 4);
        
        
        
        % Update the wrap count matrix
        wrapCount = wrapCount + 1*((v_mat) >= (v_fringe_mat));

    end
    hold off
    
    wrapCount = wrapCount - nFringes_left;
    
end % <--- keep

% Flip wrap count
if TY > 0
    wrapCount = -wrapCount;
end

% Unwrap the plane
PHASE_PLANE_UNWRAPPED = PHASE_PLANE + 2 * pi * wrapCount;  

ylim([-32 32]);
hold off;
s3 = subplot(1, 3, 3);
imagesc(u_mat(:), v_mat(:), wrapCount);
xlim([u_mat(1) u_mat(end)]);
ylim([v_mat(1) v_mat(end)]);
caxis([-5 5]);
t = colorbar;
set(get(t,'ylabel'),'String', 'Number of wraps');
axis image;
set(gca, 'xtick', -30:15:30);
set(gca, 'yticklabel', '');
xlabel(' ');
title({'Theoretical number and' 'direction of phase wraps'}, 'FontSize', 10);

% axes(s2);
% xl = sprintf('TX = %02.2f, TY = %02.2f', TX, TY);
% xlabel(xl);

s2Pos = get(s2,'position');
s3Pos = get(s3,'position');
s3Pos(3:4) = s2Pos(3:4);
set(s3,'position',s3Pos);
tPos = get(t, 'position');
tPos(1) = s3Pos(1) + s3Pos(3) + 0.01;
set(t, 'Position', tPos);

% Theoretical phase plane
phaseCorrTheory_unwrapped = phaseCorr_theory + 2 * pi * wrapCount;

figure(2);
subplot(2, 2, [2 4]);
mesh(PHASE_PLANE_UNWRAPPED, 'edgecolor', 'black'); 
% set(gca, 'view', [97.5000   24.0000]);
set(gca, 'view', [21.5000; 8.0000]);
xlim([1 64]);
ylim([1 64]);
zlim([-30 30]); 
axis image
set(gca, 'FontSize', fSize);
% set(gca, 'xticklabel', '');
% set(gca, 'yticklabel', '');
% set(gca, 'zticklabel', '');
title('Unwrapped phase plane', 'FontSize', fSize');
hold on

nPoints = 16;
[zplane, yplane] = meshgrid(linspace(-30, 30, nPoints), linspace(1, 64, nPoints));
xplane = 32 * ones(size(zplane));
mesh(xplane, yplane, zplane, 'edgecolor', 'black', 'facecolor', 'green', 'facealpha', 0.3, 'edgealpha', 0.3);
ylabel(sprintf('TX = %0.2f, TY = %0.2f', TX, TY), 'FontSize', fSize);
hold off

subplot(2, 2, 1);
plot(v_1d, PHASE_PLANE(:, 32), '-k', 'LineWidth', 4);
hold on
plot(v_1d, phaseCorr_theory(:, 32), '-r', 'LineWidth', 2);

f = fringe_coords_vect(1, :)
for n = 1 : nFringes
   plot(f(n) * [1, 1], pi * [-2 2], '--k');
end

hold off
ylim(1.1 * pi * [-1 2]);
xlim([v_1d(1) v_1d(end)]);
grid on
axis square
ylabel('Phase angle (rad)', 'FontSize', fSize);
title('Wrapped phase', 'FontSize', fSize);
% set(gca, 'xticklabel', '');
set(gca, 'FontSize', fSize);
h = legend('Measured', 'Theory');
set(h, 'fontsize', 12);


subplot(2, 2, 3);
plot(v_1d, PHASE_PLANE_UNWRAPPED(:, 32), '-k', 'LineWidth', 4);
hold on
plot(v_1d, phaseCorrTheory_unwrapped(:, 32), '-r', 'LineWidth', 2);
for n = 1 : nFringes
   plot(f(n) * [1, 1], 20 * [-1 1], '--k');
end

hold off
ylim([-20 20]);
xlim([v_1d(1) v_1d(end)]);
grid on
axis square
ylabel('Phase angle (rad)', 'FontSize', fSize);
title('Unwrapped phase', 'FontSize', fSize);
set(gca, 'FontSize', fSize);
set(gca, 'xtick', 0:16:64);

keyboard
% print(2, '-djpeg', fullfile('~/Desktop/plots', sprintf('plot_%05d', k)));
end







