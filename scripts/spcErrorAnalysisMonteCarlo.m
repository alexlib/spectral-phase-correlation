function  spcErrorAnalysisMonteCarlo(JobFile, save_path, image_file_path, parameters_file_path, spatial_window, rpc_spectral_filter); 

% Load parameters
load(parameters_file_path);

% Load images
load(image_file_path);

% Number of images
[~, ~, number_of_images] = size(imageMatrix1);

% Particle image diameter
spatialRpcDiameter = JobFile.Parameters.Processing.SpatialRPCDiameter;

% Make SPC filter
spc_filter = rpc_spectral_filter;

% Apodize the SPC filter 
spc_cutoff_amplitude = 2 / (pi * spatialRpcDiameter);
spc_filter(spc_filter < spc_cutoff_amplitude) = 0;

% True translations
TY_TRUE = Parameters.TranslationY;
TX_TRUE = Parameters.TranslationX;

% Initialize vectors to hold translation estimates (SPC)
TY_SPC = zeros(number_of_images, 1);
TX_SPC = zeros(number_of_images, 1);

% Initialize vectors to hold translation estimates (RPC)
TY_RPC = zeros(number_of_images, 1);
TX_RPC = zeros(number_of_images, 1);

% Perform the correlations
parfor k = 1 : number_of_images;
    
   % Read the raw images
   image1 = double(imageMatrix1(:, :, k));
   image2 = double(imageMatrix2(:, :, k));

   % Calculate SPC and RPC translations
   [TY_SPC(k), TX_SPC(k), TY_RPC(k), TX_RPC(k)] = spc_skel(image1 .* spatial_window, image2 .* spatial_window, rpc_spectral_filter, spc_filter);  

end

% Save the output data
save(save_path, 'JobFile','TY_SPC', 'TX_SPC', 'TY_RPC', 'TX_RPC', 'TY_TRUE', 'TX_TRUE');

end











