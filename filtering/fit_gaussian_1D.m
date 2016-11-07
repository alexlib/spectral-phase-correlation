function [AMPLITUDE, STD_DEV, CENTROID, OFFSET, ARRAY] = fit_gaussian_1D(INPUT_SIGNAL,XDATA)
% This function determines the amplitude and standard deviation
% of the best fit 2-D Gaussian to a 2-D signal.

% Size of the domain
region_width = length(INPUT_SIGNAL);

if nargin < 2
% Coordinate vectors
    XDATA = (1 : region_width);
end

std_dev_guess = (max(XDATA) - min(XDATA)) / 6;

% if nargin < 2
%     % Std devation guess
%     std_dev_guess = [region_width / 4];
% else
%     % Take the user input
%     std_dev_guess = STD_DEV_GUESS;
%     
% end

% Amplitude guess
amplitude_guess = prctile(INPUT_SIGNAL(:), 95);

% Offset guess
% offset_guess = prctile(INPUT_SIGNAL(:), 10);
offset_guess = 0;

% Centroid guess
xo_guess = median(XDATA);

% Guesses
x0 = [amplitude_guess; std_dev_guess; xo_guess; offset_guess];

% Input function data
ydata = INPUT_SIGNAL(:);

% Tell the solver to not print outputs
opts = optimset('Display','off', ...
    'UseParallel', false, ...
    'algorithm', 'levenberg-marquardt', ...
    'Jacobian', 'off');

% Run the solver
params = lsqcurvefit(@gauss_fun, x0, XDATA(:), ydata(:), [], [], opts);

% Outputs
AMPLITUDE = params(1);
STD_DEV = abs(params(2));
CENTROID = params(3);
OFFSET = params(4);

% Caluclate the gaussian
ARRAY = AMPLITUDE * exp(-(XDATA - CENTROID).^2 / (2 * STD_DEV^2)) + OFFSET;

end

function [F] = gauss_fun(x, xdata)
% This function is for least-squares fitting of a 2-D Gaussian
    
    % Gaussian coefficients

    % Amplitude
    A = x(1);
    
    % Standard deviation in the columns direction
    sx = x(2);
    
    xo = x(3);

    % Zero offset (minimum value)
    B = x(4);

    % X is the coordinate data
    X = xdata;

    % This is the Gaussian function
    F = B + A * exp(-(X - xo).^2 ./ (2 * sx^2));

end

    




