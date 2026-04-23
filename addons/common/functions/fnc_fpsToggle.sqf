#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggles the FPS hint display for server and headless clients.
        When enabled, the client polls the server every second and renders
        the current FPS values via hintSilent.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_common_fnc_fpsToggle
*/

GVAR(fpsHintActive) = !GVAR(fpsHintActive);

if (!GVAR(fpsHintActive)) exitWith {
    if (GVAR(fpsHintPFH) != -1) then {
        [GVAR(fpsHintPFH)] call CBA_fnc_removePerFrameHandler;
        GVAR(fpsHintPFH) = -1;
    };
    hintSilent "";
};

GVAR(fpsHintPFH) = [{
    // Zeus debug provider renders server + HC FPS via drawHud already; suppress the hint while Zeus is open to avoid doubling up.
    if (!isNull (findDisplay 312)) exitWith {
        hintSilent "";
    };
    [QGVAR(fpsHintRequest), [player]] call CBA_fnc_serverEvent;
}, 1, []] call CBA_fnc_addPerFrameHandler;
