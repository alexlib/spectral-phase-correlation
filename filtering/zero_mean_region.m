function REGION = zero_mean_region(REGION);
% In-place zero mean


    if size(REGION, 3) > 1
        for k = 1 : size(REGION, 3)
           subregion = REGION(:, :, k);
           REGION(:, :, k) = REGION(:, :, k) - mean(subregion(:));
        end
    else
        REGION = REGION - mean(REGION(:));
    end

    

end