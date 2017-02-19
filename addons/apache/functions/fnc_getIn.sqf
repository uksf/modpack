/*
    Author:
        Tim Beswick

    Description:
        Runs on get in

    Parameters:
        0: Heli <OBJECT>
        1: Position <STRING>
        2: Unit <OBJECT>
        3: Turret <ARRAY>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_heli"];

if (player isEqualTo (driver _heli) || {player isEqualTo (gunner _heli)}) then {
    GVAR(soundPlaying) = false;
    GVAR(soundPriority) = -1;
    GVAR(previousTailDamage) = 0;
    GVAR(previousMainDamage) = 0;
    GVAR(previousE1Damage) = 0;
    GVAR(previousE2Damage) = 0;
    GVAR(previousGunDamage) = 0;
    GVAR(previousInsDamage) = 0;

    [_heli] call FUNC(warning);
};
