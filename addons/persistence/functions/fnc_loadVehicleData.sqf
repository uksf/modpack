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
    _x params ["_id", "_type", "_position", "_vectorDirAndUp", "_damage", "_fuel", "_turretWeapons", "_turretMagazines", "_pylonLoadout", "_logisticsCargo", "_attached", "_rackChannels", "_aceCargo", "_inventory"];
    TRACE_7("Loading vehicle...",_id,_type,_position,_vectorDirAndUp,_damage,_fuel,_rackChannels);
    //TRACE_3("...",_turretWeapons,_turretMagazines,_pylonLoadout);
    //TRACE_2("...",_logisticsCargo,_attached);
    //TRACE_1("...",_aceCargo);
    //TRACE_1("...",_inventory);

    private _vehicle = objNull;
    if ([GVAR(hashPersistentVehicles), _id] call CBA_fnc_hashHasKey) then {
        TRACE_1("Loading vehicle exists in mission, using",_id);
        _vehicle = ([GVAR(hashPersistentVehicles), _id] call CBA_fnc_hashGet);
    } else {
        _vehicle = _type createVehicle [-2000,0,0];
        _vehicle setVariable [QGVAR(persistenceID), _id];
        [GVAR(hashPersistentVehicles), _id, _vehicle] call CBA_fnc_hashSet;
    };

    _vehicle setPosASL _position;
    _vehicle setVectorDirAndUp _vectorDirAndUp;
    // _vehicle setDamage _damage;
    _vehicle setFuel _fuel;

    private _currentTurretMagazines = magazinesAllTurrets _vehicle;
    private _turretPaths = _currentTurretMagazines apply {_x#1};
    _turretPaths = _turretPaths arrayIntersect _turretPaths;
    private _pylonPaths = (configProperties [configFile >> "CfgVehicles" >> typeOf _vehicle >> "Components" >> "TransportPylonsComponent" >> "Pylons", "isClass _x"]) apply {getArray (_x >> "turret")};
    private _currentTurretWeapons = _turretPaths apply {[_x, _vehicle weaponsTurret _x]};
    {
        private _turretPath = _x#0;
        {_vehicle removeWeaponTurret [_x, _turretPath]} forEach _x#1;
    } forEach _currentTurretWeapons;
    {_vehicle removeWeaponGlobal (getText (configFile >> "CfgMagazines" >> _x >> "pylonWeapon"))} forEach (getPylonMagazines _vehicle);
    {_vehicle removeMagazinesTurret [_x#0, _x#1]} forEach _currentTurretMagazines;
    {
        private _turretPath = _x#0;
        {_vehicle addWeaponTurret [_x, _turretPath]} forEach _x#1;
    } forEach _turretWeapons;
    {_vehicle addMagazineTurret [_x#0, _x#1, _x#2]} forEach _turretMagazines;
    {
        _vehicle setPylonLoadOut [_forEachIndex + 1, _x#0, true, _pylonPaths select _forEachIndex];
        _vehicle setAmmoOnPylon [_forEachIndex + 1, _x#1];
    } forEach _pylonLoadout;
    [_vehicle] call EFUNC(weapons,correctPilotPylon);

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

    if (_vehicle isKindOf "UAV") then {
        createVehicleCrew _vehicle;
    };

    if (_vehicle isKindOf QGVAR(markerAmmo)) then {
        [QGVAR(addLogisticsMarker), _vehicle] call CBA_fnc_localEvent;
    };
} forEach _vehicles;
