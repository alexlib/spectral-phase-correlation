function charge = get_charge(RESIDUE)
% This function calculates the charge of a residue as +/- 1

    charge = 1 - (2 * (RESIDUE < 0));
    
end