function REGION_OUT = zero_mean_region(REGION_IN);

    REGION_OUT = REGION_IN - mean(REGION_IN(:));

end