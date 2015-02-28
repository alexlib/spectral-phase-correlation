function [TY, TX] = spc_2D(REGION_01, REGION_02, WEIGHTING_MATRIX, UNWRAP_METHOD, COMPILED);

% Phase only correlaiton of images
% Returns complex plane
phase_plane_wrapped_complex = fftshift(phaseCorrelation(REGION_01, REGION_02));

% Unwrap using the chosen unwrapping method
% Other methods can be added.
switch UNWRAP_METHOD
    case 'HERRAEZ'
        
        % Unwrap the phase plane using the Herraez method.
        phase_plane_unwrapped = unwrap_phase_herraez(phase_plane_wrapped_complex);
    case 'GOLDSTEIN'
        
        % Set the maximum radius of the branch cut search box.
        max_box_radius = 4;
        
        % Unwrap the phase plane using the Goldstein method.
        phase_plane_unwrapped = GoldsteinUnwrap2D(phase_plane_wrapped_complex, max_box_radius, COMPILED);
    
    otherwise
        error('Error: invalid phase unwrapping algorithm specified: %s\n', UWNRAP_METHOD);
end

% Fit a plane to the unwrapped phase
[TY, TX] = spc_plane_fit(phase_plane_unwrapped, WEIGHTING_MATRIX);


end