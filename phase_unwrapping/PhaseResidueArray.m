classdef PhaseResidueArray
   % This class file defines an array of phase residue objects.
   % Unfortunately it's extremely slow. Perhaps compiling it would speed
   % things up.
   
   % Each element of the PhaseResidueArray contains a single field
   % called "Flags," which contains the array of flags defined by 
   % the object class PhaseResidue.
   properties
       Flags
   end
    
   % This is the methods for creating an array of PhaseResidue objects.
   methods
       % This function creates an array of phase residue objects
       % whose dimensions are the same size as the input array F.
       function obj = PhaseResidueArray(SIZE_TEMPLATE_ARRAY)
           
           % Allow nargin == 0 syntax
           if nargin ~= 0 
               
               % Determine the size of the array.
               % Generalize to 3D
               height = size(SIZE_TEMPLATE_ARRAY, 1);
               width  = size(SIZE_TEMPLATE_ARRAY, 2);
               depth  = size(SIZE_TEMPLATE_ARRAY, 3);
               
               % Preallocate the object array.
               obj(height, width, depth) = PhaseResidueArray;
               
               % Loop over the array, initializing each element 
               % with a phase residue object.
               %
               % Loop over the depth direction 
               for d = 1 : depth
                   % Loop over the columns
                   for c = 1 : width
                       % Loop over the rows.
                       for r = 1 : height
                           obj(r, c, d).Flags = PhaseResidue;
                       end % End looping over rows
                   end % End looping over columns
               end % End looping over depth    
               
           end % End "if nargin ~= 0"
           
       end % End function definition
       
   end % End methods section
   
end % End classdef


