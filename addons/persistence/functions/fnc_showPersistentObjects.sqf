#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates icons on persistent objects

    Parameter(s):
        None

    Return Value:
        None
*/

GVAR(persistentObjectIconsPFHID) = [{
    [GVAR(persistentObjectsHash), {
        drawIcon3D ["", [0,0,1,1], _value modelToWorld [0,0,0], 0.5, 0.5, 0, format ["%1", _key], 0, 0.03, "TahomaB", "center"];
    }] call CBA_fnc_hashEachPair;
}, 0] call CBA_fnc_addPerFrameHandler;
