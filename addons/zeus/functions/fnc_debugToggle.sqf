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

private _provider = GVAR(debugProviders) getOrDefault [_key, []];
if (_provider isNotEqualTo []) then {
    _provider params ["", "", "", "_fnc_serverGetter"];
    if (_fnc_serverGetter isNotEqualTo {}) then {
        [QGVAR(debugStreamToggle), [player, _key, _newState]] call CBA_fnc_serverEvent;
    };
};
