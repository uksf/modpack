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
{speed _vehicle > 300} &&
{!(_vehicle getVariable [QGVAR(trdUsing), false])} &&
{_vehicle getVariable [QGVAR(trdUses), 0] <= 3}
