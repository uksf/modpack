/*
    Author:
        Tim Beswick

    Description:
        Loads saved vehicle data

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

private _vehicles = (GVAR(dataNamespace) getVariable [QGVAR(vehicles), []]);
if (count _vehicles == 0) exitWith {};

{
    _x params ["_id", "_type", "_position", "_vectorDirAndUp", "_damage", "_fuel", "_aceCargo", "_attached", "_inventory"];

    if ([GVAR(hashPersistentVehicles), _id] call CBA_fnc_hashHasKey) then {
        private _missionVehicle = ([GVAR(hashPersistentVehicles), _id] call CBA_fnc_hashGet);
        deleteVehicle _missionVehicle;
    };

    private _vehicle = _type createVehicle [-10000,0,0];
    _vehicle setPosASL _position;
    _vehicle setVectorDirAndUp _vectorDirAndUp;
    _vehicle setDamage _damage;
    _vehicle setFuel _fuel;
    {[_x, _vehicle] call ace_cargo_fnc_removeCargoItem} forEach (_vehicle getVariable ["ace_cargo_loaded", []]);
    {[_x, _vehicle] call ace_cargo_fnc_addCargoItem} forEach _aceCargo;
    {
        _x params ["_type", "_offset"];
        private _object = _type createVehicle [-10000,0,0];
        _object attachedTo [_vehicle, _offset];
    } forEach _attached;
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

    _vehicle setVariable [QGVAR(persistenceID), _id];
    [GVAR(hashPersistentVehicles), _id, _vehicle] call CBA_fnc_hashSet;
} forEach _vehicles;

/*
    _vehicles = [
        [
            id,
            type,
            position,
            vectorDirAndUp,
            damage,
            fuel,
            _vehicle getVariable ["ace_cargo_loaded", []],
            [(attachedObjects _vehicle) apply {typeOf _x}, (attachedObjects _vehicle) apply {_vehicle worldToModelVisual (ASLToAGL getPosASL _x)}],
            rack radio channels
            player remembered in use (changes to acre)
            inventory = [
                getWeaponCargo _x,getMagazineCargo _x,getItemCargo _x,getBackpackCargo _x
            ]
        ]
    ]
*/
