function region_mat = make_subregion_matrix(IMAGE, GRID_SPACING, REGION_SIZE);

[image_height, image_width, num_channels] = size(IMAGE);

[x, y] = gridImage([image_height, image_width], GRID_SPACING, REGION_SIZE(1)/2 * [1, 1], REGION_SIZE(2)/2 * [1, 1]);

region_mat = extractSubRegions(IMAGE, REGION_SIZE, x, y);

end