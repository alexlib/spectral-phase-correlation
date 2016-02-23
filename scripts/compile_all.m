% This script compiles all the compile-able codes
% in this library.

% Get the path to the current dir
thisDir = pwd;

% Compile the codes in the "phase_unwrapping" directory
cd ../phase_unwrapping;

% Compile the Phase Residue code
disp('Compiling PhaseResidues.m to mex file...');
compile_calculate_phase_residues;

disp('Compiling BranchCuts.m to mex file...');
compile_calculate_branch_cuts_goldstein;

disp('Compiling FloodFill.m to mex file...');
compile_FloodFill;

disp('Compiling make_flags_matrix.m to mex file ...');
compile_make_flags_matrix;

disp('Compiling remove_dipoles.m to mex file...');
compile_remove_dipoles;

disp('Compiling calculate_phase_quality.m to mex file...')
compile_calculate_phase_quality;

cd ../filtering;

disp('Compiling phase_median_filter.m to mex file...');
compile_phase_median_filter;

% Switch back to the parent directory
cd(thisDir);
