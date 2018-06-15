/*
    Author:
        Tim Beswick

    Description:
        Gets a vehicles inventory and ACE cargo, recursively

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        Cargo <ARRAY>
*/
#include "script_component.hpp"

private _loadedCargo = _vehicle getVariable ["ace_cargo_loaded", []];
private _cargo = [];
{
    private _type = _x;
    private _xCargo = [];
    private _inventory = [];
    if (_x isEqualType objNull) then {
        _type = typeOf _x;
        _xCargo = [_x] call FUNC(getVehicleCargo);
        _inventory = [getWeaponCargo _x, getMagazineCargo _x, getItemCargo _x, getBackpackCargo _x];
    };
    _aceCargo pushBack [_type, _xCargo, _inventory];
} forEach _loadedCargo;

_cargo
