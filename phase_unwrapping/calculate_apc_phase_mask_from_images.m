function [phase_mask, phase_quality, phase_angle] = ...
    calculate_apc_phase_mask_from_images(imageMatrix1, imageMatrix2,...
    window, kernel_radius);

% Measure region dimensions
[region_height, region_width, num_regions] = size(imageMatrix1);

complex_phase = zeros(region_height, region_width);

% Calculate all the phase qualities
% 
parfor k = 1 : num_regions
    
    % Inform the user
%     fprintf('Calculating APC phase mask: region %d of %d\n', k, num_regions);
    
    I1 = double(imageMatrix1(:, :, k));
    I2 = double(imageMatrix2(:, :, k));
    
    complex_phase = ...
       complex_phase + phaseCorrelation( (I1 - mean(I1(:))) .* window, ...
      (I2 - mean(I2(:))).* window);
       
end

% Calculate the phase angle
phase_angle = fftshift(angle(complex_phase));

% Calculate the phase quality
phase_quality = calculate_phase_quality_mex(phase_angle, kernel_radius);

% Calculate the phase mask.
phase_mask = calculate_phase_mask(phase_quality, kernel_radius);


end