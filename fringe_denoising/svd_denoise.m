function Z_OUT = svd_denoise(Z_IN, N_ROTATIONS, N_EIGS);
% This function performs image denoising by image dimensionality reduction
% using singular value decomposition. The algorithm is taken 
% from Vargas et al., "Fringe pattern denoising by image dimensionality
% reduction," Optics and Lasers in Engineering 51 (2013) 
% 
% 2014-09-11
% Matthew N. Giarra
% Virginia Tech
% matthew.giarra@gmail.com
% 
%
%
% INPUTS
%   Z_IN = raw image to be filtered
%
%   N_ROTATIONS = number of rotation iterations to perform for SVD artifact reduction.
%   Typical number of rotations is 10-20.
%
%   N_EIGS = Number of singular vectors to use in the reconstruction.
%   Typical number of singular vectors to use is 5-10.
% 
% OUTPUTS
%   Z_OUT = Filtered image
% 
% Example
% x = linspace(0, 10 * pi, 128);
% z_true = repmat(cos(x) + 1, 128, 1);
% z_noisy = z_true + 3 * rand(128, 128);
% z_denoised = svd_denoise(z_noisy, 10, 5);
% subplot(1, 3, 1); imagesc(z_noisy); axis image; title('Noisy image', 'FontSize', 14, 'Interpreter', 'latex');
% subplot(1, 3, 2); imagesc(z_true); axis image; title('Ground truth image', 'FontSize', 14, 'Interpreter', 'latex');
% subplot(1, 3, 3); imagesc(z_denoised); axis image; title({'Denoised image', '($N_{\theta} = 10$, $N_{\lambda} = 5$)'}, 'FontSize', 14, 'interpreter', 'latex');
% set(gcf, 'Color', 'white');

% Image dimensions
[height, width] = size(Z_IN);

% Calculate the maximum radius of the image
maxRadius = sqrt(height^2 + width^2)/2;

% Number of value for zero padding
borderWidth = ceil(maxRadius - width/2);
borderHeight = ceil(maxRadius - height/2);

% Zero pad the image
zPadded = padarray(Z_IN, [borderHeight, borderWidth], 0);

% Make a list of rotation angles
angles = linspace(0, 2*pi, N_ROTATIONS); 

% Initialize the matrix to hold the reconstructed image
im_recon = zeros([size(zPadded), N_ROTATIONS]);

% Initialize a vector to hold the values of the
S_trace = zeros(N_ROTATIONS, 1);

% Loop over the denoising iterations.
for n = 1 : N_ROTATIONS
    
    % Initialize the matrix to hold the
    % reconstructed image for this rotation angle
    im_recon_temp = zeros(size(zPadded));
    
    % Rotate the padded image
    zRotated = (imrotate(zPadded, rad2deg(angles(n)), 'bicubic', 'crop'));
    
    % Calculate the SVD of the rotated image
    [U, S, V] = svd(zRotated);
     
    % Construct the reduced-dimension image
    for k = 1 : N_EIGS
        im_recon_temp = im_recon_temp + (U(:, k) * S(k,k) * (V(:, k))');
    end
   
    % Calculate the trace of the eigenvalue matrix.
    S_trace(n) = trace(S);
    
    % un-Rotate the temporarily-rotated reconstruction, 
    % and multiply it by the trace of S
    im_recon(:, :, n) = (imrotate(im_recon_temp, rad2deg(-angles(n)), 'crop', 'bicubic')) * S_trace(n);
    
end

% Sum the reconstructions
im_recon_sum = sum(im_recon, 3);

% Remove the borders
Z_OUT = (im_recon_sum(borderHeight +1 : borderHeight + height, borderWidth + 1 : borderWidth + width)) / sum(S_trace);

end
