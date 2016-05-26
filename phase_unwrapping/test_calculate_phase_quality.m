
region_width = 128;
region_height = 128;
kernel_radius = 5;

kernel_length = 2 * kernel_radius + 1;

nloops = 5000;
array = rand(region_height, region_width);

t = tic;
for k = 1 : nloops
	calculate_phase_quality(array, kernel_length);
end
t2 = toc(t);

ms_per_loop = t2 * 1000 / nloops;

fprintf(1, '%0.3f ms per loop\n', ms_per_loop);