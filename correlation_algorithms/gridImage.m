function [ X, Y ] = gridImage(IMAGESIZE, GRIDSPACING, GRIDBUFFERY, GRIDBUFFERX)
% function [ X, Y ] = gridImage(IMAGESIZE, GRIDSPACING, GRIDBUFFERY, GRIDBUFFERX, GRIDSHIFTY, GRIDSHIFTX)
%Generates a grid of points 
% INPUTS
%   IMAGESIZE = 2 x 1 vector of integers specifying image size (L = [height, width]);
%   GRIDSPACING = 2 x 1 vector of integers specifying grid spacing (S = [dy, dx]);
%   GRIDBUFFER = 2 x 1 vector of integers specifying the grid buffer (G = [Gy Gx]);

% if nargin < 6
%     GRIDSHIFTX = 0;
% end
% 
% if nargin < 5
%   GRIDSHIFTY = 0;
% end

if nargin < 4
    GRIDBUFFERX = [ 0 0 ];
end

% Grid buffers
if nargin < 3
    GRIDBUFFERY = [ 0 0 ];
end

% Image height and width
imageHeight = IMAGESIZE(1);
imageWidth = IMAGESIZE(2);

% Vertical and horizontal grid spacing.
gridSpacingY = GRIDSPACING(1);
gridSpacingX = GRIDSPACING(2);

% Left and right horizontal grid buffers.
gridBufferXLeft = GRIDBUFFERX(1);
gridBufferXRight = GRIDBUFFERX(2);

% Top and bottom vertical grid buffers.
gridBufferYTop = GRIDBUFFERY(1);
gridBufferYBottom = GRIDBUFFERY(2);

% Grid buffer vector
GRIDBUFFER = [gridBufferYTop, gridBufferXLeft, imageHeight-gridBufferYBottom+1, imageWidth-gridBufferXRight+1];

% Create grid.
if max(GRIDSPACING)==0
    %pixel grid
    y = (1 : imageHeight)';
    x = 1 : imageWidth;
else
    if GRIDBUFFER(1)==0
        %buffers 1/2 grid spacing
        y = (ceil((imageHeight-(floor(imageHeight/gridSpacingY)-2)*gridSpacingY)/2):gridSpacingY:(imageHeight-gridSpacingY))';
    else
        %predefined grid buffer
        y = (GRIDBUFFER(1):gridSpacingY:GRIDBUFFER(3))';
    end
    if GRIDBUFFER(2)==0
        %buffers 1/2 grid spacing
        x = ceil((imageWidth-(floor(imageWidth/gridSpacingX)-2)*gridSpacingX)/2):gridSpacingX:(imageWidth-gridSpacingX);
    else
        %predefined grid buffer
        x = (GRIDBUFFER(2):gridSpacingX:GRIDBUFFER(4));
    end
end

% This is a fast version of REPMAT, 
% used here to convert the coordinates into a grid.
X = x( ones( length(y) , 1 ), : );
Y = y( : , ones(1 , length(x) ) );



end







