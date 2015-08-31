function compile_calculate_phase_quality()


WRAPPED_PHASE_PLANE = coder.typeof(1.00, [inf, inf]);
KERNEL_RADIUS = 1.00;

% Set up the coder configuration
cfg = coder.config('mex');
cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
cfg.GenerateReport = true;

% Run coder to generate the mex file.
codegen -config cfg calculate_phase_quality -args {WRAPPED_PHASE_PLANE, KERNEL_RADIUS};

end
