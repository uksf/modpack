#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Server-side tick that collects debug data from registered providers
        and sends to requesting Zeus clients.

    Parameter(s):
        None

    Return Value:
        None
*/

params ["", "_idPFH"];

if (GVAR(debugKill)) exitWith {};

// Clean disconnected clients
GVAR(debugStreamClients) = GVAR(debugStreamClients) select {!isNull (_x#0)};

if (GVAR(debugStreamClients) isEqualTo []) exitWith {};

// Clean stale client data (older than 10s)
{
    private _sourceData = GVAR(debugClientData) getOrDefault [_x, createHashMap];
    private _staleKeys = [];
    {
        private _entry = _sourceData get _x;
        _entry params ["", "", "_timestamp"];
        if (CBA_missionTime - _timestamp > 10) then { _staleKeys pushBack _x };
    } forEach keys _sourceData;
    { _sourceData deleteAt _x } forEach _staleKeys;
} forEach keys GVAR(debugClientData);
TRACE_2("debugStreamTick",count GVAR(debugStreamClients),count GVAR(debugProviders));

// Collect unique set of all requested keys
private _allRequestedKeys = [];
{
    {
        _allRequestedKeys pushBackUnique _x;
    } forEach (_x#1);
} forEach GVAR(debugStreamClients);

// Call each provider once and cache result
private _collectedData = createHashMap;
{
    private _providerData = GVAR(debugProviders) getOrDefault [_x, []];
    if (_providerData isEqualTo []) then { continue };
    _providerData params ["", "", "", "_fnc_serverGetter"];
    _collectedData set [_x, call _fnc_serverGetter];
} forEach _allRequestedKeys;

// Send to each client only the keys they requested
{
    _x params ["_player", "_keys"];

    private _clientData = createHashMap;
    {
        private _data = _collectedData getOrDefault [_x, []];
        if (_data isNotEqualTo []) then {
            _clientData set [_x, _data];
        };
    } forEach _keys;

    if (count _clientData > 0) then {
        [QGVAR(debugStreamData), [_clientData], _player] call CBA_fnc_targetEvent;
    };
} forEach GVAR(debugStreamClients);
