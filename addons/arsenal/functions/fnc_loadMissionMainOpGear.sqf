#include "..\script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Load main op gear from mission if gear file exists
        File is "uksf_gear.sqf" in the mission root
        Assumes variables are set in the file to control the loading process
            uksf_operation_mainOpGear
                Array
                Set of gear, can be empty
            uksf_operation_replaceAllGear
                Boolean
                When true, specified gear will replace the whole main op gear set
                When false, specified gear will be added to the main op gear set

    Parameter(s):
        None

    Return Value:
        Nothing
*/
if (!fileExists MISSION_MAIN_OP_GEAR_FILE) exitWith {
    DEBUG("Mission gear file not found");
};

call (compileScript [MISSION_MAIN_OP_GEAR_FILE]);

if (isNil QEGVAR(operation,mainOpGear) || isNil QEGVAR(operation,replaceAllGear)) exitWith {
    TRACE_2("Required variables nil",QEGVAR(operation,mainOpGear),QEGVAR(operation,replaceAllGear));
};

if (EGVAR(operation,replaceAllGear)) then {
    INFO_1("Main op gear replaced with mission gear: %1",EGVAR(operation,mainOpGear));
    GVAR(mainOpGear) = EGVAR(operation,mainOpGear);
} else {
    INFO_1("Mission gear added to main op gear: %1",EGVAR(operation,mainOpGear));
    GVAR(mainOpGear) append EGVAR(operation,mainOpGear);
};
