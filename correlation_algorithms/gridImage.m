function [X, Y] = gridImage(IMAGESIZE, GRIDSPACING, GRIDBUFFERY, GRIDBUFFERX, MASK);

% Default to no mask
if nargin < 5
    MASK = ones(IMAGESIZE);
elseif isempty(MASK)
    MASK = ones(IMAGESIZE);
end
   
if nargin < 4 || isempty(GRIDBUFFERX);
    GRIDBUFFERX = [ 0 0 ];
end

% Grid buffers
if nargin < 3 || isempty(GRIDBUFFERY);
    GRIDBUFFERY = [ 0 0 ];
end

% Image height and width
imageHeight = IMAGESIZE(1);
imageWidth = IMAGESIZE(2);

% Left and right horizontal grid buffers.
gridBufferXLeft = GRIDBUFFERX(1);
gridBufferXRight = GRIDBUFFERX(2);

% Top and bottom vertical grid buffers.
gridBufferYTop = GRIDBUFFERY(1);
gridBufferYBottom = GRIDBUFFERY(2);

% Grid buffer vector
GRIDBUFFER = [gridBufferYTop, gridBufferXLeft, ...
    imageHeight-gridBufferYBottom+1, imageWidth-gridBufferXRight+1];

% Min and max x coordinates
xmin = max([1, GRIDBUFFERX(1)]);
xmax = min([imageWidth, imageWidth - GRIDBUFFERX(2)]);

% Min and max y coordinates
ymin = max([1, GRIDBUFFERY(1)]);
ymax = min([imageHeight, imageHeight - GRIDBUFFERY(2)]);

% Grid spacing in x and y directions
dx = max(1, GRIDSPACING(2));
dy = max(1, GRIDSPACING(1));

% X and Y coordinate vectors
xgv = xmin : dx : xmax;
ygv = ymin : dy : ymax;

% Grid as matrices
[xmat, ymat] = meshgrid(xgv, ygv);

% Grids as vectors
xv = xmat(:);
yv = ymat(:);

% Linear indices of the grid
full_inds = sub2ind([imageHeight, imageWidth], yv, xv);

% Values of the mask
mask_vals = MASK(full_inds);

% Nonzero parts of the mask
inds = find(mask_vals ~= 0);

% The unmaxked coordinates.
X = xv(inds);
Y = yv(inds);

end







