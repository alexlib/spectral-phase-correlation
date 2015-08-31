% Calculate wrapped phase differences in a given direction
function wrapped_diff = wrapped_phase_difference(PHASE_ANGLE_REAL, DIM)
		
	% Differences of the complex array
	phase_diff = diff(PHASE_ANGLE_REAL, 1, DIM);

	% Wrap the differences with the angle operator
	wrapped_diff = atan2(sin(phase_diff), cos(phase_diff));
	
end