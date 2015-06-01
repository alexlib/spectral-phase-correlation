function [FILTERED_COMPLEX_PLANE] = filter_complex_phase_plane(...
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

% Initialize the L2 norm 

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
        % The second argument to this function denotes the number
        % of modes used in the SVD reconstruction of the
        % complex phase plane. Currently this is hard-coded to a single
        % mode.
        FILTERED_COMPLEX_PLANE = svd_phase_filter_2D(...
            COMPLEX_PHASE_PLANE, 1);
        
        % This commented-out function is used to compute the mean absolute
        % difference between phase planes reconstructed using different
        % numbers of modes versus the GCC plane.
%         [FILTERED_COMPLEX_PLANE, L2_NORM] = ...
%           svd_phase_filter_2D_mode_sweep(COMPLEX_PHASE_PLANE);
    
    otherwise % No filtering
        FILTERED_COMPLEX_PLANE = COMPLEX_PHASE_PLANE;
end 

end


