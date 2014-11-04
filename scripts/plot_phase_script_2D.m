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

% Particle image diameter
particleDiameter = JobFile.Parameters.Processing.ParticleDiameter;

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

% Load parameters
load(parametersFilePath);

% Load images
load(imageFilePath);

% Size of the images
[regionHeight, regionWidth, nImages] = size(imageMatrix1);

% Make a Gaussian filter.
spatialWindow = gaussianWindowFilter([regionHeight, regionWidth], [0.5 0.5], 'fraction');

% Make RPC filter
rpcFilter = spectralEnergyFilter(regionHeight, regionWidth, particleDiameter);

% Make SPC filter
spcFilter = rpcFilter;

% Apodize the SPC filter 
spc_cutoff_wavenumber = 2 / (pi * particleDiameter);
spcFilter(spcFilter < spc_cutoff_wavenumber) = 0;

% True translations
TX_TRUE = Parameters.TranslationX;
TY_TRUE = Parameters.TranslationY;

% Initialize vectors to hold results
TY_SPC = zeros(1, nImages);
TX_SPC = zeros(1, nImages);

TY_RPC = zeros(1, nImages);
TX_RPC = zeros(1, nImages);

for k = 1 : 1 : nImages;
   
   % Image number
   imageNum = imageNumbers(k);
      
   % Read the raw images
   image1 = double(imageMatrix1(:, :, imageNum));
   image2 = double(imageMatrix2(:, :, imageNum));
   
   % Calculate SPC and RPC translations
   [TY_SPC(k), TX_SPC(k), TY_RPC(k), TX_RPC(k)] = spc_skel(image1 .* spatialWindow, image2 .* spatialWindow, rpcFilter, spcFilter);  
   
%    fprintf('\tTY\tTX\nTrue: %0.4f\t%0.4f\n SPC: %0.4f\t%0.4f\n RPC: %0.4f\t%0.4f\n\n', TY(k), TX(k), ty_spc, tx_spc, ty_rpc, tx_rpc);
  
end





end











