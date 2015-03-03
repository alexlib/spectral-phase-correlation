function calculate_branch_cuts(RESIDUE_MATRIX, MAX_BOX_SIZE);

% Determine matrix height and width
[height, width] = size(RESIDUE_MATRIX);

% Determine the locations of the residues.
for m = 1 : height
    for n = 1 : width
       
        % This res-assigns the residue matrix value to a new variable
        % called "res"
        res = RESIDUE_MATRIX(m, n);
        
        % This if-statement checks whether the residue is nonzero
       if res
           
           % This calculates the charge of the residue.
           residue_charge = 1 - (2 * (res < 0));
           
           % This loops over all the allowed box sizes
           for box_size = 3 : MAX_BOX_SIZE
               % This runs the box-search code with the 
               balance_residues(some_arguments, box_size);
           end
           
        end
    end
end



end