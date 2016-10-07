function [AMPLITUDE, STD_DEV_Y, STD_DEV_X, YC, XC, OFFSET, ARRAY] = fit_gaussian_2D(INPUT_SIGNAL, STD_DEV_GUESS)
% This function determines the amplitude and standard deviation
% of the best fit 2-D Gaussian to a 2-D signal.

% Size of the domain
[region_height, region_width] = size(INPUT_SIGNAL);

xv2 = ((1 : region_width) - fourier_zero(region_width)).^2;
yv2 = ((1 : region_height) - fourier_zero(region_height)).^2;

[X2, Y2] = meshgrid(xv2, yv2);

% Reshape the data into vectors
xdata = [Y2(:), X2(:)];

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
amplitude_guess = max(INPUT_SIGNAL(:));

% Offset guess
offset_guess = min(INPUT_SIGNAL(:));

% Guesses
x0 = [amplitude_guess; std_dev_guess(:); offset_guess];

% Input function data
ydata = INPUT_SIGNAL(:);

% Tell the solver to not print outputs
opts = optimset('Display','off');

% Run the solver
params = lsqcurvefit(@gauss_fun,x0,xdata,ydata, [], [], opts);

% Outputs
AMPLITUDE = params(1);
STD_DEV_Y = abs(params(2));
STD_DEV_X = abs(params(3));
OFFSET = params(4);

% Caluclate the gaussian
ARRAY = (AMPLITUDE * exp(-X2 / (2 * STD_DEV_X^2)) .* exp(-Y2 / (2 * STD_DEV_Y^2))) + OFFSET;

end


function F = gauss_fun(x, xdata)
% This function is for least-squares fitting of a 2-D Gaussian
    
    % Gaussian coefficients

    % Amplitude
    A = x(1);
    
    % Standard deviation in the rows direction
    sy = x(2);
    
    % Standard deviation in the columns direction
    sx = x(3);
    
    % Zero offset (minimum value)
    B = x(4);
    
    % X is the coordinate data
    X2 = xdata(:, 2);
    
    % Y is the data to be fit, 
    % i.e. the measured data
    Y2 = xdata(:, 1);

    % This is the Gaussian function
	F = B + A * exp(- Y2 ./ (2 * sy^2)) .* ...
           exp(-X2 ./ (2 * sx^2));
		   
		   
		   
end

    




