function compile_all_phase_unwrapping

% Compile the phase residue finding code.
fprintf(1, 'Compiling "calculate_phase_residues.m" to MEX...\n\n');
compile_calculate_phase_residues;

% Compile the branch cut algorithm
fprintf(1, 'Compiling "calculate_branch_cuts_goldstein.m" to MEX...\n\n');
compile_calculate_branch_cuts_goldstein;

% Compile the flood fill algorithm
fprintf(1, 'Compiling "FloodFill.m" to MEX...\n\n');
compile_FloodFill;



end