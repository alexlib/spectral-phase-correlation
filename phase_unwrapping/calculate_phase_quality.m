function phase_quality_array = calculate_phase_quality(wrapped_phase_angle, kernel_radius)


% Calculate the horizontal and vertical wrapped phase differences
phase_diff_rows = wrapped_phase_difference(wrapped_phase_angle, 1);
phase_diff_cols = wrapped_phase_difference(wrapped_phase_angle, 2);

% Measure the array size
% and subtract 2 from each dimensions due to the differencing 
[M, N] = size(wrapped_phase_angle);

% Array height and width
array_height = M;
array_width  = N;

% Min and maxes of rows and columns
col_min = 1 + kernel_radius;
col_max = array_width - kernel_radius;

row_min = 1 + kernel_radius;
row_max = array_height - kernel_radius;

% Allocate the phase quality array
phase_quality_array = zeros(array_height, array_width);

% Loop over the rows
for m = row_min : row_max
	for n = col_min : col_max
		
		% Extract the sub-region of phase differences
		row_diffs = phase_diff_rows(m - kernel_radius : m + kernel_radius,...
		 n - kernel_radius : n + kernel_radius);
		 
		col_diffs = phase_diff_cols(m - kernel_radius : m + kernel_radius,...
		 n - kernel_radius : n + kernel_radius);
		
		% Standard deviations
		% The 1 indicates normalization by N, not by N-1
		row_diff_std = std(row_diffs(:), 1);
		col_diff_std = std(col_diffs(:), 1);
		
		% Populate the phase quality array
		phase_quality_array(m, n) = row_diff_std + col_diff_std;
		
	end
end
	
end






