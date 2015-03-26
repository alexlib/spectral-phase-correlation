function INDEX = calculate_ft_zero_pixels(LENGTH)
% This function calculates the index of thee zero-frequency pixel
% for Matlab-calculated FFTs that have been shifted so that the 
% zero-frequency pixels are at the center of the array. 
% i.e., of FFT-shifted FTs.
% 
% Matlab puts the zero-frequency pixel at (length / 2) + 1
% for array dimensions with even numbers of elements, 
% and at (length / 2) + 0.5 for array dimensions with
% odd numbers of elements.
INDEX = (LENGTH / 2) + 1 - 0.5  * mod(LENGTH, 2);

end