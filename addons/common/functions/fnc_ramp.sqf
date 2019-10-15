#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Open/Close aircraft ramp

    Parameter(s):
        None

    Return Value:
        Nothing
*/

private _vehicle = vehicle ace_player;

if (!(alive _vehicle) || {(_vehicle getVariable ["bis_disabled_Ramp",0]) == 1} || {{ace_player == _x} count [driver _vehicle, _vehicle turretUnit [0], _vehicle turretUnit [1], _vehicle turretUnit [2]] <= 0}) exitWith {};

if ((_vehicle doorPhase "CargoRamp_Open" < 0.3) && {_vehicle animationSourcePhase "Fold" < 0.5}) then {
    _vehicle animateDoor ["CargoRamp_Open", 1];
} else {
    _vehicle animateDoor ["CargoRamp_Open", 0];
};
