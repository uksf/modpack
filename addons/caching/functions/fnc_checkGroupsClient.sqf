#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks groups to uncache for client using LOS checks

    Parameter(s):
        0: Groups to check <ARRAY>

    Return Value:
        None
*/
params [["_groups", []]];

ACE_controlledUAV params ["", "_player", "", "_seat"];
if (isNull _player) then {
    _player = call ace_common_fnc_player;
    _seat = "GUNNER"
};
if (_seat != "GUNNER") exitWith {};

private _objectViewDistance = (getObjectViewDistance#0);
{
    private _leader = leader _x;
    if (
        !(isPlayer _leader) &&
        {!((vehicle _leader) isKindOf "Air")} &&
        {((_leader getVariable [QGVAR(time), 0]) + 10) < diag_tickTime || {!(simulationEnabled _leader)}} &&
        {(_leader distance _player) > GVAR(distance)} &&
        {(_leader distance _player) < _objectViewDistance} &&
        {[_leader, _player, true, true] call EFUNC(common,lineOfSight)}
    ) then {
        if ((_leader getVariable [QGVAR(hiddenByCaching), false]) && {dynamicSimulationEnabled _x}) then {
            [QGVAR(setDynamicSimulation), [_x, false]] call CBA_fnc_globalEvent;
            [QGVAR(hideObjectGlobal), [_x, false]] call CBA_fnc_serverEvent;
            if ((vehicle _leader) != _leader) then {
                {
                    [QGVAR(setDynamicSimulation), [(group _x), false]] call CBA_fnc_globalEvent;
                    [QGVAR(hideObjectGlobal), [_x, false]] call CBA_fnc_serverEvent;
                } forEach (crew (vehicle _leader));
            };
        };
        _leader setVariable [QGVAR(time), diag_tickTime, true];
    };
} forEach _groups;
