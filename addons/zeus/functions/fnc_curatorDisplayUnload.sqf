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

(_display displayCtrl 50) ctrlRemoveEventHandler ["Draw", GVAR(visualiseMapDrawID)];
[GVAR(visualisePFH)] call CBA_fnc_removePerFrameHandler;

// Pause server data streams while Zeus is closed
{
    private _providerKeys = switch (_x) do {
        case "aicommander": { ["aicommander_ground", "aicommander_air"] };
        case "rebronetwork": { ["rebroconnections", "rebronetwork"] };
        default { [_x] };
    };
    {
        [QGVAR(visualiseStreamToggle), [player, _x, false]] call CBA_fnc_serverEvent;
    } forEach _providerKeys;
} forEach (keys GVAR(visualiseActiveToggles));

private _unconscious = player getVariable ["ACE_isUnconscious", false];
[!_unconscious, player] call ace_common_fnc_setVolume;
