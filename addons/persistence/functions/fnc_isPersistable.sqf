#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks whether automatic saving may give an object a persistence ID.
        An object that already has an ID is persistable. A mission object
        without an Eden persistence ID is persistable only after it has moved
        more than 5 m horizontally from where the mission placed it, so a
        vehicle a player drives away is saved and one left at base is not.
        Other excluded objects, such as ruins, are never persistable.

    Parameter(s):
        0: Object <OBJECT>

    Return Value:
        Persistable <BOOL>

    Example:
        [_vehicle] call uksf_persistence_fnc_isPersistable
*/
#define MOVED_DISTANCE 5

params ["_object"];

if (_object getVariable [QGVAR(persistenceID), ""] != "") exitWith {true};
if !(_object getVariable [QGVAR(excluded), false]) exitWith {true};

private _startPosition = _object getVariable [QGVAR(startPosition), []];
_startPosition isNotEqualTo [] && {(getPosASL _object) distance2D _startPosition > MOVED_DISTANCE}
