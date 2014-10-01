function KERNEL = makeKernel(ORDER, SCALE, RADIUS)
% makeKernel(ORDER, SCALE) calculates a 1-D analytically-differentiated gaussian convolution kernel.
% 
% INPUTS
%   ORDER = Order of differentiation of the gaussian kernel, with 0 ? ORDER ? 2
% 
%   SCALE = Standard deviation of the gaussian convolution kernel (pixels).
% 
%   RADIUS = Kernel radius (pixels). The default kernel radius is 4 pixels. To enforce an odd-numbered kernel length, the length of the kernel is 2 * RADIUS + 1. 
% 
% OUTPUTS
%   KERNEL = 1-D analytically differentated gaussian convolution kernel.
%
% SEE ALSO
%   imdifferentiate

%%%%%%%%%%%%%%%%%%%%%%
%%% BEGIN FUNCTION %%%
%%%%%%%%%%%%%%%%%%%%%%

is2 = 1 / (SCALE * SCALE); % kernel standard deviation squared
mis2 = -0.5 * is2; % negative half of the inverse of the standard deviation squared 
sq2pi = sqrt(2 * pi); % Square root of 2 * Pi

% Default to a kernel radius of 4 pixels
if nargin < 3
    RADIUS = 4; 
end

x = - RADIUS : RADIUS;  % Populate kernel radius as a column vector
% x = 0 : r; % Populate kernel radius as a column vector. Only populate half of the kernel because we know it's symmetric or antisymmetric.
KERNEL = zeros(length(x), 1); % Initialize kernel

% Zero order derivative
if ORDER == 0;
    for k = 1: length(x);
        x2 = x(k) * x(k);
        KERNEL(k) = exp( x2 * mis2 );
    end
    KERNEL = KERNEL ./ sum(KERNEL(:)); % Normalize kernel

% First derivative kernel
elseif ORDER == 1;
    c =  is2 / (sq2pi * SCALE); % Normalization coefficient
    for k = 1: length(x);
        x2 = x(k) * x(k);
        KERNEL(k) =  c * x(k) * exp(x2 * mis2);
    end

% Second derivative kernel
elseif ORDER == 2;
    c = is2 / (sq2pi * SCALE); % Normalization coefficient
    for k = 1: length(x);
        x2 = x(k) * x(k);
        KERNEL(k) =  c * (x2 * is2 - 1) * exp(x2 * mis2);
    end

else
% Throw error if derivative order is greater than 2, because higher
% derivatives haven't been programmed here yet. 
    error('Error in kernel.m: derivative order must be less than or equal to 2.'); 
end

end

%%%%%%%%%%%%%%%%%%%%
%%% END FUNCTION %%%
%%%%%%%%%%%%%%%%%%%%
