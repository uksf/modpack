#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggles 3D display of disconnected player positions

    Parameter(s):
        None

    Return Value:
        None
*/

[QGVAR(requestDisconnectedPositions), [player]] call CBA_fnc_serverEvent;

GVAR(disconnectedPositionsPFHID) = [{
    params ["", "_idPFH"];

    if (EGVAR(zeus,debugKill)) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    {
        _x params ["_uid", "_pos"];

        drawIcon3D ["", [1,0.5,0,1], _pos, 0.5, 0.5, 0, _uid, 1, 0.025, "TahomaB", "center"];
    } forEach GVAR(disconnectedPositionData);
}, 0] call CBA_fnc_addPerFrameHandler;
