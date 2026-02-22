#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns AI ground commander visualisation data for Zeus.

    Parameter(s):
        None

    Return Value:
        Array of visualisation data
*/

private _spawnPoints = [];
{_spawnPoints pushBack [getPosATL _x, "infantry"]} forEach GVAR(infantrySpawns);
{_spawnPoints pushBack [getPosATL _x, "car"]} forEach GVAR(carSpawns);
{_spawnPoints pushBack [getPosATL _x, "apc"]} forEach GVAR(apcSpawns);
{_spawnPoints pushBack [getPosATL _x, "tank"]} forEach GVAR(tankSpawns);

private _stagingAreas = GVAR(stagingAreas) apply {getPosATL _x};

private _killerPlayers = GVAR(killerPlayers) apply {
    [netId (_x#0), (_x#1) - CBA_missionTime]
};

private _responseGroupData = [];
{
    if (!isNull _x) then {
        private _leader = leader _x;
        if (!isNull _leader) then {
            private _targetPosition = _x getVariable [QGVAR(targetPosition), []];
            _responseGroupData pushBack [groupId _x, netId _leader, _targetPosition];
        };
    };
} forEach GVAR(responseGroups);

[
    _spawnPoints,
    _stagingAreas,
    GVAR(enemyAggressionLevel),
    [GVAR(tier1ResponseDeployed), GVAR(tier2ResponseDeployed)],
    _killerPlayers,
    _responseGroupData
]
