function [phase_mask, phase_quality, phase_angle] = ...
    calculate_apc_phase_mask_from_correlation(complex_correlation, ...
    kernel_radius, phase_mask_method, max_std)

% Kernel length
kernel_length = 2 * kernel_radius + 1;

% Default to no maximum standard deviation
if nargin < 4
    max_std = inf;
end

% Phase angle
phase_angle = angle(phaseOnlyFilter(complex_correlation));

% Calculate the phase quality
phase_quality = calculate_phase_quality(phase_angle, kernel_length);

switch lower(phase_mask_method)
    case 'symmetric'
        
        % Calculate the phase mask.
        phase_mask = calculate_phase_mask_gaussian_symmetric...
            (phase_quality, kernel_radius, max_std);
        
    case 'ellipse'
     
        % Calculate the phase mask.
        phase_mask = calculate_phase_mask_gaussian_ellipse...
            (phase_quality, kernel_radius, max_std);
end
        
end