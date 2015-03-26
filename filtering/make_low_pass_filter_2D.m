function FILTER = make_low_pass_filter_2D(IMAGE_HEIGHT, IMAGE_WIDTH,...
    CUTOFF)
% This function creates a circular low-pass filter to be applied to the
% Fourier Transform (FT) of a 2-D image. Multiplying this filter
% element-wise by the 2-D FT of an image attenuates the quickly-changing
% ("high-frequency") featues in the image, and preserves the
% slowly-changing ("low-frequency") features. One typical use of a
% low-pass filter could be to suppress noise or sharp lines in an image.
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
%       This filter is set to one for radial coordinates less than CUTOFF,
%       and set to zero for radial coordinates greater than CUTOFF, with
%       the origin of the radial coordinate system located at the center
%       of the array.
%
% OUTPUTS
%   FILTER = Array with IMAGE_HEIGHT rows and IMAGE_WIDTH columns
%       representing the low-pass filter. 
%
% SEE ALSO
%   make_high_pass_filter_2D, make_band_pass_filter_2D, 
%   make_band_block_filter_2D

% Create and invert a high-pass filter to create a low-pass filter.
FILTER = 1 - make_high_pass_filter_2D(IMAGE_HEIGHT, IMAGE_WIDTH, ...
    CUTOFF);

end


