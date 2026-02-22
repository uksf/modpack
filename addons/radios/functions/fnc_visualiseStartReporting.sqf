#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts periodic signal reporting to server for Zeus rebro visualisation.

    Parameter(s):
        None

    Return Value:
        None
*/
if (GVAR(visualiseReportingEnabled)) exitWith {};

GVAR(visualiseReportingEnabled) = true;
GVAR(visualiseSignalLog) = createHashMap;
GVAR(visualiseConnectionLog) = createHashMap;

GVAR(visualiseReportingPFH) = [{
    call FUNC(visualiseReportSignalData);
}, 4, []] call CBA_fnc_addPerFrameHandler;
