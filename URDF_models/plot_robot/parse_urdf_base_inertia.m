function [m, Ixx, Iyy, Izz] = parse_urdf_base_inertia(urdf_path, base_link_name)
% PARSE_URDF_BASE_INERTIA  Read mass and diagonal inertia of a URDF base link.
%
%   URDF defines the base link with an <inertial> block but MATLAB's
%   rigidBodyTree.Base does not expose those values through its API.
%
%   Inputs:
%       urdf_path      - Full path to the .urdf file
%       base_link_name - Name attribute of the base <link> element
%
%   Outputs:
%       m              - Link mass [kg]
%       Ixx, Iyy, Izz  - Diagonal moments of inertia [kg·m²]

if isempty(urdf_path)
    error('parse_urdf_base_inertia: could not locate "%s" on the MATLAB path.', ...
        base_link_name) ;
end

xDoc  = xmlread(urdf_path) ;
links = xDoc.getElementsByTagName('link') ;

for k = 0 : links.getLength() - 1
    link = links.item(k) ;
    if strcmp(char(link.getAttribute('name')), base_link_name)
        inertial_nodes = link.getElementsByTagName('inertial') ;
        if inertial_nodes.getLength() == 0
            error('parse_urdf_base_inertia: link "%s" has no <inertial> block.', base_link_name) ;
        end
        inertial = inertial_nodes.item(0) ;

        mass_node    = inertial.getElementsByTagName('mass').item(0) ;
        inertia_node = inertial.getElementsByTagName('inertia').item(0) ;

        m   = str2double(char(mass_node.getAttribute('value'))) ;
        Ixx = str2double(char(inertia_node.getAttribute('ixx'))) ;
        Iyy = str2double(char(inertia_node.getAttribute('iyy'))) ;
        Izz = str2double(char(inertia_node.getAttribute('izz'))) ;
        return ;
    end
end

error('parse_urdf_base_inertia: link "%s" not found in %s.', base_link_name, urdf_path) ;
end
