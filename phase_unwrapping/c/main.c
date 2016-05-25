#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>


#define PI (3.141592653589793)

// Function prototypes
void wrapped_diff(float *OUTPUT, float *INPUT, int NUM_ROWS, int NUM_COLS, int DIM);

void sub2ind(int *ind, int row, int col, int num_cols);

void calculate_phase_quality(float *PHASE_QUALITY_ARRAY, float *WRAPPED_PHASE_ANGLE,
	int NUM_ROWS, int NUM_COLS, int KERNEL_RADIUS);
	
void extract_subregion(float *DEST_ARRAY, float *SOURCE_ARRAY, int SOURCE_ORIGIN_ROW, int SOURCE_ORIGIN_COL, int SOURCE_NUM_ROWS, int SOURCE_NUM_COLS, int DEST_NUM_ROWS, int DEST_NUM_COLS);

void conv2_separable(float *DEST_ARRAY, float *DATA_ARRAY, int DATA_NUM_ROWS, int DATA_NUM_COLS,
	float *KERNEL_1D, int KERNEL_LENGTH);

float moving_std_dev_2D(float *DEST_ARRAY, float *SOURCE_ARRAY,
int SOURCE_NUM_ROWS, int SOURCE_NUM_COLS, int KERNEL_DIM);

void devrand(float *array, int array_length, float lower_bound, float upper_bound);

int isodd(int number);

void print_array(float *ARRAY, int NUM_ROWS, int NUM_COLS);

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

void calculate_phase_quality(float *PHASE_QUALITY_ARRAY, float *WRAPPED_PHASE_ANGLE,
	int NUM_ROWS, int NUM_COLS, int KERNEL_RADIUS){

		// Number of elements in the array
		int num_elements = NUM_ROWS * NUM_COLS;
		
		// Counters for rows and columns
		int k;
		
		// Size of the phase quality kernel
		int kernel_dim = 2 * KERNEL_RADIUS + 1;

		// Phase differences
		float *phase_diff_rows;
		float *phase_diff_cols;
		
		// Allocate memory for phase differences
		phase_diff_rows = calloc(num_elements, sizeof(float));
		phase_diff_cols = calloc(num_elements, sizeof(float));
				
		// Standard deviations
		float *row_std_dev;
		float *col_std_dev;
		
		// Allocate the standard deviations
		row_std_dev = calloc(num_elements, sizeof(float));
		col_std_dev = calloc(num_elements, sizeof(float));

		// Calculate the wrapped difference of the
		// wrapped phase angle in the row direction
		wrapped_diff(phase_diff_rows, WRAPPED_PHASE_ANGLE, NUM_ROWS, NUM_COLS, 1);
		wrapped_diff(phase_diff_cols, WRAPPED_PHASE_ANGLE, NUM_ROWS, NUM_COLS, 2);
		
		// Calculate the moving-window standard deviations
		moving_std_dev_2D(row_std_dev, phase_diff_rows, NUM_ROWS, NUM_COLS, kernel_dim);
		moving_std_dev_2D(col_std_dev, phase_diff_cols, NUM_ROWS, NUM_COLS, kernel_dim);
		
		// Add the standard deviations to compute the phase quality
		for(k = 0; k < num_elements; k++){
			PHASE_QUALITY_ARRAY[k] = row_std_dev[k] + col_std_dev[k];
		}
	
		// Free the memory
		free(row_std_dev);
		free(col_std_dev);
		free(phase_diff_rows);
		free(phase_diff_cols);
}

