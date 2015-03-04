function  rpcErrorAnalysisMonteCarlo(MONTE_CARLO_PARAMETERS); 

% Parse the input structure
JobFile = MONTE_CARLO_PARAMETERS.JobFile;
results_save_path = MONTE_CARLO_PARAMETERS.Save_Path;
image_file_path = MONTE_CARLO_PARAMETERS.Image_File_Path;
parameters_file_path = MONTE_CARLO_PARAMETERS.Image_Parameters_path;

% Spatial window parameters
spatialWindowType =  JobFile.Parameters.Processing.SpatialWindowType; % Spatial window type
spatialWindowFraction = JobFile.Parameters.Processing.SpatialWindowFraction; % Spatial image window fraction (y, x)

% Spatial RPC diameter
spatial_rpc_diameter = JobFile.Parameters.Processing.SpatialRPCDiameter; % Spatial image RPC diameter (pixels)

% Load images
load(image_file_path);

% Load parameters to read true solutions so they can be saved to file.
load(parameters_file_path);

% Number of images
[region_height, region_width, number_of_images] = size(imageMatrix1);

% Create the spatial window
spatial_window = gaussianWindowFilter( [region_height region_width], spatialWindowFraction, spatialWindowType);

% Initialize vectors to hold translation estimates (SPC)
TY_EST = zeros(number_of_images, 1);
TX_EST = zeros(number_of_images, 1);

% Read the true translations, which will be saved to file.
TY_TRUE = Parameters.TranslationY;
TX_TRUE = Parameters.TranslationX;

% Create the 2-D spectral filter (i.e. RPC filter)
rpc_spectral_filter = spectralEnergyFilter(region_height, region_width, spatial_rpc_diameter); % Raw image RPC spectral energy filter

% Do the correlations
% Perform the correlations
parfor k = 1 : number_of_images
    
    % Read the raw images
    region_01 = double(imageMatrix1(:, :, k));
    region_02 = double(imageMatrix2(:, :, k));
    [TY_EST(k), TX_EST(k)] = RPC(spatial_window .* region_01,...
        spatial_window .* region_02, rpc_spectral_filter);       
end    

% Save the output data
save(results_save_path, 'JobFile','TY_EST', 'TX_EST','TY_TRUE', 'TX_TRUE');

end










