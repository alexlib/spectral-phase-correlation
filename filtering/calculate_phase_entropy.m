function E = calculate_phase_entropy(PHASE_ANGLE_PLANE)

dpdx = wrapped_phase_difference(PHASE_ANGLE_PLANE, 2);
dpdy = wrapped_phase_difference(PHASE_ANGLE_PLANE, 1);

phase_grad_mag = sqrt(dpdx.^2 + dpdy.^2);

p_max = 2 * sqrt(2) * pi;

p_norm = uint8(phase_grad_mag(1 : end - 1, 1 : end - 1) ./ p_max * 255);

E = entropy(phase_grad_mag);

end