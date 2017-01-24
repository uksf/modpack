/*
    Author:
        Tim Beswick

    Description:
        Sets ai skill, overriding any other settings

    Parameter(s):
        0: Unit <OBJECT>
        1: Setting <SCALAR>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_unit", ["_setting", 0]];

switch (_setting) do {
    case (0): {
        _unit setskill ["general", 1];
        _unit setskill ["aimingAccuracy", 0.4];
        _unit setskill ["aimingShake", 0.8];
        _unit setskill ["aimingSpeed", 0.8];
        _unit setskill ["endurance", 1];
        _unit setskill ["spotDistance", 1];
        _unit setskill ["spotTime", 1];
        _unit setskill ["courage", 1];
        _unit setskill ["reloadSpeed", 1];
        _unit setskill ["commanding", 1];
    };
    case (1): {
        _unit setskill ["general", 1];
        _unit setskill ["aimingAccuracy", 0.6];
        _unit setskill ["aimingShake", 1];
        _unit setskill ["aimingSpeed", 1];
        _unit setskill ["endurance", 1];
        _unit setskill ["spotDistance", 1];
        _unit setskill ["spotTime", 1];
        _unit setskill ["courage", 1];
        _unit setskill ["reloadSpeed", 1];
        _unit setskill ["commanding", 1];
    };
};
