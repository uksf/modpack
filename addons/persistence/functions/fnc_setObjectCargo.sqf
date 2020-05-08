#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets an objects inventory and ACE cargo, recursively

    Parameter(s):
        0: Object <OBJECT>
        1: Ace Cargo <ARRAY>
        2: Inventory <ARRAY>

    Return Value:
        None
*/
params ["_object", "_aceCargo", "_inventory"];
TRACE_3("Setting object cargo",_object,_aceCargo,_inventory);

[_object, _inventory] spawn {
    params ["_object", "_inventory"];
    _inventory params ["_weapons", "_magazines", "_items", "_backpacks"];

    clearWeaponCargoGlobal _object;
    clearMagazineCargoGlobal _object;
    clearItemCargoGlobal _object;
    clearBackpackCargoGlobal _object;
    {_object addWeaponCargoGlobal [_x, (_weapons#1)#_forEachIndex]} forEach (_weapons#0);
    {_object addMagazineCargoGlobal [_x, (_magazines#1)#_forEachIndex]} forEach (_magazines#0);
    {_object addItemCargoGlobal [_x, (_items#1)#_forEachIndex]} forEach (_items#0);
    {_object addBackpackCargoGlobal [_x, (_backpacks#1)#_forEachIndex]} forEach (_backpacks#0);
};

private _initCargo = _object getVariable ["ace_cargo_loaded", []];
{[_x, _object] call ace_cargo_fnc_removeCargoItem} forEach _initCargo;
_initCargo = _object getVariable ["ace_cargo_loaded", []];
{
    _x params ["_type", "_xAceCargo", "_inventory"];

    private _cargoObject = _type;
    if (count _xAceCargo > 0 || {(count (_inventory select {count _x > 0})) > 0}) then {
        _cargoObject = _type createVehicle [-1000 + (random 50), -1000 + (random 50), 0];
        [_cargoObject, _xAceCargo, _inventory] call FUNC(setObjectCargo);
    };
    [_cargoObject, _object, true] call ace_cargo_fnc_loadItem;
} forEach _aceCargo;
