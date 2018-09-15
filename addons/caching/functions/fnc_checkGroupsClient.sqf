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

private _player = if (!(isNull (getConnectedUAV player))) then {
    (gunner (getConnectedUAV player))
} else {
    (missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player])
};
private _objectViewDistance = (getObjectViewDistance select 0);
{
    private _leader = (leader _x);
    if (
        !(isPlayer _leader) && // 0.0148ms
        {!(isObjectHidden _leader)} &&
        {!((vehicle _leader) isKindOf "Air")} && // 0.0177ms
        {!(_x getVariable [QGVAR(excluded), false])} && // 0.0198ms
        {((_leader getVariable [QGVAR(time), 0]) + 10) < diag_tickTime || {!(simulationEnabled _leader)}} && // 0.0248ms
        {(_leader distance _player) > GVAR(distance)} && // 0.0451ms
        {(_leader distance _player) < _objectViewDistance} && // 0.0471ms
        {[_leader, _player, true, true] call EFUNC(common,lineOfSight)} // 0.0200ms
    ) then {
        if (dynamicSimulationEnabled _x) then {
            [QGVAR(setDynamicSimulation), [_x, false]] call CBA_fnc_globalEvent;
            if ((vehicle _leader) != _leader) then {
                {[QGVAR(setDynamicSimulation), [(group _x), false]] call CBA_fnc_globalEvent; false} count (crew (vehicle _leader));
            };
        };
        _leader setVariable [QGVAR(time), diag_tickTime, true];
    };
    false
} count allGroups;
