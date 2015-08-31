% Create an array

% Region size
region_height = 128;
region_width = 128;



% Create coordinates
[u, v] = meshgrid(1 : region_width, 1 : region_height);

% Pixel Shifts
sy = 1;

sx_range = -3 : 0.1 : 3;

n_cases = length(sy_range);

for k = 1 : n_cases

	sx = sx_range(k);
	sy = sx;

	% Calculate complex function
	complex_phase = exp(-1i*2*pi*(sx/region_width * u + sy / region_height * v));

	% Calculate the wrapped phase difference
	wrapped_diff = wrapped_phase_difference(angle(complex_phase), 2);

	% Plot the wrapped phase
	subplot(1, 2, 1);
	imagesc(angle(complex_phase));
	axis image;
	title('Wrapped phase', 'FontSize', 20);

	% Plot the wrapped phase difference
	subplot(1, 2, 2);
	mesh(wrapped_diff);
	axis image;
	title('Wrapped phase difference', 'FontSize', 20);
	zlim(0.5 * [-1, 1]);
	axis square

	pause(0.005)

end