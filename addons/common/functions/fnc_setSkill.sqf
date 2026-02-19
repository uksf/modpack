#include "script_component.hpp"
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
params ["_unit", ["_setting", 0]];

switch (_setting) do {
    case (0): {
        _unit setSkill ["general", 1];
        _unit setSkill ["aimingAccuracy", 0.4];
        _unit setSkill ["aimingShake", 0.8];
        _unit setSkill ["aimingSpeed", 0.8];
        _unit setSkill ["endurance", 1];
        _unit setSkill ["spotDistance", 1];
        _unit setSkill ["spotTime", 1];
        _unit setSkill ["courage", 1];
        _unit setSkill ["reloadSpeed", 1];
        _unit setSkill ["commanding", 1];
    };
    case (1): {
        _unit setSkill ["general", 1];
        _unit setSkill ["aimingAccuracy", 0.6];
        _unit setSkill ["aimingShake", 1];
        _unit setSkill ["aimingSpeed", 1];
        _unit setSkill ["endurance", 1];
        _unit setSkill ["spotDistance", 1];
        _unit setSkill ["spotTime", 1];
        _unit setSkill ["courage", 1];
        _unit setSkill ["reloadSpeed", 1];
        _unit setSkill ["commanding", 1];
    };
};
