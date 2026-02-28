#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggles a debug data stream for a requesting Zeus client.
        Called on server via CBA event.

    Parameter(s):
        0: Player <OBJECT> - the Zeus client
        1: Key <STRING> - debug key
        2: State <BOOLEAN> - true to enable, false to disable

    Return Value:
        None
*/
if (!isServer) exitWith {};

params ["_player", "_key", "_state"];
TRACE_3("debugStreamToggle",_player,_key,_state);

private _index = GVAR(debugStreamClients) findIf {(_x#0) isEqualTo _player};

if (_state) then {
    if (_index == -1) then {
        GVAR(debugStreamClients) pushBack [_player, [_key]];
    } else {
        private _clientEntry = GVAR(debugStreamClients) select _index;
        _clientEntry params ["", "_keys"];
        if !(_key in _keys) then {
            _keys pushBack _key;
        };
    };
} else {
    if (_index != -1) then {
        private _clientEntry = GVAR(debugStreamClients) select _index;
        _clientEntry params ["", "_keys"];
        _keys deleteAt (_keys find _key);
        private _playerUid = getPlayerUID _player;
        if (_keys isEqualTo []) then {
            GVAR(debugStreamClients) deleteAt _index;
            GVAR(debugLastSentKeys) deleteAt _playerUid;
        } else {
            private _sentKeys = GVAR(debugLastSentKeys) getOrDefault [_playerUid, createHashMap];
            _sentKeys deleteAt _key;
        };
    };
};

// Clean disconnected players
GVAR(debugStreamClients) = GVAR(debugStreamClients) select {!isNull (_x#0)};

// Start or stop the server PFH based on whether any clients need data
if (GVAR(debugStreamClients) isNotEqualTo [] && {GVAR(debugStreamPFH) == -1}) then {
    GVAR(debugStreamPFH) = [{
        call FUNC(debugStreamTick);
    }, 1, []] call CBA_fnc_addPerFrameHandler;
} else {
    if (GVAR(debugStreamClients) isEqualTo [] && {GVAR(debugStreamPFH) != -1}) then {
        [GVAR(debugStreamPFH)] call CBA_fnc_removePerFrameHandler;
        GVAR(debugStreamPFH) = -1;
    };
};

// Manage client data sources based on active provider dependencies
private _neededSources = createHashMap;
{
    {
        private _serverGetter = GVAR(debugServerGetters) getOrDefault [_x, []];
        if (_serverGetter isNotEqualTo []) then {
            _serverGetter params ["", "", "_clientDataKey"];
            if (_clientDataKey != "") then {
                _neededSources set [_clientDataKey, true];
            };
        };
    } forEach (_x#1);
} forEach GVAR(debugStreamClients);

{
    private _wasActive = GVAR(debugActiveClientSources) getOrDefault [_x, false];
    private _isNeeded = _neededSources getOrDefault [_x, false];
    if (_isNeeded && {!_wasActive}) then {
        GVAR(debugActiveClientSources) set [_x, true];
        [QGVAR(debugStartClientSource), [_x]] call CBA_fnc_globalEvent;
    };
    if (!_isNeeded && {_wasActive}) then {
        GVAR(debugActiveClientSources) deleteAt _x;
        [QGVAR(debugStopClientSource), [_x]] call CBA_fnc_globalEvent;
        GVAR(debugClientData) deleteAt _x;
    };
} forEach (keys GVAR(debugClientSources));
