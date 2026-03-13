#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Opens the TBD fuse timer dialog for a smoke round

    Parameter(s):
        0: Round object <OBJECT>

    Return Value:
        Nothing

    Example:
        [_round] call uksf_weapons_fnc_l119SetSmokeFuseTime
*/
params ["_round"];

tbd_mortars_105mm_shell = _round;
createDialog "RscTBDTimer";
