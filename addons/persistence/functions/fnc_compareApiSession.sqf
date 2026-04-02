#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Compares a parsed API session (hashmap format) against a profile snapshot.
        Converts profile positional arrays to hashmaps for comparison.
        Logs detailed per-category match/mismatch results.
        Uses type-aware comparison: == for numbers and strings,
        isEqualTo for booleans/sides, recursive for arrays and hashmaps.
        Does not modify any state.

    Parameter(s):
        0: Session hashmap <HASHMAP> — the parsed API session (hashmap format)
        1: Profile snapshot <HASHMAP> — snapshot taken at load time

    Return Value:
        None

    Example:
        [_session, _snapshot] call uksf_persistence_fnc_compareApiSession
*/
params ["_session", "_snapshot"];

INFO("=== API vs Profile Comparison Start ===");

// Type-aware comparison that handles float precision differences from
// JSON round-trip. isEqualTo is binary-exact on floats, so two values
// that display as 3.1957 can fail if their binary representations
// differ after encoding/decoding. == handles this for numbers and strings.
// Arrays and hashmaps are compared recursively.
private _isEqual = {
    params ["_a", "_b"];
    if (isNil "_a" && isNil "_b") exitWith { true };
    if (isNil "_a" || isNil "_b") exitWith { false };
    // Side type (e.g. WEST) becomes string "WEST" after JSON round-trip — coerce for comparison
    if (_a isEqualType west && _b isEqualType "") exitWith { str _a == _b };
    if (_a isEqualType "" && _b isEqualType west) exitWith { _a == str _b };
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
        private _keysA = keys _a;
        private _keysB = keys _b;
        if (count _keysA != count _keysB) exitWith { false };
        private _match = true;
        {
            if !([_a get _x, _b getOrDefault [_x, nil]] call _isEqual) exitWith { _match = false };
        } forEach _keysA;
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
    WARNING_2("Deleted objects: MISMATCH — profile count=%1, api count=%2",count _profileDeleted,count _apiDeleted);
};

// --- Map Markers ---
private _profileMarkers = _snapshot getOrDefault ["mapMarkers", []];
private _apiMarkers = _session getOrDefault ["mapMarkers", []];
if ([_profileMarkers, _apiMarkers] call _isEqual) then {
    _successes = _successes + 1;
    INFO_1("Map markers: MATCH (count=%1)",count _profileMarkers);
} else {
    _failures = _failures + 1;
    WARNING_2("Map markers: MISMATCH — profile count=%1, api count=%2",count _profileMarkers,count _apiMarkers);
};

// --- Objects ---
// Convert profile positional arrays to hashmaps for comparison
private _objectKeys = ["id", "type", "position", "vectorDirUp", "damage", "fuel", "turretWeapons", "turretMagazines", "pylonLoadout", "logistics", "attached", "rackChannels", "aceCargo", "inventory", "aceFortify", "aceMedical", "aceRepair", "customName"];
private _profileObjects = _snapshot getOrDefault ["objects", []];
private _apiObjects = _session getOrDefault ["objects", []];

