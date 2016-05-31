function compile_calculate_get_region_props()


ARRAY = coder.typeof(1.00, [128, 128]);


% Set up the coder configuration
cfg = coder.config('mex');
% cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
cfg.GenerateReport = true;

% Run coder to generate the mex file.
codegen -config cfg get_region_props -args {ARRAY};

end
