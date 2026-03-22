#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns active debug provider keys sorted by priority (highest first).

    Parameter(s):
        None

    Return Value:
        Sorted keys <ARRAY>

    Example:
        call uksf_zeus_fnc_debugGetSortedActiveKeys
*/

if (GVAR(debugSortedActiveKeysDirty)) then {
    private _activeKeys = keys GVAR(debugActiveToggles);
    _activeKeys = _activeKeys apply {
        private _provider = GVAR(debugProviders) getOrDefault [_x, createHashMap];
        private _priority = _provider getOrDefault ["menuPriority", 0];
        [_priority, _x]
    };
    _activeKeys sort false;
    GVAR(debugSortedActiveKeys) = _activeKeys apply {_x#1};
    GVAR(debugSortedActiveKeysDirty) = false;
};
GVAR(debugSortedActiveKeys)
