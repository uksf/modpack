#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Detaches and deletes spectator camera + target dummy.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_medical_fnc_spectatorCleanup
*/

if (!isNull GVAR(spectatorCam)) then {
    GVAR(spectatorCam) cameraEffect ["terminate", "back", "uksf_medical_rtt"];
    detach GVAR(spectatorCam);
    camDestroy GVAR(spectatorCam);
};

if (!isNull GVAR(spectatorTarget)) then {
    deleteVehicle GVAR(spectatorTarget);
};

GVAR(spectatorCam) = objNull;
GVAR(spectatorTarget) = objNull;
GVAR(spectatorSelectedAlly) = objNull;
