function Z_OUT = unwrap_phase(Z_IN);
% Unwrap phase diagram via edge detection

% Number of hough lines
nLines = 4;

% Filter the input image
z_filt = svd_denoise(Z_IN, 10, 5);

% Image derivatives
dx = imdifferentiate(z_filt, [1 1 1], 1, 0, 0);
dy = imdifferentiate(z_filt, [1 1 1], 0, 1, 0);
dydx = dy .* dx;
d = dy + dx + dydx;

% Detect edges in the denoised image
z_edge = edge(d, 'sobel', 1.2);

% Calculate the dimensions of the 
% edge image
[height, width] = size(z_edge);

% Calculate geometric centroid
xc = width/2 + 0.5;
yc = height/2 + 0.5;

% Detect lines in the edge image
[H, th, rho] = hough(z_edge);

% Find the first two dominant Hough peaks
hough_peaks = houghpeaks(H, nLines);

% Radii and angles of the detected Hough lines
sorted_vals =  flipud(sortrows([(rho(hough_peaks(:, 1)))', (th(hough_peaks(:, 2)))'], 1));

% Extract radii and angles from sorted values
lines_rho = sorted_vals(:, 1);
lines_th = sorted_vals(:, 2);

% Make some coordinates
u = 1 : width;

% Initialize the vertical coordinates of the lines 
v = zeros(nLines, width);

for k = 1 : nLines
   v(k, :) = (lines_rho(k) - u .* cosd(lines_th(k))) ./ sind(lines_th(k));
end

% Display the edge image
% imagesc(z_edge); axis image; set(gca, 'ydir', 'normal');

% for k = 1 : nLines
%     plot(u, v(k, :), '--w');
% end

% Calculate difference in radial coordinates of lines
diff_r = abs(mean(diff(lines_rho)));

% Make the wrap count matrix
% Determine diagonal length of the image
imageDiameter = sqrt(width^2 + height^2);

% Number of radii greater than the most prominent hough line
nGreater = floor((imageDiameter - lines_rho(1)) / diff_r);
nLess = floor(lines_rho(1)/diff_r);

% Determine radial coordinates of the other lines in the image
lines_r_augmented = lines_rho(1) + diff_r * (-nLess : nGreater);

% Number of lines
nLinesFound = length(lines_r_augmented);

% Initialize augmented vertical ordinate matrix
v_augmented = zeros(nLinesFound, width);

% Calculate and draw the lines. 
% These are the phase discontinuity lines.
for k = 1 : nLinesFound
   v_augmented(k, :) = (lines_r_augmented(k) - u .* cosd(lines_th(1))) ./ sind(lines_th(1));
end

% Calculate the phase wrap count
wrap_count = zeros(size(Z_IN));

[x, y] = meshgrid(1 : width, 1 : height);

% Determine the wrap count matrix!
for k = 1 : nLinesFound
   v_aug_mat = (lines_r_augmented(k) - x .* cosd(lines_th(1))) ./ sind(lines_th(1));
   wrap_count = wrap_count + (y > v_aug_mat);
end

% Unwrap the phase by the wrap count matrix!
Z_OUT = Z_IN +  2* pi * wrap_count;

imagesc(Z_IN); axis image; set(gca, 'ydir','normal');
hold on
for k = 1 : nLinesFound;
   plot(u, v_augmented(k, :), 'black', 'linewidth', 2);
end
hold off

figure;
mesh(Z_OUT);

end





