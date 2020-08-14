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

(_display displayCtrl 50) ctrlRemoveEventHandler ["Draw", GVAR(curatorUnconciousMapID)];
[GVAR(curatorUnconciousID)] call CBA_fnc_removePerFrameHandler;

private _unconscious = player getVariable ["ACE_isUnconscious", false];
[!_unconscious, player] call ace_common_fnc_setVolume;
