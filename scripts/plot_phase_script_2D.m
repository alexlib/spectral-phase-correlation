% Base directory
base_dir = '/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src';


% Add paths
addpath(fullfile(base_dir, 'correlation_algorithms'));
addpath(fullfile(base_dir, 'filtering'));


% Data parent directory
dataDir = '/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/data/synthetic/mc/2014-10-05_translation_only_02/64x64/raw/mc_h64_w64_00001';

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
parametersName = 'imageParameters_mc_h64_w64_seg_000001_000100.mat';
parametersPath = fullfile(dataDir, parametersDir, parametersName);

% Load parameters
load(parametersPath);

% Image file location
imageDir = 'raw';
imageName = 'raw_image_matrix_mc_h64_w64_seg_000001_000100.mat';
imagePath = fullfile(dataDir, imageDir, imageName);

% Load images
load(imagePath);

% Read image dimensions
regionHeight = Parameters.ImageHeight;
regionWidth = Parameters.ImageWidth;

% True translations
TX = Parameters.TranslationX;
TY = Parameters.TranslationY;

% Zero frequencies
uc = (regionWidth/2 + 1);
vc = (regionHeight/2 + 1);

% Spectral coordinates
[u, v] = meshgrid((1 : regionWidth) - uc, (1 : regionHeight) - vc);

% 1-D vector of u
u_1D = u(1, :);

% Gaussian window for FFTs
gWindow = gaussianWindowFilter([regionHeight, regionWidth], [0.5 0.5], 'fraction');

% Print a display header.
fprintf('%s\t%s\t%s\n-----------------\n', 'k', 'TY(k)', 'N');

% Loop over the images and plot
% measured and synthetic phase planes
for k = 1 : 1 : nImages;
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
   phaseCorr_theory = angle(exp(-2 * pi * 1i * (TX(k) / regionWidth * u + TY(k) / regionHeight * v)));
   
   % Theoretical number of fringes
   nFringes = floor(sqrt((TX(k))^2 + (TY(k))^2 ));
   
   % Angle of the displacement vector w.r.t. positive X
   Angle = atan(TX(k) / TY(k));
   
  % Plot the phase correlation
   subplot(1, 2, 1);
   imagesc(u(:), v(:), phaseCorr);
   caxis(1.1 * [-pi pi]);
   axis image
   
   % Plot the theoretical plane
   subplot(1, 2, 2);
   imagesc(u(:), v(:), phaseCorr_theory);
   xlim([u(1) u(end)]);
   ylim([v(1) v(end)]);
   caxis(1.1 * [-pi pi]);
   axis image;
   hold on
   
   % Print some data to screen.
   fprintf('%d\t%0.2f\t%d\n', k, TY(k), nFringes);
    
   if nFringes > 0
      for n = -nFringes : nFringes
         v_fringes = regionHeight / TY(k) * ( -TX(k) / regionWidth * u_1D + (2 * n + 1) / 2 );
         plot(u_1D, v_fringes, '--g', 'linewidth', 2);
      end      
   end
   hold off;
   colormap gray;
   
   pause;
    
end

















