#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Excludes a group from caching. If group is in a vehicle, all units of the leader's vehicle are also excluded

    Parameter(s):
        0: Unit/Group <OBJECT/GROUP>

    Return Value:
        None
*/
if (!GVAR(enabled)) exitWith {};

if (!(isServer)) exitWith {
    [QGVAR(disableCache), _this] call CBA_fnc_serverEvent;
};

params [["_group", grpNull, [grpNull, objNull]]];

if (_group isEqualType objNull) then {
    _group = group _group;
};

_group setVariable [QGVAR(excluded), true, true];
{
    if (_x getVariable [QGVAR(hiddenByCaching), false]) then {
        _x enableSimulationGlobal true;
        _x hideObjectGlobal false;
    };
} forEach (units _group);

private _leader = leader _group;
private _vehicle = objectParent _leader;
if (!(isNull _vehicle)) then {
    {
        if (_x getVariable [QGVAR(hiddenByCaching), false]) then {
            _x enableSimulationGlobal true;
            _x hideObjectGlobal false;
        };
        (group _x) setVariable [QGVAR(excluded), true, true];
    } forEach (crew _vehicle);
};
