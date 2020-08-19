#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

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
GVAR(groundVehicleTypes) = [];
GVAR(airVehicleTypes) = [];
GVAR(counterBatteryUnits) = [];
GVAR(counterInProgress) = 0;
GVAR(soldierList) = [];


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

ADDON = true;
