#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Checks whether a class/object matches any class in an array using isKindOf.

    Parameters:
        0: Class name or object <STRING|OBJECT>
        1: Class array <ARRAY>

    Return value:
        BOOLEAN
*/
params ["_source", ["_classes", []]];

if (_classes isEqualTo []) exitWith {false};

private _className = if (_source isEqualType objNull) then {typeOf _source} else {_source};
(_classes findIf {_className isKindOf _x}) > -1
