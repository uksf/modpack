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
*/

[values GVAR(prefabs), values GVAR(destroyed), values GVAR(locations)]
