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

(_display displayCtrl 50) ctrlRemoveEventHandler ["Draw", GVAR(curatorViewMapID)];
[GVAR(curatorViewPFHID)] call CBA_fnc_removePerFrameHandler;

GVAR(showVirtualised) = false;
[QGVAR(toggleDataStreamForClient), [player, GVAR(showVirtualised)]] call CBA_fnc_serverEvent;
