#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Saves persistence data to the API via the extension.
        Extracts structured data from the namespace, JSON encodes it,
        chunks it, and sends each chunk as a persistence_save event.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_persistence_fnc_saveDataApi
*/

if (!GVAR(dataSaved)) exitWith {};

// --- Conversion helpers ---

// Converts a weapon slot array to a hashmap
// Input: [] or [weapon, muzzle, pointer, optic, [magClass, ammo], [magClass, ammo], bipod]
private _convertWeaponSlot = {
    params ["_slot"];
    if (count _slot == 0) exitWith { createHashMap };
    private _primaryMag = _slot#4;
    private _secondaryMag = _slot#5;
    createHashMapFromArray [
        ["weapon",           _slot#0],
        ["muzzle",           _slot#1],
        ["pointer",          _slot#2],
        ["optic",            _slot#3],
        ["primaryMagazine",  createHashMapFromArray [["className", _primaryMag#0],   ["ammo", _primaryMag#1]]],
        ["secondaryMagazine",createHashMapFromArray [["className", _secondaryMag#0], ["ammo", _secondaryMag#1]]],
        ["bipod",            _slot#6]
    ]
};

// Converts a container slot array to a hashmap
// Input: [] or [containerClassName, items[]]
// Items can be:
//   Item:      [className, count]
//   Magazine:  [className, count, ammoCount]
//   Weapon:    [[weaponClass, muzzle, pointer, optic, [mag1], [mag2], bipod], count]
//   Container: [className, isBackpack]
private _convertContainerSlot = {
    params ["_slot"];
    if (count _slot == 0) exitWith { createHashMap };
    private _items = (_slot#1) apply {
        private _item = createHashMap;
        if (_x#0 isEqualType []) then {
            // Weapon in container: _x#0 is the weapon array
            _item set ["type", "weapon"];
            _item set ["weapon", [_x#0] call _convertWeaponSlot];
            _item set ["count", _x#1];
        } else {
            if (count _x == 2 && {_x#1 isEqualType true}) then {
                // Container in container: [className, isBackpack]
                _item set ["type", "container"];
                _item set ["className", _x#0];
                _item set ["isBackpack", _x#1];
            } else {
                // Item or magazine
                if (count _x > 2) then {
                    _item set ["type", "magazine"];
                    _item set ["className", _x#0];
                    _item set ["count", _x#1];
                    _item set ["ammo", _x#2];
                } else {
                    _item set ["type", "item"];
                    _item set ["className", _x#0];
                    _item set ["count", _x#1];
                };
            };
        };
        _item
    };
    createHashMapFromArray [
        ["className", _slot#0],
        ["items",     _items]
    ]
};

// Converts linked items array to a hashmap
// Input: [map, gps, radio, compass, watch, nvg]
private _convertLinkedItems = {
    params ["_linked"];
    if (count _linked == 0) exitWith { createHashMap };
    createHashMapFromArray [
        ["map",     _linked#0],
        ["gps",     _linked#1],
        ["radio",   _linked#2],
        ["compass", _linked#3],
        ["watch",   _linked#4],
        ["nvg",     _linked#5]
    ]
};

// Converts a loadout array (getUnitLoadout) to a fully named hashmap
// Input: 10-element array from getUnitLoadout
private _convertLoadout = {
    params ["_loadout"];
    if (count _loadout == 0) exitWith { createHashMap };
    createHashMapFromArray [
        ["primaryWeapon",   [_loadout#0] call _convertWeaponSlot],
        ["secondaryWeapon", [_loadout#1] call _convertWeaponSlot],
        ["handgun",         [_loadout#2] call _convertWeaponSlot],
        ["uniform",         [_loadout#3] call _convertContainerSlot],
        ["vest",            [_loadout#4] call _convertContainerSlot],
        ["backpack",        [_loadout#5] call _convertContainerSlot],
        ["headgear",        _loadout#6],
        ["facewear",        _loadout#7],
        ["binoculars",      [_loadout#8] call _convertWeaponSlot],
        ["linkedItems",     [_loadout#9] call _convertLinkedItems]
    ]
};

// Converts inventory array [weapons, magazines, items, backpacks] to a hashmap
// Each element is [classNames[], counts[]]
private _convertInventory = {
    params ["_inv"];
    if (count _inv == 0) exitWith { createHashMap };
    private _convertCargo = {
        params ["_cargo"];
        if (count _cargo == 0) exitWith { createHashMapFromArray [["classNames", []], ["counts", []]] };
        createHashMapFromArray [
            ["classNames", _cargo#0],
            ["counts",     _cargo#1]
        ]
    };
    createHashMapFromArray [
        ["weapons",   [_inv#0] call _convertCargo],
        ["magazines", [_inv#1] call _convertCargo],
        ["items",     [_inv#2] call _convertCargo],
        ["backpacks", [_inv#3] call _convertCargo]
    ]
};

// Converts an ACE cargo entry (recursive for nested cargo/inventory)
// Input: [className, nestedCargo, inventory, customName]
private _convertCargoEntry = {
    params ["_entry"];
    // Handle raw string classnames from ace_cargo_loaded (not processed by getObjectCargo)
    if (_entry isEqualType "") exitWith {
        createHashMapFromArray [
            ["className",  _entry],
            ["cargo",      []],
            ["inventory",  createHashMap],
            ["customName", ""]
        ]
    };
    private _nestedCargo = (_entry#1) apply { _x call _convertCargoEntry };
    private _inventory = [_entry#2] call _convertInventory;
    createHashMapFromArray [
        ["className",  _entry#0],
        ["cargo",      _nestedCargo],
        ["inventory",  _inventory],
        ["customName", _entry#3]
    ]
};

// --- Main data extraction ---

private _allObjects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
private _deletedObjects = GVAR(dataNamespace) getVariable [QGVAR(deletedObjects), []];
private _dateTime = GVAR(dataNamespace) getVariable [QGVAR(dateTime), date];
private _markers = GVAR(dataNamespace) getVariable [QGVAR(mapMarkers), []];

// Build objects array with named fields
private _objects = _allObjects apply {
    // turretWeapons: [[turretPath, weapons], ...] -> [{"turretPath": [...], "weapons": [...]}, ...]
    private _turretWeapons = (_x#IDX_OBJ_TURRETWEAPONS) apply {
        createHashMapFromArray [
            ["turretPath", _x#0],
            ["weapons",    _x#1]
        ]
    };

    // turretMagazines: [[className, turretPath, ammoCount, id, creator], ...]
    // id and creator are engine internals not needed for persistence
    private _turretMagazines = (_x#IDX_OBJ_TURRETMAGS) apply {
        createHashMapFromArray [
            ["className",  _x#0],
            ["turretPath", _x#1],
            ["ammoCount",  _x#2]
        ]
    };

    // pylonLoadout: [[magazine, ammo], ...] -> [{"magazine": ..., "ammo": ...}, ...]
    private _pylonLoadout = (_x#IDX_OBJ_PYLONLOADOUT) apply {
        createHashMapFromArray [
            ["magazine", _x#0],
            ["ammo",     _x#1]
        ]
    };

    // attached: [[className, offset], ...] -> [{"className": ..., "offset": [...]}, ...]
    private _attached = (_x#IDX_OBJ_ATTACHED) apply {
        createHashMapFromArray [
            ["className", _x#0],
            ["offset",    _x#1]
        ]
    };

    // inventory: [weapons, magazines, items, backpacks]
    private _inventory = [_x#IDX_OBJ_INVENTORY] call _convertInventory;

    // aceCargo: [[className, nestedCargo, inventory, customName], ...] (recursive)
    private _aceCargo = (_x#IDX_OBJ_ACECARGO) apply { _x call _convertCargoEntry };

    // aceFortify: [isAceFortification, side] -> {"isAceFortification": ..., "side": ...}
    private _aceRaw = _x#IDX_OBJ_ACEFORTIFY;
    private _aceFortify = if (count _aceRaw > 0) then {
        createHashMapFromArray [
            ["isAceFortification", _aceRaw#0],
            ["side",               _aceRaw#1]
        ]
    } else {
        createHashMap
    };

    // aceMedical (object): [medicClass, medicalVehicle, medicalFacility] -> hashmap
    private _aceMedRaw = _x#IDX_OBJ_ACEMEDICAL;
    private _aceMedical = if (count _aceMedRaw > 0) then {
        createHashMapFromArray [
            ["medicClass",      _aceMedRaw#0],
            ["medicalVehicle",  _aceMedRaw#1],
            ["medicalFacility", _aceMedRaw#2]
        ]
    } else {
        createHashMap
    };

    // aceRepair: [repairVehicle, repairFacility] -> hashmap
    private _aceRepRaw = _x#IDX_OBJ_ACEREPAIR;
    private _aceRepair = if (count _aceRepRaw > 0) then {
        createHashMapFromArray [
            ["repairVehicle",  _aceRepRaw#0],
            ["repairFacility", _aceRepRaw#1]
        ]
    } else {
        createHashMap
    };

    createHashMapFromArray [
        ["id",             _x#IDX_OBJ_ID],
        ["type",           _x#IDX_OBJ_TYPE],
        ["position",       _x#IDX_OBJ_POSITION],
        ["vectorDirUp",    _x#IDX_OBJ_VECTORDIRUP],
        ["damage",         _x#IDX_OBJ_DAMAGE],
        ["fuel",           _x#IDX_OBJ_FUEL],
        ["turretWeapons",  _turretWeapons],
        ["turretMagazines",_turretMagazines],
        ["pylonLoadout",   _pylonLoadout],
        ["logistics",      _x#IDX_OBJ_LOGISTICS],
        ["attached",       _attached],
        ["rackChannels",   _x#IDX_OBJ_RACKCHANNELS],
        ["aceCargo",       _aceCargo],
        ["inventory",      _inventory],
        ["aceFortify",     _aceFortify],
        ["aceMedical",     _aceMedical],
        ["aceRepair",      _aceRepair],
        ["customName",     _x#IDX_OBJ_CUSTOMNAME]
    ]
};

// Build players hashmap keyed by UID
private _players = createHashMap;
{
    private _playerData = GVAR(dataNamespace) getVariable [_x, []];
    if (count _playerData > 0) then {
        // Parse ACE medical JSON string to hashmap so it stores as a nested document
        private _aceMedicalRaw = _playerData#6;
        private _aceMedical = if (_aceMedicalRaw isEqualType "" && {_aceMedicalRaw != ""}) then {
            private _parsed = [_aceMedicalRaw, 2] call CBA_fnc_parseJSON;
            if (isNil "_parsed") then { createHashMap } else { _parsed }
        } else {
            createHashMap
        };

        // vehicleState: [vehicleId, role, index] -> hashmap
        private _vsRaw = _playerData#1;
        private _vehicleState = if (count _vsRaw > 0) then {
            createHashMapFromArray [
                ["vehicleId", _vsRaw#0],
                ["role",      _vsRaw#1],
                ["index",     _vsRaw#2]
            ]
        } else {
            createHashMap
        };

        // loadout: 10-element getUnitLoadout array -> named hashmap
        private _loadout = [_playerData#4] call _convertLoadout;

        // radios: [[type, channel, volume, spatial, pttIndex], ...] -> [{"type": ..., ...}, ...]
        private _radios = (_playerData#9) apply {
            createHashMapFromArray [
                ["type",     _x#0],
                ["channel",  _x#1],
                ["volume",   _x#2],
                ["spatial",  _x#3],
                ["pttIndex", _x#4]
            ]
        };

        // diveState: [isDiving] -> hashmap
        private _dsRaw = _playerData#10;
        private _diveState = if (count _dsRaw > 0) then {
            createHashMapFromArray [["isDiving", _dsRaw#0]]
        } else {
            createHashMap
        };

        _players set [_x, createHashMapFromArray [
            ["position",     _playerData#0],
            ["vehicleState", _vehicleState],
            ["direction",    _playerData#2],
            ["animation",    _playerData#3],
            ["loadout",      _loadout],
            ["damage",       _playerData#5],
            ["aceMedical",   _aceMedical],
            ["earplugs",     _playerData#7],
            ["attachedItems",_playerData#8],
            ["radios",       _radios],
            ["diveState",    _diveState]
        ]];
    };
} forEach GVAR(playerUids);

// Build custom data from serializers
private _customData = createHashMap;
{
    _x params ["_id", "_function"];
    private _data = GVAR(dataNamespace) getVariable [_id, []];
    if (count _data > 0) then {
        _customData set [_id, _data];
    };
} forEach GVAR(serializers);

// Build the full session
private _session = createHashMapFromArray [
    ["objects",        _objects],
    ["deletedObjects", _deletedObjects],
    ["players",        _players],
    ["markers",        _markers],
    ["dateTime",       _dateTime],
    ["customData",     _customData]
];

// JSON encode
private _json = [_session] call CBA_fnc_encodeJSON;
private _jsonLength = count _json;
INFO_1("API persistence save: %1 characters",_jsonLength);

// Chunk and send
// callExtension input limit is ~10KB. The chunk gets JSON-escaped (quotes doubled)
// then wrapped in an envelope by sendEvent, adding ~200 chars overhead.
// Use 4000 to leave room for worst-case escaping expansion.
private _chunkSize = 4000;
private _totalChunks = ceil (_jsonLength / _chunkSize);
if (_totalChunks < 1) then { _totalChunks = 1 };
private _saveId = format ["%1_%2", GVAR(key), call CBA_fnc_createUUID];

for "_i" from 0 to (_totalChunks - 1) do {
    private _start = _i * _chunkSize;
    private _chunk = _json select [_start, _chunkSize];

    ["persistence_save", createHashMapFromArray [
        ["id",    _saveId],
        ["key",   GVAR(key)],
        ["sessionId", EGVAR(api,sessionId)],
        ["index", _i],
        ["total", _totalChunks],
        ["data",  _chunk]
    ]] call EFUNC(api,sendEvent);
};

LOG_1("API persistence save: sent %1 chunks",_totalChunks);
