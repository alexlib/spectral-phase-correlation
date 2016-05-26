function phase_quality_array = calculate_phase_quality(...
    wrapped_phase_angle, kernel_length)


% Calculate the horizontal and vertical wrapped phase differences
phase_diff_rows = wrapped_phase_difference(wrapped_phase_angle, 1);
phase_diff_cols = wrapped_phase_difference(wrapped_phase_angle, 2);

% Phase quality by moving standard deviations.
phase_quality_array = moving_std_dev_2D(phase_diff_rows, kernel_length) + ...
    moving_std_dev_2D(phase_diff_cols, kernel_length);

end






