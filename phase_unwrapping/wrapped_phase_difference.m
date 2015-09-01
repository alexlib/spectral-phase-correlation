% Calculate wrapped phase differences in a given direction
function wrapped_diff = wrapped_phase_difference(PHASE_ANGLE_REAL, DIM)
		
	% Allocate the wrapped difference
	wrapped_diff = zeros(size(PHASE_ANGLE_REAL));
		
	% Differences of the complex array
	phase_diff = diff(PHASE_ANGLE_REAL, 1, DIM);

	% Wrap the differences with the angle operator
	switch DIM
	case 1
		wrapped_diff(1:end - 1, :) = atan2(sin(phase_diff), cos(phase_diff));
	case 2
		wrapped_diff(:, 1 : end - 1) = atan2(sin(phase_diff), cos(phase_diff));
	end

end