/*
    Author:
        Tim Beswick

    Description:
        Initialises ATC objects/buildings

    Parameter(s):
        0: Object <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_object"];

if (isServer) then {
    if (_object isKindOf "UKSF_ATC_Station") then {
        _ATC = createVehicle ["UKSF_ATC_Core", [0,0,0], [], 0, "CAN_COLLIDE"];
        _ATC setPos (_object modelToWorld [0,0,0.5]);
        _ATC setVariable [QGVAR(radarOn), false, true];
    };
};
