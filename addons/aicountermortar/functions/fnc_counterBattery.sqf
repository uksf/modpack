#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Sets up and executes counter battery fire

    Parameters:
        0: Mortar position <ARRAY>
        1: Counter battery unit <ARRAY>

    Return value:
        Nothing
*/
params ["_mortarPosition", "_counterBatteryUnit"];

[QEGVAR(mission,fireMission), [_counterBatteryUnit, _counterBatteryUnit, _mortarPosition], gunner _counterBatteryUnit] call CBA_fnc_targetEvent;
[{GVAR(counterInProgress) = false}, [], 1200] call CBA_fnc_waitAndExecute;
