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
*/

private _activeKeys = keys GVAR(debugActiveToggles);
_activeKeys sort true;
_activeKeys = _activeKeys apply {
    private _provider = GVAR(debugProviders) getOrDefault [_x, []];
    private _priority = if (_provider isEqualTo []) then {0} else {_provider#1};
    [_priority, _x]
};
_activeKeys sort false;
_activeKeys apply {_x#1}
