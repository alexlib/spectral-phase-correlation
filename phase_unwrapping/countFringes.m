function [N_FRINGES_LEFT, N_FRINGES_RIGHT] = countFringes(TY, TX, IMAGESIZE)
% This function calculates the number of fringes that should
% appear in a 2D 2pi-wrapped phase plane.

% Height and width of the image
width  = IMAGESIZE(2);
height = IMAGESIZE(1);

% Zero frequency pixel coordinates
uc =  width/2 + 1 - 0.5 * mod(width, 2);
vc = height/2 + 1 - 0.5 * mod(height, 2);

% Number of fringes to the left of the origin
N_FRINGES_LEFT = floor(abs(TY)/height * (height/2) ...
    + abs(TX)/width * (width/2) + 1/2);

% Number of fringes to the right of the origin.
N_FRINGES_RIGHT = floor(abs(TY)/height * (height/2 - (2 * vc - height - 1)) ...
    + abs(TX)/width * (width/2 - (2 * uc - width - 1)) + 1/2);

end













