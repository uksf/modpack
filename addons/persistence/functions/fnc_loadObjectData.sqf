#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Loads saved object data

    Parameter(s):
        0: Object data <ARRAY>
        1: Force load <BOOLEAN>

    Return Value:
        None
*/
params ["_data", ["_forceLoad", false]];
_data params ["_id", "_type", "_position", "_vectorDirAndUp", "_damage", "_fuel", "_turretWeapons", "_turretMagazines", "_pylonLoadout", "_logisticsCargo", "_attached", "_rackChannels", "_aceCargo", "_inventory", ["_acexFortifyData", [false]]];
_acexFortifyData params ["_isAcexFortification", "_acexFortifySide"];

TRACE_6("Loading object...",_id,_type,_position,_vectorDirAndUp,_damage,_fuel);
// TRACE_1("...",_rackChannels);
// TRACE_3("...",_turretWeapons,_turretMagazines,_pylonLoadout);
// TRACE_2("...",_logisticsCargo,_attached);
// TRACE_1("...",_aceCargo);
// TRACE_1("...",_inventory);
// TRACE_1("...",_acexFortifyData);

if !(_type isEqualType "") exitWith {
    WARNING_1("Tried to load empty data for id %1",_id);
};

private _object = objNull;
if ([GVAR(persistentObjectsHash), _id] call CBA_fnc_hashHasKey) then {
    TRACE_1("Loading object exists in mission, using",_id);
    _object = ([GVAR(persistentObjectsHash), _id] call CBA_fnc_hashGet);
    GVAR(missionObjects) deleteAt (GVAR(missionObjects) find _object);
} else {
    _object = _type createVehicle [0,0,0];
    _object setVectorDirAndUp _vectorDirAndUp;
};

if (!_forceLoad && {!([ASLToAGL _position, _object, (_vectorDirAndUp#0) call CBA_fnc_vectDir, GVAR(missionObjects)] call EFUNC(common,isPositionSafe))}) then {
    WARNING_2("Aborted loading object %1. Saved position %2 will clip with a mission placed object. Deleting object but marking it to not be removed from persistence data.",_id,_position);
    deleteVehicle _object;
    GVAR(dontDeleteObjectIds) pushBackUnique _id;
} else {
    _object setVariable [QGVAR(persistenceID), _id];
    [GVAR(persistentObjectsHash), _id, _object] call CBA_fnc_hashSet;

    _object setPosASL _position;
    _object setVectorDirAndUp _vectorDirAndUp;
    _object setDamage _damage;
    _object setFuel _fuel;

    private _currentTurretMagazines = magazinesAllTurrets _object;
    private _turretPaths = _currentTurretMagazines apply {_x#1};
    _turretPaths = _turretPaths arrayIntersect _turretPaths;
    private _pylonPaths = (configProperties [EGVAR(common,configVehicles) >> typeOf _object >> "Components" >> "TransportPylonsComponent" >> "Pylons", "isClass _x"]) apply {getArray (_x >> "turret")};
    private _currentTurretWeapons = _turretPaths apply {[_x, _object weaponsTurret _x]};
    {
        private _turretPath = _x#0;
        {_object removeWeaponTurret [_x, _turretPath]} forEach _x#1;
    } forEach _currentTurretWeapons;
    {_object removeWeaponGlobal (getText (EGVAR(common,configMagazines) >> _x >> "pylonWeapon"))} forEach (getPylonMagazines _object);
    {_object removeMagazinesTurret [_x#0, _x#1]} forEach _currentTurretMagazines;
    {
        private _turretPath = _x#0;
        {_object addWeaponTurret [_x, _turretPath]} forEach _x#1;
    } forEach _turretWeapons;
    {_object addMagazineTurret [_x#0, _x#1, _x#2]} forEach _turretMagazines;
    {
        _object setPylonLoadOut [_forEachIndex + 1, _x#0, true, _pylonPaths select _forEachIndex];
        _object setAmmoOnPylon [_forEachIndex + 1, _x#1];
    } forEach _pylonLoadout;
    [_object] call EFUNC(weapons,correctPilotPylon);

    if (finite (_logisticsCargo#0)) then {_object setAmmoCargo _logisticsCargo#0;};
    if (finite (_logisticsCargo#1)) then {_object setFuelCargo _logisticsCargo#1;};
    if (finite (_logisticsCargo#2)) then {_object setRepairCargo _logisticsCargo#2;};

    if (count _attached > 0) then {
        private _attachList = _object getVariable ["ace_attach_attached", []];
        {
            _x params ["_type", "_offset"];
            private _attachedObject = _type createVehicle [0,0,0];
            _attachedObject attachTo [_object, _offset];
            _attachList pushBack [_attachedObject, _type];
        } forEach _attached;
        _object setVariable ["ace_attach_attached", _attachList, true];
    };
    _object setVariable [QEGVAR(radios,rackChannels), _rackChannels, true];
    [_object, _aceCargo, _inventory] call FUNC(setObjectCargo);

    if (_isAcexFortification) then {
        ["acex_fortify_objectPlaced", [objNull, _acexFortifySide, _object]] call CBA_fnc_globalEvent;
    };

    if (_object isKindOf "UAV") then {
        createVehicleCrew _object;
    };

    if (_object isKindOf QGVAR(markerAmmo)) then {
        [QGVAR(addLogisticsMarker), _object] call CBA_fnc_localEvent;
    };
};
