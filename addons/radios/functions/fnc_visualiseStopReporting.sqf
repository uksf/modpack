#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Stops periodic signal reporting.

    Parameter(s):
        None

    Return Value:
        None
*/
GVAR(visualiseReportingEnabled) = false;
[GVAR(visualiseReportingPFH)] call CBA_fnc_removePerFrameHandler;
GVAR(visualiseReportingPFH) = -1;
GVAR(visualiseSignalLog) = createHashMap;
GVAR(visualiseConnectionLog) = createHashMap;
