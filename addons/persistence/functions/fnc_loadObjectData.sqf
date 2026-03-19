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

    Example:
        [_data, _forceLoad] call uksf_persistence_fnc_loadObjectData
*/
params ["_data", ["_forceLoad", false]];

// Convert API hashmap format to positional array for downstream compatibility
if (_data isEqualType createHashMap) then {
    // turretWeapons: [{"turretPath": [...], "weapons": [...]}] → [[turretPath, weapons]]
    private _turretWeapons = (_data getOrDefault ["turretWeapons", []]) apply {
        if (_x isEqualType createHashMap) then {
            [_x getOrDefault ["turretPath", []], _x getOrDefault ["weapons", []]]
        } else { _x }
    };

    // turretMagazines: [{"className": ..., "turretPath": [...], "ammoCount": ...}] → [[className, turretPath, ammoCount]]
    private _turretMagazines = (_data getOrDefault ["turretMagazines", []]) apply {
        if (_x isEqualType createHashMap) then {
            [_x getOrDefault ["className", ""], _x getOrDefault ["turretPath", []], _x getOrDefault ["ammoCount", 0]]
        } else { _x }
    };

    // pylonLoadout: [{"magazine": ..., "ammo": ...}] → [[magazine, ammo]]
    private _pylonLoadout = (_data getOrDefault ["pylonLoadout", []]) apply {
        if (_x isEqualType createHashMap) then {
            [_x getOrDefault ["magazine", ""], _x getOrDefault ["ammo", 0]]
        } else { _x }
    };

    // attached: [{"className": ..., "offset": [...]}] → [[className, offset]]
    private _attached = (_data getOrDefault ["attached", []]) apply {
        if (_x isEqualType createHashMap) then {
            [_x getOrDefault ["className", ""], _x getOrDefault ["offset", [0,0,0]]]
        } else { _x }
    };

    // inventory: {"weapons": {"classNames": [...], "counts": [...]}, ...} → [[classNames, counts], ...]
    private _inventoryHm = _data getOrDefault ["inventory", createHashMap];
    private _inventory = if (_inventoryHm isEqualType createHashMap && count _inventoryHm > 0) then {
        private _convertCargoBack = {
            params ["_cargo"];
            if (_cargo isEqualType createHashMap) then {
                [_cargo getOrDefault ["classNames", []], _cargo getOrDefault ["counts", []]]
            } else { _cargo }
        };
        [
            [_inventoryHm getOrDefault ["weapons", createHashMap]] call _convertCargoBack,
            [_inventoryHm getOrDefault ["magazines", createHashMap]] call _convertCargoBack,
            [_inventoryHm getOrDefault ["items", createHashMap]] call _convertCargoBack,
            [_inventoryHm getOrDefault ["backpacks", createHashMap]] call _convertCargoBack
        ]
    } else {
        [[], [], [], []]
    };

    // aceCargo: recursive [{"className": ..., "cargo": [...], "inventory": {...}, "customName": ...}]
    private _convertCargoEntryBack = {
        params ["_entry"];
        if !(_entry isEqualType createHashMap) exitWith { _entry };
        private _nestedCargo = (_entry getOrDefault ["cargo", []]) apply { [_x] call _convertCargoEntryBack };
        private _cargoInv = _entry getOrDefault ["inventory", createHashMap];
        private _cargoInventory = if (_cargoInv isEqualType createHashMap && count _cargoInv > 0) then {
            private _cc = {
                params ["_c"];
                if (_c isEqualType createHashMap) then { [_c getOrDefault ["classNames", []], _c getOrDefault ["counts", []]] } else { _c }
            };
            [[_cargoInv getOrDefault ["weapons", createHashMap]] call _cc, [_cargoInv getOrDefault ["magazines", createHashMap]] call _cc, [_cargoInv getOrDefault ["items", createHashMap]] call _cc, [_cargoInv getOrDefault ["backpacks", createHashMap]] call _cc]
        } else { [] };
        [_entry getOrDefault ["className", ""], _nestedCargo, _cargoInventory, _entry getOrDefault ["customName", ""]]
    };
    private _aceCargo = (_data getOrDefault ["aceCargo", []]) apply { [_x] call _convertCargoEntryBack };

    // aceFortify: {"isAceFortification": ..., "side": ...} → [isAceFortification, side]
    // API stores side as string ("WEST"), but downstream code expects SQF side type (west)
    private _aceFortifyHm = _data getOrDefault ["aceFortify", createHashMap];
    private _aceFortify = if (_aceFortifyHm isEqualType createHashMap && count _aceFortifyHm > 0) then {
        private _sideRaw = _aceFortifyHm getOrDefault ["side", "WEST"];
        private _side = if (_sideRaw isEqualType "") then {
            switch (toUpper _sideRaw) do {
                case "WEST": {west};
                case "EAST": {east};
                case "INDEPENDENT": {independent};
                case "CIVILIAN": {civilian};
                default {west};
            }
        } else { _sideRaw };
        [_aceFortifyHm getOrDefault ["isAceFortification", false], _side]
    } else {
        [false, west]
    };

    // aceMedical: {"medicClass": ..., "medicalVehicle": ..., "medicalFacility": ...} → [medicClass, medicalVehicle, medicalFacility]
    private _aceMedHm = _data getOrDefault ["aceMedical", createHashMap];
    private _aceMedical = if (_aceMedHm isEqualType createHashMap && count _aceMedHm > 0) then {
        [_aceMedHm getOrDefault ["medicClass", 0], _aceMedHm getOrDefault ["medicalVehicle", false], _aceMedHm getOrDefault ["medicalFacility", false]]
    } else {
        [0, false, false]
    };

    // aceRepair: {"repairVehicle": ..., "repairFacility": ...} → [repairVehicle, repairFacility]
    private _aceRepHm = _data getOrDefault ["aceRepair", createHashMap];
    private _aceRepair = if (_aceRepHm isEqualType createHashMap && count _aceRepHm > 0) then {
        [_aceRepHm getOrDefault ["repairVehicle", 0], _aceRepHm getOrDefault ["repairFacility", 0]]
    } else {
        [0, 0]
    };

    // Reconstruct positional array
    _data = [
        _data getOrDefault ["id", ""],
        _data getOrDefault ["type", ""],
        _data getOrDefault ["position", [0,0,0]],
        _data getOrDefault ["vectorDirUp", [[0,1,0],[0,0,1]]],
        _data getOrDefault ["damage", 0],
        _data getOrDefault ["fuel", 0],
        _turretWeapons,
        _turretMagazines,
        _pylonLoadout,
        _data getOrDefault ["logistics", [0,0,0]],
        _attached,
        _data getOrDefault ["rackChannels", []],
        _aceCargo,
        _inventory,
        _aceFortify,
        _aceMedical,
        _aceRepair,
        _data getOrDefault ["customName", ""]
    ]
};

