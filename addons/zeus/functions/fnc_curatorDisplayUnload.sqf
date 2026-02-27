#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Zeus display unload

    Parameter(s):
        0: Display <DISPLAY>

    Return Value:
        None
*/
params ["_display"];

(_display displayCtrl 50) ctrlRemoveEventHandler ["Draw", GVAR(debugMapDrawID)];
[GVAR(debugPFH)] call CBA_fnc_removePerFrameHandler;

// Pause server data streams while Zeus is closed
{
    private _provider = GVAR(debugProviders) getOrDefault [_x, []];
    if (_provider isNotEqualTo []) then {
        _provider params ["", "", "", "_fnc_serverGetter"];
        if (_fnc_serverGetter isNotEqualTo {}) then {
            [QGVAR(debugStreamToggle), [player, _x, false]] call CBA_fnc_serverEvent;
        };
    };
} forEach (keys GVAR(debugActiveToggles));

private _unconscious = player getVariable ["ACE_isUnconscious", false];
[!_unconscious, player] call ace_common_fnc_setVolume;
