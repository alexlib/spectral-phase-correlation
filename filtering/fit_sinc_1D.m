function [AMPLITUDE, SX, ARRAY] = fit_sinc_1D(INPUT_SIGNAL)
% This function determines the amplitude and standard deviation
% of the best fit 2-D Gaussian to a 2-D signal.

% Size of the domain
[region_width] = length(INPUT_SIGNAL);

% % Zero frequency pixels
xc = (region_width  + 1) / 2 + 1/2 * (1 - mod(region_width,  2));

% Domain
xdata = (1 : region_width)';

% Amplitude guess
amplitude_guess = max(INPUT_SIGNAL);

% Width guess
sx_guess = 1 / (pi);

% Offset guess
% offset_guess = min(INPUT_SIGNAL);

% Guesses
x0 = [amplitude_guess, sx_guess];

% Input function data
ydata = INPUT_SIGNAL;

% Tell the solver to not print outputs
opts = optimset('Display','off');

% Run the solver
params = lsqcurvefit(@sinc_fun,x0,xdata,ydata, [], [], opts);

% Outputs
AMPLITUDE = params(1);
SX = params(2);

% Caluclate the sinc function
ARRAY = AMPLITUDE * sinc((xdata - xc)/ (SX)); 

end


function F = sinc_fun(x, xdata)
% This function is for least-squares fitting of a 2-D Gaussian
    
    % Gaussian coefficients
    
    % Amplitude
    A = x(1);
    sx = x(2);
%     offset = x(3);
    
    % X is the coordinate data
    X = xdata(:);
    
    % Region height and width
    region_width = length(X);
    
    % Domain center
    xc = (region_width  + 1) / 2 + 1/2 * (1 - mod(region_width,  2));

    % Sinc functions
    F = A * sinc((xdata - xc) / sx);
    
   	   
end

    




