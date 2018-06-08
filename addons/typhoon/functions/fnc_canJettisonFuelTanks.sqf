/*
    Author:
        Tim Beswick

    Description:
        Checks if able to jettison fuel tanks

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        Boolean
*/
#include "script_component.hpp"

params ["_vehicle"];

(ACE_player isEqualTo (driver _vehicle)) &&
{(_vehicle animationPhase "tank_drop_ind") > 0.9} &&
{({_x in ["EF2K_fueltank", "EF2K_CL_fueltank"]} count (magazines _vehicle)) > 0}
