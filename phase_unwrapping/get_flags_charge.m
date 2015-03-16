function CHARGE = get_flags_charge(FLAG)

positive_residue_bit_position = 1;
negative_residue_bit_position = 2;

if bitget(FLAG, positive_residue_bit_position)
    CHARGE = 1;
elseif  bitget(FLAG, negative_residue_bit_position)
    CHARGE = -1;
else
    CHARGE = 0;
end
    

end