_data params ["_id", "_type", "_position", "_vectorDirAndUp", "_damage", "_fuel", "_turretWeapons", "_turretMagazines", "_pylonLoadout", "_logisticsCargo", "_attached", "_rackChannels", "_aceCargo", "_inventory", ["_aceFortifyData", [false, west]], ["_aceMedical", [0, false, false]], ["_aceRepair", [0, 0]], ["_customName", ""], ["_failedLastLoad", false]];
_aceFortifyData params ["_isAceFortification", "_aceFortifySide"];
_aceMedical params ["_medicalClass", "_medicalVehicle", "_medicalFacility"];
_aceRepair params ["_repairVehicle", "_repairFacility"];

if (isNil "_id" || isNil "_type") exitWith {
    WARNING("An object with no id or type tried to load. Aborting.");
};

TRACE_6("Loading object...",_id,_type,_position,_vectorDirAndUp,_damage,_fuel);
// TRACE_1("...",_rackChannels);
// TRACE_3("...",_turretWeapons,_turretMagazines,_pylonLoadout);
// TRACE_2("...",_logisticsCargo,_attached);
// TRACE_1("...",_aceCargo);
// TRACE_1("...",_inventory);
// TRACE_1("...",_aceFortifyData);

if !(_type isEqualType "") exitWith {
    WARNING_1("Tried to load empty data for id %1",_id);
};

