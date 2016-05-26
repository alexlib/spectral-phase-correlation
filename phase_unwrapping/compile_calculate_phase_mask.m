function compile_calculate_phase_mask()

PHASE_QUALITY = coder.typeof(1.00, [inf, inf]);
KERNEL_RADIUS = 1.00;
MAX_STD = 1.00;

% Set up the coder configuration
cfg = coder.config('mex');
cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
cfg.GenerateReport = true;

% Run coder to generate the mex file.
codegen -config cfg calculate_phase_mask_gaussian -args {PHASE_QUALITY, KERNEL_RADIUS, MAX_STD};

end
