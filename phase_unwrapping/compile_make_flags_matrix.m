function compile_make_flags_matrix()

% Example variables
RESIDUE_MATRIX    = coder.typeof(double(1.00), [inf, inf]);

% Set up the coder configuration
cfg = coder.config('mex');
cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
cfg.GenerateReport = true;

% Run coder to generate the mex file.
codegen -config cfg make_flags_matrix -args {RESIDUE_MATRIX};



end