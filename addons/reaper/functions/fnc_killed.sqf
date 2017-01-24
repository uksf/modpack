/*
    Author:
        Tim Beswick

    Description:
        Removes compass handler if visible upon death

    Parameter(s):
        0: UAV <OBJECT>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params ["_uav"];

{
    if (!alive (getConnectedUAV player) && !isNil QGVAR(handlerCompass)) then {
        [GVAR(handlerCompass)] call CBA_fnc_removePerFrameHandler;
    };
} remoteExecCall ["bis_fnc_call", 0];
