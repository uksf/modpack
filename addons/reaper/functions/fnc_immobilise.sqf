#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Removes fuel from drone

    Parameter(s):
        0: UAV <OBJECT>
        1: Immobilise state <BOOL>

    Return Value:
        Nothing
*/
params ["_uav", "_state"];

if (_state) then {
    _uav setVariable [QGVAR(immobilised), true, true];
    deleteVehicle (driver (ACE_controlledUAV#0));
    _uav engineOn false;
} else {
    createVehicleCrew _uav;
    _uav setVariable [QGVAR(immobilised), false, true];
};
