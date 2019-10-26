#include "script_component.hpp"
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
params ["_heli"];

if (player isEqualTo (driver _heli) || {player isEqualTo (gunner _heli)}) then {
    GVAR(soundPlaying) = false;
    [_heli] call FUNC(warning);
};
