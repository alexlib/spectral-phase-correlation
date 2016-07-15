function [AMPLITUDE, ARRAY] = fit_sinc_2D(INPUT_SIGNAL)
% This function determines the amplitude and standard deviation
% of the best fit 2-D Gaussian to a 2-D signal.

% Size of the domain
[region_height, region_width] = size(INPUT_SIGNAL);

% % Zero frequency pixels
yc = (region_height + 1) / 2 + 1/2 * (1 - mod(region_height, 2));
xc = (region_width  + 1) / 2 + 1/2 * (1 - mod(region_width,  2));

% Domain as matrices
[X, Y] = meshgrid(1 : region_width, 1 : region_height);

% Reshape the data into vectors
xdata = [Y(:), X(:)];

% Amplitude guess
amplitude_guess = max(INPUT_SIGNAL(:));

% Guesses
x0 = [amplitude_guess, sy, sx];

% Input function data
ydata = INPUT_SIGNAL(:);

% Tell the solver to not print outputs
opts = optimset('Display','off');

% Run the solver
params = lsqcurvefit(@sinc_fun,x0,xdata,ydata, [], [], opts);

% Outputs
AMPLITUDE = params(1);

% Caluclate the sinc function
sinc_x = sinc((X - xc) * 2 * pi * sx / region_width); 
sinc_y = sinc((Y - yc) * 2 * pi * sy / region_height);

ARRAY = AMPLITUDE * sinc_x.^2 .* sinc_y.^2;

end


function F = sinc_fun(x, xdata)
% This function is for least-squares fitting of a 2-D Gaussian
    
    % Gaussian coefficients
    
    % Amplitude
    A = x(1);
    sy = x(2);
    sx = x(3);
    % X is the coordinate data
    X = xdata(:, 2);
    
    % Y is the data to be fit, 
    % i.e. the measured data
    Y = xdata(:, 1);
    
    % Region height and width
    region_height = max(Y) - min(Y) + 1;
    region_width = max(X) - min(X) + 1;
    
    % Domain center
    yc = (region_height + 1) / 2 + 1/2 * (1 - mod(region_height, 2));
    xc = (region_width  + 1) / 2 + 1/2 * (1 - mod(region_width,  2));

    % Sinc functions
    sinc_x = sinc((X - xc) * 2 * pi * sx / region_width); 
    sinc_y = sinc((Y - yc) * 2 * pi * sy / region_height);

    % This is the Gaussian function
	F =  A * sinc_x.^2 .* sinc_y.^2;
		   
		   
end

    




