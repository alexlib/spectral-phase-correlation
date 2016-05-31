function [PHASE_MASK] = ...
    calculate_phase_mask_gaussian_vision(PHASE_QUALITY, KERNEL_RADIUS, MAX_STD)
	% This function computes a quality-based mask of the phase angle plane of a cross correlation.
	
    % Defualt to no maximum standard deviation
    if nargin < 3
        MAX_STD = inf;
    end
    
    % Rename the kernel radius
    rad = KERNEL_RADIUS;
    
    % Extract the central portion of the phase quality
%     phase_quality_interior = PHASE_QUALITY(rad + 1 : end - rad - 1, rad + 1 : end - rad - 1);
    
    % Minimum subtraction of phase quality
%     phase_quality_sub = (phase_quality_interior - ...
%         min(phase_quality_interior(:)));
    
    phase_quality_sub = PHASE_QUALITY - min(PHASE_QUALITY(:));
    
    % Rescale the phase quality so that its range is [0, 1]
    phase_quality_scaled = phase_quality_sub ./ max(phase_quality_sub(:));
    
    % Measure size
	[region_height, region_width] = size(phase_quality_scaled);
    
	% Make coordinates (Cartesian)
	[x, y] = meshgrid(1 : region_width, 1 : region_height);
	
	% Centroid
	xc = region_width  / 2;
	yc = region_height / 2;
	
	% Make coordinates (polar),
	% with origin (r = 0) at geometric centroid of the region
	[~, r] = cart2pol(x - xc, y - yc);
	
    % Thresh
%     thresh = mean(phase_quality_scaled(:));
    
%     phase_quality_bw = logical((imquantize(phase_quality_scaled, thresh)) - 1);
    
    coder.extrinsic('im2bw');

	% Threshold the phase quality map using histogram equalization
    phase_quality_bw = im2bw(phase_quality_scaled, 0.5);
	
% % 	Set border pixels to 1 to prevent connecting regions via the border
% 	phase_quality_bw(1, :) = 1;
% 	phase_quality_bw(end, :) = 1;
% 	phase_quality_bw(:, 1) = 1;
% 	phase_quality_bw(:, end) = 1;
	
    % Get the properties
    [areas, centroids, major_axis, minor_axis, theta, L] = get_region_props(~phase_quality_bw);
	
	% Count the number of regions
	num_regions = length(areas);
	
	% Allocate a vector that will contain the median values
	% of the radial coordinates of each region.
	region_weighted_centroid_radial = zeros(num_regions, 1);
	    
    % Make a vector of all the pixel indices
    all_inds = 1 : (region_width * region_height);
	
	% Measure the median radial coordinate of each region
	for k = 1 : num_regions
		
		% Find the radial coordinate of the region's centroid.
		% whose value is equal to the k'th iteration of this loop
% 		region_centroid_subs = phase_quality_region_props(k).Centroid;
        region_centroid_subs = centroids(k, :);
        
        idx_list = all_inds(L == k);
        
        region_radius_median = median(r(idx_list));
		
		% Radial coordinates of the pixels in the region
% 		region_radius_median(k) = median(r(phase_quality_region_props(k).PixelIdxList));
		
		% Convert to radial
		region_centroid_radial = sqrt((region_centroid_subs(1) - xc)^2 + (region_centroid_subs(2) - yc)^2);
		
		% Centroid coordinates weighted by the median radial coordinate of the pixels in the region
		region_weighted_centroid_radial(k) = region_radius_median * region_centroid_radial;
	
	end
		
	% Find the minimum
	[~, region_weighted_centroid_idx] = min(region_weighted_centroid_radial);
	
	% Mask indices
% 	mask_idx = phase_quality_region_props(region_weighted_centroid_idx).PixelIdxList;
%     mask_idx = all_inds(L == region_weighted_centroid_idx);
	
% 	% Allocate a mask matrix
% 	phase_mask_holder = zeros(region_height, region_width);
% 	
% 	% Apply the mask
% 	phase_mask_holder(mask_idx) = 1;
% 	
% 	% Zero the border pixels just in cae
% 	phase_mask_holder(:, 1) = 0 ;
% 	phase_mask_holder(:, end) = 0;
% 	phase_mask_holder(1, :) = 0;
% 	phase_mask_holder(end, :) = 0;

	% Fill the holes
% 	phase_mask_holder = imfill(phase_mask_holder);
    
%     % Get the region properties again
%     phase_mask_region_props = regionprops(phase_mask_holder,...
%         'PixelIdxList', 'MajorAxisLength', 'MinorAxisLength', ...
%         'Orientation');
    
    % Read the measured major axis of the ellipse
    % that best fits the binary quality mask
%     ax_maj = phase_mask_region_props.MajorAxisLength/2;
    ax_maj = major_axis(region_weighted_centroid_idx);
    ax_min = minor_axis(region_weighted_centroid_idx);
    
    % Same for the minor axis
%     ax_min = phase_mask_region_props.MinorAxisLength/2;
    ax_angle = pi / 180 * (theta(region_weighted_centroid_idx));
    
    % Measure the orientation angle of
    % the best fit ellipse and convert it to radians.
%     ax_angle = 1 * deg2rad(phase_mask_region_props.Orientation);
    
    % Gaussian standard deviations as fractions
    % of the major and minor axes of the ellipse fit
    % MAX_STD is the largest allowable standard deviation,
    % and a reasonable choice is, e.g., the 
    % standard deviation of the normal RPC filter.
    std_maj = min(ax_maj / 2.00, MAX_STD);
    std_min = min(ax_min / 2.00, MAX_STD);
    
    % Rotate the coordinates for the elliptical Gaussian
    x2 = (x - xc) * cos(ax_angle) - (y - yc) * sin(ax_angle);
    y2 = (x - xc) * sin(ax_angle) + (y - yc) * cos(ax_angle);
    
    % Calculate the Gaussian function
%     gaussian_mask = exp(-(x2.^2)/(2 * std_maj^2) - (y2.^2) / (2 * std_min^2));
    PHASE_MASK = exp(-(x2.^2)/(2 * std_maj^2) - (y2.^2) / (2 * std_min^2));
    
    % Insert the cropped mask into the phase
    % quality matrix, so that it's the same
    % size as the original phase matrix.
%     PHASE_MASK = zeros(size(PHASE_QUALITY));
%     PHASE_MASK(rad + 1 : end - rad - 1, rad + 1 : end - rad - 1) = gaussian_mask;
  
end










