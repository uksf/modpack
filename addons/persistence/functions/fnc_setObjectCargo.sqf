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
        3: Custom name <STRING>

    Return Value:
        None
*/
params ["_object", "_aceCargo", "_inventory", ["_customName", ""]];
TRACE_3("Setting object cargo",_object,_aceCargo,_inventory);

private _initCargo = _object getVariable ["ace_cargo_loaded", []];
{[_x, _object] call ace_cargo_fnc_removeCargoItem} forEach _initCargo;

[{
    params ["_object", "_inventory"];
    if (count _inventory < 4) exitWith {
        WARNING_1("Malformed inventory data for %1, skipping inventory restore",_object);
    };
    _inventory params ["_weapons", "_magazines", "_items", "_backpacks"];

    clearWeaponCargoGlobal _object;
    clearMagazineCargoGlobal _object;
    clearItemCargoGlobal _object;
    clearBackpackCargoGlobal _object;
    {_object addWeaponCargoGlobal [_x, (_weapons#1)#_forEachIndex]} forEach (_weapons#0);
    {_object addMagazineCargoGlobal [_x, (_magazines#1)#_forEachIndex]} forEach (_magazines#0);
    {_object addItemCargoGlobal [_x, (_items#1)#_forEachIndex]} forEach (_items#0);
    {_object addBackpackCargoGlobal [_x, (_backpacks#1)#_forEachIndex]} forEach (_backpacks#0);
}, [_object, _inventory]] call CBA_fnc_execNextFrame;

{
    _x params ["_type", "_xAceCargo", "_inventory", ["_customName", ""]];

    private _cargoObject = _type;
    if (_xAceCargo isNotEqualTo [] || {(_inventory select {count _x > 0}) isNotEqualTo []}) then {
        _cargoObject = createVehicle [_type, [0,0,0], [], 0, "NONE"];
        [QGVAR(setObjectCargo), [_cargoObject, _xAceCargo, _inventory, _customName]] call CBA_fnc_localEvent;
    };

    if (_cargoObject isEqualType "" && _customName != "") then {
        _cargoObject = createVehicle [_type, [0,0,0], [], 0, "NONE"];
        _cargoObject setVariable ["ace_cargo_customName", _customName, true];
    };

    [_cargoObject, _object, true] call ace_cargo_fnc_loadItem;
} forEach _aceCargo;

if (_customName != "") then {
    _object setVariable ["ace_cargo_customName", _customName, true];
};
