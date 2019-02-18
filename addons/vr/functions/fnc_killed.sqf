/*
    Author:
        Tim Beswick

    Description:
        Sets colour to black when dead

    Parameters:
        0: Unit <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_unit"];

{
    _unit setObjectTextureGlobal [_forEachIndex, "#(argb,8,8,3)color(0.1,0.1,0.1,1,ca)"];
} forEach (getObjectTextures _unit);

{
    _unit setObjectMaterialGlobal [_forEachIndex, QPATHTO_R(data\dead.rvmat)];
} forEach (getObjectMaterials _unit);
