function [UVAL, VVAL, ISOUTLIER] = validateField_prana(X, Y, U, V, UOD_EXPECTED_DIFF)
% Size of the grid

% Default value
if nargin < 5
    UOD_EXPECTED_DIFF = 2 * [1, 1];
end

% Assume symmetric
if length(UOD_EXPECTED_DIFF) == 1
    UOD_EXPECTED_DIFF = UOD_EXPECTED_DIFF * [1, 1];
end

% Hard code a bunch of validation parameters
Eval = zeros(size(U));
ThreshSwitch = 0;
UODswitch = 1;
BootSwitch = 0;
extraPeakSwitch = 0;
Uthresh = [-inf inf];
Vthresh = [-inf inf];
UODthresh = [3 2];
UODwinsize = [3 3; 3 3];
BootPer = 0;
BootIter = 0;
BootKMax = 0;
c = zeros(length(X(:)), 1);
d = zeros(length(X(:)), 1);

% v = -V;
% y = flipud(Y);

% Do UOD
[UVAL, VVAL, ISOUTLIER] = VAL(X(:), Y(:), U(:), V(:), Eval(:), c(:), d(:),ThreshSwitch,UODswitch,BootSwitch,extraPeakSwitch,...
                        Uthresh,Vthresh,UODwinsize,UODthresh, UOD_EXPECTED_DIFF, BootPer,BootIter,BootKMax);

end

function [Uval,Vval,Evalval,Cval,Dval,DXval,DYval,ALPHAval] = VAL(X, Y, U, V, Eval,C,D,Threshswitch,UODswitch,Bootswitch,extrapeaks,Uthresh,Vthresh,UODwinsize,UODthresh, UOD_EXPECTED_DIFF, Bootper,Bootiter,Bootkmax,DX,DY,ALPHA)
% --- Validation Subfunction ---
if extrapeaks
    number_of_peaks_used = 3;
else
    number_of_peaks_used = 1;
end

imClass = 'double';

if exist('DX','var')
    [~,~,~,~,DX,DY,ALPHA]=matrixform(X,Y,U,V,DX,DY,ALPHA);
    [X,Y,U,V,Eval,C,D]=matrixform(X,Y,U,V,Eval,C,D);
else
    [X,Y,U,V,Eval,C,D]=matrixform(X,Y,U,V,Eval,C,D);
    DX    = zeros(size(D),imClass);
    DY    = zeros(size(D),imClass);
    ALPHA = zeros(size(D),imClass);
end

Uval=U(:,:,1);
Vval=V(:,:,1);
Evalval=Eval(:,:,1);

if ~isempty(C)
    Cval=C(:,:,1);
    Dval=D(:,:,1);
else
    Cval=[];
    Dval= [];
end

    DXval    = DX(:,:,1);
    DYval    = DY(:,:,1);
    ALPHAval = ALPHA(:,:,1);
    
    
    
S=size(X);

