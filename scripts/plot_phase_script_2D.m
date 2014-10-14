function plot_phase_script_2D();

% Base directory
base_dir = fullfile(pwd, '..');

% Add paths
addpath(fullfile(base_dir, 'correlation_algorithms'));
addpath(fullfile(base_dir, 'filtering'));
addpath(fullfile(base_dir, 'jobfiles'));

setNumber = 1; 

% Job file name
JobFileName = 'spc_jobfile';

% Run / load the jobfile
eval(['JobFile = ' JobFileName]);

nDigits = JobFile.JobOptions.NumberOfDigits;
imagePerSet = JobFile.Parameters.Sets.ImagesPerSet;
numberFormat = ['%0' num2str(nDigits) '.0f'];
regionHeight = JobFile.Parameters.RegionHeight;
regionWidth = JobFile.Parameters.RegionWidth;


% Data directory
dataDir = fullfile(JobFile.ProjectRepository, 'analysis', 'data',...
    JobFile.ImageType, JobFile.SetType,...
    JobFile.CaseName, [num2str(regionHeight) 'x' num2str(regionWidth)], 'raw', [JobFile.SetType '_h' num2str(regionHeight) '_w' num2str(regionHeight) '_' num2str(setNumber, '%05.0f' ) ]);

% Parameters and image dir
parametersDir = fullfile(dataDir, 'parameters');
imageDir = fullfile(dataDir, 'raw');

% Image file name
imageFileName = ['raw_image_matrix_'...
    JobFile.SetType '_h' num2str(regionHeight) ...
    '_w' num2str(regionWidth) '_seg_' num2str(1, numberFormat) '_' num2str(imagePerSet, numberFormat) '.mat'];

% Parameters file name
% Image file name
parametersFileName = ['imageParameters_'...
    JobFile.SetType '_h' num2str(regionHeight) ...
    '_w' num2str(regionWidth) '_seg_' num2str(1, numberFormat) '_' num2str(imagePerSet, numberFormat) '.mat'];

% Image file path
imageFilePath = fullfile(imageDir, imageFileName);

% Parameters file path
parametersFilePath = fullfile(parametersDir, parametersFileName);

% Image numbers
imageNumbers = 1 : imagePerSet;

% Number of images to plot
nImages = length(imageNumbers);

% Load parameters
load(parametersFilePath);

% Load images
load(imageFilePath);

% True translations
TX = Parameters.TranslationX;
TY = Parameters.TranslationY;

% Print a display header.
fprintf('%s\t%s\t%s\t%s\n-------------------\n', 'k','TY(k)', 'TX(k)', 'N');

% Loop over the images and plot
% measured and synthetic phase planes

for k = 1 : nImages;
   imageNum = imageNumbers(k);
   
   % Read the raw images
   image1 = double(imageMatrix1(:, :, imageNum));
   image2 = double(imageMatrix2(:, :, imageNum));
   
   spc(image1, image2, TY(k), TX(k), k);
   
   pause;
    
end


end











