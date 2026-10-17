#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Saves persistence data to the API via the unified SQF event wire.
        Builds a hashmap-based session and ships it as the `data` payload of a
        persistence_save event — extension forwards the SQF bytes verbatim, API
        parses with SqfNotationParser and converts to DomainPersistenceSession.

        Bypasses CBA_fnc_encodeJSON entirely on the large session payload — at
        ~500 objects + 40 players, encodeJSON took ~43s; this path takes ~20ms.

    Parameter(s):
        0: Partial save <BOOL> (default: false)

    Return Value:
        Delivery sequence number <NUMBER>

    Example:
        [false] call uksf_persistence_fnc_saveDataApi
*/
params [["_partial", false, [false]]];

if (!GVAR(dataSaved)) exitWith {0};

private _objects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
private _objectHashmaps = _objects apply {
    private _object = _x;
    private _aceFortify = _object#IDX_OBJ_ACEFORTIFY;
    private _aceFortifySide = _aceFortify param [1, west];
    if (_aceFortifySide isEqualType west) then {
        _aceFortify = [_aceFortify param [0, false], toLower str _aceFortifySide];
    };
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
        ["aceFortify",      _aceFortify],
        ["aceMedical",      _object#IDX_OBJ_ACEMEDICAL],
        ["aceRepair",       _object#IDX_OBJ_ACEREPAIR],
        ["customName",      _object#IDX_OBJ_CUSTOMNAME]
    ]
};

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

private _session = createHashMapFromArray [
    ["dateTime",       GVAR(dataNamespace) getVariable [QGVAR(dateTime), []]],
    ["deletedObjects", GVAR(dataNamespace) getVariable [QGVAR(deletedObjects), []]],
    ["mapMarkers",     GVAR(dataNamespace) getVariable [QGVAR(mapMarkers), []]],
    ["objects",        _objectHashmaps],
    ["players",        _playersHashmap]
];

{
    _x params ["_id"];
    private _data = GVAR(dataNamespace) getVariable [_id, []];
    _session set [_id, _data];
} forEach GVAR(serializers);

private _eventData = createHashMapFromArray [
    ["key",       GVAR(key)],
    ["sessionId", EGVAR(api,sessionId)],
    ["data",      _session],
    ["partial",   _partial]
];

INFO_2("API persistence save: %1 objects, %2 players",count _objectHashmaps,count _playersHashmap);
private _sendStart = diag_tickTime;
private _seq = ["persistence_save", _eventData, 6] call EFUNC(api,sendEvent);
INFO_1("API persistence save sent in %1 ms",round ((diag_tickTime - _sendStart) * 1000));
_seq
