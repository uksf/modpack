/*
    Author:
        Tim Beswick

    Description:
        Remove any NVG class from unit

    Parameter(s):
        0: Unit <OBJECT>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params [["_unit", objNull]];

if (local _unit) then {
    private _items = assignedItems _unit;
    {
        if (getText (configFile >> "CfgWeapons" >> _x >> "simulation") isEqualTo "NVGoggles") then {
            _unit unassignItem _x;
            _unit removeItem _x;
        };
        true
    } count _items;
};