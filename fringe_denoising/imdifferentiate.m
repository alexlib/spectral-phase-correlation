function IMAGE = imdifferentiate(IMAGE, SCALES, XORDER, YORDER, ZORDER, KERNELRADIUS)
% imdifferentiate(IMAGE, SCALES, XORDER, YORDER, ZORDER, KERNELRADIUS) calculates
% spatial derivatives (up to second order) of intensity of a 2-D or 3-D array of scalar values by convolution
% with an analytically-differentiated 1-D gaussian kernel in each direction.
% When the specified order of differentiation in any direction is zero, this function
% performs gaussian smoothing over that dimension (i.e., convolution with
% an un-differentiated gaussian kernel). 
% 
% KNOWN ISSUES
%   Currently the length of the convolution kernel is hard-coded as 9 pixels
%   (i.e. a kernel of odd-numbered length with a radius of 4 pixels). This is
%   probably a bad way to handle kernels, but I have not come up with a
%   smart way to deal with image edges with kernels of variable lengths. 
% 
% INPUTS
%   IMAGE = 2-D image or a 3-D stack of images. The [ 1, 2, 3 ] dimensions of the array
%   correspond to the [ y, x, z ] dimensions of the image stack.
%
%   SCALES = 3 - element vector containing the standard deviations of the
%   gaussian kernels used to calculate image derivatives in each direction.
%   The elements of SCALE are [ scaleX scaleY scaleZ ]. The default value
%   of SCALES is [ 1 1 1 ] .
% 
%   XORDER = Order of differentiation along the X-direction. The default
%   values of XORDER is 1.
% 
%   YORDER = Order of differentiation along the Y-direction. The default
%   value of YORDER is 0.
% 
%   ZORDER = Order of differentiation along the Z-direction. The default
%   value of ZORDER is 0.
% 
%  KERNELRADIUS = Radius (in pixels) of convolution kernel (integer). The
%  kernel radius should be an an even integer so that the kernel is symmetric
%  about its anchor point; therefore, if an odd or non-integer kernel
%  radius is specified, the kernel radius is forced to the next greatest
%  even integer. 
%
% OUTPUTS
%   IMAGE = Image whose pixel values are the values of the input image's spatial
%   derivative of intensity in the specified direction. The variable IMAGE
%   is reused here to save memory.
%   
% SEE ALSO
%   makeKernel

%%%%%%%%%%%%%%%
%%% BEGIN FUNCTION %%%
%%%%%%%%%%%%%%%

% Default to kernel radius of 4 pixels
if nargin < 6
    KERNELRADIUS = 4;
end

% Default to no derivative in Z direction (i.e. smoothing)
if nargin < 5
    ZORDER = 0;
end

% Default to no derivative in Y direction (i.e. smoothing)
if nargin < 4
    YORDER = 0;
end

% Default to first derivative in X direction
if nargin < 3
    XORDER = 1;
end

% Default to scales of 1 in every direction.
if nargin < 2;
    SCALES = [1 1 1];
end

% Extract scales from scale vector
scaleX = SCALES(1);
scaleY = SCALES(2);

% Only extract Z-scale if it is specified
if length(SCALES) > 2
    scaleZ = SCALES(3);
else
    scaleZ = 0;
end

% Throw an error if no input image is specified.
if nargin < 1
    error('No input image specified.');
    
else    % If an image is specified, commence processing. 
    
    IMAGE = double(IMAGE); % Convert input image to double-precision format
    
    [height width depth] = size(IMAGE); % Determine image dimensions
    
% Perform Y- differentiation
    ker = makeKernel(YORDER, scaleY, KERNELRADIUS); % Generate kernel for x derivatives. The kernel is a column vector. 
    kerLength = length(ker); % Length of the kernel
    
    % Skip Y-differentiation if the Y-dimension is small
    if size(IMAGE, 1) < kerLength
        fprintf(1, 'Image dimension in X direction is smaller than the convolution kernel! Skipping X - differentiation. \n');

    else
    
% Mirror the edges of the input array. The size of the mirrored region in each dimension is the radius of the kernel for differentiation in that dimension. 
        mirrorTop = real(flipdim(IMAGE(2 : (kerLength + 1) / 2,   :,  :), 1)); % Mirror the left side of the of the image
        mirrorBottom = real(flipdim(IMAGE(end - (kerLength - 1) / 2 : end - 1, :, :), 1));
        IMAGE = cat(1, mirrorTop, IMAGE, mirrorBottom);
        numRows = size(IMAGE, 1); % Number of rows in the mirrored image
        
        tempImage = zeros(height, width, depth, kerLength); % Initialize image derivative container
     
