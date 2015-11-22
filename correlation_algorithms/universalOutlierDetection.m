function isOutlier = universalOutlierDetection(VARS, GRIDSIZE, STENCILRADIUS, THRESH, EXPECTED_DIFF)
% This function performs universal outlier detection (UOD) on a
% rectilinear velocity field (U, V)and returns a matrix isOutlier 
% whose value is 1 at the points that are detected as outliers
% and 0 at the points that are not detected as outliers.

% Default to expected difference of zero pixels
if nargin < 5
    EXPECTED_DIFF = 0;
end

% Number of variables on which to perform outlier detection. 
nVars = size(VARS, 2);

% Calculate the height and width of the vector field.
fieldHeight = GRIDSIZE(1);
fieldWidth  = GRIDSIZE(2);

% Stencil radius for this pass
r = STENCILRADIUS;

% Outside stencil element numbers
stencilElements = [(1 : (2 * r + 1)*r + r), ...
    (2 * r + 1)*r + r + 2 : (2*r + 1)^2];

% Initialize the normalized median-difference vectors.
normDiffs = zeros(fieldHeight, fieldWidth, nVars);

% Number of elements in the stencil minus the center point
N = (2 * r + 1)^2 - 1;

% Loop over the different variables
for v = 1 : nVars
    
    % Reshape the variable vector into a matrix
    varMat = reshape(VARS(:, v), fieldHeight, fieldWidth);
    
    % Loop over the whole grid
    for m = 1 + r : fieldHeight - r
       for n = 1 + r : fieldWidth - r
           
           % Test value
           testValue = varMat(m, n);
           
           % Extract the velocity components and their
           % surrounding values at each grid point.
           varStencil = varMat(m - r : m + r, n - r : n + r);

           % Stencils as columns
           varCol = varStencil(:);

           % Stencil elements excluding center points
           varColOutside = varCol(stencilElements);

                % Median value of surrounding vectors
                varMed = (varColOutside(N/2)+varColOutside(N/2+1))/2;

                % Sorted difference between the non-NAN values and the median of
                % the surrounding vectors
                MADfull = sort(abs(varColOutside-varMed));

                % Median of the medians of the surrounding vectors
                Q = (MADfull(N/2)+MADfull(N/2+1))/2;

                % Ratio of the magnitude of the (test vector - the median of
                % surrounding vectors) to the (median of the medians plus the expected variance)
                normDiffs(m, n, v) = abs(testValue-varMed)/(Q + EXPECTED_DIFF) > THRESH;
       end
    end
end

% Determine which elements are outliers
% isOutlier = sqrt(sum(normDiffs, 3)) > THRESH;
isOutlier = any(normDiffs, 3);


end


