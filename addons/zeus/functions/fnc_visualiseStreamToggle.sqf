#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggles a visualisation data stream for a requesting Zeus client.
        Called on server via CBA event.

    Parameter(s):
        0: Player <OBJECT> - the Zeus client
        1: Key <STRING> - visualisation key
        2: State <BOOLEAN> - true to enable, false to disable

    Return Value:
        None
*/
if (!isServer) exitWith {};

params ["_player", "_key", "_state"];
TRACE_3("visualiseStreamToggle",_player,_key,_state);

private _index = GVAR(visualiseStreamClients) findIf {(_x#0) isEqualTo _player};

if (_state) then {
    if (_index == -1) then {
        GVAR(visualiseStreamClients) pushBack [_player, [_key]];
    } else {
        private _keys = (GVAR(visualiseStreamClients)#_index)#1;
        if !(_key in _keys) then {
            _keys pushBack _key;
        };
    };
} else {
    if (_index != -1) then {
        private _keys = (GVAR(visualiseStreamClients)#_index)#1;
        _keys deleteAt (_keys find _key);
        if (_keys isEqualTo []) then {
            GVAR(visualiseStreamClients) deleteAt _index;
        };
    };
};

// Clean disconnected players
GVAR(visualiseStreamClients) = GVAR(visualiseStreamClients) select {alive (_x#0)};

// Start or stop the server PFH based on whether any clients need data
if (GVAR(visualiseStreamClients) isNotEqualTo [] && {GVAR(visualiseStreamPFH) == -1}) then {
    GVAR(visualiseStreamPFH) = [{
        call FUNC(visualiseStreamTick);
    }, 3, []] call CBA_fnc_addPerFrameHandler;
} else {
    if (GVAR(visualiseStreamClients) isEqualTo [] && {GVAR(visualiseStreamPFH) != -1}) then {
        [GVAR(visualiseStreamPFH)] call CBA_fnc_removePerFrameHandler;
        GVAR(visualiseStreamPFH) = -1;
    };
};

// Notify clients to start/stop rebro reporting
if (_key in ["rebroconnections", "rebronetwork"]) then {
    private _anyRebroActive = false;
    {
        if ("rebroconnections" in (_x#1) || {"rebronetwork" in (_x#1)}) exitWith {
            _anyRebroActive = true;
        };
    } forEach GVAR(visualiseStreamClients);

    if (_anyRebroActive) then {
        {[QEGVAR(radios,visualiseStartReporting), [], _x] call CBA_fnc_targetEvent} forEach ALL_PLAYERS;
    } else {
        {[QEGVAR(radios,visualiseStopReporting), [], _x] call CBA_fnc_targetEvent} forEach ALL_PLAYERS;
        GVAR(visualiseRebroReports) = createHashMap;
    };
};
