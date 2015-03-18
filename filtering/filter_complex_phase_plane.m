function FILTERED_COMPLEX_PLANE = filter_complex_phase_plane(...
    COMPLEX_PHASE_PLANE, FILTER_TYPE)

% Default to no filter.
if nargin < 2
    FILTER_TYPE = 'none';
end

switch lower(FILTER_TYPE)
    case 'mean'
        FILTERED_COMPLEX_PLANE = phase_mean_filter(...
    COMPLEX_PHASE_PLANE, [5, 5]);

    case 'svd'
        FILTERED_COMPLEX_PLANE = svd_phase_filter_2D(COMPLEX_PHASE_PLANE);
    otherwise
        FILTERED_COMPLEX_PLANE = COMPLEX_PHASE_PLANE;
end 

end