void wrapped_diff(float *OUTPUT, float *INPUT, int NUM_ROWS, int NUM_COLS, int DIM){
	// This function calculates wrapped differences of arrays. 
	// It's like diff() in Matlab except it ignores differences of +/- 2pi
	// so that a wrapped phase angle doesn't show big differences at the
	// wrapping locations.
	// 
	// This algorithm is specific to my problem.
		
	// Counter
	int r, c;
	int *ind;
	int *ind_plusone;
	float *diff;
	
	// Allocate memory for pointers
	ind = malloc(sizeof(int));
	ind_plusone = malloc(sizeof(int));
	diff = malloc(sizeof(float));
	
	// Take the differences either in the row or column direction
	// Direction is specified by DIM.
	switch(DIM) {

	   case 1: // Taking differences in the "1" direction, i.e., top to bottom.
	
	   // Loop over the array
	   // This is for differences in the row-direction
	   for(c = 0; c < NUM_COLS; c++){
		   for(r = 0; r < NUM_ROWS - 1; r++){
			   
			   // Determine the indices of the adjacent pixels	
			   sub2ind(ind, r, c, NUM_COLS);
			   sub2ind(ind_plusone, r+1, c, NUM_COLS);
			   
			   // Calculate the difference
			   *diff = INPUT[*ind_plusone] - INPUT[*ind];
			   
			   // Calculate the phase difference
			   OUTPUT[*ind] = atan2(sin(*diff), cos(*diff));
			   
		   }
	   }	
	      break; 
	
	
	   case 2: // Taking differences in the "2" direction, i.e., left to right.
	     
		// Loop over the array
	   // This is for differences in the column-direction
	   for(r = 0; r < NUM_ROWS; r++){
		   for(c = 0; c < NUM_COLS - 1; c++){
			   
			   // Determine the indices of the adjacent pixels
			   sub2ind(ind, r, c, NUM_COLS);
			   sub2ind(ind_plusone, r, c+1, NUM_COLS);
			   
			   // Calculate the difference
			   *diff = INPUT[*ind_plusone] - INPUT[*ind];
			   
			   // Calculate the phase difference
			   OUTPUT[*ind] = atan2(sin(*diff), cos(*diff));
		   }
	   }
	      break; 
	}
	
	// Free memory
	free(ind);
	free(ind_plusone);
	free(diff);
}

void sub2ind(int *ind, int row, int col, int num_cols){
	// This function finds the linear index of an array
	// that is conceptually organized in 2-D with rows
	// and columns, but occupies contiguous space
	// in memory. In this paradigm, the top-left
	// element in the array is at (0,0), and the
	// array increases in column order. 
	// 
	// I know that C is faster with row operations
	// but I don't think it should matter because
	// I have created the arrays to be consistent
	// with the description here. 
	//
	// I made ind a pointer because this function
	// is going to get called millions of times
	// and I don't want to be allocating private
	// variables that many times... Basically 
	// I thought using an externally-allocated
	// pointer would be faster.
	
	// Calculate the linear index.
	*ind = row * num_cols + col;

}

float moving_std_dev_2D(float *DEST_ARRAY, float *DATA_ARRAY,
int DATA_NUM_ROWS, int DATA_NUM_COLS, int KERNEL_DIM){
// Compute the moving-window standard deviation of an array	
// using a symmetric window of length N per side.
	
	// Counters
	int k;
	
	// Number of elements in the data array
	int numel_data = DATA_NUM_ROWS * DATA_NUM_COLS;	
	
	// Number of elements in the 2D kernel
	// Cast as a float because it's only used
	// for a division
	float numel_kernel = (float)KERNEL_DIM * (float)KERNEL_DIM;

	// Array to hold the squares of the values
	float *x2;
	x2 = malloc(numel_data * sizeof(float));
	
	// Populate the squares array
	for(k = 0; k < numel_data; k++){
		x2[k] = DATA_ARRAY[k] * DATA_ARRAY[k];
	}

	// Allocate arrays to hold the intermediate calculations
	// Sum of the elements
	float *sum_x;
	sum_x = calloc(numel_data, sizeof(float));
	
	// Sum of the squares of the elements
	float *sum_x2;
	sum_x2 = calloc(numel_data, sizeof(float));
	
	// Convolution kernel
	float *kernel_1D;
	kernel_1D = malloc(KERNEL_DIM * sizeof(float));
	
	// Populate the kernel
	for(k = 0; k < KERNEL_DIM; k++){
		kernel_1D[k] = 1;
	}
	
	// Calculate the sums
	conv2_separable(sum_x, DATA_ARRAY, DATA_NUM_ROWS, DATA_NUM_COLS, kernel_1D, KERNEL_DIM);
	conv2_separable(sum_x2, x2, DATA_NUM_ROWS, DATA_NUM_COLS, kernel_1D, KERNEL_DIM);
	
	// Calculate the square of the 
	for(k = 0; k < numel_data; k++){
		DEST_ARRAY[k] = sqrt( 1.0 / (numel_kernel - 1) * (sum_x2[k] - ((sum_x[k] * sum_x[k]) / numel_kernel)) );
	}

	// Free memory
	free(x2);
	free(sum_x);
	free(sum_x2);
	free(kernel_1D);
}	


