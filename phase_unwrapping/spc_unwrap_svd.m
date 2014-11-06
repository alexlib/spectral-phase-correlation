function UNWRAPPED_PLANE = spc_unwrap_svd(WRAPPED_PLANE, NUM_EIGS, DIM);

% Calculate the SVD of the rotated image
[U, S, V] = svd(WRAPPED_PLANE);

% Unwrapped plane
SVD_PLANE = zeros(size(WRAPPED_PLANE));

% Construct the reduced-dimension image
for k = 1 : NUM_EIGS
    SVD_PLANE = SVD_PLANE + (U(:, k) * S(k,k) * (V(:, k))');
end

svd_plane_v = U(:, 1) * S(1,1);
svd_plane_u = S(1,1)  * (V(:, 1))';


end