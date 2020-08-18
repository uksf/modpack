#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        creates variables and Fired EH

    Parameters:
        None

    Return value:
        Nothing
*/
GVAR(groundForceSpawns) = [];
GVAR(airForceSpawns) = [];
GVAR(groundVehicleTypes) = ["CUP_B_MTVR_BAF_WOOD"];
GVAR(airVehicleTypes) = ["rksla3_puma_hc1_2gpmg"];
GVAR(counterBatteryUnits) = [];
GVAR(counterInProgress) = 0;
GVAR(soldierList) = [
    "O_Soldier_SL_F",
    "O_Soldier_AR_F",
    "O_Soldier_AR_F",
    "O_Soldier_LAT_F",
    "O_Soldier_LAT_F",
    "O_Soldier_F",
    "O_Soldier_F",
    "O_Soldier_F",
    "O_Soldier_F",
    "O_Soldier_F"
];


["UK3CB_BAF_Static_Mortar_Base", "Fired", {
    params ["_unit"];
    if (isServer) then {
        [_unit] call FUNC(selectResponse);
    };
}] call cba_fnc_addClassEventHandler;


[QGVAR(artilleryFire), {
    params ["_caller", "_artillery", "_targetPosition", "_callerDistance", "_stage", "_previousPosition", "_spread"];
    [_caller, _artillery, _targetPosition, _callerDistance, _stage, _previousPosition, _spread] call uksf_mission_fnc_fireMission;
}] call CBA_fnc_addEventHandler;
