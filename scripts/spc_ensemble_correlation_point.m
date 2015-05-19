
% Input data directory
input_dir = '~/Desktop/schlieren_test_06/tiff';

% Input data base name
input_base_name = 'schlieren_test_06_';

% Input data number format
num_format = '%06d';

% Input data extension
input_extension = '.tiff';

% Grid point location (just a single grid point)
grid_row = 400;
grid_col = 400;

% Start image
start_image = 1000;

% End image
end_image = 1499;

% Frame step
frame_step = 1;

% Correlation step
correlation_step = 1;

% Region size
region_height = 64;
region_width = 64;

% Window fractions
window_fraction = [0.5, 0.5];

% Correlation method
correlation_method = 'spc';

% Cutoff radius
rc_outer = 8;
rc_inner = 3;

% Coordinates
[x, y] = meshgrid(1 : region_width, 1 : region_height);

% Centroid
xc = region_height / 2 + 1;
yc = region_width  / 2 + 1;

% Angular coordinates
[~, r] = cart2pol(x - xc, y - yc);

% Weighting filter
plane_fit_weights = ones(size(x));
plane_fit_weights(r > rc_outer) = 0;
plane_fit_weights(r < rc_inner) = 0;

% First image numbers
image_numbers_01 = start_image : frame_step : end_image;

% Second image numbers
image_numbers_02 = image_numbers_01 + correlation_step;

% Number of images
num_images = length(image_numbers_01);

% Region rows
region_rows = grid_row + [-region_height/2 : region_height/2 - 1];

% Region columns
region_cols = grid_col +  [-region_width/2 : region_width/2 - 1];

% Create a region window
region_window = gaussianWindowFilter([region_height, region_width], ...
    window_fraction, 'fraction');

% Allocate a correlation plane
cross_correlation = zeros(region_height, region_width, 'double');

% Make file paths
for k = 1 : num_images
   
    % File name of the first images
    file_name_01 = [input_base_name num2str(image_numbers_01(k), num_format) input_extension];
    
    % File name of the second images
    file_name_02 = [input_base_name num2str(image_numbers_02(k), num_format) input_extension];
    
    % File paths
    file_path_01{k} = fullfile(input_dir, file_name_01);
    file_path_02{k} = fullfile(input_dir, file_name_02);
   
end

% Do the correlations
for k = 1 : num_images
   
    % Check existence of both filepaths
    if exist(file_path_01{k}, 'file') && exist(file_path_02{k}, 'file')
        
        % Inform the user
        fprintf('Processing image %d of %d...\n', k, num_images);
        
        % Read the first image
        img_01 = double(imread(file_path_01{k}));
        
        % Read the second image
        img_02 = double(imread(file_path_02{k}));
        
        % Extract the parts of the image used in the correlation
        region_01 = img_01(region_rows, region_cols) .* region_window;
        region_02 = img_02(region_rows, region_cols) .* region_window;
        
        % Take the FFT of both regions
        ft_01 = fftn(region_01, [region_height, region_width]);
        ft_02 = fftn(region_02, [region_height, region_width]);
        
        % Conjugate-multiply the regions' Fourier Transforms 
        % to produce the complex cross correlation
        cross_correlation = cross_correlation + ft_01 .* conj(ft_02);
          
    end
    
end

% Extract the phase from the ensemble cross correlation plane
spectral_phase_plane = fftshift(phaseOnlyFilter(cross_correlation));

% % Zero the parts of the phase plane that are outsize the cutoff radius
% spectral_phase_plane(r > rc_outer) = 0;

% Extract the phase angle from the phase plane
phase_angle_plane = angle(spectral_phase_plane);

% Calculate the displacement from the SPC plane fit
[v_spc, u_spc, coeffs] = spc_plane_fit(angle(spectral_phase_plane), ...
    plane_fit_weights);

z = polyval2(coeffs,x,y);

figure(1);
% Plot the phase angle plane
imagesc(phase_angle_plane); 
axis image

% Invert FT the phase and plot
spatial_phase_plane = fftshift(abs(ifft2(spectral_phase_plane)));

% Plot the spatial phase plane
figure(2)
mesh(spatial_phase_plane ./ max(spatial_phase_plane(:)));
























