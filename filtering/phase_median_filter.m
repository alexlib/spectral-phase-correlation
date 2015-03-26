function FILTERED_COMPLEX_PHASE_PLANE = phase_median_filter(...
    WRAPPED_PHASE_PLANE_COMPLEX, KERNEL_SIZE)
% This function applies a median filter calculates the 

% Signal magnitude
sig_mag_norm = WRAPPED_PHASE_PLANE_COMPLEX ./ ...
    sqrt(real(WRAPPED_PHASE_PLANE_COMPLEX).^2 + ...
    imag(WRAPPED_PHASE_PLANE_COMPLEX).^2);

% Calculate the median of the real part of the phase
real_median = medfilt2(real(sig_mag_norm), KERNEL_SIZE);

% Calculate the median of the imaginary part of the phase
imag_median = medfilt2(imag(sig_mag_norm), KERNEL_SIZE);

% Assign the inverse tangent of the real and imaginary medians
% to the solution array.
FILTERED_COMPLEX_PHASE_PLANE = real_median + 1i * imag_median;

end


