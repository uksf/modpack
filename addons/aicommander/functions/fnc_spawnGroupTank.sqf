#include "script_component.hpp"
params [
    ["_position", [0, 0, 0], [[]]],
    ["_side", sideUnknown, [sideUnknown]],
    ["_groupCfg", configNull, [configNull]]
];

if (isNull _groupCfg) exitWith {grpNull};
[_position, _side, _groupCfg] call BIS_fnc_spawnGroup

