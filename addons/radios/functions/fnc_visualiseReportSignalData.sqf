#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Reports accumulated signal data to server, then clears logs.

    Parameter(s):
        None

    Return Value:
        None
*/
if (GVAR(visualiseSignalLog) isEqualTo createHashMap && {GVAR(visualiseConnectionLog) isEqualTo createHashMap}) exitWith {};

[QEGVAR(zeus,visualiseRebroReport), [
    player,
    getPosATL player,
    +GVAR(visualiseSignalLog),
    +GVAR(visualiseConnectionLog)
]] call CBA_fnc_serverEvent;

GVAR(visualiseSignalLog) = createHashMap;
GVAR(visualiseConnectionLog) = createHashMap;
