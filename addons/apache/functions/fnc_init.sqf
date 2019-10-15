#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Inits Apache

    Parameters:
        0: Heli <OBJECT>

    Return value:
        Nothing
*/

params ["_heli"];

if (local _heli) then {
    _heli setVariable [QGVAR(previousTailDamage), 0, true];
    _heli setVariable [QGVAR(previousMainDamage), 0, true];
    _heli setVariable [QGVAR(previousE1Damage), 0, true];
    _heli setVariable [QGVAR(previousE2Damage), 0, true];
    _heli setVariable [QGVAR(previousGunDamage), 0, true];
    _heli setVariable [QGVAR(previousInsDamage), 0, true];
    _heli setVariable [QGVAR(jammerMode), 0, true];
};

if (player in _heli) then {
    [_heli] call FUNC(getIn);
}
