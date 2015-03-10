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

% Extract images
image_01 = g.* double(imageMatrix1(:, :, 1));
image_02 = g.* double(imageMatrix2(:, :, 1));

% Phase correlation
IM = phaseCorrelation(image_01, image_02);

% Calculate the wrapped phase angle plane
wrapped_phase_plane = fftshift(angle(phaseCorrelation(image_01, image_02)));

tic;
% Calculate residues
phase_residue_matrix = calculate_phase_residues_mex(wrapped_phase_plane);
toc;