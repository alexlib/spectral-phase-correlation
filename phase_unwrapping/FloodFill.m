%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% FloodFill.m unwraps the phase image, avoiding all branch cuts.
% Created by B.S. Spottiswoode on 12/10/2004
% Last modified on 13/10/2004
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [IM_unwrapped, rowref, colref] = FloodFill(IM_phase, BRANCH_CUT_MATRIX)

[height, width]=size(IM_phase);
% figure; imagesc(immultiply(IM_phase, ~branch_cuts)), colormap(gray), axis square, axis off, title('Phase image');
% uiwait(msgbox('Select a known true phase reference point','Phase reference point','modal'));
% [xref,yref] = ginput(1); 

% Use the matlab floodfill algorithm to detect isolated
% portions of the image.
isolated_regions = imfill(BRANCH_CUT_MATRIX) - BRANCH_CUT_MATRIX;

% Determine the positions of the non-branch cut pixels
% that don't lie within isolated regions
non_branch_cuts = find(BRANCH_CUT_MATRIX < 1 & isolated_regions < 1);
% non_branch_cuts = find(BRANCH_CUT_MATRIX < 1);


% Determine the row and column indices of these pixels
% [y_ind, x_ind] = ind2sub([height, width], non_branch_cuts);
y_ind = rem(non_branch_cuts - 1, height) + 1;
x_ind = (non_branch_cuts - y_ind) / height + 1;

% Determine the center of the array
xc = width/2;
yc = height/2;

% Determine radial position of those points
r = sqrt((x_ind - xc).^2 + (y_ind - yc).^2);

% This picks the unwrapping starting position
% At the non-branch cut pixel closest to the 
% center of the spectrum.
rowref = y_ind(r == min(r));
colref = x_ind(r == min(r));

% Check if this 

% Flag specifying that the starting point corresponds
% to a branch cut
% branch_cut_start = branch_cuts(rowref, colref);

% if logical(branch_cut_start)
%     error('Selected point corresponds to a branch cut.');
% end

IM_unwrapped=zeros(height,width);
unwrapped_binary=zeros(height,width);
adjoin=zeros(height,width);

adjoin(rowref-1, colref)=1;                                 %Label the first four adjoining pixels
adjoin(rowref+1, colref)=1;
adjoin(rowref, colref-1)=1;
adjoin(rowref, colref+1)=1;
IM_unwrapped(rowref, colref)=IM_phase(rowref, colref);      %Mark the first pixel as unwrapped
unwrapped_binary(rowref, colref)=1;

