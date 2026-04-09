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

    Example:
        [_idPFH] call uksf_zeus_fnc_debugStreamTick
*/

params ["", "_idPFH"];

if (GVAR(debugKill)) exitWith {};

// Clean disconnected clients
GVAR(debugStreamClients) = GVAR(debugStreamClients) select {!isNull (_x#0)};

if (GVAR(debugStreamClients) isEqualTo []) exitWith {};

// Clean stale client data
{
    private _sourceData = GVAR(debugClientData) getOrDefault [_x, createHashMap];
    private _staleKeys = [];
    {
        private _entry = _sourceData get _x;
        _entry params ["", "", "_timestamp"];
        if (CBA_missionTime - _timestamp > 3) then { _staleKeys pushBack _x };
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

// Call each provider's getter only if its interval has elapsed
private _now = CBA_missionTime;
private _changedKeys = createHashMap;
{
    private _provider = GVAR(debugProviders) getOrDefault [_x, createHashMap];
    private _fnc_serverGetter = _provider getOrDefault ["serverGetter", {}];
    if (_fnc_serverGetter isEqualTo {}) then { continue };
    private _getterInterval = _provider getOrDefault ["getterInterval", 5];

    private _lastRun = GVAR(debugLastGetterRun) getOrDefault [_x, -_getterInterval];
    if (_now - _lastRun >= _getterInterval) then {
        private _newData = call _fnc_serverGetter;
        private _previousData = GVAR(debugLastSentData) getOrDefault [_x, []];
        if (_newData isNotEqualTo _previousData) then {
            GVAR(debugLastSentData) set [_x, _newData];
            _changedKeys set [_x, true];
        };
        GVAR(debugLastGetterRun) set [_x, _now];
    };
} forEach _allRequestedKeys;

// Send changed data to each subscribed client
{
    _x params ["_player", "_keys"];

    private _clientData = createHashMap;
    {
        if (_changedKeys getOrDefault [_x, false]) then {
            _clientData set [_x, GVAR(debugLastSentData) getOrDefault [_x, []]];
        };
    } forEach _keys;

    if (count _clientData > 0) then {
        [QGVAR(debugStreamData), [_clientData], _player] call CBA_fnc_targetEvent;
    };
} forEach GVAR(debugStreamClients);
