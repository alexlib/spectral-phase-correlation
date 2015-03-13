function compile_spc_plane_fit();

% Example variables
unwrapped_phase_Plane    = coder.typeof(double(1.00), [inf, inf]);
weighting_matrix = coder.typeof(double(1.00), [inf, inf]);

% Set up the coder configuration
cfg = coder.config('mex');
cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
cfg.GenerateReport = true;

% Run coder to generate the mex file.
codegen -config cfg spc_plane_fit -args {unwrapped_phase_Plane, weighting_matrix};

end