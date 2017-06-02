/*
    Author:
        Tim Beswick

    Description:
        Checks groups to cache for client using LOS checks

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

{
    private _player = if (!(isNull (getConnectedUAV player))) then {
        (gunner (getConnectedUAV player))
    } else {
        (missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player])
    };
    if (CLIENT_CONDITION) then {
        if (dynamicSimulationEnabled _x) then {
            [QGVAR(setDynamicSimulation), [_x, false]] call CBA_fnc_serverEvent;
        };
        (leader _x) setVariable [QGVAR(time), diag_tickTime, true];
    };
    false
} count allGroups;
