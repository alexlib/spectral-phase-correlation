

% Number of times to rotate the image for denoising
nRotations = 10;

% Number of eigenvalues to keep
nEigs = 5;

% % Make a test pattern without noise (smooth);
width = 128;
height = 128;
nCycles = 8;

% Gaussian filter
% gaussianWindow = fspecial('gaussian', [height, width], height/6);
gaussianWindow = ones([height, width]);

% Noise magnitude
noiseMag = 10;

% Make coordinates
x = linspace(0,2 * pi * nCycles, width);
z_1d = cos(x);

% Make the pattern 2D
z_clean = repmat(z_1d, height, 1) + 1;

% Add noise to the matrix and window it.
z = (z_clean + noiseMag * rand(height, width)) .* gaussianWindow;

% Calculate the geometric centroid of the image.
xc = width/2 + 1;
yc = height/2 + 1;

% Calculate the maximum radius of the image
maxRadius = sqrt(height^2 + width^2)/2;

% Number of value for zero padding
borderWidth = ceil(maxRadius - width/2);
borderHeight = ceil(maxRadius - height/2);

% borderWidth = 0;
% borderHeight = 0;

% Zero pad the image
zPadded = padarray(z, [borderHeight, borderWidth], 0);

% Make a list of rotation angles
angles = linspace(0, 2*pi, nRotations); 

% Initialize the matrix to hold the reconstructed image
im_recon = zeros([size(zPadded), nRotations]);

% Initialize a vector to hold the values of the
S_trace = zeros(nRotations, 1);

% Loop over the denoising iterations.
for n = 1 : nRotations
    
    % Initialize the matrix to hold the
    % reconstructed image for this rotation angle
    im_recon_temp = zeros(size(zPadded));
    
    % Rotate the padded image
    zRotated = (imrotate(zPadded, rad2deg(angles(n)), 'bicubic', 'crop'));
    
    % Calculate the SVD of the rotated image
    [U, S, V] = svd(zRotated);
     
    % Construct the reduced-dimension image
    for k = 1 : nEigs
        im_recon_temp = im_recon_temp + (U(:, k) * S(k,k) * (V(:, k))');
%         imagesc(im_recon_temp); axis image; colormap gray; 
%         title(num2str(k));
%         pause(0.05);
    end
   
    % Calculate the trace of the eigenvalue matrix.
    S_trace(n) = trace(S);
    
    % un-Rotate the temporarily-rotated reconstruction, 
    % and multiply it by the trace of S
%     im_recon = im_recon + (imrotate(im_recon_temp, rad2deg(-angles(n)), 'crop', 'bicubic')) * S_trace(n);
    im_recon(:, :, n) = (imrotate(im_recon_temp, rad2deg(-angles(n)), 'crop', 'bicubic')) * S_trace(n);
    
%     imagesc(im_recon(:, :, n)); axis image; colormap gray;
%     pause(0.1);
    
end

% Sum the reconstructions
im_recon_sum = sum(im_recon, 3);

% Remove the borders
im_recon_cropped = (im_recon_sum(borderHeight +1 : borderHeight + height, borderWidth + 1 : borderWidth + width)) / sum(S_trace);

% Display the reconstructed image next to the original image
subplot(1, 3, 1);
imagesc(z); axis image; colormap gray; title('Original image', 'FontSize', 16);
subplot(1, 3, 2); 
imagesc(z_clean); axis image; title('True underlying pattern', 'FontSize', 16);
subplot(1, 3, 3);
imagesc(im_recon_cropped); axis image; title('Reconstructed image', 'FontSize', 16);


