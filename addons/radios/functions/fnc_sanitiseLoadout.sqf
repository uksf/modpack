#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Removes radio IDs from loadout, and replaces with base class

    Parameter(s):
        0: Inventory to sanitise <ARRAY>

    Return Value:
        Sanitised inventory <ARRAY>
*/
params ["_inventory"];

private _sanitisedInventory = [];
{
    private _part = _x;
    private _sanitisedPart = "";
    if (_part isEqualType "") then {
        if ((_part select [0, 4]) isEqualTo "ACRE") then {
            private _uniqueBaseClass = getText (configFile >> "CfgWeapons" >> _part >> "ace_arsenal_uniqueBase");
            if (_uniqueBaseClass != "") then {
                _part = _uniqueBaseClass;
            };
        };
        _sanitisedPart = _part;
    } else {
        if (_part isEqualType 0 || {_part isEqualType false}) then {
            _sanitisedPart = _part;
        } else {
            if (_part isEqualType []) then {
                _sanitisedPart = [_part] call FUNC(sanitiseLoadout);
            };
        };
    };
    _sanitisedInventory pushBack _sanitisedPart;
} forEach _inventory;

_sanitisedInventory
