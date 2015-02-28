function compile_BranchCuts();

% Example variables
RESIDUE_CHARGE    = coder.typeof(1.00, [inf, inf]);
MAX_BOX_SIZE = coder.typeof(1.00, [1, 1]);

% Set up the coder configuration
cfg = coder.config('mex');
cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
cfg.GenerateReport = true;

% Run coder to generate the mex file.
codegen -config cfg BranchCuts -args {RESIDUE_CHARGE, MAX_BOX_SIZE};

end