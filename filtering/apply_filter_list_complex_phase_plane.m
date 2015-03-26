function COMPLEX_PHASE_PLANE = apply_filter_list_complex_phase_plane(...
    COMPLEX_PHASE_PLANE, FILTER_LIST, KERNEL_SIZE_LIST, COMPILED);

% Make sure kernel size list is at least as long as filter list
if length(KERNEL_SIZE_LIST) < length(FILTER_LIST)
   KERNEL_SIZE_LIST{length(FILTER_LIST)} = [];
end

% Loop over the list of filters
for k = 1 : length(FILTER_LIST)
   
    COMPLEX_PHASE_PLANE = filter_complex_phase_plane(...
    COMPLEX_PHASE_PLANE, FILTER_LIST{k}, KERNEL_SIZE_LIST{k}, COMPILED);
    
end


end