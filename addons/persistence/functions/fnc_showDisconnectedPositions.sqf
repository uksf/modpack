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
    {
        _x params ["_uid", "_pos"];

        drawIcon3D ["", [1,0.5,0,1], _pos, 0.5, 0.5, 0, format ["%1\n(%2m)", _uid, round (player distance _pos)], 0, 0.03, "TahomaB", "center"];
    } forEach GVAR(disconnectedPositionData);
}, 0] call CBA_fnc_addPerFrameHandler;
