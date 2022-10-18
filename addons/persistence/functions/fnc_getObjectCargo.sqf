#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Gets an objects inventory and ACE cargo, recursively

    Parameter(s):
        0: Object <OBJECT>

    Return Value:
        Cargo <ARRAY>
*/
params ["_object"];

private _loadedCargo = _object getVariable ["ace_cargo_loaded", []];
TRACE_2("Getting object cargo",_object,_loadedCargo);
private _aceCargo = [];
{
    private _type = _x;
    private _xAceCargo = [];
    private _inventory = [];
    private _customName = "";
    if (_x isEqualType objNull) then {
        _type = typeOf _x;
        _xAceCargo = [_x] call FUNC(getObjectCargo);
        _inventory = [getWeaponCargo _x, getMagazineCargo _x, getItemCargo _x, getBackpackCargo _x];
        _customName = _x getVariable ["ace_cargo_customName", ""];
    };
    TRACE_4("Found cargo",_type,_xAceCargo,_inventory,_customName);
    _aceCargo pushBack [_type, _xAceCargo, _inventory, _customName];
} forEach _loadedCargo;

TRACE_1("Got cargo",_aceCargo);
_aceCargo
