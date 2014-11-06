function [PHASE_PLANE_UNWRAPPED] = spc_unwrap_analytical(PHASE_PLANE, TY, TX)

% Size of the wrapped phase plane.
[height, width] = size(PHASE_PLANE);

% This analytically counts the number of
% fringes in the wrapped phase plane.

% Zero frequency pixel coordinates
uc =  width/2 + 1 - 0.5 * mod(width, 2);
vc =  height/2 + 1 - 0.5 * mod(height, 2);

% 1-D u vector
u_1d = (1-uc : width - uc);
v_1d = (1 - vc : height - vc)';

% Coordinate matrices
u_mat = u_1d(ones(height, 1), :);
v_mat = v_1d(:, ones(width, 1));

%% Count fringes
% Number of fringes to the right of the origin.
nFringes_right = floor(abs(TY)/height * (height/2 - (2 * vc - height - 1)) ...
    + abs(TX)/width * (width/2 - (2 * uc - width - 1)) + 1/2);

% Number of fringes to the left of the origin
nFringes_left = floor(abs(TY)/height * (height/2) ...
    + abs(TX)/width * (width/2) + 1/2);

% Total number of fringes
nFringes = nFringes_left + nFringes_right;

% Wrap count matrix
wrapCount = zeros(height, width);

% Fringe coordinate vector
fringe_coords_vect = zeros(length(u_1d), nFringes);

%% Calculate fringe lines
% Calculate fringe lines if there are any
if nFringes > 0

    % fringe vector
    % These are the values of N in the equation
    % for the fringe lines. Subtract 1 from the 
    % positive fringes because n=0 corresponds
    % to the first positive fringe line.
    fringe_count_vector = -nFringes_left : nFringes_right-1;

    % Wrap count matrix
    wrapCount = zeros(height, width);    
    
    % Plot all the fringes
    for n = 1 : nFringes
        % Analytical equation for the n'th fringe line
        v_fringe_mat = (height / TY * ...
        ( -TX / width * u_mat + (2 * fringe_count_vector(n) + 1) / 2 ));
        
        % Fringe coordinates
        fringe_coords_vect(:, n) = v_fringe_mat(1, :);
        
        % Update the wrap count matrix
        wrapCount = wrapCount + 1*((v_mat) >= (v_fringe_mat));

    end
    
    % Fix plane intercept of wrap count matrix
    wrapCount = wrapCount - nFringes_left;
    
end % <--- keep

% Flip wrap count
if TY > 0
    wrapCount = -wrapCount;
end

% Unwrap the plane
PHASE_PLANE_UNWRAPPED = PHASE_PLANE + 2 * pi * wrapCount;  


end







