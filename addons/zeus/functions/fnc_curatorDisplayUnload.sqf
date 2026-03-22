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
    if (_x in GVAR(debugServerGetters)) then {
        [QGVAR(debugStreamToggle), [player, _x, false]] call CBA_fnc_serverEvent;
    };
} forEach (keys GVAR(debugActiveToggles));

// Remove auto-managed providers (not user-toggled)
GVAR(debugActiveToggles) deleteAt QGVAR(fps);
GVAR(debugData) deleteAt QGVAR(fps);
GVAR(debugActiveToggles) deleteAt QGVAR(unconscious);
GVAR(debugData) deleteAt QGVAR(unconscious);

private _unconscious = player getVariable ["ACE_isUnconscious", false];
[!_unconscious, player] call ace_common_fnc_setVolume;
