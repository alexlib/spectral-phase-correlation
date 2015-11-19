% Calculate wrapped phase differences in a given direction
function wrapped_diff = phase_diff_kernel_wrapped...
    (PHASE_ANGLE_REAL, DIM, METHOD)

    % Create the derivative kernel based on the method specified.
    switch lower(METHOD)
        case 'sobel'
            % Sobel filter
            kernel = [ 1  2  1 ;
                    0  0  0 ;
                    -1 -2 -1 ];
        case 'prewitt'
            % Prewitt filter
            kernel = [ 1  1  1; 
                   0  0  0 ; 
                  -1 -1 -1 ];
    end
		
    % Transpose the kernel if taking horizontal derivatives
    if DIM == 2;
        kernel = kernel';
    end
    		
	% Differences of the complex array
	phase_diff = conv2(PHASE_ANGLE_REAL, kernel, 'same');

    % Wrapped phase difference
    wrapped_diff = atan2(sin(phase_diff), cos(phase_diff));
    
end