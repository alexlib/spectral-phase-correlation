
region_width = 128;
region_height = 128;
kernel_radius = 5;


nloops = 1000;
array = rand(region_height, region_width);

t = tic;
for k = 1 : nloops
	calculate_phase_quality(array, kernel_radius);
end
t2 = toc(t);

seconds_per_loop = t2 / nloops;

fprintf(1, 'Time per loop: %0.3f sec.\n', seconds_per_loop);