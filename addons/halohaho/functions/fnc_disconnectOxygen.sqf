#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Disconnects oxygen and stops any pending or playing breathing loop.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_halohaho_fnc_disconnectOxygen
*/
GVAR(oxygenGeneration) = GVAR(oxygenGeneration) + 1;
GVAR(oxygenConnected) = false;
if (GVAR(oxygenSound) isNotEqualTo -1) then {
    stopSound GVAR(oxygenSound);
    GVAR(oxygenSound) = -1;
};
if (!isNull GVAR(oxygenUnit)) then {
    GVAR(oxygenUnit) removeEventHandler ["Killed", GVAR(oxygenKilledEH)];
    GVAR(oxygenUnit) = objNull;
};
GVAR(oxygenKilledEH) = -1;
