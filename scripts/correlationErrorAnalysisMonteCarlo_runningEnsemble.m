function  results_save_path = correlationErrorAnalysisMonteCarlo_runningEnsemble(MONTE_CARLO_PARAMETERS); 

% Parse the input structure
JobFile = MONTE_CARLO_PARAMETERS.JobFile;
results_save_path = MONTE_CARLO_PARAMETERS.Save_Path;
image_file_path = MONTE_CARLO_PARAMETERS.Image_File_Path;
parameters_file_path = MONTE_CARLO_PARAMETERS.Image_Parameters_path;

% Suppress messages?
suppress_messages = JobFile.JobOptions.SuppressMessages;

% Start and end image numbers
start_image = JobFile.Parameters.Images.Start;
end_image = JobFile.Parameters.Images.End;

% Number of images to skip between successive correlations.
skip_image = JobFile.Parameters.Images.Skip;

% Parallel processing flag
parallel_processing = JobFile.JobOptions.ParallelProcessing;

% Whether or not to zero-mean regions
zero_mean_regions = JobFile.JobOptions.ZeroMeanRegions;

% Spatial window parameters
spatialWindowType =  JobFile.Parameters.Processing.SpatialWindowType; % Spatial window type
spatialWindowFraction = JobFile.Parameters.Processing.SpatialWindowFraction; % Spatial image window fraction (y, x)

% Weighted fit option
weighted_spc_plane_fit_method = lower( ...
    JobFile.Parameters.Processing.WeightedSpcPlaneFitMethod);

% Subpixel peak fit method
subpixel_peak_fit_method = lower(...
    JobFile.Parameters.Processing.PeakFitMethod);

% Ensemble length
ensemble_length = JobFile.Parameters.Processing.EnsembleLength;

% Load images
load(image_file_path);

% Load parameters to read true solutions so they can be saved to file.
load(parameters_file_path);

% Image numbers
image_numbers = start_image : skip_image : end_image;

% Number of images
[region_height, region_width, number_of_images] = size(imageMatrix1(:, :, image_numbers));

% Create the spatial window
spatial_window = gaussianWindowFilter( [region_height region_width], spatialWindowFraction, spatialWindowType);

% Initialize vectors to hold translation estimates
ty_rpc = zeros(number_of_images, 1);
tx_rpc = zeros(number_of_images, 1);

ty_scc = zeros(number_of_images, 1);
tx_scc = zeros(number_of_images, 1);

ty_apc = zeros(number_of_images, 1);
tx_apc = zeros(number_of_images, 1);

% Read the true translations, which will be saved to file.
TY_TRUE = Parameters.Translation.Y(image_numbers);
TX_TRUE = Parameters.Translation.X(image_numbers);

% APC Kernel radius
apc_kernel_radius = JobFile.Parameters.Processing.APC.KernelRadius;

% RPC Diameter
rpc_diameter = JobFile.Parameters.Processing.SpatialRPCDiameter;

% RPC Filter
rpc_filter = spectralEnergyFilter(region_height, ...
        region_width, rpc_diameter);

% Standard deviation of the RPC filter
[~, rpc_std, ~] = fit_gaussian_2D(rpc_filter);
    
% Convert the subpixel peak-fit method string extracted from the jobfile
% into the numerical peak-fit method identifier expected by the function
% subpixel.m
switch subpixel_peak_fit_method
    case 'least_squares'
        subpixel_peak_fit_method_numerical = 3;
    case '3_point'
        subpixel_peak_fit_method_numerical = 1;
    otherwise
        subpixel_peak_fit_method_numerical = 1;
end

% Initialize the complex correlation
complex_correlation = zeros(region_height, region_width);

% Do the processing.
for k = 1 : number_of_images

    % Region matrices
    region_matrix_01 = double(imageMatrix1(:, :, image_numbers(k)));
    region_matrix_02 = double(imageMatrix2(:, :, image_numbers(k)));

     % Print the iteration number
    if ~suppress_messages
        fprintf('On region %d of %d\n', k, number_of_images);
    end

    % Ensemble correlation
    % Zero mean the regions, or not
    if zero_mean_regions
         region_01 = zero_mean_region(...
             region_matrix_01) .* spatial_window;
          region_02 = zero_mean_region(...
             region_matrix_02) .* spatial_window;
    else
        % Read the raw images
        region_01 = region_matrix_01 .* spatial_window;
        region_02 = region_matrix_02 .* spatial_window;
    end

    % Complex correlation
    complex_correlation = complex_correlation + ...
        fftshift(crossCorrelation(region_01, region_02));
    
    % Calculate the APC filter
    [apc_filter, ~, ang] = calculate_apc_phase_mask_from_correlation(...
            complex_correlation, apc_kernel_radius, 'gaussian', rpc_std);

    % SCC
    [ty_scc(k), tx_scc(k), scc_plane] = ...
        complex_to_scc(complex_correlation, ...
        subpixel_peak_fit_method_numerical);

    % RPC
    [ty_rpc(k), tx_rpc(k), rpc_plane] = ...
        complex_to_filtered_phase_correlation(...
            complex_correlation, rpc_filter, ...
            subpixel_peak_fit_method_numerical); 
    % APC   
    [ty_apc(k), tx_apc(k), apc_plane] = ...
    complex_to_filtered_phase_correlation(...
        complex_correlation, apc_filter, ...
        subpixel_peak_fit_method_numerical); 

end 
    

% figure(1)
% subplot(2, 3, 1)
% % Do the different correlation algorithms.
% imagesc(ang);
% axis image;
% axis off
% 
% subplot(2, 3, 2);
% imagesc(apc_filter);
% axis image;
% axis off
% 
% subplot(2, 3, 4);
% mesh(scc_plane ./ max(scc_plane(:)), 'edgecolor', 'black');
% axis square
% axis off
% title('SCC');
% 
% subplot(2, 3, 5);
% mesh(rpc_plane ./ max(rpc_plane(:)), 'edgecolor', 'black');
% axis square
% axis off
% title('RPC');
% 
% subplot(2, 3, 6);
% mesh(apc_plane ./ max(apc_plane(:)), 'edgecolor', 'black');
% axis square
% axis off
% title('APC');


% Save the output data
save(results_save_path,...
    'JobFile',...
    'tx_rpc', 'ty_rpc', ...
    'tx_scc', 'ty_scc', ...
    'tx_apc', 'ty_apc', ...
    'TX_TRUE', 'TY_TRUE', '-v7.3');

end











