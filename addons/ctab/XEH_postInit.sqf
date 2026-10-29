#include "script_component.hpp"

[QGVAR(droneTask), FUNC(droneTask)] call CBA_fnc_addEventHandler;
if (isServer) then {
    GVAR(escorts) = [];
    [QGVAR(droneRoute), FUNC(droneRoute)] call CBA_fnc_addEventHandler;
    addMissionEventHandler ["PlayerDisconnected", {_this call FUNC(droneOwnerLeft)}];
};

if (!hasInterface) exitWith {};

[QGVAR(modeChanged), FUNC(onModeChanged)] call CBA_fnc_addEventHandler;
["ctab_interface_open", FUNC(onInterfaceOpen)] call CBA_fnc_addEventHandler;

["route", "Route", FUNC(routeOpen), {}, true] call FUNC(registerApp);
["elevation", "Elevation", FUNC(elevationOpen), {}, true] call FUNC(registerApp);
["reports", "Reports", FUNC(reportsOpen)] call FUNC(registerApp);
["jump", "HAHO / HALO", FUNC(jumpOpen), {}, true] call FUNC(registerApp);
["weather", "Weather", FUNC(weatherOpen)] call FUNC(registerApp);
["friendly", "Friendly", FUNC(friendlyOpen)] call FUNC(registerApp);
["drones", "Drones", FUNC(droneOpen), {}, true] call FUNC(registerApp);

if (isClass (configFile >> "CfgPatches" >> "acre_sys_mpu5")) then {
    ["mpu5", "MPU-5", FUNC(mpu5Open)] call FUNC(registerApp);
    ["acre_sys_mpu5_openGui", FUNC(mpu5OpenGui)] call CBA_fnc_addEventHandler;
};

GVAR(overlays) append [FUNC(routeDraw), FUNC(elevationDraw), FUNC(jumpDraw)];
