#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Inclues a unit or a group in caching
        Any units inside another unit's vehicle will also be enabled

    Parameter(s):
        0: Unit/Group <OBJECT/GROUP>

    Return Value:
        None
*/
if (!GVAR(enabled)) exitWith {};

if (!(isServer)) exitWith {
    [QGVAR(enableCache), _this] call CBA_fnc_serverEvent;
};

params [["_group", grpNull, [grpNull, objNull]]];

if (_group isEqualType objNull) then {
    _group = group _group;
};

_group setVariable [QGVAR(excluded), false, true];

private _leader = leader _group;
private _vehicle = objectParent _leader;
if (!(isNull _vehicle)) then {
    {
        (group _x) setVariable [QGVAR(excluded), false, true];
    } forEach (crew _vehicle);
};
