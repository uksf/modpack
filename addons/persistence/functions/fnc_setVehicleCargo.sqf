#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets a vehicles inventory and ACE cargo, recursively

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Ace Cargo <ARRAY>
        2: Inventory <ARRAY>

    Return Value:
        None
*/
params ["_vehicle", "_aceCargo", "_inventory"];
TRACE_3("Setting vehicle cargo",_vehicle,_aceCargo,_inventory);

[_vehicle, _inventory] spawn {
    params ["_vehicle", "_inventory"];
    _inventory params ["_weapons", "_magazines", "_items", "_backpacks"];

    clearWeaponCargoGlobal _vehicle;
    clearMagazineCargoGlobal _vehicle;
    clearItemCargoGlobal _vehicle;
    clearBackpackCargoGlobal _vehicle;
    {_vehicle addWeaponCargoGlobal [_x, (_weapons#1)#_forEachIndex]} forEach (_weapons#0);
    {_vehicle addMagazineCargoGlobal [_x, (_magazines#1)#_forEachIndex]} forEach (_magazines#0);
    {_vehicle addItemCargoGlobal [_x, (_items#1)#_forEachIndex]} forEach (_items#0);
    {_vehicle addBackpackCargoGlobal [_x, (_backpacks#1)#_forEachIndex]} forEach (_backpacks#0);
};

private _initCargo = _vehicle getVariable ["ace_cargo_loaded", []];
{[_x, _vehicle] call ace_cargo_fnc_removeCargoItem} forEach _initCargo;
_initCargo = _vehicle getVariable ["ace_cargo_loaded", []];
{
    _x params ["_type", "_xAceCargo", "_inventory"];

    private _cargoVehicle = _type;
    if (count _xAceCargo > 0 || {(count (_inventory select {count _x > 0})) > 0}) then {
        _cargoVehicle = _type createVehicle [-1000 + (random 50), -1000 + (random 50), 0];
        [_cargoVehicle, _xAceCargo, _inventory] call FUNC(setVehicleCargo);
    };
    [_cargoVehicle, _vehicle, true] call ace_cargo_fnc_loadItem;
} forEach _aceCargo;
