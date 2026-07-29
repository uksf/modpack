#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Mouse wheel handler attached to the Zeus curator display. Adjusts the
        Watch zoom along the fixed offset axis when a Watch is active, and
        consumes the event so the engine does not also displace the camera.
        Returns false when no Watch is active so the default Zeus zoom works.

    Parameter(s):
        0: Display
        1: Scroll Amount

    Return Value:
        Boolean — true to consume the event

    Example:
        Registered via displayAddEventHandler in uksf_zeus_fnc_curatorDisplayLoad
*/
if (GVAR(watchPFH) < 0) exitWith {false};
if (visibleMap) exitWith {false};

params ["", "_scroll"];

GVAR(watchZoom) = ((GVAR(watchZoom) + (-_scroll * 1.0)) max -50) min 50;
GVAR(watchScrolledFrame) = true;

true
