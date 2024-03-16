#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Clear debug speheres

    Parameters:
        None

    Return value:
        Nothing

    Example:
        call uksf_common_fnc_debugClearSpheres;
*/
{
    deleteVehicle _x;
} forEach GVAR(debugSpheres);
GVAR(debugSpheres) = [];

deleteVehicle GVAR(debugSingletonSphere);
GVAR(debugSingletonSphere) = objNull;
