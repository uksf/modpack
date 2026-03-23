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
    private _provider = GVAR(debugProviders) get _providerKey;
    if (isNil "_provider") then { continue };
    private _fnc_drawMap = _provider get "drawMap";
    if (isNil "_fnc_drawMap") then { continue };

    private _data = GVAR(debugData) getOrDefault [_providerKey, []];
    if ("serverGetter" in _provider && {_data isEqualTo []}) then { continue };

    [_data, _map] call _fnc_drawMap;
} forEach _activeKeys;
