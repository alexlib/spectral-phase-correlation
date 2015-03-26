function FILTERED_COMPLEX_PLANE = filter_complex_phase_plane(...
    COMPLEX_PHASE_PLANE, FILTER_TYPE, KERNEL_SIZE, COMPILED)

% Default to not running compiled codes.
if nargin < 4
    COMPILED = 0;
end

% Default kernel size
if nargin < 3
    KERNEL_SIZE = [5, 5];
end

% Default to no filter.
if nargin < 2
    FILTER_TYPE = 'none';
end

% Choose between filter types.
switch lower(FILTER_TYPE)
    case 'mean' % Mean filtering
        
        % Check if the kernel size is empty.
        % Populate it with the default value if so.
        if isempty(KERNEL_SIZE)
            KERNEL_SIZE = [5, 5];
        end
        
        % Apply the wrapped moving mean filter.
        FILTERED_COMPLEX_PLANE = phase_mean_filter(...
    COMPLEX_PHASE_PLANE, KERNEL_SIZE);

    case 'median' % Median filtering
        
        % Check if the kernel size is empty.
        % Populate it with the default value if so.
        if isempty(KERNEL_SIZE)
            KERNEL_SIZE = [5, 5];
        end
        
        if COMPILED
            
            % Apply the wrapped moving median filter (compiled)
            FILTERED_COMPLEX_PLANE = phase_median_filter_mex( ...
                COMPLEX_PHASE_PLANE, KERNEL_SIZE);
        else
            % Apply the wrapped moving median filter (non-compiled)
            FILTERED_COMPLEX_PLANE = phase_median_filter( ...
                COMPLEX_PHASE_PLANE, KERNEL_SIZE);
        end

    case 'svd' % SVD Filtering
        
        % Apply the SVD denoising
        FILTERED_COMPLEX_PLANE = svd_phase_filter_2D(COMPLEX_PHASE_PLANE);
    
    otherwise % No filtering
        FILTERED_COMPLEX_PLANE = COMPLEX_PHASE_PLANE;
end 

end