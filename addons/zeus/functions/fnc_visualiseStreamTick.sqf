#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Server-side tick that collects visualisation data from registered providers
        and sends to requesting Zeus clients.

    Parameter(s):
        None

    Return Value:
        None
*/

// Clean disconnected players
GVAR(visualiseStreamClients) = GVAR(visualiseStreamClients) select {alive (_x#0)};

if (GVAR(visualiseStreamClients) isEqualTo []) exitWith {};
TRACE_2("visualiseStreamTick",count GVAR(visualiseStreamClients),count GVAR(visualiseProviders));

// Collect unique set of all requested keys
private _allRequestedKeys = [];
{
    {
        _allRequestedKeys pushBackUnique _x;
    } forEach (_x#1);
} forEach GVAR(visualiseStreamClients);

// Call each provider once and cache result
private _collectedData = createHashMap;
{
    private _getter = GVAR(visualiseProviders) getOrDefault [_x, {}];
    _collectedData set [_x, call _getter];
} forEach _allRequestedKeys;

// Send to each client only the keys they requested
{
    _x params ["_player", "_keys"];

    private _clientData = createHashMap;
    {
        private _data = _collectedData getOrDefault [_x, []];
        _clientData set [_x, _data];
    } forEach _keys;

    [QGVAR(visualiseStreamData), [_clientData], _player] call CBA_fnc_targetEvent;
} forEach GVAR(visualiseStreamClients);
