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

    Example:
        [_player, _key, _state] call uksf_zeus_fnc_debugStreamToggle
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
        if (_keys isEqualTo []) then {
            GVAR(debugStreamClients) deleteAt _index;
        };
    };
};

// Seed initial data immediately so the client doesn't wait for the next tick
if (_state) then {
    private _provider = GVAR(debugProviders) getOrDefault [_key, createHashMap];
    private _fnc_serverGetter = _provider getOrDefault ["serverGetter", {}];
    if (_fnc_serverGetter isNotEqualTo {}) then {
        private _initialData = call _fnc_serverGetter;
        if (_initialData isNotEqualTo []) then {
            GVAR(debugLastSentData) set [_key, _initialData];
            GVAR(debugLastGetterRun) set [_key, CBA_missionTime];
            [QGVAR(debugStreamData), [createHashMapFromArray [[_key, _initialData]]], _player] call CBA_fnc_targetEvent;
        };
    };
};

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

call FUNC(debugManageClientSources);
