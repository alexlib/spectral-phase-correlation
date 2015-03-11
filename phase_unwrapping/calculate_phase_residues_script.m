% Add paths
addpath ../filtering;
addpath ../correlation_algorithms;
addpath ../phase_unwrapping;

% Path to data file
file_path = '~/Desktop/data.mat';

% Load data file
load(file_path);

% Calculate size of images
[height, width, n_pairs] = size(imageMatrix1);

% Create a Gaussian window
g = gaussianWindowFilter([height, width], [0.5, 0.5], 'fraction');

t1 = tic;
for k = 1 : 100
    % Extract images
    image_01 = g.* double(imageMatrix1(:, :, k));
    image_02 = g.* double(imageMatrix2(:, :, k));
    
    % Calculate the wrapped phase angle plane
    wrapped_phase_plane = fftshift(angle(phaseCorrelation(image_01, image_02)));

    % Calculate residues
    phase_residue_matrix = calculate_phase_residues_mex(wrapped_phase_plane);

    % Calculate the branch cuts.
    [branch_cut_matrix, flags_matrix] = ...
calculate_branch_cuts_goldstein_mex(phase_residue_matrix, 7);
    
end

% End timer.
t2 = double(toc(t1));
fprintf('Computed branch cuts for %d arrays in %d seconds\n\n', n_pairs, t2);
