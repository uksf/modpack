#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Dialog onLoad handler. Opens Health tab by default, starts vitals PFH.
        Spectator PFH (and the camera) is started on demand from openSpectatorTab.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        Called automatically via dialog onLoad
*/

call FUNC(openHealthTab);

GVAR(activeVitalsPFH) = [FUNC(vitalsUpdate), 1, []] call CBA_fnc_addPerFrameHandler;
