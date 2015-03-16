function compile_calculate_branch_cuts_goldstein()


% Example variables
FLAGS_MATRIX = coder.typeof(uint8(1.00), [inf, inf]);
MAX_BOX_SIZE = 7.00;

% Set up the coder configuration
cfg = coder.config('mex');
cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
cfg.GenerateReport = true;

% Run coder to generate the mex file.
codegen -config cfg calculate_branch_cuts_goldstein -args {FLAGS_MATRIX, MAX_BOX_SIZE};

end
