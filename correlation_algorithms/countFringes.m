function NFRINGES = countFringes(TY, TX, IMAGESIZE)
% This function calculates the number of fringes that should
% appear in a 2D 2pi-wrapped phase plane.

% Calculate the angle between the horizontal and vertical translations
th = atan2(TY, TX);

% Height and width of the image
width  = IMAGESIZE(2);
height = IMAGESIZE(1);

% Zero frequency pixel coordinates
uc =  width/2 + 1 - 0.5 * mod(width, 2);
vc = height/2 + 1 - 0.5 * mod(height, 2);

% Absolute normalized components of the vector
abs_cos_angle = abs(cos(th));
abs_sin_angle = abs(sin(th));

% Calculate the vector magnitude (pixel units)
if (width / 2 * abs_sin_angle)  <= (height / 2 * abs_cos_angle) 
   vectorMagnitude_right = (width - uc)  / abs_cos_angle;
   vectorMagnitude_left = (uc - 1) / abs_cos_angle;
else
   vectorMagnitude_right = (height - vc) / abs_sin_angle;
   vectorMagnitude_left = (vc - 1) / abs_sin_angle;
end

% Calculate the components of the
% gradient of the unwrapped phase plane
dpdu = - 2 * pi * TX / width;
dpdv = - 2 * pi * TY / height;

% Vector gradient of the phase plane
gradp = [dpdu; dpdv];

% Magnitude of the vector gradient
% of the phase plane
gradp_mag = norm(gradp);

% Total function increase from the zero-frequency,
% in multiples of pi
n_01 = gradp_mag * vectorMagnitude_right / pi;
n_02 = gradp_mag * vectorMagnitude_left / pi;

% Number of fringes before and after the zero frequency
n_fringes_01 = floor((n_01 + 1)/2);
n_fringes_02 = floor((n_02 + 1)/2);

% Number of fringes in the image
NFRINGES = n_fringes_01 + n_fringes_02;


end