void conv2_separable(float *DEST_ARRAY, float *DATA_ARRAY, int DATA_NUM_ROWS, int DATA_NUM_COLS,
	float *KERNEL_1D, int KERNEL_LENGTH){
// In-place 2-D convolution with a separable kernel.
	
	// Counters
	int r, c, k;
	
	// Running sum
	float sum;
		
	// Determine if the kernel offset
	// This is the number of elements away from the
	// edge of the kernel where the result is placed.
	int kernel_offset = isodd(KERNEL_LENGTH) ? (KERNEL_LENGTH - 1) / 2 : KERNEL_LENGTH / 2;
	
	// Data index
	int *source_ind;
	source_ind = malloc(sizeof(int));	
	
	// Result index
	int *dest_ind;
	dest_ind = malloc(sizeof(int));
	
	// Number of elements
	int data_num_elements = DATA_NUM_ROWS * DATA_NUM_COLS;
		
	// Max column
	int col_max = DATA_NUM_COLS - KERNEL_LENGTH + 1; 
	
	// Max row
	int row_max = DATA_NUM_ROWS - KERNEL_LENGTH + 1;
		
	// Array to hold intermediate calculations
	float *conv_array;
	conv_array = calloc(data_num_elements, sizeof(float));
	
	// Perform convolution of the rows
	for(r = 0; r < DATA_NUM_ROWS; r++){
		for(c = 0; c < col_max; c++){
			
				// Anchor index
				sub2ind(source_ind, r, c, DATA_NUM_COLS);
				
				// Get the index of the border element
				sub2ind(dest_ind, r, c + kernel_offset, DATA_NUM_COLS);
				
				// Initialize the sum
				sum = 0;
	
				// Loop over the kernel, updating the sum for each iteration
				for(k = 0; k < KERNEL_LENGTH; k++){
					
					// Add to the sum
					sum += ( KERNEL_1D[k] * DATA_ARRAY[*source_ind + k] );				
				}
				
				// Set the value of the destination
				// to that of the sum.
				conv_array[*dest_ind] = sum;
		}
	}
		
	// Now perform convolution of the rows of the result
	// (this is how separable kernels work)
	// 
	// This indexing is a little more annoying
	// because columns are not contiguous in memory.
	for(c = 0; c < DATA_NUM_COLS; c++){
		for(r = 0; r < row_max; r++){
				
			// Get the index of the border element
			sub2ind(dest_ind, r + kernel_offset, c, DATA_NUM_COLS);	
			
			// Initialize the sum
			sum = 0;
	
			// Loop over the kernel
			for(k = 0; k < KERNEL_LENGTH; k++){
				
					// Source index
					sub2ind(source_ind, r + k, c, DATA_NUM_COLS);
			
					// Add the result to the total
					sum += KERNEL_1D[k] * conv_array[*source_ind];
				}
				
			// Put the result in the destination array
			DEST_ARRAY[*dest_ind] = sum;			
		}
	}
		
	// Free memory
	free(conv_array);
	free(source_ind);
	free(dest_ind);
		
	}



