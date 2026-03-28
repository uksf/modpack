#include "script_component.hpp"

/*
    Author:
        Codex

    Description:
        Debug helper to force an air strike against a player position.
*/

params [
    ["_targetUnit", objNull, [objNull]],
    ["_forceIgnoreCooldown", false, [false]],
    ["_commander", objNull, [objNull]]
];

if (!isServer) exitWith {
    [QGVAR(forceAirStrikeOnPlayer), [_targetUnit, _forceIgnoreCooldown, _commander]] call CBA_fnc_serverEvent;
    [false, createHashMap, "forwarded_to_server"]
};

if (isNull _targetUnit) then {
    private _candidates = allPlayers select {alive _x};
    _targetUnit = _candidates param [0, objNull];
};
if (isNull _targetUnit) exitWith {[false, createHashMap, "no_target_player"]};

if (isNull _commander) then {
    _commander = GVAR(commanders) param [0, objNull];
};
if (isNull _commander) exitWith {[false, createHashMap, "no_commander"]};

private _request = createHashMapFromArray [
    ["type", "air_strike"],
    ["targetPosition", getPosATL _targetUnit],
    ["source", "debug_force_player"],
    ["targetPlayerNetId", netId _targetUnit]
];

[_commander, _request, _forceIgnoreCooldown] call FUNC(requestAirStrike)
