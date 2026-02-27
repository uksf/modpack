#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Debug map draw orchestrator. Called every frame while Zeus map is open.
        Delegates actual drawing to registered provider functions.

    Parameter(s):
        0: Map control <CONTROL>

    Return Value:
        None
*/
params ["_map"];

if (GVAR(debugKill)) exitWith {};

// Sort active toggles by provider priority for deterministic draw ordering
private _activeKeys = keys GVAR(debugActiveToggles);
_activeKeys sort true;
_activeKeys = _activeKeys apply {
    private _provider = GVAR(debugProviders) getOrDefault [_x, []];
    private _priority = if (_provider isEqualTo []) then {0} else {_provider#1};
    [_priority, _x]
};
_activeKeys sort false;
_activeKeys = _activeKeys apply {_x#1};

{
    private _providerKey = _x;
    private _provider = GVAR(debugProviders) getOrDefault [_providerKey, []];
    if (_provider isEqualTo []) then { continue };

    private _data = GVAR(debugData) getOrDefault [_providerKey, []];
    _provider params ["", "", "", "_fnc_serverGetter", "", "", "_fnc_drawMap"];
    private _clientOnly = _fnc_serverGetter isEqualTo {};
    if (!_clientOnly && {_data isEqualTo []}) then { continue };

    [_data, _map] call _fnc_drawMap;
} forEach _activeKeys;
