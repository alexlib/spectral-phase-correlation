function [PHASE_MASK] = calculate_phase_mask(PHASE_QUALITY, KERNEL_RADIUS)
	% This function computes a quality-based mask of the phase angle plane of a cross correlation.
		
    % Rename the kernel radius
    rad = KERNEL_RADIUS;
    
    % Extract the central portion of the phase quality
    phase_quality_interior = PHASE_QUALITY(rad + 1 : end - rad - 1, rad + 1 : end - rad - 1);
    
    phase_quality_sub = (phase_quality_interior - ...
        min(phase_quality_interior(:)));
    
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
	
	% Threshold the phase quality map using histogram equalization
% 	phase_quality_bw = (histeq(phase_quality_scaled, 2));
    phase_quality_bw = im2bw(phase_quality_scaled, 0.5);
	
% 	Set border pixels to 1 to prevent connecting regions via the border
	phase_quality_bw(1, :) = 1;
	phase_quality_bw(end, :) = 1;
	phase_quality_bw(:, 1) = 1;
	phase_quality_bw(:, end) = 1;
	
	% Find properties of all the connected regions in the thresholded image. 
	phase_quality_region_props = regionprops(~phase_quality_bw, 'Centroid', 'PixelIdxList');
	
	% Count the number of regions
	num_regions = length(phase_quality_region_props);
	
	% Allocate a vector that will contain the median values
	% of the radial coordinates of each region.
	region_weighted_centroid_radial = zeros(num_regions, 1);
	
	% Allocate a vector to hold the centroids of the detected regions
	region_centroid_radial = zeros(num_regions, 1);
	
	% Allocate a vector to hold the mean values of the radial coordinates
	% of the pixels comprising the detected regions.
	region_radius_median = zeros(num_regions, 1);
	
	% Measure the median radial coordinate of each region
	for k = 1 : num_regions
		
		% Find the radial coordinate of the region's centroid.
		% whose value is equal to the k'th iteration of this loop
		region_centroid_subs = phase_quality_region_props(k).Centroid;
		
		% Radial coordinates of the pixels in the region
		region_radius_median(k) = median(r(phase_quality_region_props(k).PixelIdxList));
		
		% Convert to radial
		region_centroid_radial(k) = sqrt((region_centroid_subs(1) - xc)^2 + (region_centroid_subs(2) - yc)^2);
		
		% Centroid coordinates weighted by the median radial coordinate of the pixels in the region
		region_weighted_centroid_radial(k) = region_radius_median(k) * region_centroid_radial(k);
	
	end
		
	% Find the minimum
	[~, region_weighted_centroid_idx] = min(region_weighted_centroid_radial);
	
	% Mask indices
	mask_idx = phase_quality_region_props(region_weighted_centroid_idx).PixelIdxList;
	
	% Allocate a mask matrix
	phase_mask_holder = zeros(region_height, region_width);
	
	% Apply the mask
	phase_mask_holder(mask_idx) = 1;
	
	% Zero the border pixels just in cae
	phase_mask_holder(:, 1) = 0 ;
	phase_mask_holder(:, end) = 0;
	phase_mask_holder(1, :) = 0;
	phase_mask_holder(end, :) = 0;

	% Fill the holes
	phase_mask_holder = imfill(phase_mask_holder);
    
    % Get the region properties again
    phase_mask_region_props = regionprops(phase_mask_holder,...
        'PixelIdxList', 'MajorAxisLength', 'MinorAxisLength', ...
        'Orientation');
    
    ax_maj = phase_mask_region_props.MajorAxisLength;
    ax_min = phase_mask_region_props.MinorAxisLength;
    ax_angle = 1 * deg2rad(phase_mask_region_props.Orientation);
    
    std_maj = ax_maj / 3;
    std_min = ax_min / 3;
    
    % Elliptical Gaussian function
    x2 = (x - xc) * cos(ax_angle) - (y - yc) * sin(ax_angle);
    y2 = (x - xc) * sin(ax_angle) + (y - yc) * cos(ax_angle);
    
    gaussian_mask = exp(-(x2.^2)/(std_maj^2) - (y2.^2) / (std_min^2));
    
    
    % Full phase mask
    PHASE_MASK = zeros(size(PHASE_QUALITY));
    PHASE_MASK(rad + 1 : end - rad - 1, rad + 1 : end - rad - 1) = gaussian_mask;
  
   
end











