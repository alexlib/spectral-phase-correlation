function compile_fit_gaussian_2D()


INPUT_SIGNAL = coder.typeof(1.00, [inf, inf]);

% Set up the coder configuration
cfg = coder.config('mex');
cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
cfg.GenerateReport = true;

% Run coder to generate the mex file.
codegen -config cfg fit_gaussian_2D -args {INPUT_SIGNAL};

end