private _profileObjectMap = createHashMap;
{
    _profileObjectMap set [_x#IDX_OBJ_ID, _x];
} forEach _profileObjects;

private _apiObjectMap = createHashMap;
{
    _apiObjectMap set [_x getOrDefault ["id", ""], _x];
} forEach _apiObjects;

private _allObjectIds = keys _profileObjectMap + keys _apiObjectMap;
_allObjectIds = _allObjectIds arrayIntersect _allObjectIds;

private _objectMatches = 0;
private _objectMismatches = 0;
private _objectMissing = 0;

INFO_2("Objects: profile count=%1, api count=%2",count _profileObjects,count _apiObjects);

{
    private _objectId = _x;
    private _profileObject = _profileObjectMap getOrDefault [_objectId, []];
    private _apiObject = _apiObjectMap getOrDefault [_objectId, createHashMap];

    if (_profileObject isEqualTo []) then {
        _objectMissing = _objectMissing + 1;
        WARNING_1("Object %1: in API only, missing from profile",_objectId);
    } else {
        if (_apiObject isEqualTo createHashMap) then {
            _objectMissing = _objectMissing + 1;
            WARNING_1("Object %1: in profile only, missing from API",_objectId);
        } else {
            // Normalise profile turretMagazines: magazinesAllTurrets returns 5 elements
            // per entry but only the first 3 (className, turretPath, ammoCount) are meaningful
            private _profileTurretMags = if (IDX_OBJ_TURRETMAGS < count _profileObject) then {
                (_profileObject#IDX_OBJ_TURRETMAGS) apply {_x select [0, 3]}
            } else {
                []
            };

            // Compare per-field: convert profile positional to keyed lookup
            private _fieldMismatch = false;
            {
                private _key = _x;
                private _profileField = if (_key == "turretMagazines") then {
                    _profileTurretMags
                } else {
                    if (_forEachIndex < count _profileObject) then {_profileObject#_forEachIndex} else {nil}
                };
                private _apiField = _apiObject getOrDefault [_key, nil];
                if !([_profileField, _apiField] call _isEqual) then {
                    _fieldMismatch = true;
                    WARNING_4("Object %1 field '%2': profile=%3, api=%4",_objectId,_key,_profileField,_apiField);
                };
            } forEach _objectKeys;

            if (_fieldMismatch) then {
                _objectMismatches = _objectMismatches + 1;
            } else {
                _objectMatches = _objectMatches + 1;
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
private _playerKeys = ["position", "vehicleState", "direction", "animation", "loadout", "damage", "aceMedical", "earplugs", "attachedItems", "radios", "diveState"];
private _profilePlayers = _snapshot getOrDefault ["players", createHashMap];
private _profilePlayerUids = _snapshot getOrDefault ["playerUids", []];

private _apiPlayersHashmap = _session getOrDefault ["players", createHashMap];
private _apiPlayerUids = keys _apiPlayersHashmap;

private _allPlayerUids = +_profilePlayerUids;
{_allPlayerUids pushBackUnique _x} forEach _apiPlayerUids;

private _playerMatches = 0;
private _playerMismatches = 0;
private _playerMissing = 0;

INFO_2("Players: profile count=%1, api count=%2",count _profilePlayerUids,count _apiPlayerUids);

{
    private _uid = _x;
    private _profilePlayer = _profilePlayers getOrDefault [_uid, []];
    private _apiPlayer = _apiPlayersHashmap getOrDefault [_uid, createHashMap];

    if (_profilePlayer isEqualTo [] && _apiPlayer isEqualTo createHashMap) then {
        // Both empty, skip
    } else {
        if (_profilePlayer isEqualTo []) then {
            _playerMissing = _playerMissing + 1;
            WARNING_1("Player %1: in API only, missing from profile",_uid);
        } else {
            if (_apiPlayer isEqualTo createHashMap) then {
                _playerMissing = _playerMissing + 1;
                WARNING_1("Player %1: in profile only, missing from API",_uid);
            } else {
                private _fieldMismatch = false;
                {
                    private _key = _x;
                    private _profileField = if (_forEachIndex < count _profilePlayer) then {_profilePlayer#_forEachIndex} else {nil};
                    private _apiField = _apiPlayer getOrDefault [_key, nil];
                    if !([_profileField, _apiField] call _isEqual) then {
                        _fieldMismatch = true;
                        WARNING_4("Player %1 field '%2': profile=%3, api=%4",_uid,_key,_profileField,_apiField);
                    };
                } forEach _playerKeys;

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
private _knownKeys = ["objects", "deletedObjects", "dateTime", "mapMarkers", "players"];
private _customDataKeys = (keys _session) select {!(_x in _knownKeys)};
{
    _x params ["_id"];
    _customDataKeys pushBackUnique _id;
} forEach GVAR(serializers);

private _customMatches = 0;
private _customMismatches = 0;

{
    private _key = _x;
    private _profileValue = _snapshot getOrDefault [_key, []];
    private _apiValue = _session getOrDefault [_key, []];
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

INFO_2("=== API vs Profile Comparison Complete: %1 categories passed, %2 categories failed ===",_successes,_failures);
if (_failures == 0) then {
    INFO("API persistence proofing: ALL CATEGORIES MATCH");
} else {
    ERROR_1("API persistence proofing: %1 CATEGORIES FAILED — see warnings above for details",_failures);
};
