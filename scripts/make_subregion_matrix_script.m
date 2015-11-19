
% Image paths
image_dir = '/Users/matthewgiarra/Desktop/fullfield/raw';

image_name_01 = 'image_001.tiff';
image_name_02 = 'image_002.tiff';

grid_spacing = [64, 64];
region_size = [128, 128];

% Load the images
image_01 = imread(fullfile(image_dir, image_name_01));
image_02 = imread(fullfile(image_dir, image_name_02));

% Extract the subregions
imageMatrix1 = make_subregion_matrix(image_01, grid_spacing, region_size);
imageMatrix2 = make_subregion_matrix(image_02, grid_spacing, region_size);













