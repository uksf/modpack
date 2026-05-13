#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Dialog onLoad handler. Hides all controls, opens Health tab by default, starts PFHs.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        Called automatically via dialog onLoad
*/

call FUNC(hidePreviousTabs);
call FUNC(openHealthTab);

GVAR(activeVitalsPFH) = [FUNC(vitalsUpdate), 1, []] call CBA_fnc_addPerFrameHandler;
GVAR(activeSpectatorPFH) = [FUNC(spectatorUpdate), 0.5, []] call CBA_fnc_addPerFrameHandler;
