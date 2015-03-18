function  sccErrorAnalysisMonteCarlo(MONTE_CARLO_PARAMETERS); 

% Parse the input structure
JobFile = MONTE_CARLO_PARAMETERS.JobFile;
results_save_path = MONTE_CARLO_PARAMETERS.Save_Path;
image_file_path = MONTE_CARLO_PARAMETERS.Image_File_Path;
parameters_file_path = MONTE_CARLO_PARAMETERS.Image_Parameters_path;

% Start and end image numbers
start_image = JobFile.Parameters.Images.Start;
end_image = JobFile.Parameters.Images.End;

% Number of images to skip between successive correlations.
skip_image = JobFile.Parameters.Images.Skip;

% Job Options
run_compiled = JobFile.JobOptions.RunCompiled;

% Parallel processing flag
parallel_processing = JobFile.JobOptions.ParallelProcessing;

% Spatial window parameters
spatialWindowType =  JobFile.Parameters.Processing.SpatialWindowType; % Spatial window type
spatialWindowFraction = JobFile.Parameters.Processing.SpatialWindowFraction; % Spatial image window fraction (y, x)

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

% Initialize vectors to hold translation estimates (SPC)
TY_EST = zeros(number_of_images, 1);
TX_EST = zeros(number_of_images, 1);

% Read the true translations, which will be saved to file.
TY_TRUE = Parameters.TranslationY(image_numbers);
TX_TRUE = Parameters.TranslationX(image_numbers);

% Do the correlations
% Perform the correlations
if parallel_processing
    parfor k = 1 : number_of_images
        
        % Print the iteration number
        fprintf('On region %d of %d\n', k, number_of_images);
        
        % Read the raw images
        region_01 = double(imageMatrix1(:, :, image_numbers(k)));
        region_02 = double(imageMatrix2(:, :, image_numbers(k)));
        [TY_EST(k), TX_EST(k)] = SCC(spatial_window .* region_01,...
            spatial_window .* region_02);       
    end 
else
    for k = 1 : number_of_images
        
        % Print the iteration number
        fprintf('On region %d of %d\n', k, number_of_images);
        
        % Read the raw images
        region_01 = double(imageMatrix1(:, :, image_numbers(k)));
        region_02 = double(imageMatrix2(:, :, image_numbers(k)));
        [TY_EST(k), TX_EST(k)] = SCC(spatial_window .* region_01,...
            spatial_window .* region_02);       
    end 
end
   

% Save the output data
save(results_save_path, 'JobFile','TY_EST', 'TX_EST','TY_TRUE', 'TX_TRUE');

end











