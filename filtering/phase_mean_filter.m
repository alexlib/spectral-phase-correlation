function FILTERED_COMPLEX_PHASE_PLANE = phase_mean_filter(...
    WRAPPED_PHASE_PLANE_COMPLEX, KERNEL_SIZE);

% Make a convolution kernel
KERNEL = ones(KERNEL_SIZE) ./ prod(KERNEL_SIZE);

% Signal magnitude
sig_mag_norm = WRAPPED_PHASE_PLANE_COMPLEX ./ ...
    sqrt(real(WRAPPED_PHASE_PLANE_COMPLEX).^2 + ...
    imag(WRAPPED_PHASE_PLANE_COMPLEX).^2);

% Take the arctangent of the two signals
FILTERED_COMPLEX_PHASE_PLANE = ...
    conv2(real(sig_mag_norm), KERNEL, 'same') + ...
    1i * conv2(imag(sig_mag_norm), KERNEL, 'same');

end