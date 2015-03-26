function FILTER = make_high_pass_filter_2D(IMAGE_HEIGHT, IMAGE_WIDTH,...
    CUTOFF)
% This function creates a circular high-pass filter to be applied to the
% Fourier Transform (FT) of a 2-D image. Multiplying this filter
% element-wise by the 2-D FT of an image preserves the quickly-changing
% ("high-frequency") featues in the image, and attenuates the
% slowly-changing ("low-frequency") features. One typical use of a
% high-pass filter could be to suppress background intensities in images
% and simultaneously to highlight edges. 
%
% INPUTS
%   IMAGE_HEIGHT = Height (number of rows) of the filter in pixels
%       (integer). This should be the same as the height of the FT of
%       the image to be filtered.
%
%   IMAGE_WIDTH = Width (number of columns) of the filter in pixels
%       (integer). This should be the same as the width of the FT of
%       the image to be filtered.
%
%   CUTOFF = Cutoff frequency of the radial filter (positive number).
%       This filter is set to zero for radial coordinates less than CUTOFF,
%       and set to one for radial coordinates greater than CUTOFF, with
%       the origin of the radial coordinate system located at the center
%       of the array.
%
% OUTPUTS
%   FILTER = Array with IMAGE_HEIGHT rows and IMAGE_WIDTH columns
%       representing the high-pass filter. 
%
% SEE ALSO
%   make_low_pass_filter_2D, make_band_pass_filter_2D, 
%   make_band_block_filter_2D

% Create an array with the same dimensions as the image
% 
% u is the wave number in the horizontal direction (i.e., across columns)
% v is the wave number in the vertical direction   (i.e., across rows)
[u, v] = meshgrid(1 : IMAGE_WIDTH, 1 : IMAGE_HEIGHT);

% Calculate the coordinates of the zero-frequency pixels
% in a 2-D Fourier Transform calculated by Matlab.
% Matlab puts the zero-frequency pixel at (length / 2) + 1
% for array dimensions with even numbers of elements, 
% and at (length / 2) + 0.5 for array dimensions with
% odd numbers of elements.
u_zero = calculate_ft_zero_pixels(IMAGE_WIDTH);
v_zero = calculate_ft_zero_pixels(IMAGE_HEIGHT);

% Calculate the radial coordinate of the array
r = sqrt((u - u_zero).^2 + (v - v_zero).^2);

% Create an array that is one where r > CUTOFF
% and zero where r < CUTOFF. This array is the high-pass
% filter, which should be multiplied element-wise by the
% FT of the image that's being filtered.
FILTER = double(r > CUTOFF);

end


