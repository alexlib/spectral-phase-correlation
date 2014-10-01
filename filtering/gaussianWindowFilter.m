function WINDOW = gaussianWindowFilter(DIMENSIONS, WINDOWSIZE, WINDOWTYPE)
% gaussianWindowFilter(DIMENSIONS, WINDOWSIZE, WINDOWTYPE) creates a 2-D
% gaussian window
%
% INPUTS
%   DIMENSIONS = 2 x 1 Vector specifying  the Dimensions (in rows and columns) of the gaussian window filter
%   WINDOWSIZE = 2 x 1 vector specifying the effective window resolution of
%   the gaussian window. WINDOWSIZE can either specify the resolution in
%   pixels or as a fraction of the filter dimensions. This option is
%   controlled by the input WINDOWTYPE.
%   WINDOWTYPE = String specifying whether WINDOWSIZE specifies a
%   resolution in pixels ('pixels') or as a fraction of the window
%   dimensions ('fraction').
% 
% OUTPUTS
%   WINDOW = 2-D gaussian window
% 
% SEE ALSO
%   findwidth

% Default to an absolute size window type
if nargin < 3
    WINDOWTYPE = 'fraction';
end

% Signal height and width
height = DIMENSIONS(1);
width = DIMENSIONS(2);

% Determine whether window size is an absolute size or a fraction of the
% window dimensions
if strcmp(WINDOWTYPE, 'fraction')
    windowSizeX = width .* WINDOWSIZE(2);
    windowSizeY = height .* WINDOWSIZE(1);
elseif strcmp(WINDOWTYPE, 'pixels');
    windowSizeX = WINDOWSIZE(2);
    windowSizeY = WINDOWSIZE(1);
else
    error('Invalid window type "%s"\n', WINDOWTYPE);
end

% Standard deviations
[sy, sx] = findGaussianWidth(height, width, windowSizeY, windowSizeX);

% Calculate center of signal
xo = round(width/2);
yo = round(height/2);

% Create grid of x,y positions to hold gaussian filter data
[x,y] = meshgrid(1:width, 1:height);

% Calculate gaussian distribution (X)
WindowX = exp( - ((x - xo).^2 / (2 * sx^2)));

% Calculate gaussian distribution (Y)
WindowY = exp( - ((y - yo).^2 / (2 * sy^2)));

% 2-D Gaussian Distribution
WINDOW = WindowX .* WindowY;

end