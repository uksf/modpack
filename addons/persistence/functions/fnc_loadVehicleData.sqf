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
    _x params ["_id", "_type", "_position", "_vectorDirAndUp", "_damage", "_fuel", "_magazines", "_logisticsCargo", "_attached", "_rackChannels", "_cargo", "_inventory"];

    if ([GVAR(hashPersistentVehicles), _id] call CBA_fnc_hashHasKey) then {
        private _missionVehicle = ([GVAR(hashPersistentVehicles), _id] call CBA_fnc_hashGet);
        deleteVehicle _missionVehicle;
    };

    private _vehicle = _type createVehicle [-10000,0,0];
    _vehicle setPosASL _position;
    _vehicle setVectorDirAndUp _vectorDirAndUp;
    _vehicle setDamage _damage;
    _vehicle setFuel _fuel;
    {_vehicle removeMagazinesTurret [_this#0, _this#1];} forEach (magazinesAllTurrets _vehicle);
    {_vehicle addMagazineTurret [_this#0, _this#1, _this#2];} forEach _magazines;
    _vehicle setAmmoCargo _logisticsCargo#0;
    _vehicle setAmmoCargo _logisticsCargo#1;
    _vehicle setAmmoCargo _logisticsCargo#2;
    {
        _x params ["_type", "_offset"];
        private _object = _type createVehicle [-10000,0,0];
        _object attachedTo [_vehicle, _offset];
    } forEach _attached;
    _vehicle setVariable [QGVAR(rackChannels), _rackChannels, true];
    [_vehicle, _aceCargo, _inventory] call FUNC(setVehicleCargo);
    _vehicle setVariable [QGVAR(persistenceID), _id];
    [GVAR(hashPersistentVehicles), _id, _vehicle] call CBA_fnc_hashSet;
} forEach _vehicles;
