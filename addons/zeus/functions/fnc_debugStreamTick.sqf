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
TRACE_2("debugStreamTick",count GVAR(debugStreamClients),count GVAR(debugServerGetters));

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
    private _serverGetterData = GVAR(debugServerGetters) getOrDefault [_x, []];
    if (_serverGetterData isEqualTo []) then { continue };
    _serverGetterData params ["_fnc_serverGetter", "_getterInterval"];

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

// Send to each client: changed keys, plus any key the client hasn't received yet
{
    _x params ["_player", "_keys"];

    private _playerUid = getPlayerUID _player;
    private _sentKeys = GVAR(debugLastSentKeys) getOrDefault [_playerUid, createHashMap];

    private _clientData = createHashMap;
    {
        private _data = GVAR(debugLastSentData) getOrDefault [_x, []];

        private _isNew = !(_sentKeys getOrDefault [_x, false]);
        private _isChanged = _changedKeys getOrDefault [_x, false];
        if (_isNew || _isChanged) then {
            _clientData set [_x, _data];
            _sentKeys set [_x, true];
        };
    } forEach _keys;

    GVAR(debugLastSentKeys) set [_playerUid, _sentKeys];

    if (count _clientData > 0) then {
        [QGVAR(debugStreamData), [_clientData], _player] call CBA_fnc_targetEvent;
    };
} forEach GVAR(debugStreamClients);
