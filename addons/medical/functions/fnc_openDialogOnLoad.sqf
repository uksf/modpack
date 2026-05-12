#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Dialog onLoad handler. Applies default tab visibility and starts PFHs.

    Parameter(s):
        Display arg from onLoad (unused here, ACE_player is the implicit target)

    Return Value:
        None

    Example:
        Called automatically via dialog onLoad
*/

private _initialTab = GVAR(currentTab);

if (_initialTab == "spectator" && {!GVAR(showSpectator)}) then {
    _initialTab = if (GVAR(showHealth)) then { "health" } else { "settings" };
};
if (_initialTab == "health" && {!GVAR(showHealth)}) then {
    _initialTab = if (GVAR(showSpectator)) then { "spectator" } else { "settings" };
};

[_initialTab] call FUNC(switchTab);

// viewMode default already set in fnc_openDialog from viewModeDefault setting.
// Per-tick ctrlShow gates in fnc_vitalsUpdate apply the visibility from GVAR(viewMode).

GVAR(activeVitalsPFH) = [FUNC(vitalsUpdate), 1, []] call CBA_fnc_addPerFrameHandler;
GVAR(activeSpectatorPFH) = [FUNC(spectatorUpdate), 0.5, []] call CBA_fnc_addPerFrameHandler;
