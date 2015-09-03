function [PHASE_MASK, PHASE_QUALITY] = calculate_phase_mask(wrapped_phase_angle_plane)
	% This function computes a quality-based mask of the phase angle plane of a cross correlation.
		
	% Measure size
	[region_height, region_width] = size(wrapped_phase_angle_plane);
	
	% Make coordinates (Cartesian)
	[x, y] = meshgrid(1 : region_width, 1 : region_height);
	
	% Centroid
	xc = region_width  / 2;
	yc = region_height / 2;
	
	% Make coordinates (polar),
	% with origin (r = 0) at geometric centroid of the region
	[~, r] = cart2pol(x - xc, y - yc);
	
	% Compute the phase quality map
	PHASE_QUALITY = calculate_phase_quality_mex(wrapped_phase_angle_plane, 1);
	
	% Threshold the phase quality map using histogram equalization
	phase_quality_bw = (histeq(PHASE_QUALITY, 2));
	
	% Set border pixels to 1 to prevent connecting regions via the border
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
	[region_weighted_centroid_val, region_weighted_centroid_idx] = min(region_weighted_centroid_radial);
	
	% Mask indices
	mask_idx = phase_quality_region_props(region_weighted_centroid_idx).PixelIdxList;
	
	% Allocate a mask matrix
	PHASE_MASK = zeros(region_height, region_width);
	
	% Apply the mask
	PHASE_MASK(mask_idx) = 1;
	
	% Zero the border pixels
	PHASE_MASK(:, 1) = 0 ;
	PHASE_MASK(:, end) = 0;
	PHASE_MASK(1, :) = 0;
	PHASE_MASK(end, :) = 0;
	
	% Fill the holes
	PHASE_MASK = imfill(PHASE_MASK);
	
end











