function PHASE_MASK = calculate_phase_regions(wrapped_phase_angle_plane, threshold)
	
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
	phase_quality = calculate_phase_quality_mex(wrapped_phase_angle_plane, 1);
	
	% Threshold the phase quality map
	phase_quality_bw = im2bw(phase_quality, threshold);
	
	% Perform the region segmentation
	phase_quality_bw_label = bwlabel(~phase_quality_bw);
	
	% Count the number of regions
	num_regions = max(phase_quality_bw_label(:));
	
	% Allocate a vector that will contain the median values
	% of the radial coordinates of each region.
	r_median = zeros(num_regions, 1);
	
	% Measure the median radial coordinate of each region
	for k = 1 : num_regions
		
		% Find the indices of the labeled region matrix
		% whose value is equal to the k'th iteration of this loop
		region_idx = find(phase_quality_bw_label(:) == k);
		
		% Calculate the median radial coordinate of the region
		r_median(k) = median(r(region_idx));
	
	end
	
	% Find the minimum
	[r_median_min, r_median_min_idx] = min(r_median);
	
	% Allocate a mask matrix
	PHASE_MASK = zeros(region_height, region_width);
	
	% Apply the mask
	PHASE_MASK(phase_quality_bw_label == r_median_min_idx) = 1;
	
end











