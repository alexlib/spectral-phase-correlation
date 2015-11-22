function [X, Y, U, V] = apcFullField(IMAGE_LIST_01, IMAGE_LIST_02,...
    GRID_SPACING, REGION_DIMS, MASK);

% Defaults
if nargin < 5
    MASK = [];
end

% Force a grid buffer of zero for now
gbx = [0, 0];
gby = [0, 0];

% Load the first image to measure it
image_01 = imread(IMAGE_LIST_01{1});

% Image size
[image_height, image_width] = size(image_01);

% Default mask
if isempty(MASK)
    grid_mask = ones(image_height, image_width);
else
    grid_mask = MASK;
end

% Make the grid
[X, Y] = gridImage([image_height, image_width],...
    GRID_SPACING, gby, gbx, grid_mask);

% Count the number of images
num_pairs = length(IMAGE_LIST_01);

% Number of grid points
num_grid_points = numel(Y);

% Allocate the velocities
V = zeros(num_grid_points, 1);
U = zeros(num_grid_points, 1);

% Window
g = gaussianWindowFilter(REGION_DIMS, [0.5, 0.5], 'fraction');

% loop over the grid points
parfor k = 1 : num_grid_points
    fprintf('On %d of %d\n', k, num_grid_points);
    region_mat_01 = zeros([REGION_DIMS, num_pairs]);
    region_mat_02 = zeros([REGION_DIMS, num_pairs]);
    
    % Determine image extents
   
% Populate the region matrix
 
% Loop over the images
    for n = 1 : num_pairs
        
        % Read the image
        img_01 = double(imread(IMAGE_LIST_01{n}));
        img_02 = double(imread(IMAGE_LIST_02{n}));
        
        % Populate the region matrix
        region_mat_01(:, :, n) = ...
            extractSubRegions(img_01, ...
            REGION_DIMS, X(k), Y(k));
        
        region_mat_02(:, :, n) = ...
            extractSubRegions(img_02, ...
            REGION_DIMS, X(k), Y(k));
        
    end
     
    % Figure out the APC filter
    [phase_mask, phase_quality, phase_angle] = ...
        calculate_apc_phase_mask_from_images...
        (region_mat_01, region_mat_02, 1, 'gaussian');
    
    img_01 = double(imread(IMAGE_LIST_01{1}));
    img_02 = double(imread(IMAGE_LIST_02{1}));

    region_01 = extractSubRegions(img_01, REGION_DIMS, X(k), Y(k));
    region_02 = extractSubRegions(img_02, REGION_DIMS, X(k), Y(k));
    
    R1_ZM = region_01 - mean(region_01(:));
    R2_ZM = region_02 - mean(region_02(:));
    
    [V(k), U(k)] = RPC(R1_ZM .* g, R2_ZM .* g, phase_mask, 1);

    
end




end




