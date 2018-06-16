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
    _x params ["_id", "_type", "_position", "_vectorDirAndUp", "_damage", "_fuel", "_magazines", "_logisticsCargo", "_attached", "_rackChannels", "_aceCargo", "_inventory"];
    TRACE_7("Loading vehicle...",_id,_type,_position,_vectorDirAndUp,_damage,_fuel,_rackChannels);
    TRACE_3("...",_magazines,_logisticsCargo,_attached);
    TRACE_1("...",_aceCargo);
    TRACE_1("...",_inventory);

    if ([GVAR(hashPersistentVehicles), _id] call CBA_fnc_hashHasKey) then {
        private _missionVehicle = ([GVAR(hashPersistentVehicles), _id] call CBA_fnc_hashGet);
        deleteVehicle _missionVehicle;
    };

    private _vehicle = _type createVehicle [-2000,0,0];
    _vehicle setVariable [QGVAR(persistenceID), _id];
    _vehicle setPosASL _position;
    _vehicle setVectorDirAndUp _vectorDirAndUp;
    _vehicle setDamage _damage;
    _vehicle setFuel _fuel;
    {_vehicle removeMagazinesTurret [_x#0, _x#1];} forEach (magazinesAllTurrets _vehicle);
    {_vehicle addMagazineTurret [_x#0, _x#1, _x#2];} forEach _magazines;
    if (finite (_logisticsCargo#0)) then {_vehicle setAmmoCargo _logisticsCargo#0;};
    if (finite (_logisticsCargo#1)) then {_vehicle setFuelCargo _logisticsCargo#1;};
    if (finite (_logisticsCargo#2)) then {_vehicle setRepairCargo _logisticsCargo#2;};
    if (count _attached > 0) then {
        private _attachList = _vehicle getVariable ["ace_attach_attached", []];
        {
            _x params ["_type", "_offset"];
            private _attachedObject = _type createVehicle [0,-2000,0];
            _attachedObject attachTo [_vehicle, _offset];
            _attachList pushBack [_attachedObject, _type];
        } forEach _attached;
        _vehicle setVariable ["ace_attach_attached", _attachList, true];
    };
    _vehicle setVariable [QEGVAR(radios,rackChannels), _rackChannels, true];
    [_vehicle, _aceCargo, _inventory] call FUNC(setVehicleCargo);
    [GVAR(hashPersistentVehicles), _id, _vehicle] call CBA_fnc_hashSet;
} forEach _vehicles;
