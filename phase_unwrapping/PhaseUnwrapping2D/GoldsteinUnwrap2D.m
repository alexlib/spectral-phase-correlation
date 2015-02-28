function PHASE_PLANE_UNWRAPPED = GoldsteinUnwrap2D(PHASE_PLANE_WRAPPED_COMPLEX, MAX_BOX_RADIUS, COMPILED)
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

% Phase angle plane
phase_angle_plane = angle(PHASE_PLANE_WRAPPED_COMPLEX);

% Choose between compiled and non-compiled codes.
if COMPILED
    
    % Calculate residue charges
    residue_charge = PhaseResidues_mex(phase_angle_plane);
    
    % Calculate branch cuts
    branch_cuts = BranchCuts_mex(residue_charge, MAX_BOX_RADIUS); 
    
    % Unwrap the phase
    PHASE_PLANE_UNWRAPPED = FloodFill_mex(phase_angle_plane, branch_cuts);

else
    
    % Calculate residue charges
    residue_charge = PhaseResidues(phase_angle_plane);
    
    % Calculate branch cuts
    branch_cuts = BranchCuts(residue_charge, MAX_BOX_RADIUS); 
    
    % Unwrap the phase
    PHASE_PLANE_UNWRAPPED = FloodFill(phase_angle_plane, branch_cuts);

    
end
% fprintf('Residue charge time: %0.2f msec\n', 10^3 * toc(t0));


% Unwrap the phase plane.
% t2 = tic;

% fprintf('Unwrapping time: %0.2f msec\n', 10^3 * toc(t2));

end

