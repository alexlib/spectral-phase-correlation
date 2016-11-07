function [AMPLITUDE, STD_DEV_Y, STD_DEV_X, OFFSET, THETA, ARRAY] = fit_gaussian_2D_elliptical(INPUT_SIGNAL, STD_DEV_GUESS)
% This function determines the amplitude and standard deviation
% of the best fit 2-D Gaussian to a 2-D signal.

% Size of the domain
[region_height, region_width] = size(INPUT_SIGNAL);

% Coordinate vectors
xv = ((1 : region_width) - fourier_zero(region_width));
yv = ((1 : region_height) - fourier_zero(region_height));

% Coordinate matrix
[X, Y] = meshgrid(xv, yv);

% Reshape the data into vectors
xdata = [Y(:), X(:)];

if nargin < 2
    % Std devation guess
    std_dev_guess = [region_height / 4, region_width / 4];
else
    
    % If only one element is provided for STD DEV GUESS
    % then assume the user means "symmetric standard deviation"
    if length(STD_DEV_GUESS) == 1
        std_dev_guess = STD_DEV_GUESS * [1, 1];
    else
        std_dev_guess = STD_DEV_GUESS;
    end
    
end

% Amplitude guess
amplitude_guess = prctile(INPUT_SIGNAL(:), 95);

% Offset guess
offset_guess = prctile(INPUT_SIGNAL(:), 10);

% Theta guess
theta_guess = 0;

% Guesses
x0 = [amplitude_guess; std_dev_guess(:); theta_guess; offset_guess];

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
AMPLITUDE = params(1);
STD_DEV_Y = abs(params(2));
STD_DEV_X = abs(params(3));
THETA = params(4);
OFFSET = params(5);

x_angle = X * cos(THETA) - Y * sin(THETA);
y_angle = X * sin(THETA) + Y * cos(THETA);

% Caluclate the gaussian
ARRAY = (AMPLITUDE * exp(-x_angle.^2 / (2 * STD_DEV_X^2)) .* ...
    exp(-y_angle.^2 / (2 * STD_DEV_Y^2))) + OFFSET;

end

function [F] = gauss_fun(x, xdata)
% This function is for least-squares fitting of a 2-D Gaussian
    
    % Gaussian coefficients

    % Amplitude
    A = x(1);

    % Standard deviation in the rows direction
    sy = x(2);

    % Standard deviation in the columns direction
    sx = x(3);
    
    % Theta
    TH = x(4);

    % Zero offset (minimum value)
    B = x(5);

    % X is the X coordinate
    X = xdata(:, 2);

    % Y is the Y coordinate
    Y = xdata(:, 1);
    
    x_angle = X * cos(TH) - Y * sin(TH);
    y_angle = X * sin(TH) + Y * cos(TH);
    
    % This is the Gaussian function
    F = B + A * exp(- y_angle.^2 ./ (2 * sy^2)) .* ...
        exp(-x_angle.^2 ./ (2 * sx^2));




end

    