void extract_subregion(float *DEST_ARRAY, float *SOURCE_ARRAY, int SOURCE_ORIGIN_ROW, int SOURCE_ORIGIN_COL, int SOURCE_NUM_ROWS, int SOURCE_NUM_COLS, int DEST_NUM_ROWS, int DEST_NUM_COLS){
// This function extracts a chunk of SOURCE_ARRAY and puts it in DEST_ARRAY.
// SOURCE_ARRAY and DEST_ARRAY are pointers so they don't have to get allocated
// every time the function runs -- they're preallocated outside of this function.
// 
// 	

	// Counters	for row and column position
	int r, c;
	
	// Pointer for the source index
	int *source_ind;
	
	// Pointer for the destination index
	int *dest_ind;
	
	// Allocate space for those pointers
	source_ind = malloc(sizeof(int));
	dest_ind = malloc(sizeof(int));
	
	// source_ind = calloc(1, sizeof(int));
	// dest_ind = calloc(1, sizeof(int));
	
	// Loop over the rows and columns
	// of the destination array,  
	// extracting the data from the source array
	for(r = 0; r < DEST_NUM_ROWS; r++){
		for(c = 0; c < DEST_NUM_COLS; c++){
			
			// Determine the indices of the pixels in the
			// source and destination arrays
			sub2ind(dest_ind, r, c, DEST_NUM_COLS);
			sub2ind(source_ind, r + SOURCE_ORIGIN_ROW, c + SOURCE_ORIGIN_COL, SOURCE_NUM_COLS);
			
			// Populate the destination array with the source pixels.
			DEST_ARRAY[*dest_ind] = SOURCE_ARRAY[*source_ind];
		}
	}

	// Free the arrays.
	free(source_ind);
	free(dest_ind);
}

void devrand(float *array, int array_length, float lower_bound, float upper_bound) {
// This function fills an array of length array_length with random numbers
// drawn from a uniform distribution with lower_bound and upper_bound
	
	// Initialize some variables
	FILE *urandom; // This will hold the file /dev/urandom
	unsigned int seed; // Random number seed
	
	int k; // Counter for loops

	// Open the /urandom file for reading.
	urandom = fopen("/dev/urandom", "r");

	// Inform the user if the file wasn't opened successfully.
	if (urandom == NULL) {
		fprintf(stderr, "Cannot open /dev/urandom!\n");
		exit(1);
	}

	// Put a random number from /urandom into the memory location of the seed; 
	// i.e. set the seed to a random number obtained from /urandom.
	// "&seed" specifies a pointer to the memory location of the variable 'seed';
	// sizeof(seed) specifies the size in bytes of the the variable "seed"
	// The number "1" here means "read 1 element from the file" (which is /urandom)
	// The last input is the pointer to the file /urandom (specified as a pointer in the beginning of the file)
	fread(&seed, sizeof(seed), 1, urandom);

	// Seed the random number generator using the seed obtained from /urandom
	srand(seed); 
	
	// Generate the numbers between the upper and lower bounds.
	for (k = 0; k < array_length; k++) {
		array[k] = rand() / (float)RAND_MAX * (upper_bound - lower_bound) + lower_bound ;
	}
}

void print_array(float *ARRAY, int NUM_ROWS, int NUM_COLS){
	// This function prints an array row by row.
	
	// Counters
	int r, c;
	
	// Array index
	int *ind;
	ind = malloc(sizeof(int));
	
	for(r = 0; r < NUM_ROWS; r++){
		for(c = 0; c < NUM_COLS; c++){
			sub2ind(ind, r, c, NUM_COLS);
			printf("%0.2f  ", ARRAY[*ind]);
		}
		printf("\n");
	}
	
	// Free memory
	free(ind);
}

double get_time_ms()
	// This function gets the current machine time in milliseconds.
	// Used for timing codes.
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}

int isodd(int number){
	// Determine if a number is odd
	// Returns 1 if odd and 0 if even.
	return number%2;
}