% Compute the derivatives by convolving the input image with the kernel.
        for k = 1:kerLength
            tempImage(:, :, :, k)     =  IMAGE(k : numRows - kerLength + k     , :, :) * ker(k);
        end
           
        IMAGE = sum(tempImage, 4);
    end
                   
% Perform X- differentiation
    ker = makeKernel(XORDER, scaleX, KERNELRADIUS); % Generate kernel for x derivatives. The kernel is a column vector. 
    kerLength = length(ker); % Length of the kernel
    
% Skip X-differentiation if the X-dimension is small
    if size(IMAGE, 2) < kerLength
        fprintf(1, 'Image dimension in X direction is smaller than the convolution kernel! Skipping X - differentiation. \n');

    else

% Permute the image so that the differentiation direction is in the (1) direction
        IMAGE = permute(IMAGE, [2 1 3]);

%  Mirror the edges of the input array. The size of the mirrored region in each dimension is the radius of the kernel for differentiation in that dimension. 
        mirrorTop = real(flipdim(IMAGE(2 : (kerLength + 1) / 2,   :,  :), 1)); % Mirror the left side of the of the image
        mirrorBottom = real(flipdim(IMAGE(end - (kerLength - 1) / 2 : end - 1, :, :), 1));
        IMAGE = cat(1, mirrorTop, IMAGE, mirrorBottom);
        numRows = size(IMAGE, 1); % Number of rows in the mirrored image
        
        tempImage = zeros(width, height, depth, kerLength); % Initialize image derivative container

% Compute the derivatives by convolving the input image with the kernel.
        for k = 1:kerLength
            tempImage(:, :, :, k)     =  IMAGE(k : numRows - kerLength + k     , :, :) * ker(k);
        end
        
        IMAGE = sum(tempImage, 4); % Add the convolved values

        IMAGE = ipermute(IMAGE, [2 1 3]); % Invert permutation 
    end
    
% Perform Z- differentiation
    if size(IMAGE, 3) > 1; % Skip Z-differentiation if the image is 2-D
  
        ker = makeKernel(ZORDER, scaleZ, KERNELRADIUS); % Generate kernel for x derivatives. The kernel is a column vector. 
        kerLength = length(ker); % Length of the kernel
    
% Skip Z-differentiation if the Z-dimension is small
        if size(IMAGE, 3) < kerLength
            fprintf(1, 'Image dimension in Z direction is smaller than the convolution kernel! Skipping Z - differentiation. \n');

        else

% Permute the image so that the differentiation direction is in the (1) direction
            IMAGE = permute(IMAGE, [3 1 2]);

% Only mirror in the Z- direction if the stack passed to the function is
% larger than the convolution kernel. This is so that a single z-derivative can
% be calculated for an anchor image by taking into account the images
% before and after it, without performing extra calculations. This solution
% seems kind of ugly, but it might work for now.

            numRows = size(IMAGE, 1); % Number of rows in the permuted image
                   
            if numRows ~= kerLength % If the number of images is exactly equal to the kernel length
            
% Mirror the edges of the input array. The size of the mirrored
%region in each dimension is the radius of the kernel for differentiation in that dimension. 
                mirrorTop = real(flipdim(IMAGE(2 : (kerLength + 1) / 2,   :,  :), 1)); % Mirror the left side of the of the image
                mirrorBottom = real(flipdim(IMAGE(end - (kerLength - 1) / 2 : end - 1, :, :), 1)); % Mirror the right side of the of the image
                IMAGE = cat(1, mirrorTop, IMAGE, mirrorBottom); % Contatonate the mirrored regions with the image
                tempImage = zeros(depth, height, width, kerLength); % Initialize image derivative container
                numRows = size(IMAGE, 1); % Number of rows in the (possibly mirrored) image

% Compute the derivatives by convolving the input image with the kernel.
                for k = 1:kerLength
                    tempImage(:, :, :, k)     =  IMAGE(k : numRows - kerLength + k     , :, :) * ker(k);
                end
              
                IMAGE = sum(tempImage, 4); % Add together the convolved values               
                
% If the number of images is equal to the kernel length
            else               
                tempImage = zeros(depth, height, width); % Initialize the temporary image container
                for k = 1:kerLength
                    tempImage(k, :, :)     =  IMAGE(k, :, :) * ker(k); % Convolve the kernel with the image
                end
                IMAGE = sum(tempImage, 1); % Sum convolved values
            end
                
            IMAGE = ipermute(IMAGE, [3 1 2]); % Inverse the permutation
        
% Generate a single output image if the stack size is exactly the kernel length
            if numRows == kerLength
                IMAGE = sum(IMAGE, 3); 
            end                          
        end
    end

end

end



%%%%%%%%%%%%%%
%%% END FUNCTION %%%
%%%%%%%%%%%%%%