if Threshswitch || UODswitch
    for i=1:number_of_peaks_used
        %Thresholding
        if Threshswitch
            [Uval,Vval,Evalval] = Thresh(Uval,Vval,Uthresh,Vthresh,Evalval);
        end

        %Univeral Outlier Detection
        if UODswitch
            t=permute(UODwinsize,[2 3 1]);
            t=t(:,t(1,:)~=0);
            
            % T are the UOD window sizes (in pixels) in the row
            % and column directions for each UOD pass. 
            
            [Uval,Vval,Evalval] = UOD(Uval,Vval,t',UODthresh, UOD_EXPECTED_DIFF, Evalval);
        end

        
        %Try additional peaks where validation failed
        if i<number_of_peaks_used
            Utemp=U(:,:,i+1);Vtemp=V(:,:,i+1);Evaltemp=Eval(:,:,i+1);Ctemp=C(:,:,i+1);Dtemp=D(:,:,i+1);
            DXtemp=DX(:,:,i+1);DYtemp=DY(:,:,i+1);ALPHAtemp=ALPHA(:,:,i+1);
            Uval(Evalval>0)=Utemp(Evalval>0);
            Vval(Evalval>0)=Vtemp(Evalval>0);
            Cval(Evalval>0)=Ctemp(Evalval>0);
            Dval(Evalval>0)=Dtemp(Evalval>0); 
            Evalval(Evalval>0)=Evaltemp(Evalval>0);
            
            DXval(Evalval>0)=DXtemp(Evalval>0); 
            DYval(Evalval>0)=DYtemp(Evalval>0); 
            ALPHAval(Evalval>0)=ALPHAtemp(Evalval>0); 
        end
    end
end

%limit replacement search radius to largest region tested during UOD
maxSearch = floor( (max(UODwinsize(:)) - 1) / 2 );

%replacement
for i = 1:S(1)
    for number_of_peaks_used=1:S(2)
        if Evalval(i,number_of_peaks_used)>0
            %initialize replacement search size
            q=0;
            s=0;

            %get replacement block with at least 8 valid points, but stop if region grows bigger than UOD test region
            while s==0
                q=q+1;
                Imin = max([i-q 1   ]);
                Imax = min([i+q S(1)]);
                Jmin = max([number_of_peaks_used-q 1   ]);
                Jmax = min([number_of_peaks_used+q S(2)]);
                Iind = Imin:Imax;
                Jind = Jmin:Jmax;
                Ublock = Uval(Iind,Jind);
                if q >= maxSearch || length(Ublock(~isnan(Ublock)))>=8 
                    Xblock = X(Iind,Jind)-X(i,number_of_peaks_used);
                    Yblock = Y(Iind,Jind)-Y(i,number_of_peaks_used);
                    Vblock = Vval(Iind,Jind);
                    s=1;
                end
            end
            
            %distance from erroneous vector
            Dblock = (Xblock.^2+Yblock.^2).^-0.5;
            Dblock(isnan(Ublock))=nan;
            Dblock(isinf(Dblock))=nan;

            %validated vector
            Uval(i,number_of_peaks_used) = nansum(nansum(Dblock.*Ublock))/nansum(nansum(Dblock));
            Vval(i,number_of_peaks_used) = nansum(nansum(Dblock.*Vblock))/nansum(nansum(Dblock));       
        end
    end
end

%clean up any remaining NaNs
Uval(isnan(Uval)) = 0;
Vval(isnan(Vval)) = 0;

%Bootstrapping
if Bootswitch
    [Uval,Vval,Evalval] = bootstrapping(X,Y,Uval,Vval,Bootper,Bootiter,Bootkmax,Evalval);
end

%convert back to vector
[Uval,Vval,Evalval,Cval,Dval]=vectorform(X,Y,Uval,Vval,Evalval,Cval,Dval);
[DXval,DYval,ALPHAval]=vectorform(X,Y,DXval,DYval,ALPHAval,[],[]);

end



function [X,Y,U,V,Eval,C,D]=matrixform(x,y,u,v,eval,c,d)
% --- Vector to Matrix Subfunction ---

imClass = 'double';

%find unique x and y grid points
a=sort(unique(x));
b=sort(unique(y));
N=length(x);

%initialize matrices
U=nan(length(b),length(a),size(u,2));
V=nan(length(b),length(a),size(v,2));
Eval= -1 * ones(length(b),length(a),size(eval,2),imClass);

%generate grid matrix
[X,Y]=meshgrid(a,b);

%generate variable matrices (nans where no data available)
for i=1:size(U,3)
    for n=1:N
        I=find(b==y(n));
        J=find(a==x(n));
        U(I,J,i) = u(n,i);
        V(I,J,i) = v(n,i);
        Eval(I,J,i) = eval(n);
    end
end
if ~isempty(c)
    C=nan(length(b),length(a),size(c,2));
    for i=1:size(c,2)
        for n=1:N
            I= b==y(n);
            J= a==x(n);
            C(I,J,i)=c(n,i);
        end
    end
else
    C=[];
end
if ~isempty(d)
    D=nan(length(b),length(a),size(d,2));
    for i=1:size(d,2)
        for n=1:N
            I= b==y(n);
            J= a==x(n);
            D(I,J,i)=d(n,i);
        end
    end
else
    D=[];
end

end


function [u,v,eval,c,d]=vectorform(x,y,U,V,Eval,C,D)
% --- Matrix to Vector Subfunction ---
x=x(:);y=y(:);
%find unique x and y grid points
a=sort(unique(x));
b=sort(unique(y));
N=length(x(:));

imClass = 'double';

%initialize vectors
S=size(x(:));
u    = zeros(S,imClass);
v    = zeros(S,imClass);
eval = zeros(S,imClass);
if ~isempty(C)
    c = zeros(S,imClass);
    d = zeros(S,imClass);
else
    c = [];
    d = [];
end

%generate data vectors where data is available
for n=1:N
    I=find(b==y(n));
    J=find(a==x(n));
    u(n)    = U(I,J);
    v(n)    = V(I,J);
    eval(n) = Eval(I,J);
    if ~isempty(C)
        c(n)    = C(I,J);
        d(n)    = D(I,J);
    end
end

end

function [U, V, Eval] = UOD(U, V, UOD_WINDOW_SIZE, UOD_TOLERANCE, UOD_EXPECTED_DIFF, Eval)
% --- Universal Outlier Detection Validation Subfunction ---

% This is the number of UOD iterations to perform.
number_of_uod_iterations = length(UOD_TOLERANCE);

% This is the number of rows and columns in the array of values.
[num_rows, num_columns] = size(U);

% These are the expected pixel differences in the X and Y directions.
uod_expected_diff_v = UOD_EXPECTED_DIFF(1);
uod_expected_diff_u = UOD_EXPECTED_DIFF(2);

% This loop loops over the specified number of UOD iterations ,
% identifying outliers at each iteration.
for k = 1 : number_of_uod_iterations
    
    % This is the UOD window radius in the row direction.
    uod_window_radius_rows = floor( ( UOD_WINDOW_SIZE(k, 2) - 1 ) / 2);
    
    % This is the UOD window radius in the column direction.
    uod_window_radius_cols = floor( ( UOD_WINDOW_SIZE(k, 1) - 1 ) / 2);
    
    % Loop over all of the vectors.
    % i is the row number
    for i = 1 : num_rows
        
        % j is the column number
        for j = 1 : num_columns
            
            % This variable indicates the UOD iteration number at which
            % the (i, j) vector was flagged as an outlier.
            % Eval = 0 indicates that the vector was never flagged as an
            % outlier.
            % Eval = 1 indicates that the vector was flagged as an outlier
            % on the first UOD iteration. Etc. 
            if Eval(i,j) == 0           
                
                % This flag specifies whether a returned array of values
                % is acceptable for UOD analysis based on criteria
                % specified below. 
                accept_array = 0;
                
                % These are variable UOD window radii in the 
                % row and column direction. These variables are
                % created to allow the UOD window radii to increase
                % in the following loop without affecting the
                % user-specified UOD window radii.
                uod_window_radius_rows_temp = uod_window_radius_rows;
                uod_window_radius_cols_temp = uod_window_radius_cols;
                
                % Increment the UOD window radii until the array of values
                % is acceptable for UOD analysis based on the specified
                % criteria. 
                while accept_array == 0
                    
                    % This is the index of the top-most row to be evaluated
                    row_min = max([i - uod_window_radius_rows_temp, 1 ]);
                    
                    % This is the index of the bottom-most row to be evaluated
                    row_max = min([i + uod_window_radius_rows_temp, num_rows]);
                    
                    % This is the index of the left-most column to be evaulated.
                    column_min = max([j - uod_window_radius_cols_temp, 1 ]);
                    
                    % This is the index of the right-most column to be evaluated.
                    column_max = min([j + uod_window_radius_cols_temp, num_columns]);
                    
                    % These are the indices of the rows and columns
                    % to which UOD will be applied.
                    rows_to_evaluate = row_min : row_max;
                    columns_to_evaluate = column_min : column_max;
                    
                    % This is the array ("block") of vector values to evaluate with UOD. 
                    Ublock = U(rows_to_evaluate, columns_to_evaluate);
                    
                    % This line checks whether the array of vectors
                    % contains at least eight values that have not already
                    % been identified as outliers by previous UOD iterations
                    % (those values that have been identified as outliers 
                    % should have already been replaced with NaNs). 
                    % The other check performed is whether the temporary
                    % UOD radii have reached values equal to or greater
                    % than twice the originally specified radii. If 
                    % either of these criteria are true, then the block
                    % of values is saved for UOD evaluation. If neither
                    % criteria is true, then the UOD window radii are
                    % incremented by one.
                    if length(Ublock(~isnan(Ublock))) >= 8 || any( [uod_window_radius_rows_temp, uod_window_radius_cols_temp] >= 2 * [uod_window_radius_rows, uod_window_radius_cols])

                        % If the array of U values met the acceptable
                        % criteria, then read the corresponding V values
                        % within that array.
                        Vblock = V(rows_to_evaluate ,columns_to_evaluate);
                        
                        % Set the "acceptable array" flag to one to 
                        % escape this "while" loop.
                        accept_array = 1;
                        
                    else
                        
                        % This increments the variable-sized UOD window
                        % radii. Also, the acceptable array flag remains
                        % set to zero so that this "while" loop continues.
                        uod_window_radius_rows_temp = uod_window_radius_rows_temp + 1;
                        uod_window_radius_cols_temp = uod_window_radius_cols_temp + 1;
                        
                    end
                end
                
                % This is row index within the evaluation array
                % of the vector to be evaluated.
                Ipos = find(rows_to_evaluate == i);
                
                % This is column index within the evaluation array
                % of the vector to be evaluated.
                Jpos = find(columns_to_evaluate == j);
                
                % This returns the UOD outlier criterion for the U
                % components of the field.
                outlier_criterion_u = UOD_sub(Ublock, Ipos, Jpos, uod_expected_diff_u);
                
                % This returns the UOD outlier criterion for the V
                % components of the field.
                outlier_criterion_v = UOD_sub(Vblock, Ipos, Jpos, uod_expected_diff_v);

                % This checks whether the outlier criterion exceeds
                % the outlier threshold for either component of the field.
                if outlier_criterion_u > UOD_TOLERANCE(k) || outlier_criterion_v > UOD_TOLERANCE(k)
                    
                    % If the outlier criterion exceeds the outlier
                    % threshold for either component of the field, 
                    % set both components of that vector to NaNs.
                    U(i, j) = nan;
                    V(i, j) = nan;
                    
                    % This variable specifies the UOD iteration number at 
                    % which the vector was flagged as an outlier.
                    Eval(i, j) = k;
                end
            end
        end
    end
end

end


function R = UOD_sub(W, p, q, EXPECTED_DIFFERENCE)
% --- Universal Outlier Detection Algorithm ---

% EXPECTED_DIFFERENCE = 0.1;

%remove value from query point
x = W(p,q);
W(p,q) = nan;

%remove any erroneous points
P = W(:);
Ps = sort(P);
Psfull = Ps(~isnan(Ps));
N = length(Psfull);

if N<=floor(length(W)/3)
    %return negative threshold value if no valid vectors in block
    R = inf;
else
    %return the median deviation normalized to the MAD
    if mod(N,2)==0
        
        % Median value of surrounding vectors
        M = (Psfull(N / 2) + Psfull(N / 2 + 1))/2;
        
        % Sorted difference between the non-NAN values and the median of
        % the surrounding vectors
        MADfull = sort(abs(Psfull - M));
        
        % Median of the medians of the surrounding vectors
        Q = (MADfull(N/2)+MADfull(N/2+1))/2;
        
        % Ratio of the magnitude of the (test vector - the median of
        % surrounding vectors) to the (median of the medians plus the expected variance)
        R = abs(x-M)/(Q+EXPECTED_DIFFERENCE);
    else
        M = Psfull((N+1)/2);
        MADfull = sort(abs(Psfull-M));
        Q = MADfull((N+1)/2);        
        R = abs(x-M)/(Q+EXPECTED_DIFFERENCE);
    end
end

end