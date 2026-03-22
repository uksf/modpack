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

    Example:
        [_display] call uksf_zeus_fnc_curatorDisplayUnload
*/
params ["_display"];

(_display displayCtrl 50) ctrlRemoveEventHandler ["Draw", GVAR(debugMapDrawID)];
[GVAR(debugPFH)] call CBA_fnc_removePerFrameHandler;

// Pause server data streams while Zeus is closed
{
    private _provider = GVAR(debugProviders) getOrDefault [_x, createHashMap];
    if ("serverGetter" in _provider) then {
        [QGVAR(debugStreamToggle), [player, _x, false]] call CBA_fnc_serverEvent;
    };
} forEach (keys GVAR(debugActiveToggles));

// Remove auto-managed providers (not user-toggled)
{
    GVAR(debugActiveToggles) deleteAt _x;
    GVAR(debugData) deleteAt _x;
} forEach GVAR(debugAlwaysActiveProviders);
GVAR(debugSortedActiveKeysDirty) = true;

private _unconscious = player getVariable ["ACE_isUnconscious", false];
[!_unconscious, player] call ace_common_fnc_setVolume;
