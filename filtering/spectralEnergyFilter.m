function energyFilter=spectralEnergyFilter(height, width, particle_diameter, q)
% --- RPC Spectral Filter Subfunction ---
% 
% INPUTS
%   xregion = Size of interrogation region in the horizontal direction (pixels)
%   xregion = Size of interrogation region in the horizontal direction (pixels)
%   d = Effective particle diameter (pixels)
%   q = UNSURE WHAT THIS VARIABLE IS
% 
% Outputs
%   energyFilter = Spectral energy filter
% 
% SEE ALSO
% 

%assume no aliasing
if nargin<4
    q = 0;
end

% Create filter coordinate matrices.
[k1, k2]=meshgrid(-pi : 2*pi/height : pi-2*pi/height, -pi : 2*pi/width : pi-2*pi/width);

%particle-image spectrum
Ep = ( pi * 255 * particle_diameter^2 / 8)^2 .* exp( -particle_diameter^2 * k1.^2 / 16) .* exp( -particle_diameter^2 * k2.^2 / 16);

%aliased particle-image spectrum
Ea = (pi*255*particle_diameter^2/8)^2*exp(-particle_diameter^2*(k1+2*pi).^2/16).*exp(-particle_diameter^2*(k2+2*pi).^2/16)+...
     (pi*255*particle_diameter^2/8)^2*exp(-particle_diameter^2*(k1-2*pi).^2/16).*exp(-particle_diameter^2*(k2+2*pi).^2/16)+...
     (pi*255*particle_diameter^2/8)^2*exp(-particle_diameter^2*(k1+2*pi).^2/16).*exp(-particle_diameter^2*(k2-2*pi).^2/16)+...
     (pi*255*particle_diameter^2/8)^2*exp(-particle_diameter^2*(k1-2*pi).^2/16).*exp(-particle_diameter^2*(k2-2*pi).^2/16)+...
     (pi*255*particle_diameter^2/8)^2*exp(-particle_diameter^2*(k1+0*pi).^2/16).*exp(-particle_diameter^2*(k2+2*pi).^2/16)+...
     (pi*255*particle_diameter^2/8)^2*exp(-particle_diameter^2*(k1+0*pi).^2/16).*exp(-particle_diameter^2*(k2-2*pi).^2/16)+...
     (pi*255*particle_diameter^2/8)^2*exp(-particle_diameter^2*(k1+2*pi).^2/16).*exp(-particle_diameter^2*(k2+0*pi).^2/16)+...
     (pi*255*particle_diameter^2/8)^2*exp(-particle_diameter^2*(k1-2*pi).^2/16).*exp(-particle_diameter^2*(k2+0*pi).^2/16);

% Noise spectrum
En = pi/4 * width * height;

% DPIV SNR spectral filter
energyFilter  = Ep./((1-q)*En+(q)*Ea);
energyFilter  = (energyFilter)' / max(energyFilter(:));

end

