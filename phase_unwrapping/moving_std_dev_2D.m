function ARRAY_OUT = moving_std_dev_2D(INPUT_ARRAY, KERNEL_LENGTH)

    % Squared values
    x2 = INPUT_ARRAY.^2;
    
    % Covolution kernel
    kernel = ones(KERNEL_LENGTH, 1);

    % Do the convolutions
    sum_x = conv2(kernel, kernel, INPUT_ARRAY, 'same');
    sum_x2 = conv2(kernel, kernel, x2, 'same');

    ARRAY_OUT = 1 / (KERNEL_LENGTH^2 - 1) * ...
        (sum_x2 - (sum_x.^2 / (KERNEL_LENGTH^2)));

end