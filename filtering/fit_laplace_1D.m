function [A, B, XO, OFFSET, ARRAY] = fit_laplace_1D(INPUT_SIGNAL,XDATA)
% This function determines the amplitude and standard deviation
% of the best fit 2-D Gaussian to a 2-D signal.

% Size of the domain
region_width = length(INPUT_SIGNAL);

if nargin < 2
% Coordinate vectors
    xdata = ((1 : region_width))';
else
    xdata = XDATA(:);
end

% Amplitude guess
amplitude_guess = prctile(INPUT_SIGNAL(:), 95);

b_guess = 1;


% Offset guess
% offset_guess = prctile(INPUT_SIGNAL(:), 10);
offset_guess = 0;

% Centroid guess
xo_guess = median(xdata);

% Guesses
x0 = [amplitude_guess; b_guess; xo_guess; offset_guess];

% Input function data
ydata = INPUT_SIGNAL(:);

% Tell the solver to not print outputs
opts = optimset('Display','off', ...
    'UseParallel', false, ...
    'algorithm', 'levenberg-marquardt', ...
    'Jacobian', 'off');

% Run the solver
params = lsqcurvefit(@gauss_fun, x0, xdata, ydata, [], [], opts);

% Outputs
A = params(1);
B = params(2);
XO = abs(params(3));
OFFSET = params(4);

% Caluclate the gaussian
ARRAY = A * exp(- abs((xdata - XO) / B) / (2 * B)) + OFFSET;

end

function [F] = gauss_fun(x, xdata)
% This function is for least-squares fitting of a 2-D Gaussian
    
    % Gaussian coefficients

    % Amplitude
    A = x(1);
    
    b = x(2);
    
    % Centroid
    xo = x(3);

    % Zero offset (minimum value)
    offset = x(4);

    % X is the coordinate data
    X = xdata;

    % This is the Gaussian function
    F = A * exp(- abs((X - xo) / b) / (2 * b)) + offset;

end

    




