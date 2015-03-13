% Add paths
addpath ../filtering;
addpath ../correlation_algorithms;
addpath ../correlation_algorithms/polyfitweighted2
addpath ../phase_unwrapping;

% Path to data file
file_path = '~/Desktop/data.mat';

% Load data file
load(file_path);

% Calculate size of images
[height, width, n_pairs] = size(imageMatrix1);

% Create a Gaussian window
g = gaussianWindowFilter([height, width], [0.5, 0.5], 'fraction');

% spectral energy filter
energy_filt = spectralEnergyFilter(height, width, sqrt(8));

% Image border bit position
image_border_bit_position = 4;

% Enable compiled codes.
COMPILED = 1;

t1 = tic;
parfor k = 1 : n_pairs
    % Extract images
    region_01 = g.* double(imageMatrix1(:, :, k));
    region_02 = g.* double(imageMatrix2(:, :, k));
    
    
    [TY, TX] = spc_2D(region_01, region_02, energy_filt, 'GOLDSTEIN', COMPILED);
    
    
%     
%     % Calculate the wrapped phase angle plane
%     wrapped_phase_plane = fftshift(angle(phaseCorrelation(...
%         region_01, region_02)));
% 
%     % Calculate residues
%     phase_residue_matrix = ...
%         calculate_phase_residues_mex(wrapped_phase_plane);
% 
%     % Calculate the branch cuts.
%     [branch_cut_matrix, flags_matrix] = ...
%             calculate_branch_cuts_goldstein_mex(phase_residue_matrix, 7);
% 
%     % Unwrap the plane using the Flood fill algorithm.
%     unwrapped_phase_plane = FloodFill_mex(wrapped_phase_plane, ...
%         uint8(branch_cut_matrix));
%     
%     % Weighting filter for plane fit
%     weighting_filter = energy_filt .* (~(branch_cut_matrix |...
%         bitget(flags_matrix, image_border_bit_position)));
%     
%     % Fit a plane to the unwrapped phase, and interpret its slopes
%     % as the horizontal and veritcal translations of the image pattern.
%     [TY, TX] = spc_plane_fit(unwrapped_phase_plane, weighting_filter);
%  
    % Plot the residue matrix with the branch cuts
%     fprintf('Image pair number: %d of %d\nTX = %0.3f\tTY = %0.3f\n\n', k, n_pairs, TX, TY);
%     imagesc(phase_residue_matrix + branch_cut_matrix);
%     axis image;
%     pause;
    
end

% End timer.
t2 = double(toc(t1));
fprintf('Computed branch cuts for %d arrays in %d seconds\n\n', n_pairs, t2);
