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
    private _leader = (leader _x);
    if (
        !(isPlayer _leader) &&
        {(_leader distance _player) > GVAR(distance)} &&
        {(_leader distance _player) < (getObjectViewDistance select 0)} &&
        {!(_x getVariable [QGVAR(excluded), false])} &&
        {!((vehicle _leader) isKindOf "Air")} &&
        {((_leader getVariable [QGVAR(time), 0]) + 10) < diag_tickTime || {!(simulationEnabled _leader)}} &&
        {[_leader, _player, true, true] call EFUNC(common,lineOfSight)}
    ) then {
        if (dynamicSimulationEnabled _x) then {
            INFO_1("Sending disable to %1",_x);
            [QGVAR(setDynamicSimulation), [_x, false]] call CBA_fnc_serverEvent;
        };
        _leader setVariable [QGVAR(time), diag_tickTime, true];
    };
    false
} count allGroups;
