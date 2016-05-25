#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include "apc.h"

#define PI (3.141592653589793)

// Function prototypes
double get_time_ms();

// Main function 
int main(int argc, char *argv[]){
	
	// Yell at the user if they don't input a number of loops
	if(argc < 2){
		printf("Usage: ./main <number_of_loops>\n");
		return(-1);
	}
	
	// Number of times to run this code
	// for testing
	int nloops = atoi(argv[1]);
	
	// Kernel radius for calculating
	// the phase quality. 5 is a reasonable
	// number so I just left it hard coded.
	int kernel_radius = 5;
	
	// Counters
	int r, c, k;
	
	// Argument for trigonometric function.
	// used to build the input array
	float arg;
	
	// Index counter.
	// The value stored at this pointer's address
	// will be the linear indices of some 2-D arrays
	// Similar treatment as matlab where you can 
	// specify an array position as ARRAY(row, col)
	// or as ARRAY(linear_index)
	int *ind;
	ind = malloc(sizeof(int));
	
	// Specify the number of rows and columns in the input.
	int num_rows = 128;
	int num_cols = 128;
	
	// Signal amplitude
	float signal_amplitude = 3.0;
	
	// Noise amplitude
	float noise_amplitude = 1.0;
	
	// Noise upper and lower bounds
	float noise_ub = 1.0 * noise_amplitude;
	float noise_lb = -1.0 * noise_amplitude;
	
	// Compute the number of elements
	int num_elements = num_rows * num_cols;
	
	// Allocate the input array
	float *input_array;
	input_array = calloc(num_elements, sizeof(float));
	
	// Allocate the quality (output) array
	float *quality_array;
	quality_array = calloc(num_elements, sizeof(float));
	
	// Allocate the noise array
	float *noise_array;
	noise_array = malloc(num_elements * sizeof(float));

	// Populate the noise array
	devrand(noise_array, num_elements, noise_lb, noise_ub);
	
	// Construct the input array
	for(r = 0; r < num_rows; r++){
		for(c = 0; c < num_cols; c++){
			sub2ind(ind, r, c, num_cols);
			arg = ((float)c / (float)num_cols) * 2.0 * PI * 2.0;
			input_array[*ind] = signal_amplitude * cos(arg) + noise_array[*ind];
		}
	}
	
	// Machine time at the beginning of the loop
	double t1 = get_time_ms();
	
	// This is the parallel section
	for(k = 0; k < nloops; k++){
	// printf("On loop %d of %d\n", k, nloops);
		calculate_phase_quality(quality_array, input_array, num_rows, num_cols, kernel_radius);
	}
	
	// Timing crap
	// Machine time at the end of the loop
	double t2 = get_time_ms();
	
	// Calculate total time elapsed
	double dt = t2 - t1;
	
	// Calculate milliseconds per loop
	double ms_per_loop = dt / (double)nloops;
	
	// Tell me how long you took
	printf("Timing (C):\n%0.0f ms total\n%0.3f ms per loop\n", dt, ms_per_loop);
	
	// Free the memory
	free(input_array);
	free(quality_array);
	free(noise_array);
	free(ind);
	
	// GTFO
	return(0);
}

double get_time_ms()
	// This function gets the current machine time in milliseconds.
	// Used for timing codes.
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}







