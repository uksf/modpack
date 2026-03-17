#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Compares a parsed API session against a profile snapshot.
        Logs detailed per-category match/mismatch results.
        Uses type-aware comparison: == for numbers and strings,
        isEqualTo for booleans/sides, recursive for arrays and hashmaps.
        Does not modify any state.

    Parameter(s):
        0: Session hashmap <HASHMAP> — the parsed API session
        1: Profile snapshot <HASHMAP> — snapshot taken at load time

    Return Value:
        None

    Example:
        [_session, _snapshot] call uksf_persistence_fnc_compareApiSession
*/
params ["_session", "_snapshot"];

INFO("=== API vs Profile Comparison Start ===");

private _parseSide = {
    params ["_sideString"];
    switch (toUpper _sideString) do {
        case "WEST": {west};
        case "EAST": {east};
        case "INDEPENDENT": {independent};
        case "CIVILIAN": {civilian};
        default {west};
    }
};

// Type-aware comparison that handles float precision differences from
// JSON round-trip. isEqualTo is binary-exact on floats, so two values
// that display as 3.1957 can fail if their binary representations
// differ after encoding/decoding. == handles this for numbers and strings.
// Arrays and hashmaps are compared recursively.
private _isEqual = {
    params ["_a", "_b"];
    if (isNil "_a" && isNil "_b") exitWith { true };
    if (isNil "_a" || isNil "_b") exitWith { false };
    if !(_a isEqualType _b) exitWith { false };
    if (_a isEqualType 0) exitWith { _a == _b };
    if (_a isEqualType "") exitWith { _a == _b };
    if (_a isEqualType []) exitWith {
        if (count _a != count _b) exitWith { false };
        private _match = true;
        for "_i" from 0 to (count _a - 1) do {
            if !([_a#_i, _b#_i] call _isEqual) exitWith { _match = false };
        };
        _match
    };
    if (_a isEqualType createHashMap) exitWith {
        if (count _a != count _b) exitWith { false };
        private _match = true;
        {
            private _valB = _b getOrDefault [_x, nil];
            if (isNil "_valB" || {!([_y, _valB] call _isEqual)}) exitWith { _match = false };
        } forEach _a;
        _match
    };
    _a isEqualTo _b
};

private _failures = 0;
private _successes = 0;

// --- DateTime ---
private _profileDateTime = _snapshot getOrDefault ["dateTime", []];
private _apiDateTime = _session getOrDefault ["dateTime", []];
if ([_profileDateTime, _apiDateTime] call _isEqual) then {
    _successes = _successes + 1;
    INFO("DateTime: MATCH");
} else {
    _failures = _failures + 1;
    WARNING_2("DateTime: MISMATCH — profile=%1, api=%2",_profileDateTime,_apiDateTime);
};

// --- Deleted Objects ---
private _profileDeleted = _snapshot getOrDefault ["deletedObjects", []];
private _apiDeleted = _session getOrDefault ["deletedObjects", []];
if ([_profileDeleted, _apiDeleted] call _isEqual) then {
    _successes = _successes + 1;
    INFO_1("Deleted objects: MATCH (count=%1)",count _profileDeleted);
} else {
    _failures = _failures + 1;
    private _profileOnly = _profileDeleted - _apiDeleted;
    private _apiOnly = _apiDeleted - _profileDeleted;
    WARNING_4("Deleted objects: MISMATCH — profile count=%1, api count=%2, in profile only=%3, in api only=%4",count _profileDeleted,count _apiDeleted,_profileOnly,_apiOnly);
};

// --- Map Markers ---
private _profileMarkers = _snapshot getOrDefault ["mapMarkers", []];
private _apiMarkers = _session getOrDefault ["markers", []];
if ([_profileMarkers, _apiMarkers] call _isEqual) then {
    _successes = _successes + 1;
    INFO_1("Map markers: MATCH (count=%1)",count _profileMarkers);
} else {
    _failures = _failures + 1;
    WARNING_2("Map markers: MISMATCH — profile count=%1, api count=%2",count _profileMarkers,count _apiMarkers);
};

// --- Objects ---
private _profileObjects = _snapshot getOrDefault ["objects", []];
private _apiObjectsRaw = _session getOrDefault ["objects", []];

// Convert API objects to indexed arrays for comparison (same logic as loadObjectData)
private _convertCargoBack = {
    params ["_cargo"];
    if (_cargo isEqualType createHashMap) then {
        [_cargo getOrDefault ["classNames", []], _cargo getOrDefault ["counts", []]]
    } else { _cargo }
};

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

private _apiObjects = _apiObjectsRaw apply {
    // turretWeapons: [{"turretPath": [...], "weapons": [...]}] → [[turretPath, weapons]]
    private _turretWeapons = (_x getOrDefault ["turretWeapons", []]) apply {
        if (_x isEqualType createHashMap) then {
            [_x getOrDefault ["turretPath", []], _x getOrDefault ["weapons", []]]
        } else { _x }
    };

    // turretMagazines: [{"className": ..., "turretPath": [...], ...}] → [[className, turretPath, ammoCount, id, ammo]]
    private _turretMagazines = (_x getOrDefault ["turretMagazines", []]) apply {
        if (_x isEqualType createHashMap) then {
            [_x getOrDefault ["className", ""], _x getOrDefault ["turretPath", []], _x getOrDefault ["ammoCount", 0], _x getOrDefault ["id", 0], _x getOrDefault ["ammo", 0]]
        } else { _x }
    };

    // pylonLoadout: [{"magazine": ..., "ammo": ...}] → [[magazine, ammo]]
    private _pylonLoadout = (_x getOrDefault ["pylonLoadout", []]) apply {
        if (_x isEqualType createHashMap) then {
            [_x getOrDefault ["magazine", ""], _x getOrDefault ["ammo", 0]]
        } else { _x }
    };

    // attached: [{"className": ..., "offset": [...]}] → [[className, offset]]
    private _attached = (_x getOrDefault ["attached", []]) apply {
        if (_x isEqualType createHashMap) then {
            [_x getOrDefault ["className", ""], _x getOrDefault ["offset", [0,0,0]]]
        } else { _x }
    };

    // inventory: {"weapons": {"classNames": [...], "counts": [...]}, ...} → [[classNames, counts], ...]
    private _inventoryHm = _x getOrDefault ["inventory", createHashMap];
    private _inventory = if (_inventoryHm isEqualType createHashMap && count _inventoryHm > 0) then {
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
    private _aceCargo = (_x getOrDefault ["aceCargo", []]) apply { [_x] call _convertCargoEntryBack };

    // aceFortify: {"isAceFortification": ..., "side": ...} → [isAceFortification, side]
    //             or old positional array [bool, side] — leave untouched
    private _aceFortifyRaw = _x getOrDefault ["aceFortify", createHashMap];
    private _aceFortify = if (_aceFortifyRaw isEqualType createHashMap && count _aceFortifyRaw > 0) then {
        private _sideStr = _aceFortifyRaw getOrDefault ["side", "WEST"];
        private _side = if (_sideStr isEqualType "") then { [_sideStr] call _parseSide } else { _sideStr };
        [_aceFortifyRaw getOrDefault ["isAceFortification", false], _side]
    } else {
        if (_aceFortifyRaw isEqualType [] && count _aceFortifyRaw > 1 && {_aceFortifyRaw#1 isEqualType ""}) then {
            private _fortifyData = +_aceFortifyRaw;
            _fortifyData set [1, [_fortifyData#1] call _parseSide];
            _fortifyData
        } else {
            if (_aceFortifyRaw isEqualType []) then { _aceFortifyRaw } else { [false, west] }
        }
    };

    // aceMedical: {"medicClass": ..., "medicalVehicle": ..., "medicalFacility": ...} → [medicClass, medicalVehicle, medicalFacility]
    private _aceMedHm = _x getOrDefault ["aceMedical", createHashMap];
    private _aceMedical = if (_aceMedHm isEqualType createHashMap && count _aceMedHm > 0) then {
        [_aceMedHm getOrDefault ["medicClass", 0], _aceMedHm getOrDefault ["medicalVehicle", false], _aceMedHm getOrDefault ["medicalFacility", false]]
    } else {
        if (_aceMedHm isEqualType []) then { _aceMedHm } else { [0, false, false] }
    };

    // aceRepair: {"repairVehicle": ..., "repairFacility": ...} → [repairVehicle, repairFacility]
    private _aceRepHm = _x getOrDefault ["aceRepair", createHashMap];
    private _aceRepair = if (_aceRepHm isEqualType createHashMap && count _aceRepHm > 0) then {
        [_aceRepHm getOrDefault ["repairVehicle", 0], _aceRepHm getOrDefault ["repairFacility", 0]]
    } else {
        if (_aceRepHm isEqualType []) then { _aceRepHm } else { [0, 0] }
    };

    [
        _x getOrDefault ["id", ""],
        _x getOrDefault ["type", ""],
        _x getOrDefault ["position", [0, 0, 0]],
        _x getOrDefault ["vectorDirUp", [[0, 1, 0], [0, 0, 1]]],
        _x getOrDefault ["damage", 0],
        _x getOrDefault ["fuel", 0],
        _turretWeapons,
        _turretMagazines,
        _pylonLoadout,
        _x getOrDefault ["logistics", [0, 0, 0]],
        _attached,
        _x getOrDefault ["rackChannels", []],
        _aceCargo,
        _inventory,
        _aceFortify,
        _aceMedical,
        _aceRepair,
        _x getOrDefault ["customName", ""]
    ]
};

private _objectFieldNames = [
    "id", "type", "position", "vectorDirUp", "damage", "fuel",
    "turretWeapons", "turretMagazines", "pylonLoadout", "logistics",
    "attached", "rackChannels", "aceCargo", "inventory",
    "aceFortify", "aceMedical", "aceRepair", "customName"
];

// Build lookup by ID for both sets
private _profileObjectMap = createHashMap;
{_profileObjectMap set [_x#IDX_OBJ_ID, _x]} forEach _profileObjects;

private _apiObjectMap = createHashMap;
{_apiObjectMap set [_x#IDX_OBJ_ID, _x]} forEach _apiObjects;

private _allObjectIds = keys _profileObjectMap + keys _apiObjectMap;
_allObjectIds = _allObjectIds arrayIntersect _allObjectIds;

private _objectMatches = 0;
private _objectMismatches = 0;
private _objectMissing = 0;

INFO_2("Objects: profile count=%1, api count=%2",count _profileObjects,count _apiObjects);

{
    private _objectId = _x;
    private _profileObject = _profileObjectMap getOrDefault [_objectId, []];
    private _apiObject = _apiObjectMap getOrDefault [_objectId, []];

    if (_profileObject isEqualTo []) then {
        _objectMissing = _objectMissing + 1;
        WARNING_1("Object %1: in API only, missing from profile",_objectId);
    } else {
        if (_apiObject isEqualTo []) then {
            _objectMissing = _objectMissing + 1;
            WARNING_1("Object %1: in profile only, missing from API",_objectId);
        } else {
            if ([_profileObject, _apiObject] call _isEqual) then {
                _objectMatches = _objectMatches + 1;
            } else {
                _objectMismatches = _objectMismatches + 1;
                // Log which fields differ
                for "_i" from 0 to (count _objectFieldNames - 1) do {
                    private _profileField = if (_i < count _profileObject) then {_profileObject#_i} else {nil};
                    private _apiField = if (_i < count _apiObject) then {_apiObject#_i} else {nil};
                    if !([_profileField, _apiField] call _isEqual) then {
                        WARNING_4("Object %1 field '%2': profile=%3, api=%4",_objectId,_objectFieldNames#_i,_profileField,_apiField);
                    };
                };
            };
        };
    };
} forEach _allObjectIds;

if (_objectMismatches == 0 && _objectMissing == 0) then {
    _successes = _successes + 1;
    INFO_1("Objects: MATCH (all %1 objects identical)",_objectMatches);
} else {
    _failures = _failures + 1;
    WARNING_3("Objects: MISMATCH — matches=%1, mismatches=%2, missing=%3",_objectMatches,_objectMismatches,_objectMissing);
};

// --- Players ---
private _apiPlayersRaw = _session getOrDefault ["players", createHashMap];
private _profilePlayers = _snapshot getOrDefault ["players", createHashMap];
private _profilePlayerUids = _snapshot getOrDefault ["playerUids", []];
private _allPlayerUids = +_profilePlayerUids;
{_allPlayerUids pushBackUnique _x} forEach (keys _apiPlayersRaw);

private _playerFieldNames = [
    "position", "vehicleState", "direction", "animation", "loadout",
    "damage", "aceMedical", "earplugs", "attachedItems", "radios", "diveState"
];

private _playerMatches = 0;
private _playerMismatches = 0;
private _playerMissing = 0;

INFO_2("Players: profile count=%1, api count=%2",count _profilePlayerUids,count _apiPlayersRaw);

{
    private _uid = _x;
    private _profilePlayer = _profilePlayers getOrDefault [_uid, []];

    private _apiPlayerRaw = _apiPlayersRaw getOrDefault [_uid, createHashMap];
    private _apiPlayer = if (count _apiPlayerRaw == 0) then {
        []
    } else {
        // vehicleState: {"vehicleId": ..., "role": ..., "index": ...} → [vehicleId, role, index]
        private _vsHm = _apiPlayerRaw getOrDefault ["vehicleState", createHashMap];
        private _vehicleState = if (_vsHm isEqualType createHashMap && count _vsHm > 0) then {
            [_vsHm getOrDefault ["vehicleId", ""], _vsHm getOrDefault ["role", ""], _vsHm getOrDefault ["index", -1]]
        } else {
            if (_vsHm isEqualType []) then { _vsHm } else { ["", "", -1] }
        };

        // loadout — convert hashmap back to setUnitLoadout positional array (same as loadRedeployData)
        private _convertWeaponSlotBack = {
            params ["_slot"];
            if (count _slot == 0) exitWith { [] };
            if !(_slot isEqualType createHashMap) exitWith { _slot };
            private _pm = _slot getOrDefault ["primaryMagazine", createHashMap];
            private _sm = _slot getOrDefault ["secondaryMagazine", createHashMap];
            [
                _slot getOrDefault ["weapon", ""],
                _slot getOrDefault ["muzzle", ""],
                _slot getOrDefault ["pointer", ""],
                _slot getOrDefault ["optic", ""],
                if (_pm isEqualType createHashMap && count _pm > 0) then { [_pm getOrDefault ["className", ""], _pm getOrDefault ["ammo", 0]] } else { [] },
                if (_sm isEqualType createHashMap && count _sm > 0) then { [_sm getOrDefault ["className", ""], _sm getOrDefault ["ammo", 0]] } else { [] },
                _slot getOrDefault ["bipod", ""]
            ]
        };

        private _convertContainerSlotBack = {
            params ["_slot"];
            if (count _slot == 0) exitWith { [] };
            if !(_slot isEqualType createHashMap) exitWith { _slot };
            [
                _slot getOrDefault ["className", ""],
                (_slot getOrDefault ["items", []]) apply {
                    if (_x isEqualType createHashMap) then {
                        private _base = [_x getOrDefault ["className", ""], _x getOrDefault ["count", 0]];
                        private _ammo = _x getOrDefault ["ammo", nil];
                        if (!isNil "_ammo") then { _base pushBack _ammo };
                        _base
                    } else { _x }
                }
            ]
        };

        private _convertLinkedItemsBack = {
            params ["_items"];
            if (count _items == 0) exitWith { ["","","","","",""] };
            if !(_items isEqualType createHashMap) exitWith { _items };
            [
                _items getOrDefault ["map", ""],
                _items getOrDefault ["gps", ""],
                _items getOrDefault ["radio", ""],
                _items getOrDefault ["compass", ""],
                _items getOrDefault ["watch", ""],
                _items getOrDefault ["nvg", ""]
            ]
        };

        private _loadoutHm = _apiPlayerRaw getOrDefault ["loadout", createHashMap];
        private _loadout = if (_loadoutHm isEqualType createHashMap && count _loadoutHm > 0) then {
            [
                [_loadoutHm getOrDefault ["primaryWeapon", createHashMap]] call _convertWeaponSlotBack,
                [_loadoutHm getOrDefault ["secondaryWeapon", createHashMap]] call _convertWeaponSlotBack,
                [_loadoutHm getOrDefault ["handgun", createHashMap]] call _convertWeaponSlotBack,
                [_loadoutHm getOrDefault ["uniform", createHashMap]] call _convertContainerSlotBack,
                [_loadoutHm getOrDefault ["vest", createHashMap]] call _convertContainerSlotBack,
                [_loadoutHm getOrDefault ["backpack", createHashMap]] call _convertContainerSlotBack,
                _loadoutHm getOrDefault ["headgear", ""],
                _loadoutHm getOrDefault ["facewear", ""],
                [_loadoutHm getOrDefault ["binoculars", createHashMap]] call _convertWeaponSlotBack,
                [_loadoutHm getOrDefault ["linkedItems", createHashMap]] call _convertLinkedItemsBack
            ]
        } else {
            if (_loadoutHm isEqualType []) then { _loadoutHm } else { [] }
        };

        // radios: [{"type": ..., "channel": ..., "volume": ..., "spatial": ..., "pttIndex": ...}] → [[type, channel, volume, spatial, pttIndex]]
        private _radios = (_apiPlayerRaw getOrDefault ["radios", []]) apply {
            if (_x isEqualType createHashMap) then {
                [_x getOrDefault ["type", ""], _x getOrDefault ["channel", 0], _x getOrDefault ["volume", 1], _x getOrDefault ["spatial", "CENTER"], _x getOrDefault ["pttIndex", 0]]
            } else { _x }
        };

        // diveState: {"isDiving": ...} → [isDiving]
        private _dsHm = _apiPlayerRaw getOrDefault ["diveState", createHashMap];
        private _diveState = if (_dsHm isEqualType createHashMap && count _dsHm > 0) then {
            [_dsHm getOrDefault ["isDiving", false]]
        } else {
            if (_dsHm isEqualType []) then { _dsHm } else { [false] }
        };

        [
            _apiPlayerRaw getOrDefault ["position", [0, 0, 0]],
            _vehicleState,
            _apiPlayerRaw getOrDefault ["direction", 0],
            _apiPlayerRaw getOrDefault ["animation", ""],
            _loadout,
            _apiPlayerRaw getOrDefault ["damage", 0],
            _apiPlayerRaw getOrDefault ["aceMedical", createHashMap],
            _apiPlayerRaw getOrDefault ["earplugs", false],
            _apiPlayerRaw getOrDefault ["attachedItems", []],
            _radios,
            _diveState
        ]
    };

    if (_profilePlayer isEqualTo [] && _apiPlayer isEqualTo []) then {
        // Both empty, skip
    } else {
        if (_profilePlayer isEqualTo []) then {
            _playerMissing = _playerMissing + 1;
            WARNING_1("Player %1: in API only, missing from profile",_uid);
        } else {
            if (_apiPlayer isEqualTo []) then {
                _playerMissing = _playerMissing + 1;
                WARNING_1("Player %1: in profile only, missing from API",_uid);
            } else {
                private _fieldMismatch = false;
                for "_i" from 0 to (count _playerFieldNames - 1) do {
                    private _profileField = if (_i < count _profilePlayer) then {_profilePlayer#_i} else {nil};
                    private _apiField = if (_i < count _apiPlayer) then {_apiPlayer#_i} else {nil};

                    // aceMedical: profile stores as JSON string, API returns as hashmap
                    // Parse profile string to hashmap so both sides compare as hashmaps
                    if (_playerFieldNames#_i == "aceMedical") then {
                        if (_profileField isEqualType "" && {_profileField != ""}) then {
                            _profileField = [_profileField, 2] call CBA_fnc_parseJSON;
                            if (isNil "_profileField") then { _profileField = createHashMap };
                        } else {
                            _profileField = createHashMap;
                        };
                        if !(_apiField isEqualType createHashMap) then {
                            _apiField = createHashMap;
                        };
                    };

                    if !([_profileField, _apiField] call _isEqual) then {
                        _fieldMismatch = true;
                        WARNING_4("Player %1 field '%2': profile=%3, api=%4",_uid,_playerFieldNames#_i,_profileField,_apiField);
                    };
                };

                if (_fieldMismatch) then {
                    _playerMismatches = _playerMismatches + 1;
                } else {
                    _playerMatches = _playerMatches + 1;
                };
            };
        };
    };
} forEach _allPlayerUids;

if (_playerMismatches == 0 && _playerMissing == 0) then {
    _successes = _successes + 1;
    INFO_1("Players: MATCH (all %1 players identical)",_playerMatches);
} else {
    _failures = _failures + 1;
    WARNING_3("Players: MISMATCH — matches=%1, mismatches=%2, missing=%3",_playerMatches,_playerMismatches,_playerMissing);
};

// --- Custom Data ---
private _apiCustomData = _session getOrDefault ["customData", createHashMap];
private _customDataKeys = keys _apiCustomData;
{
    _x params ["_id"];
    _customDataKeys pushBackUnique _id;
} forEach GVAR(serializers);

private _customMatches = 0;
private _customMismatches = 0;

{
    private _key = _x;
    private _profileValue = _snapshot getOrDefault [_key, []];
    private _apiValue = _apiCustomData getOrDefault [_key, []];
    if ([_profileValue, _apiValue] call _isEqual) then {
        _customMatches = _customMatches + 1;
    } else {
        _customMismatches = _customMismatches + 1;
        WARNING_3("Custom data '%1': MISMATCH — profile count=%2, api count=%3",_key,count _profileValue,count _apiValue);
    };
} forEach _customDataKeys;

if (_customMismatches == 0) then {
    _successes = _successes + 1;
    INFO_1("Custom data: MATCH (all %1 keys identical)",_customMatches);
} else {
    _failures = _failures + 1;
    WARNING_2("Custom data: MISMATCH — matches=%1, mismatches=%2",_customMatches,_customMismatches);
};

// --- Summary ---
INFO_2("=== API vs Profile Comparison Complete: %1 categories passed, %2 categories failed ===",_successes,_failures);
if (_failures == 0) then {
    INFO("API persistence proofing: ALL CATEGORIES MATCH");
} else {
    ERROR_1("API persistence proofing: %1 CATEGORIES FAILED — see warnings above for details",_failures);
};
