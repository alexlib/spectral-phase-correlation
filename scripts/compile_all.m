% This script compiles all the compile-able codes
% in this library.

% Get the path to the current dir
thisDir = pwd;

% Compile the codes in the "phase_unwrapping" directory
cd ../phase_unwrapping/PhaseUnwrapping2D;

% Compile the Phase Residue code
disp('Compiling PhaseResidues.m to mex file...');
compile_PhaseResidues;

disp('Compiling BranchCuts.m to mex file...');
compile_BranchCuts;

disp('Compiling FloodFill.m to mex file...');
compile_FloodFill;

cd ../../filtering;

disp('Compiling phase_median_filter.m to mex file...');
compile_phase_median_filter;

% Switch back to the parent directory
cd(thisDir);
