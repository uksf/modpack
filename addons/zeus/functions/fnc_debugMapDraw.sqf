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

    Example:
        [_map] call uksf_zeus_fnc_debugMapDraw
*/
params ["_map"];

if (GVAR(debugKill)) exitWith {};

private _activeKeys = call FUNC(debugGetSortedActiveKeys);

{
    private _providerKey = _x;
    private _drawData = GVAR(debugDraws) getOrDefault [_providerKey, []];
    if (_drawData isEqualTo []) then { continue };

    private _data = GVAR(debugData) getOrDefault [_providerKey, []];
    private _hasServerGetter = _providerKey in GVAR(debugServerGetters);
    if (_hasServerGetter && {_data isEqualTo []}) then { continue };

    _drawData params ["", "_fnc_drawMap"];

    [_data, _map] call _fnc_drawMap;
} forEach _activeKeys;
