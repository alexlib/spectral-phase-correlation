function [TRANSLATION_Y, TRANSLATION_X, SPATIAL_RPC_PLANE, ...
    CORR_HEIGHT, CORR_DIAMETER] = ...
    scc_spectral_ensemble(REGION_MATRIX_01, REGION_MATRIX_02, PEAK_FIT_METHOD);


if nargin < 4
    PEAK_FIT_METHOD = 1;
end

% Calculate size of interrogation regions (homogeneous) (pixels)
[region_height, region_width, num_regions] = size(REGION_MATRIX_01);

% Initialize the cross correlation
cc = zeros(region_height, region_width) + 1i * zeros(region_height, region_width);

% Loop over all the regions
for k = 1 : num_regions
    
    % Extract the regions
   region_01 = REGION_MATRIX_01(:, :, k);
   region_02 = REGION_MATRIX_02(:, :, k);
   
   % Fourier transforms
   f1 = fft2(region_01);
   f2 = fft2(region_02);
   
   % Add the complex correlation to the ensemble
   cc = cc + f1 .* conj(f2);
    
end

SPATIAL_RPC_PLANE = fftshift(abs(ifft(cc)));

% Subpixel fit
% Prana subpixel implmentation of the sub-pixel fit
[TRANSLATION_X, TRANSLATION_Y, CORR_HEIGHT, CORR_DIAMETER] = ...
    subpixel(SPATIAL_RPC_PLANE, ...
    region_width, region_height, ones(size(SPATIAL_RPC_PLANE)), PEAK_FIT_METHOD, ...
    0, sqrt(8) * [1, 1]);


end