% disp('Performing floodfill operation ...');
count_limit=0;
adjoin_stuck=0;
while sum(sum(adjoin(2:height-1,2:width-1)))~=0              %Loop until there are no adjoining pixels or they all lie on the border
    while count_limit<100                                   %or the code gets stuck because of isolated regions
        [r_adjoin, c_adjoin]=find(adjoin);                          %Obtain coordinates of adjoining unwrapped phase pixels
        if (length(r_adjoin)==adjoin_stuck)
            count_limit=count_limit+1;                              %Make sure loop doesn't get stuck
        else
            count_limit=0;
        end
        temp = length(r_adjoin);
        adjoin_stuck = temp;
        for i=1:temp(1)
            r_active=r_adjoin(i);
            c_active=c_adjoin(i);
            if r_active <= height-1 && r_active>=2 && c_active<=width-1 && c_active>=2                    %Ignore pixels near the border
                %First search below for an adjoining unwrapped phase pixel
                if BRANCH_CUT_MATRIX(r_active+1, c_active)==0 && unwrapped_binary(r_active+1, c_active)==1
                    phase_ref=IM_unwrapped(r_active+1, c_active);                                   %Obtain the reference unwrapped phase
                    p=unwrap([phase_ref IM_phase(r_active, c_active)]);                             %Unwrap the active pixel
                    IM_unwrapped(r_active, c_active)=p(2);
                    unwrapped_binary(r_active, c_active)=1;                                         %Mark the pixel as unwrapped
                    adjoin(r_active, c_active)=0;                                                   %Remove it from the list of adjoining pixels
                    if r_active-1>=1 && unwrapped_binary(r_active-1, c_active)==0 && BRANCH_CUT_MATRIX(r_active-1, c_active)==0
                        adjoin(r_active-1, c_active)=1;
                    end
                    if c_active-1>=1 && unwrapped_binary(r_active, c_active-1)==0 && BRANCH_CUT_MATRIX(r_active, c_active-1)==0
                        adjoin(r_active, c_active-1)=1;
                    end
                    if c_active+1<=width && unwrapped_binary(r_active, c_active+1)==0 && BRANCH_CUT_MATRIX(r_active, c_active+1)==0
                        adjoin(r_active, c_active+1)=1;
                    end
                end
                %Then search above
                if BRANCH_CUT_MATRIX(r_active-1, c_active)==0 && unwrapped_binary(r_active-1, c_active)==1
                    phase_ref=IM_unwrapped(r_active-1, c_active);                                   %Obtain the reference unwrapped phase
                    p=unwrap([phase_ref IM_phase(r_active, c_active)]);                             %Unwrap the active pixel
                    IM_unwrapped(r_active, c_active)=p(2);
                    unwrapped_binary(r_active, c_active)=1;                                         %Mark the pixel as unwrapped
                    adjoin(r_active, c_active)=0;                                                   %Remove it from the list of adjoining pixels
                    %Update the new adjoining pixels:
                    if r_active+1<=height && unwrapped_binary(r_active+1, c_active)==0 && BRANCH_CUT_MATRIX(r_active+1, c_active)==0
                        adjoin(r_active+1, c_active)=1;
                    end
                    if c_active-1>=1 && unwrapped_binary(r_active, c_active-1)==0 && BRANCH_CUT_MATRIX(r_active, c_active-1)==0
                        adjoin(r_active, c_active-1)=1;
                    end
                    if c_active+1<=width && unwrapped_binary(r_active, c_active+1)==0 && BRANCH_CUT_MATRIX(r_active, c_active+1)==0
                        adjoin(r_active, c_active+1)=1;
                    end
                end
                %Then search on the right
                if BRANCH_CUT_MATRIX(r_active, c_active+1)==0 && unwrapped_binary(r_active, c_active+1)==1
                    phase_ref=IM_unwrapped(r_active, c_active+1);                                   %Obtain the reference unwrapped phase
                    p=unwrap([phase_ref IM_phase(r_active, c_active)]);                             %Unwrap the active pixel
                    IM_unwrapped(r_active, c_active)=p(2);
                    unwrapped_binary(r_active, c_active)=1;                                         %Mark the pixel as unwrapped
                    adjoin(r_active, c_active)=0;                                                   %Remove it from the list of adjoining pixels
                    if r_active+1<=height && unwrapped_binary(r_active+1, c_active)==0 && BRANCH_CUT_MATRIX(r_active+1, c_active)==0
                        adjoin(r_active+1, c_active)=1;
                    end
                    if c_active-1>=1 && unwrapped_binary(r_active, c_active-1)==0 && BRANCH_CUT_MATRIX(r_active, c_active-1)==0
                        adjoin(r_active, c_active-1)=1;
                    end
                    if r_active-1>=1 && unwrapped_binary(r_active-1, c_active)==0 && BRANCH_CUT_MATRIX(r_active-1, c_active)==0
                        adjoin(r_active-1, c_active)=1;
                    end
                end
                %Finally search on the left
                if BRANCH_CUT_MATRIX(r_active, c_active-1)==0 && unwrapped_binary(r_active, c_active-1)==1
                    phase_ref=IM_unwrapped(r_active, c_active-1);                                   %Obtain the reference unwrapped phase
                    p=unwrap([phase_ref IM_phase(r_active, c_active)]);                             %Unwrap the active pixel
                    IM_unwrapped(r_active, c_active)=p(2);
                    unwrapped_binary(r_active, c_active)=1;                                         %Mark the pixel as unwrapped
                    adjoin(r_active, c_active)=0;                                                   %Remove it from the list of adjoining pixels
                    if r_active+1<=height && unwrapped_binary(r_active+1, c_active)==0 && BRANCH_CUT_MATRIX(r_active+1, c_active)==0
                        adjoin(r_active+1, c_active)=1;
                    end
                    if c_active+1<=width && unwrapped_binary(r_active, c_active+1)==0 && BRANCH_CUT_MATRIX(r_active, c_active+1)==0
                        adjoin(r_active, c_active+1)=1;
                    end
                    if r_active-1>=1 && unwrapped_binary(r_active-1, c_active)==0 && BRANCH_CUT_MATRIX(r_active-1, c_active)==0
                        adjoin(r_active-1, c_active)=1;
                    end
                end
            end
        end
        
        %figure; imagesc(adjoin), colormap(gray), axis square, axis off, title('Adjoining pixels');
        %figure; imagesc(IM_unwrapped), colormap(gray), axis square, axis off, title('Pixels unwrapped');
    end
    
    % Print the number of iterations?
