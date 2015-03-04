function flags_matrix = calculate_branch_cuts(RESIDUE_MATRIX, MAX_BOX_SIZE);

% Determine matrix height and width
[height, width] = size(RESIDUE_MATRIX);

% Create a matrix containing the residue flags
% This matrix contains [height, width] 8-bit values
% where the first seven bits of each byte refer in
% little-endian order to the values of the following
% flags at each pixel: 
% 2^0 bit = 1 if positive residue, 0 if not positive residue.
% 2^1 bit = 1 if negative residue, 0 if not negative residue.
% 2^2 bit = 1 if the pixel lies on a branch cut, 0 if not.
% 2^3 bit = 1 if the pixel lies on the image border (I think??), 0 if not.
% 2^4 bit = 1 if the pixel represents a balanced residue, 0 if not.
% 2^5 bit = 1 if the pixel represnts an "active residue," i.e.
%   if the pixel is "connected to the current set of branch cuts."
%   I think this means that the pixel is on a branch cut within
%   an active search window.
% 2^6 bit = 1 if the pixel has been unwrapped.
%
% This should really be done in the object-oriented sense
% where all these flags are attributes of a residue object.
% But I'm not sure how to do this in matlab, or if it would be efficient
flags_matrix = PhaseResidueArray(zeros([height, width]));

% Determine the locations of the residues.
for m = 1 : height
    for n = 1 : width
       
        % This res-assigns the residue matrix value to a new variable
        % called "res"
        residue = RESIDUE_MATRIX(m, n);
        
        % This if-statement checks whether the residue is nonzero
        % ("if residue" returns true whenever residue ~= 0, 
        % even if residue < 0)
       if residue
           
           % This calculates the charge of the residue,
           % which is either +1 ("positive charge")
           % or -1 ("negative charge").
           residue_charge = 1 - (2 * (residue < 0));
           
           % This loops over all the allowed box sizes
           for box_size = 3 : MAX_BOX_SIZE
               % This runs the box-search code with the 
               balance_residues(some_arguments, box_size);
           end
           
        end
    end
end



end