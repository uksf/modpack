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
#define INTERVAL 10

GVAR(persistentObjectIconsPFHID) = [{
    params ["_args"];
    _args params ["_time"];

    if (CBA_missionTime > (_time + INTERVAL)) then {
        [QGVAR(requestPersistentObjectsHash), [player]] call CBA_fnc_serverEvent;
        _args set [0, CBA_missionTime];
    };


    {
        params ["_id", "_object"];

        drawIcon3D ["", [0,0,1,1], _object modelToWorld [0,0,0], 0.5, 0.5, 0, _id, 0, 0.03, "TahomaB", "center"];
    } forEach GVAR(persistentObjects);
}, 0, [0]] call CBA_fnc_addPerFrameHandler;
