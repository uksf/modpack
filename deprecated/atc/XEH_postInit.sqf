#include "script_component.hpp"

if (isServer) then {
    _mapCenter = getArray(configFile >> "CfgWorlds" >> worldName >> "centerPosition");
    _towers = nearestobjects [_mapCenter, ["Land_Airport_Tower_F"], 10000];
    
    {
        _ATC = createVehicle ["UKSF_ATC_Core", [0,0,0], [], 0, "CAN_COLLIDE"];
        _ATC setPos (_x modelToWorld [-3.8,-3.8,3.3]);
        _ATC setVariable ["RadarOn", false, true];
    } forEach _towers;

    missionNamespace setVariable [QGVAR(airTargets), [], true];
};
