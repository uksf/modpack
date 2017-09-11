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
#include "script_component.hpp"

params ["_uav", "_state"];

if (_state) then {
    _uav setVariable [QGVAR(immobilised), true, true];
    deleteVehicle (driver (ACE_controlledUAV  select 0));
    _uav engineOn false;
} else {
    private _driver = (group (ACE_controlledUAV  select 0)) createUnit ["B_UAV_AI", [-1000,-1000,0], [], 0, "NONE"];
    _driver moveInDriver _uav;
    _uav setVariable [QGVAR(immobilised), false, true];
};
