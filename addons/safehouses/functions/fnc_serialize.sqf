#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Serializes safehouse data for persistence save

    Parameters:
        None

    Return value:
        Serialized safehouse data
        [Prefabs, Destroyed, Locations]

    Example:
        call uksf_safehouses_fnc_serialize
*/

[values GVAR(prefabs), values GVAR(destroyed), values GVAR(locations)]
