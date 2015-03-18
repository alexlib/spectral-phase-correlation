function [PHASE_PLANE_UNWRAPPED, BRANCH_CUT_MATRIX] = GoldsteinUnwrap2D(PHASE_PLANE_WRAPPED_COMPLEX, MAX_BOX_SIZE, COMPILED)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% GoldsteinUnwrap2D implements 2D Goldstein branch cut phase unwrapping algorithm.
%
% References::
% 1. R. M. Goldstein, H. A. Zebken, and C. L. Werner, “Satellite radar interferometry:
%    Two-dimensional phase unwrapping,” Radio Sci., vol. 23, no. 4, pp. 713–720, 1988.
% 2. D. C. Ghiglia and M. D. Pritt, Two-Dimensional Phase Unwrapping:
%    Theory, Algorithms and Software. New York: Wiley-Interscience, 1998.
%
% Inputs: 1. Complex image in .mat double format
%         2. Binary mask (optional)          
% Outputs: 1. Unwrapped phase image
%          2. Phase quality map
%
% This code can easily be extended for 3D phase unwrapping.
% Posted by Bruce Spottiswoode on 22 December 2008
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Default to not run compiled codes
if nargin < 3
    COMPILED = 0;
end

% Calculate the phase angle of the complex plane
phase_angle_plane_wrapped = angle(PHASE_PLANE_WRAPPED_COMPLEX);

% Choose between compiled and non-compiled codes.
if COMPILED
    
    % Calculate residue charges
    residue_matrix = calculate_phase_residues_mex(phase_angle_plane_wrapped);
    
     % Create the residue flags matrix
    flags_matrix = make_flags_matrix_mex(residue_matrix);
    
    % Remove dipoles
    flags_matrix = remove_dipoles_mex(flags_matrix);
    
    % Calculate branch cuts
    BRANCH_CUT_MATRIX = uint8(calculate_branch_cuts_goldstein_mex(...
        flags_matrix, MAX_BOX_SIZE)); 
    
    % Unwrap the phase
    PHASE_PLANE_UNWRAPPED = FloodFill_mex(phase_angle_plane_wrapped,...
        BRANCH_CUT_MATRIX);

else
    
    % Calculate residue charges
    residue_matrix = calculate_phase_residues(phase_angle_plane_wrapped);
    
     % Create the residue flags matrix
    flags_matrix = make_flags_matrix(residue_matrix);
    
    % Remove dipoles
    flags_matrix = remove_dipoles(flags_matrix);
    
    % Calculate branch cuts
    BRANCH_CUT_MATRIX = uint8(calculate_branch_cuts_goldstein(...
        flags_matrix, MAX_BOX_SIZE)); 
    
    % Unwrap the phase
    PHASE_PLANE_UNWRAPPED = FloodFill(phase_angle_plane_wrapped,...
        BRANCH_CUT_MATRIX);

end

end

