#include "script_component.hpp"
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
params ["_vehicle"];

private _loadedCargo = _vehicle getVariable ["ace_cargo_loaded", []];
TRACE_2("Getting vehicle cargo",_vehicle,_loadedCargo);
private _aceCargo = [];
{
    private _type = _x;
    private _xAceCargo = [];
    private _inventory = [];
    if (_x isEqualType objNull) then {
        _type = typeOf _x;
        _xAceCargo = [_x] call FUNC(getVehicleCargo);
        _inventory = [getWeaponCargo _x, getMagazineCargo _x, getItemCargo _x, getBackpackCargo _x];
    };
    //TRACE_3("Found cargo",_type,_xAceCargo,_inventory);
    _aceCargo pushBack [_type, _xAceCargo, _inventory];
} forEach _loadedCargo;

//TRACE_1("Got cargo",_aceCargo);
_aceCargo