%     fprintf('Number of iterations: %d\n', count_limit);
    
    % 
    if count_limit >= 100
        break
    end
    
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Finally, fill in the branch cut pixels that adjoin the unwrapped pixels.
% This can be done because the branch cuts actually lie between the pixels,
% and not on top of them.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% disp('Filling in branch cuts that border on unwrapped pixels ...');
adjoin=zeros(height, width);                                 
%Re-load the adjoining pixel matrix with the branch cut values:
for i=2:height-1
    for j=2:width-1
       if BRANCH_CUT_MATRIX(i,j)==1 && ...                         %Identify which branch cut pixel borders an unwrapped pixel
          ( (BRANCH_CUT_MATRIX(i+1,j)==0 || BRANCH_CUT_MATRIX(i-1,j)==0 || BRANCH_CUT_MATRIX(i,j-1)==0 || BRANCH_CUT_MATRIX(i,j+1)==0) ) 
         adjoin(i,j)=1;
       end
    end
end

[r_adjoin, c_adjoin]=find(adjoin);                          %Obtain coordinates of adjoining unwrapped phase pixels

% Matt changed from 'size' to length
temp=length(r_adjoin);

for i=1:temp(1)
    r_active=r_adjoin(i);
    c_active=c_adjoin(i);
        %First search below for an adjoining unwrapped phase pixel
        if unwrapped_binary(r_active+1, c_active)==1
            phase_ref=IM_unwrapped(r_active+1, c_active);                                   %Obtain the reference unwrapped phase
            p=unwrap([phase_ref IM_phase(r_active, c_active)]);                             %Unwrap the active pixel
            IM_unwrapped(r_active, c_active)=p(2);
            unwrapped_binary(r_active, c_active)=1;                                         %Mark the pixel as unwrapped
            adjoin(r_active, c_active)=0;                                                   %Remove it from the list of adjoining pixels
        end
        %Then search above
        if unwrapped_binary(r_active-1, c_active)==1
            phase_ref=IM_unwrapped(r_active-1, c_active);                                   %Obtain the reference unwrapped phase
            p=unwrap([phase_ref IM_phase(r_active, c_active)]);                             %Unwrap the active pixel
            IM_unwrapped(r_active, c_active)=p(2);
            unwrapped_binary(r_active, c_active)=1;                                         %Mark the pixel as unwrapped
            adjoin(r_active, c_active)=0;                                                   %Remove it from the list of adjoining pixels
        end
        %Then search on the right
        if unwrapped_binary(r_active, c_active+1)==1
            phase_ref=IM_unwrapped(r_active, c_active+1);                                   %Obtain the reference unwrapped phase
            p=unwrap([phase_ref IM_phase(r_active, c_active)]);                             %Unwrap the active pixel
            IM_unwrapped(r_active, c_active)=p(2);
            unwrapped_binary(r_active, c_active)=1;                                         %Mark the pixel as unwrapped
            adjoin(r_active, c_active)=0;                                                   %Remove it from the list of adjoining pixels
        end
        %Finally search on the left
        if unwrapped_binary(r_active, c_active-1)==1
            phase_ref=IM_unwrapped(r_active, c_active-1);                                   %Obtain the reference unwrapped phase
            p=unwrap([phase_ref IM_phase(r_active, c_active)]);                             %Unwrap the active pixel
            IM_unwrapped(r_active, c_active)=p(2);
            unwrapped_binary(r_active, c_active)=1;                                         %Mark the pixel as unwrapped
            adjoin(r_active, c_active)=0;                                                   %Remove it from the list of adjoining pixels
        end
end

end



   
