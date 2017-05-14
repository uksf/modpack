/*
    Author:
        Tim Beswick

    Description:
        Handles caching of AI units

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

{
    private _unit = if (!(isNull (getConnectedUAV player))) then {
        (gunner (getConnectedUAV player))
    } else {
        (missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player])
    };
    if (({!(isPlayer _x) && {!(_x getVariable [QGVAR(excluded), false])} && {[_x, _unit, true] call EFUNC(common,lineOfSight)}} count (units _x)) > 0) exitWith {
        if (dynamicSimulationEnabled _x) then {
            _x enableDynamicSimulation false;
        };
    };
    if (!(dynamicSimulationEnabled _x) && {!(isPlayer (leader _x))} && {!(_x getVariable [QGVAR(excluded), false])} && {!((vehicle (leader _x)) isKindOf "Air")}) then {
        _x enableDynamicSimulation true;
    };
    false
} count allGroups;
