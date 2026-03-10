#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Remove any NVG class from unit

    Parameter(s):
        0: Unit <OBJECT>

    Return Value:
        Nothing

    Example:
        [_unit] call uksf_common_fnc_removeNVG
*/
params [["_unit", objNull]];

if (local _unit) then {
    private _items = assignedItems _unit;
    {
        if (getText (GVAR(configWeapons) >> _x >> "simulation") isEqualTo "NVGoggles") then {
            _unit unassignItem _x;
            _unit removeItem _x;
        };
    } forEach _items;
};
