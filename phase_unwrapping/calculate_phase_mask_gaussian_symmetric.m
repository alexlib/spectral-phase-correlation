function [PHASE_MASK] = ...
    calculate_phase_mask_gaussian_symmetric(PHASE_QUALITY, KERNEL_RADIUS, MAX_STD)
	% This function computes a quality-based mask of the phase angle plane of a cross correlation.
		
    % Defualt to no maximum standard deviation
    if nargin < 3
        MAX_STD = inf;
    end
    
    % Rename the kernel radius
    rad = KERNEL_RADIUS;
    
    % Extract the central portion of the phase quality
    phase_quality_interior = PHASE_QUALITY(rad + 1 : end - rad - 1, rad + 1 : end - rad - 1);
    
    % Minimum subtraction of phase quality
    phase_quality_sub = (phase_quality_interior - ...
        min(phase_quality_interior(:)));
    
    % Rescale the phase quality so that its range is [0, 1]
    phase_quality_scaled = phase_quality_sub ./ max(phase_quality_sub(:));
    
    % Measure size of the phase quality array
	[phase_height, phase_width] = size(phase_quality_scaled);
    
    % Number of extra rows and columns
    % in the original correlation matrix
    % compared to the phase quality matrix
    % (the quality matrix is cropped)
    extra_rows = 2 * rad + 1;
    extra_cols = 2 * rad + 1;
    
    % Calculate the corresponding size
    % of the original interrogation regions
    region_height = phase_height + extra_rows;
    region_width  = phase_width  + extra_cols;
    
	% Make coordinates (Cartesian)
	[x_phase, y_phase] = meshgrid(1 : phase_width, 1 : phase_height);
    [x_region, y_region] = meshgrid(1 : region_height, 1 : region_width);
	
	% Centroid of the phase matrix
	xc_phase = (phase_width  + 1) / 2 + 0.5 * ( 1 - mod(phase_width,  2) );
	yc_phase = (phase_height + 1) / 2 + 0.5 * ( 1 - mod(phase_height, 2) );
  
    % Centroid of the region matrix
    xc_region = (region_width   + 1) / 2 + 0.5 * ( 1 - mod(region_width,  2) );
	yc_region = (region_height  + 1) / 2 + 0.5 * ( 1 - mod(region_height, 2) );
	
	% Make coordinates (polar),
	% with origin (r = 0) at geometric centroid of the region
	[~, r_phase] = cart2pol(x_phase - xc_phase, y_phase - yc_phase);
    
	% Threshold the phase quality map using histogram equalization
    phase_quality_bw = im2bw(phase_quality_scaled, 0.5);
	
% 	Set border pixels to 1 to prevent connecting regions via the border
	phase_quality_bw(1, :) = 1;
	phase_quality_bw(end, :) = 1;
	phase_quality_bw(:, 1) = 1;
	phase_quality_bw(:, end) = 1;
	
	% Find properties of all the connected regions in the thresholded image. 
	phase_quality_region_props = ...
        regionprops(~phase_quality_bw, 'Centroid', 'PixelIdxList');
	
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
		region_radius_median(k) = median(r_phase(phase_quality_region_props(k).PixelIdxList));
		
		% Convert to radial
		region_centroid_radial(k) = sqrt((region_centroid_subs(1) - xc_phase)^2 + (region_centroid_subs(2) - yc_phase)^2);
		
		% Centroid coordinates weighted by the median radial coordinate of the pixels in the region
		region_weighted_centroid_radial(k) = region_radius_median(k) * region_centroid_radial(k);
	
	end
		
	% Find the minimum
	[~, region_weighted_centroid_idx_phase] = min(region_weighted_centroid_radial);
    
	% Mask indices in the phase matrix
    mask_idx_phase = phase_quality_region_props(...
        region_weighted_centroid_idx_phase).PixelIdxList;
    
	% Allocate a mask matrix
	phase_mask_holder = zeros(phase_height, phase_width);
	
	% Apply the mask
	phase_mask_holder(mask_idx_phase) = 1;
	
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
    
    % Read the measured major axis of the ellipse
    % that best fits the binary quality mask
    ax_maj = phase_mask_region_props.MajorAxisLength/2;
    
    % Same for the minor axis
    ax_min = phase_mask_region_props.MinorAxisLength/2;
    
    % Gaussian standard deviations as fractions
    % of the major and minor axes of the ellipse fit
    % MAX_STD is the largest allowable standard deviation,
    % and a reasonable choice is, e.g., the 
    % standard deviation of the normal RPC filter.
    std_maj = ax_maj / 2.00;
    std_min = ax_min / 2.00;
    
    % Standard deviation to use
    std_dev = min([std_maj, std_min, MAX_STD]);
    
    % This is the phase mask.
    PHASE_MASK = exp((- (x_region - xc_region).^2 -(y_region - yc_region).^2 ) / (2 * std_dev^2));
    
end










