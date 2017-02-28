/*
    Author:
        Tim Beswick

    Description:
        Cleans radio of IDs, leaving base class name.

    Parameter(s):
        0: Item <STRING>

    Return Value:
        Item <STRING>
*/
#include "script_component.hpp"

params ["_item"];

if (_item isKindOf ["ACRE_BaseRadio", configFile >> "CfgWeapons"]) then {
    private _baseClass = getText (configFile >> "CfgWeapons" >> _item >> "acre_baseClass");
    if (_baseClass != "") then {
        _item = _baseClass;
    };
};

_item
