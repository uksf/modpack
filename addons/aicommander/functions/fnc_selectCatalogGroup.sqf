#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Select a catalog group using action-type weighting.

    Parameters:
        0: Commander module <OBJECT>
        1: Action type <STRING>

    Return Value:
        Catalog entry <HASHMAP>
*/

params [
    ["_commander", objNull, [objNull]],
    ["_actionType", "reinforce", [""]],
    ["_actionId", "", [""]]
];

if (isNull _commander) exitWith {createHashMap};

private _catalog = _commander getVariable [QGVAR(groupCatalog), []];
if (_catalog isEqualTo []) exitWith {createHashMap};

private _managedGroups = _commander getVariable [QGVAR(managedGroups), []];
private _actionManaged = if (_actionId isEqualTo "") then {
    _managedGroups
} else {
    _managedGroups select {(_x getOrDefault ["actionId", ""]) isEqualTo _actionId}
};

private _infCount = {
    (_x getOrDefault ["groupType", "man"]) isEqualTo "man"
} count _actionManaged;

private _vehicleCount = {
    (_x getOrDefault ["groupType", "man"]) in ["car", "apc", "tank"]
} count _actionManaged;

private _fnc_weight = {
    params ["_type", "_action", "_inf", "_veh"];

    private _base = switch (_action) do {
        case "attack": {
            switch (_type) do {
                case "man": {3};
                case "tank": {4};
                case "apc": {3};
                case "car": {2};
                default {0};
            };
        };
        case "reinforce": {
            switch (_type) do {
                case "man": {5};
                case "car": {2};
                case "apc": {2};
                case "tank": {2};
                default {0};
            };
        };
        case "defend": {
            switch (_type) do {
                case "man": {5};
                case "apc": {2};
                case "car": {2};
                case "tank": {1};
                default {0};
            };
        };
        case "recon": {
            switch (_type) do {
                case "man": {4};
                case "car": {3};
                default {0};
            };
        };
        case "patrol": {
            switch (_type) do {
                case "man": {4};
                case "car": {3};
                case "apc": {1};
                default {0};
            };
        };
        default {
            if (_type isEqualTo "man") then {3} else {1}
        };
    };

    // Keep vehicle pushes supported by infantry.
    if (_type isEqualTo "man") then {
        if (_veh > _inf) then {_base = _base + 4;};
        if (_inf <= 0 && {_veh >= 1}) then {_base = _base + 6;};
    } else {
        if (_veh >= (_inf + 1)) then {_base = _base - 2;};
        if (_veh >= (_inf + 2)) then {_base = _base - 3;};
    };

    _base max 0
};

private _weighted = [];
private _weightSum = 0;
{
    private _w = [_x getOrDefault ["type", "man"], _actionType, _infCount, _vehicleCount] call _fnc_weight;
    if (_w <= 0) then {continue};
    _weightSum = _weightSum + _w;
    _weighted pushBack [_x, _w];
} forEach _catalog;

if (_weighted isEqualTo []) exitWith {createHashMap};

private _roll = random _weightSum;
private _cursor = 0;
private _selected = createHashMap;
{
    _cursor = _cursor + (_x#1);
    if (_roll <= _cursor) exitWith {
        _selected = _x#0;
    };
} forEach _weighted;

_selected
