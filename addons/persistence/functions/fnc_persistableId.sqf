#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns the persistence ID automatic saving uses for an object. Gives
        the object an ID when it is persistable and has none yet. Returns an
        empty string for an object that must not be saved.

    Parameter(s):
        0: Object <OBJECT>

    Return Value:
        ID, or "" when the object is not persistable <STRING>

    Example:
        [_vehicle] call uksf_persistence_fnc_persistableId
*/
params ["_object"];

if !([_object] call FUNC(isPersistable)) exitWith {""};

[_object] call FUNC(markObjectAsPersistent)
