function compile_remove_dipoles()


FLAGS_MATRIX = coder.typeof(uint8(1), [inf, inf]);


% Set up the coder configuration
cfg = coder.config('mex');
cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
cfg.GenerateReport = true;

% Run coder to generate the mex file.
codegen -config cfg remove_dipoles -args {FLAGS_MATRIX};



end