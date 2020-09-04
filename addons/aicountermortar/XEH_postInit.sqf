#include "script_component.hpp"

if (!isServer) exitWith {};

if (GVAR(groundVehiclePool) isEqualTo [] && {GVAR(airVehiclePool) isEqualTo [] && {GVAR(counterBatteryUnits) isEqualTo []}}) exitWith {
    WARNING("No counter units defined");
};

["UK3CB_BAF_Static_Mortar_Base", "Fired", {call FUNC(selectResponse)}, true, [], true] call CBA_fnc_addClassEventHandler;
