function  results_save_path = ...
    correlationErrorAnalysisMonteCarlo_runningEnsemble(MONTE_CARLO_PARAMETERS); 


% Parse the input structure
JobFile = MONTE_CARLO_PARAMETERS.JobFile;
results_save_path = MONTE_CARLO_PARAMETERS.Save_Path;
image_file_path = MONTE_CARLO_PARAMETERS.Image_File_Path;
parameters_file_path = MONTE_CARLO_PARAMETERS.Image_Parameters_path;

makePlots = JobFile.JobOptions.MakePlots;

% Suppress messages?
suppress_messages = JobFile.JobOptions.SuppressMessages;

% Start and end image numbers
start_image = JobFile.Parameters.Images.Start;
end_image = JobFile.Parameters.Images.End;

% Number of images to skip between successive correlations.
skip_image = JobFile.Parameters.Images.Skip;

% Whether or not to zero-mean regions
zero_mean_regions = JobFile.JobOptions.ZeroMeanRegions;

% Spatial window parameters
spatialWindowType =  ...
    JobFile.Parameters.Processing.SpatialWindowType; % Spatial window type

% Spatial window fraction (y, x)
spatialWindowFraction = ...
    JobFile.Parameters.Processing.SpatialWindowFraction;

% Weighted fit option
weighted_spc_plane_fit_method = lower( ...
    JobFile.Parameters.Processing.WeightedSpcPlaneFitMethod);

% Subpixel peak fit method
subpixel_peak_fit_method = lower(...
    JobFile.Parameters.Processing.PeakFitMethod);

% Ensemble method
ensemble_method_string = lower(...
    JobFile.Parameters.Processing.Ensemble.Method);

% APC Kernel radius
apc_kernel_radius = JobFile.Parameters.Processing.APC.KernelRadius;

% RPC Diameter
rpc_diameter = JobFile.Parameters.Processing.SpatialRPCDiameter;

% Load images
load(image_file_path);

% Load parameters to read true solutions so they can be saved to file.
load(parameters_file_path);

% Image numbers
image_numbers = start_image : skip_image : end_image;

% Number of images
[region_height, region_width, number_of_images] = size(imageMatrix1(:, :, image_numbers));

% Read the true translations, which will be saved to file.
TY_TRUE = -1 * Parameters.Translation.Y(image_numbers);
TX_TRUE = -1 * Parameters.Translation.X(image_numbers);

% Create the spatial window
spatial_window = gaussianWindowFilter(...
    [region_height region_width], ...
    spatialWindowFraction, spatialWindowType);

% Allocate memory for the RPC translation estimates.
ty_rpc_signed = zeros(number_of_images, 1);
tx_rpc_signed = zeros(number_of_images, 1);
ty_rpc_abs = zeros(number_of_images, 1);
tx_rpc_abs = zeros(number_of_images, 1);
tx_rpc_complex = zeros(number_of_images, 1);
ty_rpc_complex = zeros(number_of_images, 1);

% Allocate memory for the SCC translation estimates.
ty_scc_signed = zeros(number_of_images, 1);
tx_scc_signed = zeros(number_of_images, 1);
ty_scc_abs = zeros(number_of_images, 1);
tx_scc_abs = zeros(number_of_images, 1);
tx_scc_complex = zeros(number_of_images, 1);
ty_scc_complex = zeros(number_of_images, 1);

% Allocate memory for the APC translation estimates.
ty_apc = zeros(number_of_images, 1);
tx_apc = zeros(number_of_images, 1);

% Make the RPC filter.
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

% Allocate an array for the complex correlation
ensemble_correlation_complex = zeros(region_height, region_width);

% Allocate the ensemble phase correlation plane
ensemble_phase_corr = zeros(region_height, region_width);

% Allocate memory for SCC ensemble planes
scc_plane_ensemble_signed = zeros(region_height, region_width);
scc_plane_ensemble_abs = zeros(region_height, region_width);

% Allocate memory for RPC ensemble planes
rpc_plane_ensemble_signed = zeros(region_height, region_width);
rpc_plane_ensemble_abs = zeros(region_height, region_width);

