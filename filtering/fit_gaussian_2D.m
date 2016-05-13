function [AMPLITUDE, STD_DEV_Y, STD_DEV_X] = fit_gaussian_2D(INPUT_SIGNAL)
% This function determines the amplitude and standard deviation
% of the best fit 2-D Gaussian to a 2-D signal.

% Size of the domain
[region_height, region_width] = size(INPUT_SIGNAL);

% Zero frequency pixels
yc = (region_height + 1) / 2 + 1/2 * (1 - mod(region_height, 2));
xc = (region_width  + 1) / 2 + 1/2 * (1 - mod(region_width,  2));

% Domain as matrices
[X, Y] = meshgrid(1 : region_width, 1 : region_height);

% Reshape the data into vectors
xdata = [Y(:), X(:)];

% This is the function to be fit
fun = @(x,xdata)...
    x(1) * exp(-(xdata(:, 1) - yc).^2 ./ (2 * x(2)^2)) .* ...
           exp(-(xdata(:, 2) - xc).^2 ./ (2 * x(3)^2));
     
% Std devation guess
std_dev_guess = [region_height / 2, region_width / 2];

% Amplitude guess
amplitude_guess = max(INPUT_SIGNAL(:));

% Guesses
x0 = [amplitude_guess; std_dev_guess(:)];

% Input function data
ydata = INPUT_SIGNAL(:);

% Tell the solver to not print outputs
opts = optimset('Display','off');

% Run the solver
params = lsqcurvefit(fun,x0,xdata,ydata, [], [], opts);

% Outputs
AMPLITUDE = params(1);
STD_DEV_Y = params(2);
STD_DEV_X = params(3);

end






