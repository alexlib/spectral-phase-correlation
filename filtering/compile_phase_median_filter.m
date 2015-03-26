function compile_phase_median_filter()


WRAPPED_PHASE_PLANE = coder.typeof(1.00 + 1i, [inf, inf]);
KER_SIZE = coder.typeof(1.00, [1, 2]);

% Set up the coder configuration
cfg = coder.config('mex');
cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
cfg.GenerateReport = true;

% Run coder to generate the mex file.
codegen -config cfg phase_median_filter -args {WRAPPED_PHASE_PLANE, KER_SIZE};

end
