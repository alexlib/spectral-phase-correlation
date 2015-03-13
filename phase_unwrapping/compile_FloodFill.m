function compile_FloodFill();

% Example variables
IM_PHASE    = coder.typeof(double(1.00), [inf, inf]);
BRANCH_CUTS = coder.typeof(ones(64, 64, 'uint8'), [inf, inf]);

% Set up the coder configuration
cfg = coder.config('mex');
cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
cfg.GenerateReport = true;

% Run coder to generate the mex file.
codegen -config cfg FloodFill -args {IM_PHASE, BRANCH_CUTS};

end