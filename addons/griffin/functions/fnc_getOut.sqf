/*
    Author:
        Tim Beswick

    Description:
        Called when unit gets out of helicopter. Removes UI.

    Parameter(s):
        0: Helicopter <OBJECT>
        1: Position <STRING>
        2: Unit <OBJECT>
        3: Turret <ARRAY>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params ["_heli", "_position", "_unit"];

if((_position == "driver" || _position == "gunner") && local _unit) then {
    [GVAR(metricsHandler)] call CBA_fnc_removePerFrameHandler;
    (QGVAR(metricsLayer) call BIS_fnc_rscLayer) cutFadeOut 0;
};
