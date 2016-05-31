
function [AREAS, CENTROIDS, MAJOR_AXIS, MINOR_AXIS, THETA, REGION_ID] = get_region_props(REGION)

    % Declare System objects as persistent.
    persistent H_OBJ;

    % Initialize persistent System objects only once
    if isempty(H_OBJ)
        % This constructs a vision toolbox object
        % to be used for blob detection for creating
        % the APC filter.
        H_OBJ = vision.BlobAnalysis(...
        'MajorAxisLengthOutputPort', true, ...
        'MinorAxisLengthOutputPort', true, ...
        'LabelMatrixOutputPort', true, ...
        'ExcludeBorderBlobs', true, ...
        'OrientationOutputPort', true);
    end

    % Do the calculation
    [AREAS, CENTROIDS, ~, MAJOR_AXIS, MINOR_AXIS, THETA, REGION_ID] = step(H_OBJ, REGION);
    
end

