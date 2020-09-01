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

if (count (GVAR(groundVehicleTypes) + GVAR(airVehicleTypes) + GVAR(counterBatteryUnits)) == 0) exitWith {diag_log "UKSF: ANTI MORTAR --- No counter units defined ---"};

["UK3CB_BAF_Static_Mortar_Base", "Fired", {
    params ["_unit"];
    if (isServer) then {
        [_unit] call FUNC(selectResponse);
    };
}] call cba_fnc_addClassEventHandler;

ADDON = true;