private _object = objNull;
if ([GVAR(persistentObjectsHash), _id] call CBA_fnc_hashHasKey) then {
    TRACE_1("Loading object exists in mission, using",_id);
    _object = ([GVAR(persistentObjectsHash), _id] call CBA_fnc_hashGet);
    GVAR(missionObjects) deleteAt (GVAR(missionObjects) find _object);
};

if (isNull _object) then {
    _object = _type createVehicle [0,0,0];
    _object setVectorDirAndUp _vectorDirAndUp;
};

if (!_forceLoad && {!([ASLToAGL _position, _object, (_vectorDirAndUp#0) call CBA_fnc_vectDir, GVAR(missionObjects)] call EFUNC(common,isPositionSafe))}) then {
    deleteVehicle _object;

    if (_failedLastLoad) exitWith {
        WARNING_2("Aborted loading object %1. Saved position %2 will clip with a mission placed object. This is the second failed load. Removing this object from persistence data",_id,_position);
        [QGVAR(removeAbortedObjectFromPersistence), [_id]] call CBA_fnc_localEvent;
    };

    WARNING_2("Aborted loading object %1. Saved position %2 will clip with a mission placed object. Deleting object but marking it to not be removed from persistence data for this load. Object will be removed on the next failed load",_id,_position);
    GVAR(abortedObjectIds) pushBackUnique _id;
} else {
    _object setVariable [QGVAR(persistenceID), _id];
    [GVAR(persistentObjectsHash), _id, _object] call CBA_fnc_hashSet;
    GVAR(abortedObjectIds) deleteAt (GVAR(abortedObjectIds) find _id);

    _object setPosASL _position;
    _object setVectorDirAndUp _vectorDirAndUp;
    _object setDamage _damage;
    _object setFuel _fuel;

    private _currentTurretMagazines = magazinesAllTurrets _object;
    private _turretPaths = _currentTurretMagazines apply {_x#1};
    _turretPaths = _turretPaths arrayIntersect _turretPaths;
    private _pylonPaths = (configProperties [configOf _object >> "Components" >> "TransportPylonsComponent" >> "Pylons", "isClass _x"]) apply {getArray (_x >> "turret")};
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
        if (_forEachIndex < count _pylonPaths) then {
            _object setPylonLoadout [_forEachIndex + 1, _x#0, true, _pylonPaths select _forEachIndex];
            _object setAmmoOnPylon [_forEachIndex + 1, _x#1];
        };
    } forEach _pylonLoadout;
    [_object] call EFUNC(air_weapons,correctPilotPylon);

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
    [QGVAR(setObjectCargo), [_object, _aceCargo, _inventory, _customName]] call CBA_fnc_localEvent;

    if (_isAceFortification) then {
        ["acex_fortify_objectPlaced", [objNull, _aceFortifySide, _object]] call CBA_fnc_globalEvent;
    };

    _object setVariable ["ace_medical_medicClass", _medicalClass, true];
    _object setVariable ["ace_medical_isMedicalVehicle", _medicalVehicle, true];
    _object setVariable ["ace_medical_isMedicalFacility", _medicalFacility, true];
    _object setVariable ["ace_isRepairVehicle", _repairVehicle, true];
    _object setVariable ["ace_isRepairFacility", _repairFacility, true];

    if (_object isKindOf "UAV") then {
        createVehicleCrew _object;
    };

    if (_object isKindOf QGVAR(markerAmmo)) then {
        [QGVAR(addLogisticsMarker), _object] call CBA_fnc_localEvent;
    };
};
