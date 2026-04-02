#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggles a debug provider on or off. Updates local state and notifies server.

    Parameter(s):
        0: Key <STRING> - provider key to toggle

    Return Value:
        None

    Example:
        [_key] call uksf_zeus_fnc_debugToggle
*/
params ["_key"];
TRACE_1("debugToggle",_key);

private _newState = !(GVAR(debugActiveToggles) getOrDefault [_key, false]);
if (_newState) then {
    GVAR(debugActiveToggles) set [_key, true];
} else {
    GVAR(debugActiveToggles) deleteAt _key;
    GVAR(debugData) deleteAt _key;
};

GVAR(debugSortedActiveKeysDirty) = true;

private _provider = GVAR(debugProviders) getOrDefault [_key, createHashMap];
if ("serverGetter" in _provider) then {
    [QGVAR(debugStreamToggle), [player, _key, _newState]] call CBA_fnc_serverEvent;
};
