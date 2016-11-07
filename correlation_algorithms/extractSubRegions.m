function REGIONMATRIX = extractSubRegions(IMAGE, REGIONSIZE, GRID_POINTS_X, GRID_POINTS_Y)
% This function extracts subregions from an image.

% Load the image if it's passed as a string
if ischar(IMAGE)
    IMAGE = double(imread(IMAGE));
end

% Determine the size of the image.
[imageHeight, imageWidth, ~] = size(IMAGE);

% Make grid points into column vectors
gx = GRID_POINTS_X(:);
gy = GRID_POINTS_Y(:);

% Number of regions
nRegions = length(gx);

% Sub region height and width
region_height = REGIONSIZE(1);
region_width  = REGIONSIZE(2);

% Determine the leftmost and rightmost columns of the interrogation regions
% (first image)
xMin = gx -  ceil(region_width / 2 ) + 1;
xMax = gx + floor(region_width / 2 );

% Determine the top and bottom rows of the interrogation regions
% (first image)
yMin = gy -  ceil(region_height / 2 ) + 1;
yMax = gy + floor(region_height / 2 );

% Initialze a matrix for holding a stack of subregions.
REGIONMATRIX = zeros(region_height, region_width, nRegions);

% Create stacks of the subregions.
% This is done so that individual subregions (rather than entire images)
% can be passed to the parfor loop. 
for k = 1 : nRegions  
    
    % Zero the temporary matrix
    region_mat_temp = zeros(region_height, region_width);
    
    % image subregion
    image_subregion = IMAGE( ...
        max([1, yMin(k)]) : min([imageHeight, yMax(k)]) ,...
        max([1, xMin(k)]) : min([imageWidth, xMax(k)]) );
    
    % Min and max row numbers in the full image
    row_min = max([1, yMin(k)]);
    row_max = min([imageHeight, yMax(k)]);
    
    % Min and max column numbers in the full image.
    col_min = max([1, xMin(k)]);
    col_max = min([imageWidth, xMax(k)]);
    
    % Number of rows and columns
    num_rows = row_max - row_min + 1;
    num_cols = col_max - col_min + 1;
    
    % Left column and top row
    col_left = 1 - min(0, xMin(k) - 1);
    row_top = 1 - min(0, yMin(k) - 1);
    
    % Populate the temporary region matrix
    region_mat_temp(row_top : (row_top + num_rows - 1), ...
        col_left : (col_left + num_cols - 1)) = image_subregion;
    
    % Populate the full region matrix
    REGIONMATRIX(:, :, k) =  region_mat_temp;
end

end




