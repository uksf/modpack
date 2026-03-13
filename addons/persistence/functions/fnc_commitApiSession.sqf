#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Commits a parsed API session hashmap into GVAR(dataNamespace).
        Creates a fresh namespace and populates it with objects, players,
        deleted objects, markers, datetime, and custom data.

    Parameter(s):
        0: Session hashmap <HASHMAP>

    Return Value:
        None

    Example:
        [_session] call uksf_persistence_fnc_commitApiSession
*/
params ["_session"];

GVAR(dataNamespace) = call CBA_fnc_createNamespace;
GVAR(playerUids) = [];

// JSON encoding stringifies side types ("WEST", "EAST", etc.)
// Convert the string back to a side value on load
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

// Objects — convert from named fields back to indexed arrays
// Field names match those written by fnc_saveDataApi.sqf
// Array order matches IDX_OBJ_* constants from script_component.hpp (indices 0-17)
private _objects = _session getOrDefault ["objects", []];
private _objectArrays = _objects apply {
    private _fortifyData = +(_x getOrDefault ["aceFortify", [false, west]]);
    if (count _fortifyData > 1 && {_fortifyData#1 isEqualType ""}) then {
        _fortifyData set [1, [_fortifyData#1] call _parseSide];
    };

    [
        _x getOrDefault ["id", ""],
        _x getOrDefault ["type", ""],
        _x getOrDefault ["position", [0, 0, 0]],
        _x getOrDefault ["vectorDirUp", [[0, 1, 0], [0, 0, 1]]],
        _x getOrDefault ["damage", 0],
        _x getOrDefault ["fuel", 0],
        _x getOrDefault ["turretWeapons", []],
        _x getOrDefault ["turretMagazines", []],
        _x getOrDefault ["pylonLoadout", []],
        _x getOrDefault ["logistics", [0, 0, 0]],
        _x getOrDefault ["attached", []],
        _x getOrDefault ["rackChannels", []],
        _x getOrDefault ["aceCargo", []],
        _x getOrDefault ["inventory", [[], [], [], []]],
        _fortifyData,
        _x getOrDefault ["aceMedical", [0, false, false]],
        _x getOrDefault ["aceRepair", [0, 0]],
        _x getOrDefault ["customName", ""]
    ]
};
GVAR(dataNamespace) setVariable [QGVAR(objects), _objectArrays];

// Deleted objects
GVAR(dataNamespace) setVariable [QGVAR(deletedObjects), _session getOrDefault ["deletedObjects", []]];

// Date time
GVAR(dataNamespace) setVariable [QGVAR(dateTime), _session getOrDefault ["dateTime", date]];

// Markers
GVAR(dataNamespace) setVariable [QGVAR(mapMarkers), _session getOrDefault ["markers", []]];

// Players — convert from named fields back to indexed arrays
private _players = _session getOrDefault ["players", createHashMap];
{
    private _uid = _x;
    private _playerData = _y;
    // Convert aceMedical hashmap back to JSON string for profile format
    private _aceMedicalData = _playerData getOrDefault ["aceMedical", createHashMap];
    private _aceMedicalString = if (_aceMedicalData isEqualType createHashMap && {count _aceMedicalData > 0}) then {
        [_aceMedicalData] call CBA_fnc_encodeJSON
    } else {
        if (_aceMedicalData isEqualType "") then { _aceMedicalData } else { "" }
    };

    private _playerArray = [
        _playerData getOrDefault ["position", [0, 0, 0]],
        _playerData getOrDefault ["vehicleState", ["", "", -1]],
        _playerData getOrDefault ["direction", 0],
        _playerData getOrDefault ["animation", ""],
        _playerData getOrDefault ["loadout", []],
        _playerData getOrDefault ["damage", 0],
        _aceMedicalString,
        _playerData getOrDefault ["earplugs", false],
        _playerData getOrDefault ["attachedItems", []],
        _playerData getOrDefault ["radios", []],
        _playerData getOrDefault ["diveState", [false]]
    ];
    GVAR(dataNamespace) setVariable [_uid, _playerArray];
    GVAR(playerUids) pushBack _uid;
} forEach _players;

// Custom data — restore each serialiser's data
private _customData = _session getOrDefault ["customData", createHashMap];
{
    GVAR(dataNamespace) setVariable [_x, _y];
} forEach _customData;

INFO("API session committed to namespace");
