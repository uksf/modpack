#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Manages client data sources based on active provider dependencies.
        Starts sources needed by subscribed clients, stops sources no longer needed.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_zeus_fnc_debugManageClientSources
*/
if (!isServer) exitWith {};

private _neededSources = createHashMap;
{
    {
        private _provider = GVAR(debugProviders) getOrDefault [_x, createHashMap];
        private _clientDataKey = _provider getOrDefault ["clientDataKey", ""];
        if (_clientDataKey != "") then {
            _neededSources set [_clientDataKey, true];
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