% Weighting matrix for the subpixel fit
subpixel_weighting_matrix = ones(region_height, region_width);

% Initialize the Standard Deviation guesses for the APC filter
SY = region_height / 2;
SX = region_width /2 ;

% Make a new figure if plots are to be generated
if makePlots
    f = figure(1); 
    v = [-17.1000   15.6000];
    z = 1.5;
end


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
             region_matrix_01) .* spatial_window ;
          region_02 = zero_mean_region(...
             region_matrix_02) .* spatial_window ;
    else
        % Read the raw images
        region_01 = region_matrix_01 .* spatial_window;
        region_02 = region_matrix_02 .* spatial_window;
    end
    
    % Ensemble normalization factor by the standard
    % deviations of the regions and the region size
 ensemble_norm_factor = std(region_01(:)) * std(region_02(:)) ...
        * region_height * region_width;
   
    
    f1 = fftshift(fft2(region_01));
    f2 = fftshift(fft2(region_02));
    complex_correlation = f1 .* conj(f2);
    
%     % This is the complex cross correlation
%     complex_correlation =  ...
%         fftshift(crossCorrelation(region_01, region_02));
%     
    % Ensemble phase correlation
    ensemble_phase_corr = ensemble_phase_corr + phaseOnlyFilter(complex_correlation);
    
    % Add to the ensemble
    ensemble_correlation_complex = ensemble_correlation_complex ...
        + complex_correlation;
          
    % Signed inverse FT of SCC 
    scc_ifft_signed = ...
        fftshift(real(ifft2(complex_correlation))) ...
        / ensemble_norm_factor;

    % Signed inverse FT of RPC
    rpc_ifft_signed = fftshift(...
        real(ifft2(rpc_filter .* phaseOnlyFilter(...
        complex_correlation)))) / ensemble_norm_factor;

    % Add the signed SCC to its ensemble.
    scc_plane_ensemble_signed = scc_plane_ensemble_signed + ...
        scc_ifft_signed;
    
    % Add the absolute SCC to its ensemble
    scc_plane_ensemble_abs = scc_plane_ensemble_abs + ...
        abs(scc_ifft_signed);

    % Add the signed RPC to its ensemble.
    rpc_plane_ensemble_signed = rpc_plane_ensemble_signed + ...
        rpc_ifft_signed;

    % Add the absolute RPC to its ensemble
    rpc_plane_ensemble_abs = rpc_plane_ensemble_abs + ...
        abs(rpc_ifft_signed);

    % Signed SCC ensemble displacements
    [tx_scc_signed(k), ty_scc_signed(k)] = ...
        subpixel(abs(scc_plane_ensemble_signed), ...
    region_width, region_height, subpixel_weighting_matrix, ...
    subpixel_peak_fit_method_numerical, 0, sqrt(8));

    % Absolute SCC ensemble displacements
    [tx_scc_abs(k), ty_scc_abs(k)] = ...
        subpixel(scc_plane_ensemble_abs, ...
    region_width, region_height, subpixel_weighting_matrix, ...
    subpixel_peak_fit_method_numerical, 0, sqrt(8));

    % Signed RPC ensemble displacements
    [tx_rpc_signed(k), ty_rpc_signed(k)] = ...
        subpixel(abs(rpc_plane_ensemble_signed), ...
    region_width, region_height, subpixel_weighting_matrix, ...
    subpixel_peak_fit_method_numerical, 0, sqrt(8));

    % Absolute RPC ensemble displacements
    [tx_rpc_abs(k), ty_rpc_abs(k)] = ...
        subpixel(rpc_plane_ensemble_abs, ...
    region_width, region_height, subpixel_weighting_matrix, ...
    subpixel_peak_fit_method_numerical, 0, sqrt(8));

    % Complex ensemble SCC displacements
    [ty_scc_complex(k), tx_scc_complex(k), scc_plane_ensemble_complex] =...
        complex_to_scc(...
        ensemble_correlation_complex, ...
        subpixel_peak_fit_method_numerical);

    % Complex ensemble RPC displacements
    [ty_rpc_complex(k), tx_rpc_complex(k), rpc_plane_ensemble_complex] = ...
        complex_to_filtered_phase_correlation(...
        ensemble_correlation_complex, rpc_filter, ...
        subpixel_peak_fit_method_numerical);
    
