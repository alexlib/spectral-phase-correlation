function spectralCrossCorr = crossCorrelation(A, B)
% crossCorrelation calculates the discrete cross correlation between two similarly sized matrices.
% 
% INPUTS
%   A = First of two [m x n] matrices in the spatial domain to be correlated.
%   B = Second of two [m x n] matrices in the spatial domain to be correlated.
% 
% OUTPUTS
%    spectralCrossCorr = Cross correlation (in the spectral domain) between region2 and region1
% 
% EXAMPLE
%   Perform a cross correlation betwen (1) a noisy 2-D Gaussian function centered about [x, y] = [0, 0], 
%   and (2) a noisy 2-D Gaussian function centered about [x, y] = [10, 5]
% 
%   % Generate grid
%   [x y] = meshgrid(-32:32,-32:32);
%   
%   % Specify image centers
%   xo1 = 0;
%   yo1 = 0;
%   xo2 = 10;
%   yo2 = 5;
%   
%   % Speficy standard deviations for Gaussian functions
%   sx = 1;
%   sy = 1;
%   
%   % Generate noisy 2-D Gaussian distributions
%   A = exp( -( (x-xo1).^2 / (2 * sx^2) + (y - yo1).^2 / (2 * sy^2) ) ) + 0.1 * rand(size(x, 1), size(x,2));
%   B = exp( -( (x-xo2).^2 / (2 * sx^2) + (y - yo2).^2 / (2 * sy^2) ) ) + 0.1 * rand(size(x, 1), size(x,2));
%   
%   % Perform cross correlation in the spectral domain
%   spectralCrossCorr = crossCorrelation(B, A);
%   
%   % Transform the cross correlation back into the spatial domain
%   spatialCorr = freq2space(spectralCrossCorr);
%   
%   % Plot cross correlation in the spatial domain
%   figure;
%   set(gcf, 'Color', [1 1 1]);
%   set(gca, 'FontSize', 20);
%   q = mesh(x, y, spatialCorr);
%   title('Cross Correlation');
%   zlabel('Strength of Cross Correlation');
%   xlabel('Horizontal Position (Pixels)')
%   ylabel('Vertical Position (Pixels)')
%   set(q,'EdgeColor', [0 0 0 ], 'FaceAlpha',0.5);
% 
% SEE ALSO
%   fftn, freq2space

% Calculate size of interrogation regions (homogeneous) (pixels)
[m, n] = size(A);

% Perform Fourier transforms
f1 = fftn(A, [m, n]);
f2 = fftn(B, [m, n]);

% Perform cross correlation in spectral domain
% spectralCrossCorr = f1 .* conj(f2);
spectralCrossCorr =  f2 .* conj(f1);

end









