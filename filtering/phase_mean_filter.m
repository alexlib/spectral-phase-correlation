function FILTERED_PHASE_ANGLE_PLANE = phase_mean_filter(WRAPPED_PHASE_PLANE_COMPLEX, KERNEL_SIZE);

% Make a convolution kernel
KERNEL = ones(KERNEL_SIZE) ./ prod(KERNEL_SIZE);

% Signal magnitude
sig_mag_norm = WRAPPED_PHASE_PLANE_COMPLEX ./ ...
    sqrt(real(WRAPPED_PHASE_PLANE_COMPLEX).^2 + ...
    imag(WRAPPED_PHASE_PLANE_COMPLEX).^2);

% Take the arctangent of the two signals
FILTERED_PHASE_ANGLE_PLANE = atan2(conv2(imag(sig_mag_norm), ...
    KERNEL, 'same'), conv2(real(sig_mag_norm), KERNEL, 'same'));

end