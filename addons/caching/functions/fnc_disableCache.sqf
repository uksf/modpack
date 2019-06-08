/*
    Author:
        Tim Beswick

    Description:
        Excludes a group from caching. If group is in a vehicle, all units of the leader's vehicle are also excluded

    Parameter(s):
        0: Group to exclude from caching

    Return Value:
        None
*/
#include "script_component.hpp"

if (!(isServer)) exitWith {
    [QGVAR(disableCache), this] call CBA_fnc_serverEvent;
};

params [["_group", grpNull, [grpNull, objNull]]];

if (_group isEqualType objNull) then {
    _group = group _group;
};

_group enableDynamicSimulation false;
_group setVariable [QGVAR(excluded), true, true];
{
    _x enableSimulationGlobal true;
    _x hideObjectGlobal false;
    false
} count (units _group);
if (!(isNull (objectParent (leader _group)))) then {
    {
        _x enableSimulationGlobal true;
        _x hideObjectGlobal false;
        (group _x) setVariable [QGVAR(excluded), true, true];
        false
    } count (crew (objectParent (leader _group)));
};
