function [TY, TX] = spc_unwrap_2D(COMPLEX_PHASE_PLANE, WEIGHTING_MATRIX,...
    PHASE_FILTER_LIST, KERNEL_SIZE_LIST, UNWRAP_METHOD, COMPILED);

% Filter plane
phase_plane_filtered_complex = apply_filter_list_complex_phase_plane(...
    COMPLEX_PHASE_PLANE, PHASE_FILTER_LIST, ...
    KERNEL_SIZE_LIST, COMPILED);

% Unwrap using the chosen unwrapping method
% Other methods can be added.
switch lower(UNWRAP_METHOD)
    case 'herraez'
        
        % Unwrap the phase plane using the Herraez method.
        phase_plane_unwrapped = unwrap_phase_herraez(phase_plane_filtered_complex);
    
    case 'goldstein'
        
        % Set the maximum radius of the branch cut search box.
        max_box_size = 9;
        
        % Unwrap the phase plane using the Goldstein method.
        [phase_plane_unwrapped, branch_cut_matrix] = ...
            GoldsteinUnwrap2D(phase_plane_filtered_complex, ...
            max_box_size, COMPILED);
    
        % Update the weighting matrix
        WEIGHTING_MATRIX(branch_cut_matrix > 0) = 0;
        WEIGHTING_MATRIX(phase_plane_unwrapped == 0) = 0;
        
    case 'none'
        phase_plane_unwrapped = angle(phase_plane_filtered_complex);
        
    otherwise
        error('Error: invalid phase unwrapping algorithm specified: %s\n', ...
            UWNRAP_METHOD);
end

% Fit a plane to the unwrapped phase
[TY, TX] = spc_plane_fit(phase_plane_unwrapped, WEIGHTING_MATRIX);


end