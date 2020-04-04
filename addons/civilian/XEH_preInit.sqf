#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

["CBA_settingsInitialized", {
    if (!GVAR(enableGestures)) exitWith {};

    GVAR(vehicle_statemachine) = locationNull;
    GVAR(vehicle_statemachine_vehicles) = [];
    GVAR(unit_statemachine) = locationNull;
    GVAR(unit_statemachine_units) = [];

    if (hasInterface) then {
        GVAR(lastGesture) = 0;

        if (GVAR(allowDebug)) then {
            GVAR(debugDrawId) = -1;
            GVAR(debugPFHId) = -1;
            GVAR(debugBroadcastPFHId) = -1;
            GVAR(debugVehicles) = [];
            GVAR(debugUnits) = [];
            GVAR(debugVehicleSpheres) = [];
            GVAR(debugVehicleMoveCommandSpheres) = [];
            GVAR(debugVehicleFollowCommandSpheres) = [];
            GVAR(debugUnitSpheres) = [];
            GVAR(debugUnitMoveCommandSpheres) = [];
            GVAR(debugUnitFollowCommandSpheres) = [];
        };
    };
}] call CBA_fnc_addEventHandler;

ADDON = true;
