function  spcErrorAnalysisMonteCarlo(MONTE_CARLO_PARAMETERS); 

% Parse the input structure
JobFile = MONTE_CARLO_PARAMETERS.JobFile;
results_save_path = MONTE_CARLO_PARAMETERS.Save_Path;
image_file_path = MONTE_CARLO_PARAMETERS.Image_File_Path;
parameters_file_path = MONTE_CARLO_PARAMETERS.Image_Parameters_path;
phase_unwrapping_method = MONTE_CARLO_PARAMETERS.PhaseUnwrappingAlgorithm;

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
% Spatial window type ('fraction' or 'pixels')
spatialWindowType =  JobFile.Parameters.Processing.SpatialWindowType;

% Spatial image window fraction (y, x)
spatialWindowFraction = JobFile.Parameters.Processing.SpatialWindowFraction; 

% Spatial RPC diameter (pixels)
spatial_rpc_diameter = JobFile.Parameters.Processing.SpatialRPCDiameter;

% Zero mean images flag
zero_mean_regions = JobFile.JobOptions.ZeroMeanRegions;

% Read the phase filter list
phase_filter_list = JobFile.Parameters.Processing.PhaseFilterList;
phase_filter_kernel_size_list = JobFile.Parameters.Processing.KernelSizeList;

% Load images
load(image_file_path);

% Load parameters to read true solutions so they can be saved to file.
load(parameters_file_path);

% Image numbers
image_numbers = start_image : skip_image : end_image;

% Number of images
[region_height, region_width, number_of_images] = size(imageMatrix1(:, :, image_numbers));

% Create the spatial window
spatial_window = gaussianWindowFilter( [region_height region_width],...
    spatialWindowFraction, spatialWindowType);

% SPC filter cutoff amplitude
spc_cutoff_amplitude = 2 / (pi * spatial_rpc_diameter);

% Initialize vectors to hold translation estimates (SPC)
TY_EST = zeros(number_of_images, 1);
TX_EST = zeros(number_of_images, 1);

% Read the true translations, which will be saved to file.
TY_TRUE = Parameters.Translation.Y(image_numbers);
TX_TRUE = Parameters.Translation.X(image_numbers);

% Create the spectral filters
switch phase_unwrapping_method
    
    case 'SVD'
        
        % Create the row-wise spectral energy filter
        spectral_weights_rows = spectralEnergyFilter(region_height, ...
            1, spatial_rpc_diameter);
        
        % Create the column-wise spectral energy filter
        spectral_weights_cols = spectralEnergyFilter(region_width, 1, ...
            spatial_rpc_diameter);
        
        % Apply the cutoff amplitude to the filters
        spectral_weights_rows(spectral_weights_rows < ...
            spc_cutoff_amplitude) = 0;
        spectral_weights_cols(spectral_weights_cols < ...
            spc_cutoff_amplitude) = 0;
        
        % Perform the correlations
        if parallel_processing
            parfor k = 1 : number_of_images
                % Print the iteration number
                fprintf('On region %d of %d\n', k, number_of_images);

                % Read the raw images
                region_01 = double(imageMatrix1(:, :, image_numbers(k)));
                region_02 = double(imageMatrix2(:, :, image_numbers(k))); 
                
                % Zero-mean if requested
                if zero_mean_regions
                    region_01 = region_01 ./ mean(region_01(:));
                    region_02 = region_02 ./ mean(region_02(:));
                end
                
                [TY_EST(k), TX_EST(k)] = spc_svd_1D(spatial_window .* ...
                region_01, spatial_window .* region_02,...
                spectral_weights_rows, spectral_weights_cols);       
            end
        
        else
            for k = 1 : number_of_images

                % Print the iteration number
                fprintf('On region %d of %d\n', k, number_of_images);

                % Read the raw images
                region_01 = double(imageMatrix1(:, :, image_numbers(k)));
                region_02 = double(imageMatrix2(:, :, image_numbers(k)));
                
                % Zero-mean if requested
                if zero_mean_regions
                    region_01 = region_01 ./ mean(region_01(:));
                    region_02 = region_02 ./ mean(region_02(:));
                end

                [TY_EST(k), TX_EST(k)] = spc_svd_1D(spatial_window .* ...
                region_01, spatial_window .* region_02,...
                spectral_weights_rows, spectral_weights_cols);  
            end
        end

    
    otherwise
        % All the other phase unwrapping algorithms are 2D,
        % so create the same filters for all of them.
        
        % Read the filter type.
        phase_filter_type = JobFile.Parameters. ...
            Processing.PhaseFilterAlgorithm;
        
        % Create the 2-D spectral filter (i.e. RPC filter)
        rpc_spectral_filter = spectralEnergyFilter(region_height, ...
            region_width, spatial_rpc_diameter); 

        % Make the 2-D SPC filter
        spc_weighting_matrix = rpc_spectral_filter;
        spc_weighting_matrix(spc_weighting_matrix < ...
            spc_cutoff_amplitude) = 0;
        
        % Choose between parallel and single-core processing
        if parallel_processing
            
            % Perform the correlations using parallel processing
            parfor k = 1 : number_of_images;

                fprintf('%d of %d\n', k, number_of_images);

                % Read the raw images
                region_01 = double(imageMatrix1(:, :, image_numbers(k)));
                region_02 = double(imageMatrix2(:, :, image_numbers(k)));
                
                % Zero-mean if requested
                if zero_mean_regions
                    region_01 = region_01 ./ mean(region_01(:));
                    region_02 = region_02 ./ mean(region_02(:));
                end

                [TY_EST(k), TX_EST(k)] = spc_2D(spatial_window .* region_01,...
                    spatial_window .* region_02, spc_weighting_matrix, ...
                    phase_filter_list, phase_filter_kernel_size_list,...
                    phase_unwrapping_method, run_compiled);    
            end  
        
        else
        
            % Perform the correlations using single-core processing
            for k = 1 : number_of_images;

                fprintf('%d of %d\n', k, number_of_images);

                % Read the raw images
                region_01 = double(imageMatrix1(:, :, image_numbers(k)));
                region_02 = double(imageMatrix2(:, :, image_numbers(k)));
                
                % Zero-mean if requested
                if zero_mean_regions
                    region_01 = region_01 ./ mean(region_01(:));
                    region_02 = region_02 ./ mean(region_02(:));
                end

                [TY_EST(k), TX_EST(k)] = spc_2D(spatial_window .* region_01,...
                    spatial_window .* region_02, spc_weighting_matrix, ...
                    phase_filter_list, phase_filter_kernel_size_list,...
                    phase_unwrapping_method, run_compiled);   
            end         
        end
end

% Save the output data
save(results_save_path, 'JobFile','TY_EST', 'TX_EST','TY_TRUE', 'TX_TRUE');

% Inform the user of the save location
fprintf(1, 'Saved results to %s\n', results_save_path);

end











