% Base directory
base_dir = '/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src';


% Add paths
addpath(fullfile(base_dir, 'correlation_algorithms'));
addpath(fullfile(base_dir, 'filtering'));


% Data parent directory
dataDir = '/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/data/synthetic/lin/2014-10-05_translation_only/64x64/raw/lin_h64_w64_00001';

% Number of images to plot
startImage = 1;
endImage = 100;
skipImage = 1;

% Image numbers
imageNumbers = startImage : skipImage : endImage;

% Number of images to plot
nImages = length(imageNumbers);

% Parameters file location
parametersDir = 'parameters';
parametersName = 'imageParameters_lin_h64_w64_seg_000001_000100.mat';
parametersPath = fullfile(dataDir, parametersDir, parametersName);

% Load parameters
load(parametersPath);

% Image file location
imageDir = 'raw';
imageName = 'raw_image_matrix_lin_h64_w64_seg_000001_000100.mat';
imagePath = fullfile(dataDir, imageDir, imageName);

% Load images
load(imagePath);

% Read image dimensions
regionHeight = Parameters.ImageHeight;
regionWidth = Parameters.ImageWidth;

% True translations
TX = Parameters.TranslationX;
TY = Parameters.TranslationY;

% Spectral coordinates
[u, v] = meshgrid(1 : regionWidth, 1 : regionHeight);

uc = (regionWidth/2 + 1);
vc = (regionHeight/2 + 1);

% Gaussian window for FFTs
gWindow = gaussianWindowFilter([regionHeight, regionWidth], [0.5 0.5], 'fraction');

% Linear index for FFT wave numbers
u_1d = (1 : regionWidth) - uc;

% Loop over the images and plot
% measured and synthetic phase planes
for k = 1 : 5: nImages;
   imageNum = imageNumbers(k);
   
   % Read the raw images
   image1 = double(imageMatrix1(:, :, imageNum));
   image2 = double(imageMatrix2(:, :, imageNum));
    
   % Phase correlation of windowed images
   phaseCorr = angle(fftshift(phaseCorrelation(gWindow .* image1, gWindow .* image2)));
   
   % Translations in units of image periods
   txPeriod = TX(k) / regionWidth; 
   tyPeriod = TY(k) / regionHeight;
   
   % Theoretical phase plane
   phaseCorr_theory = angle(exp(-2 * pi * 1i * (TX(k) / regionWidth * (u-uc) + TY(k) / regionHeight * (v-vc))));
   
   % Theoretical number of fringes
   nFringes = floor(sqrt((TX(k))^2 + (TY(k))^2 ));
   
   % Angle of the displacement vector w.r.t. positive X
   Angle = atan(TX(k) / TY(k));
   
  % Plot the phase correlation
   subplot(1, 3, 1);
   imagesc(u(:), v(:), phaseCorr);
   caxis(1.1 * [-pi pi]);
   axis image
   
   % Make the plots
   
   % Plot the theoretical plane
   subplot(1, 3, 2);
   plot(u_1d, phaseCorr(:, 32), '-k', 'LineWidth', 2);
   xlim([u_1d(1) u_1d(end)]);
   ylim(1.1 * [-pi pi]);
   axis square
%    imagesc(u(:), v(:), phaseCorr_theory);
%    caxis(1.1* [-pi pi]);
%    axis image
%    hold on
%    
    
%    Calculate the theoretical fringe wrap lines
  
%   if nFringes > 0
%     for n = 1 : nFringes
%         v_fringe =  -regionHeight / TY(k) * ((u_1d-uc) * TX(k)/regionWidth + (2*n+1)/2); 
%         plot(u_1d, v_fringe, '--b', 'LineWidth', 2); 
%         hold on;
%     end
%   end
  
%    hold off;
%    axis image;
%    xlim([1, regionWidth]);
%    ylim([1, regionHeight]);
   title(['S_X = ' num2str(TX(k), '%0.2f') ', S_Y = ' num2str(TY(k), '%0.2f'),  ', nFringes = '  num2str(nFringes) ], 'FontSize', 16);  


    
   subplot(1,3,3)
%    plot([1 1], (TX(k)>0) * [1 1], 'ok', 'MarkerFaceColor', 'black', 'markersize', 10);
%    hold on
%    plot([2 2], (TY(k)>0) * [1 1], 'ok', 'MarkerFaceColor', 'Red', 'markersize', 10);
%    hold off
%    xlim([0 3]);
%    ylim([-1 2]);
%    
   phaseCorr_theory = angle(exp(-2 * pi * 1i * (TY(k) / regionHeight * (u_1d))));
   
   plot(u_1d, phaseCorr_theory, '-k', 'LineWidth', 2);
   ylim(1.1 * [-pi pi]);
   xlim([u_1d(1) u_1d(end)]);
   axis square;
   set(gcf, 'color', 'white');
   colormap gray;
   
   
   
   hold on
   if nFringes > 0
       for n = 0 : nFringes
           
           % Fringe locations
           uf = regionHeight/(TY(k)) *  (2 * n + 1)/2;
          
           % Positive fringe
           plot(uf, pi, 'ok', 'markersize', 10, 'markerfacecolor', 'red');
           plot(-uf, pi, 'ok', 'markersize', 10, 'markerfacecolor', 'blue');
%            phaseCorr_theory = angle(exp(-2 * pi * 1i * (TY(k) / regionHeight * (u_1d))));
           
       end
       
       
   end  
   
   fprintf('Fringe location: %0.2f\n', regionHeight/TY(k) * (0.5));
   fprintf('\n\n');
   
   hold off
   
   pause;
    
end

















