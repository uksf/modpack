#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Saves persistence data to the API via the extension.
        Builds a hashmap-based session with keyed objects and players,
        encodes as JSON, and sends as a single event.
        The C# API handles transformation to structured models for MongoDB.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_persistence_fnc_saveDataApi
*/

if (!GVAR(dataSaved)) exitWith {};

// Build object hashmaps from positional arrays in the namespace
private _objects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
private _objectHashmaps = _objects apply {
    private _object = _x;
    createHashMapFromArray [
        ["id",              _object#IDX_OBJ_ID],
        ["type",            _object#IDX_OBJ_TYPE],
        ["position",        _object#IDX_OBJ_POSITION],
        ["vectorDirUp",     _object#IDX_OBJ_VECTORDIRUP],
        ["damage",          _object#IDX_OBJ_DAMAGE],
        ["fuel",            _object#IDX_OBJ_FUEL],
        ["turretWeapons",   _object#IDX_OBJ_TURRETWEAPONS],
        ["turretMagazines", _object#IDX_OBJ_TURRETMAGS],
        ["pylonLoadout",    _object#IDX_OBJ_PYLONLOADOUT],
        ["logistics",       _object#IDX_OBJ_LOGISTICS],
        ["attached",        _object#IDX_OBJ_ATTACHED],
        ["rackChannels",    _object#IDX_OBJ_RACKCHANNELS],
        ["aceCargo",        _object#IDX_OBJ_ACECARGO],
        ["inventory",       _object#IDX_OBJ_INVENTORY],
        ["aceFortify",      _object#IDX_OBJ_ACEFORTIFY],
        ["aceMedical",      _object#IDX_OBJ_ACEMEDICAL],
        ["aceRepair",       _object#IDX_OBJ_ACEREPAIR],
        ["customName",      _object#IDX_OBJ_CUSTOMNAME]
    ]
};

// Build player hashmaps from positional arrays in the namespace
private _playersHashmap = createHashMap;
{
    private _playerData = GVAR(dataNamespace) getVariable [_x, []];
    if (count _playerData > 0) then {
        _playersHashmap set [_x, createHashMapFromArray [
            ["position",      _playerData#0],
            ["vehicleState",  _playerData#1],
            ["direction",     _playerData#2],
            ["animation",     _playerData#3],
            ["loadout",       _playerData#4],
            ["damage",        _playerData#5],
            ["aceMedical",    _playerData#6],
            ["earplugs",      _playerData#7],
            ["attachedItems", _playerData#8],
            ["radios",        _playerData#9],
            ["diveState",     if (count _playerData > 10) then {_playerData#10} else {[false]}]
        ]];
    };
} forEach GVAR(playerUids);

// Build the session hashmap
private _session = createHashMapFromArray [
    ["dateTime",       GVAR(dataNamespace) getVariable [QGVAR(dateTime), []]],
    ["deletedObjects", GVAR(dataNamespace) getVariable [QGVAR(deletedObjects), []]],
    ["mapMarkers",     GVAR(dataNamespace) getVariable [QGVAR(mapMarkers), []]],
    ["objects",        _objectHashmaps],
    ["players",        _playersHashmap]
];

// Add custom serializer data at root level
{
    _x params ["_id"];
    private _data = GVAR(dataNamespace) getVariable [_id, []];
    _session set [_id, _data];
} forEach GVAR(serializers);

private _json = [_session] call CBA_fnc_encodeJSON;
INFO_1("API persistence save: %1 characters",count _json);

["persistence_save", createHashMapFromArray [
    ["key",       GVAR(key)],
    ["sessionId", EGVAR(api,sessionId)],
    ["data",      _json]
]] call EFUNC(api,sendEvent);
