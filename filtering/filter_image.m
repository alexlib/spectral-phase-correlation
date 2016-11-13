function IMAGE_OUT = filter_image(IMAGE_IN, FILTER)

% Make sure the image and filter are the same size.
if size(IMAGE_IN) ~= size(FILTER)
    error('Error in filter_image: IMAGE_IN and FILTER must be same size.');
end

% Calculate the FT of the image
image_ft = fftshift(fft2(IMAGE_IN));

% Multiply the image FT by the filter
ft_filtered = image_ft .* FILTER;

% Invert the FT
IMAGE_OUT = real(ifft2(fftshift(ft_filtered)));


end