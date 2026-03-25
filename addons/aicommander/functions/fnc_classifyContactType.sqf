#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Classify an observed hostile entity into a high-level type bucket.

    Parameters:
        0: Entity <OBJECT>

    Return Value:
        Type label <STRING>
*/

params [["_entity", objNull, [objNull]]];

if (isNull _entity) exitWith {"other"};

private _vehicle = if (_entity isKindOf "Man") then {
    vehicle _entity
} else {
    _entity
};

if (isNull _vehicle) exitWith {"other"};
if (_vehicle isKindOf "Air") exitWith {"air"};
if (_vehicle isKindOf "Tank") exitWith {"tank"};
if (_vehicle isKindOf "APC") exitWith {"apc"};
if (_vehicle isKindOf "Car") exitWith {"car"};
if (_vehicle isKindOf "Man") exitWith {"man"};
"other"