%     % Calculate the APC filter
%     [apc_filter, ~, phase_angle_plane] = ...
%         calculate_apc_phase_mask_from_correlation(...
%         ensemble_correlation_complex, apc_kernel_radius,...
%         'symmetric', rpc_std);

    % Calculate the phase angle
    phase_angle_plane = angle(ensemble_phase_corr);
    
    % Calculate the APC filter
    [~, ~, ~, ~, ~, array_offset, array_raw] = ...
        fit_gaussian_2D(...
        abs(ensemble_phase_corr), 5);
    
    array_sub = array_raw - array_offset;
    apc_filter = array_sub ./ max(array_sub(:));
    
    
    
%     if k == 1
%         keyboard
%     end

    % APC displacements
    [ty_apc(k), tx_apc(k), apc_plane] = ...
        complex_to_filtered_phase_correlation(...
    ensemble_correlation_complex, apc_filter, ...
    subpixel_peak_fit_method_numerical);

    % Make plots if requested
    if makePlots
        
        subplot(2, 3, 1)
        % Do the different correlation algorithms.
        imagesc(phase_angle_plane);
        axis image;
        axis off
        title({'Phase angle', sprintf('Ensemble length: %d', k)});
        colormap parula;

        subplot(2, 3, 2);
        imagesc(real(ensemble_phase_corr));
        axis image;
        axis off
    %     title({'APC filter', sprintf('Diffusion std dev: %0.1f pix', diffusion_std_dev)});

        subplot(2, 3, 3);
        imagesc(apc_filter);
        axis image;
        axis off
    
        subplot(2, 3, 4);
%         mesh(scc_plane_ensemble_signed ./ max(scc_plane_ensemble_signed(:)), 'edgecolor', 'black', 'linewidth', 0.1);
        surf(abs(scc_plane_ensemble_signed) ./ max(abs(scc_plane_ensemble_signed(:))));
        axis square
        axis off
        title('SCC');
        set(gca, 'view', v);
        zoom(z);
        xlim([1, region_width]);
        ylim([1, region_height]);
        zlim([0, 1]);

        subplot(2, 3, 5);
%         mesh(rpc_plane_ensemble_signed ./ max(rpc_plane_ensemble_signed(:)), 'edgecolor', 'black', 'linewidth', 0.1);
        surf(abs(rpc_plane_ensemble_signed) ./ max(abs(rpc_plane_ensemble_signed(:))));
        axis square
        axis off
        title('RPC');
         set(gca, 'view', v);
        zoom(z);
        xlim([1, region_width]);
        ylim([1, region_height]);
        zlim([0, 1]);

        subplot(2, 3, 6);
%         mesh(apc_plane ./ max(apc_plane(:)), 'edgecolor', 'black', 'linewidth', 0.1);
        surf(apc_plane ./ max(apc_plane(:)));
        axis square
        axis off
        title('APC');
        set(gca, 'view', v);
        zoom(z);
        xlim([1, region_width]);
        ylim([1, region_height]);
        zlim([0, 1]);

        drawnow;
        
    end
end 

% Save the output data
save(results_save_path,...
    'JobFile',...
    'tx_rpc_signed', 'ty_rpc_signed', ...
    'tx_rpc_abs', 'ty_rpc_abs', ...
    'tx_rpc_complex',  'ty_rpc_complex', ...
    ...
    'tx_scc_signed', 'ty_scc_signed', ...
    'tx_scc_abs', 'ty_scc_abs', ...
    'tx_scc_complex', 'ty_scc_complex', ...
    ...
    'tx_apc', 'ty_apc', ...
    'TX_TRUE', 'TY_TRUE',...
    '-v7.3');
end











