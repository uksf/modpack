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

private _allObjects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
private _deletedObjects = GVAR(dataNamespace) getVariable [QGVAR(deletedObjects), []];
private _dateTime = GVAR(dataNamespace) getVariable [QGVAR(dateTime), date];
private _markers = GVAR(dataNamespace) getVariable [QGVAR(mapMarkers), []];

// Build objects array with named fields
private _objects = _allObjects apply {
    createHashMapFromArray [
        ["id", _x#IDX_OBJ_ID],
        ["type", _x#IDX_OBJ_TYPE],
        ["position", _x#IDX_OBJ_POSITION],
        ["vectorDirUp", _x#IDX_OBJ_VECTORDIRUP],
        ["damage", _x#IDX_OBJ_DAMAGE],
        ["fuel", _x#IDX_OBJ_FUEL],
        ["turretWeapons", _x#IDX_OBJ_TURRETWEAPONS],
        ["turretMagazines", _x#IDX_OBJ_TURRETMAGS],
        ["pylonLoadout", _x#IDX_OBJ_PYLONLOADOUT],
        ["logistics", _x#IDX_OBJ_LOGISTICS],
        ["attached", _x#IDX_OBJ_ATTACHED],
        ["rackChannels", _x#IDX_OBJ_RACKCHANNELS],
        ["aceCargo", _x#IDX_OBJ_ACECARGO],
        ["inventory", _x#IDX_OBJ_INVENTORY],
        ["aceFortify", _x#IDX_OBJ_ACEFORTIFY],
        ["aceMedical", _x#IDX_OBJ_ACEMEDICAL],
        ["aceRepair", _x#IDX_OBJ_ACEREPAIR],
        ["customName", _x#IDX_OBJ_CUSTOMNAME]
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

        _players set [_x, createHashMapFromArray [
            ["position", _playerData#0],
            ["vehicleState", _playerData#1],
            ["direction", _playerData#2],
            ["animation", _playerData#3],
            ["loadout", _playerData#4],
            ["damage", _playerData#5],
            ["aceMedical", _aceMedical],
            ["earplugs", _playerData#7],
            ["attachedItems", _playerData#8],
            ["radios", _playerData#9],
            ["diveState", _playerData#10]
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
    ["objects", _objects],
    ["deletedObjects", _deletedObjects],
    ["players", _players],
    ["markers", _markers],
    ["dateTime", _dateTime],
    ["customData", _customData]
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
private _saveId = format ["%1_%2", GVAR(key), diag_tickTime];

for "_i" from 0 to (_totalChunks - 1) do {
    private _start = _i * _chunkSize;
    private _chunk = _json select [_start, _chunkSize];

    ["persistence_save", createHashMapFromArray [
        ["id", _saveId],
        ["key", GVAR(key)],
        ["index", _i],
        ["total", _totalChunks],
        ["data", _chunk]
    ]] call EFUNC(api,sendEvent);
};

LOG_1("API persistence save: sent %1 chunks",_totalChunks);
