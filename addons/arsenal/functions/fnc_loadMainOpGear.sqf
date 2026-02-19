#include "..\script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Set main op gear cache

    Parameter(s):
        None

    Return Value:
        Nothing
*/
if (!fileExists MAIN_OP_GEAR_FILE) exitWith {
    DEBUG("Main op gear file not found");
};

call (compileScript [MAIN_OP_GEAR_FILE]);

if (isNil QGVAR(mainOpGearBase)) exitWith {
    ERROR_1("Required variable nil: %1",QGVAR(mainOpGearBase));
};

uiNamespace setVariable [QGVAR(mainOpGear), GVAR(mainOpGearBase)];
