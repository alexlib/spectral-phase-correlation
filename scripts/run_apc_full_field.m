% run_apc_full_field

mask_path = '~/Desktop/xray_mask.tif';
image_mask = double(imread(mask_path));

im_dir = '/Users/matthewgiarra/Desktop/xray_test_01/raw';

im_base = 'img1_';

num_digits = 5;

ext = '.TIF';

im_start = 1;
im_end = 9;
im_step = 1;

c_step = 1;

% Grid spacing
grid_spacing = [16, 16];
region_dims = [128, 128];

image_nums_01 = im_start : im_step : im_end;
image_nums_02 = image_nums_01 + c_step;

% Number of images
num_images = length(image_nums_01);

% Make image path list
for k = 1 : num_images
    image_name_01 = [im_base num2str(image_nums_01(k), '%05d') ext];
    image_name_02 = [im_base num2str(image_nums_02(k), '%05d') ext];
    
   image_list_01{k} = fullfile(im_dir, image_name_01);
   image_list_02{k} = fullfile(im_dir, image_name_02);
    
    
end

[X, Y, U, V] = apcFullField(image_list_01, image_list_02,...
    grid_spacing, region_dims, image_mask);

[UVAL, VVAL, IS_OUTLIER] = validateField_prana(X, Y, U, V, 1 * [1, 1]);

inds = find(U == UVAL & V == VVAL);

quiver(X(inds), Y(inds), S * U(inds), S * V(inds), 'black'); axis image;



