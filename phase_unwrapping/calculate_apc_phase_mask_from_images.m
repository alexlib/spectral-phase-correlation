function [phase_mask, phase_quality, phase_angle] = ...
    calculate_apc_phase_mask_from_images(imageMatrix1, imageMatrix2,...
    region_window, kernel_radius, phase_mask_method);

% Measure region dimensions
[region_height, region_width, num_regions] = size(imageMatrix1);

complex_phase = zeros(region_height, region_width);

% Calculate all the phase qualities
% 
for k = 1 : num_regions

    % Extract the subregions
    I1 = region_window .* zero_mean_region(double(imageMatrix1(:, :, k)));
    I2 = region_window .* zero_mean_region(double(imageMatrix2(:, :, k)));
    
    % Zero mean
    
    % Add the complex phase
    complex_phase = ...
       complex_phase + phaseCorrelation(I1, I2);
       
end

% Calculate the phase angle
phase_angle = fftshift(angle(complex_phase));

% Calculate the phase quality
phase_quality = calculate_phase_quality_mex(phase_angle, kernel_radius);


switch lower(phase_mask_method)
    case 'gaussian'
                % Calculate the phase mask.
        phase_mask = calculate_phase_mask_gaussian...
            (phase_quality, kernel_radius);
        
    case 'ellipse'
        
        % Calculate the phase mask.
        phase_mask = calculate_phase_mask_ellipse...
            (phase_quality, kernel_radius);

end
        




end