#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Tears down PFHs, cleans up spectator camera, closes the dialog.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_medical_fnc_closeDialog
*/

if (GVAR(activeVitalsPFH) != -1) then {
    [GVAR(activeVitalsPFH)] call CBA_fnc_removePerFrameHandler;
    GVAR(activeVitalsPFH) = -1;
};

if (GVAR(activeSpectatorPFH) != -1) then {
    [GVAR(activeSpectatorPFH)] call CBA_fnc_removePerFrameHandler;
    GVAR(activeSpectatorPFH) = -1;
};

[] call FUNC(spectatorCleanup);

if (!isNull findDisplay IDD_UNCON) then {
    (findDisplay IDD_UNCON) closeDisplay 2;
};
