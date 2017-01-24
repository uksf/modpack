/*
    Author:
        Tim Beswick

    Description:
        Gets air targets

    Parameter(s):
        0: Object <OBJECT>
        1: Unit <OBJECT>

    Return Value:
        Arrays of targets <ARRAY>
*/
#include "script_component.hpp"

params ["_object", "_unit"];

_enemysides = [];
_friendlysides = [];
_allTargets = [];
_airTargetsHostile = [];
_airTargetsFriendly = [];

{
    if (((side _unit) getFriend _x) < 0.6) then {
        _enemysides pushBack _x;
    } else {
        _friendlysides pushBack _x;
    };
} forEach [EAST, WEST, resistance, civilian];

{
    if ((alive _x) && (isEngineOn _x)) then {
        _allTargets pushBack _x;
    };
} forEach (missionNamespace getVariable [QGVAR(airTargets), []]);

{
    _enemyside = _x;
    {
        if (side _x == _enemyside) then {
            _airTargetsHostile pushBack _x;
        };
    } forEach _allTargets;
} forEach _enemysides;

{
    _friendlyside = _x;
    {
        if (side _x == _friendlyside) then {
            _airTargetsFriendly pushBack _x;
        };
    } forEach _allTargets;
} forEach _friendlysides;

[_airTargetsHostile, _airTargetsFriendly]
