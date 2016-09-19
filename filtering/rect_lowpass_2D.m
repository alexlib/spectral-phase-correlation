function F = rect_lowpass_2D(DIMENSIONS, WINDOWSIZE, WINDOWTYPE)
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
region_height = DIMENSIONS(1);
region_width  = DIMENSIONS(2);

% Determine whether window size is an absolute size or a fraction of the
% window dimensions
if strcmp(WINDOWTYPE, 'fraction')
    windowSizeX = region_width  .* WINDOWSIZE(2);
    windowSizeY = region_height .* WINDOWSIZE(1);
elseif strcmp(WINDOWTYPE, 'pixels');
    windowSizeX = WINDOWSIZE(2);
    windowSizeY = WINDOWSIZE(1);
else
    error('Invalid window type "%s"\n', WINDOWTYPE);
end

% Calculate center of signal
xc = (region_width + 1) / 2 + 0.5 * (1 - mod(region_width, 2));
yc = (region_height + 1) / 2 + 0.5 * (1 - mod(region_height, 2));

% Create grid of x,y positions to hold gaussian filter data
[x,y] = meshgrid(1:region_width, 1:region_height);

% Shifted coordinates
X = x - xc;
Y = y - yc;

x_min = -1 * windowSizeX/2;
x_max = windowSizeX/2 - 1;

y_min = -1 * windowSizeY / 2;
y_max = windowSizeY/2 - 1;

F = zeros(size(x));

F(X >= x_min &...
    X <= x_max & ...
    Y >= y_min & ...
    Y <= y_max) = 1;

end




