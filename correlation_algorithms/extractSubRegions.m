function REGIONMATRIX = extractSubRegions(IMAGE, REGIONSIZE, GRID_POINTS_X, GRID_POINTS_Y)
% This function extracts subregions from an image.


% Determine the size of the image.
[imageHeight, imageWidth] = size(IMAGE);

% Make grid points into column vectors
gx = GRID_POINTS_X(:);
gy = GRID_POINTS_Y(:);

% Number of regions
nRegions = length(gx);

% Sub region height and width
regionHeight = REGIONSIZE(1);
regionWidth  = REGIONSIZE(2);

% Determine the leftmost and rightmost columns of the interrogation regions
% (first image)
xMin = gx -  ceil(regionWidth / 2 ) + 1;
xMax = gx + floor(regionWidth / 2 );

% Determine the top and bottom rows of the interrogation regions
% (first image)
yMin = gy -  ceil(regionHeight / 2 ) + 1;
yMax = gy + floor(regionHeight / 2 );

% Initialze a matrix for holding a stack of subregions.
REGIONMATRIX = zeros(regionHeight, regionWidth, nRegions);

% Create stacks of the subregions.
% This is done so that individual subregions (rather than entire images)
% can be passed to the parfor loop. 
for k = 1 : nRegions  
    REGIONMATRIX(:, :, k) = IMAGE( max([1, yMin(k)]) : min([imageHeight, yMax(k)]) , max([1, xMin(k)]) : min([imageWidth, xMax(k)]) ); 
end

end