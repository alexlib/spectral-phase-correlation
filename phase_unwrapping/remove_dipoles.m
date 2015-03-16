function FLAGS_MATRIX = remove_dipoles(FLAGS_MATRIX)

% Define values for the different flags...
% Note that matlab indexes bit positions the same way
% it does arrays, e.g., little-endian bit 1 corresponds to 2^0.
% Positive residue flag bit-position and byte-value-if-true
positive_residue_bit_position = 1;

% Negative residue flag bit position and byte-value-if-true
negative_residue_bit_position = 2;

% Branch cut flag bit position and byte-value-if-true
branch_cut_bit_position = 3;

% Determine the locations of the residues
residue_locs = find_residue_locs(FLAGS_MATRIX);

% Number of residues identified
num_residues = length(residue_locs);

% Flags matrix dimensions
[height, width] = size(FLAGS_MATRIX);

% Loop over all the residues
for k = 1 : num_residues
   
    % Residue row and column
    anchor_row = rem(residue_locs(k) - 1, height) + 1;
    anchor_col = (residue_locs(k) - anchor_row) / height + 1;
    
    % Anchor flag
   anchor_flag = FLAGS_MATRIX(anchor_row, anchor_col);
    
   % Check if the pixel is still marked as a residue,
   % since its residue flag may have been removed.
   if is_residue(anchor_flag) 
       anchor_charge = get_flags_charge(anchor_flag);
       
       % Determine the rows and columns of the surrounding pixels.
       rows = anchor_row + [-1, 0, 1, -1, 1, -1, 0, 1];
       cols = anchor_col + [-1, -1, -1, 0, 0, 1, 1, 1];
       
       % Number of surrounding pixels (should always be 8)
       num_surrounding = length(rows);
       
       for p = 1 : num_surrounding
           
           if rows(p) >= 1 && cols(p) >= 1 && rows(p) <= height && cols(p) <= width
           
           
               % Grab the current flag
               current_flag = FLAGS_MATRIX(rows(p), cols(p));

               % Measure the charge of the current flag
               current_flag_charge = get_flags_charge(current_flag);

               % If the charge of the current flag opposes the anchor flag
               % then place a branch cut and remove the two residues.
               net_charge = anchor_charge + current_flag_charge;

               if net_charge == 0

                   % Set the anchor pixel charge to zero
                   if anchor_charge > 0
                       FLAGS_MATRIX(anchor_row, anchor_col) = bitset(...
                       FLAGS_MATRIX(anchor_row, anchor_col), ...
                       positive_residue_bit_position, 0);
                   elseif anchor_charge < 0
                       FLAGS_MATRIX(anchor_row, anchor_col) = bitset(...
                       FLAGS_MATRIX(anchor_row, anchor_col), ...
                       negative_residue_bit_position, 0);
                   end

                   % Set the current pixel charge to zero
                   if current_flag_charge > 0
                       FLAGS_MATRIX(rows(p), cols(p)) = bitset(...
                       FLAGS_MATRIX(rows(p), cols(p)), ...
                       positive_residue_bit_position, 0);
                   elseif current_flag_charge < 0
                       FLAGS_MATRIX(rows(p), cols(p)) = bitset(...
                       FLAGS_MATRIX(rows(p), cols(p)), ...
                       negative_residue_bit_position, 0);
                   end

                    % Place the anchor pixel on a branch cut.
                   FLAGS_MATRIX(anchor_row, anchor_col) = bitset(...
                       FLAGS_MATRIX(anchor_row, anchor_col), ...
                       branch_cut_bit_position, 1);

                   % Place the box pixel on a branch cut.
                   FLAGS_MATRIX(rows(p), cols(p)) = bitset(...
                       FLAGS_MATRIX(rows(p), cols(p)), ...
                       branch_cut_bit_position, 1);

                   % Break the for-loop
                   break

               end % End if net_charge == 0
           
           end
           
       end % End looping around surrounding pixels
       
       
      
   end % end if(is_residue)
       
end % End looping over all detected residues.


end


function IS_RESIDUE =  is_residue(FLAG)
positive_residue_bit_position = 1;
negative_residue_bit_position = 2;


IS_RESIDUE = bitget(FLAG, positive_residue_bit_position) | ...
             bitget(FLAG, negative_residue_bit_position);
         

end



