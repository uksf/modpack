#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns side and group from given faction

    Parameters:
        0: Faction Name <SCALAR>

    Return value:
        [Side, Group config] <ARRAY>
*/
params ["_factionName"];

private _return = [];
private _factionMap = uiNamespace getVariable [QGVAR(factionMap), []];
private _group = selectRandom (((_factionMap select {(_x#0) isEqualTo _factionName})#0)#1);
if (isNil "_group") exitWith {
    INFO_1("Could not find a group for faction: '%1'",_factionName);
    [east, []]
};

private _side = switch (getNumber (_group >> "side")) do {
    case 0: {east};
    case 1: {west};
    case 2: {independent};
    default {east};
};
_return pushBack _side;
_return pushBack _group;

_return
