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

private _activeKeys = keys GVAR(debugActiveToggles);
_activeKeys sort true;
_activeKeys = _activeKeys apply {
    private _action = GVAR(debugActions) getOrDefault [_x, []];
    private _priority = if (_action isEqualTo []) then {0} else {_action#1};
    [_priority, _x]
};
_activeKeys sort false;
_activeKeys apply {_x#1}
