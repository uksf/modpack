#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Collect currently known/spotted hostile objects for a group.

    Parameters:
        0: Friendly group <GROUP>
        1: Friendly side <SIDE>

    Return Value:
        Known hostile objects <ARRAY>
*/

params [
    ["_group", grpNull, [grpNull]],
    ["_friendlySide", sideUnknown, [sideUnknown]]
];

if (isNull _group) exitWith {[]};

private _aliveUnits = units _group select {alive _x};
if (_aliveUnits isEqualTo []) exitWith {[]};

private _radius = 500;

private _candidates = [];
{
    _candidates append (_x nearEntities [["Man", "LandVehicle"], _radius]);
} forEach _aliveUnits;
_candidates = _candidates arrayIntersect _candidates;

private _known = _candidates select {
    private _entity = _x;
    alive _entity
    && {side _entity isNotEqualTo _friendlySide}
    && {{_x knowsAbout _entity > 0.5} count _aliveUnits > 0}
};

_known

