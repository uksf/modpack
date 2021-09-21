#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Safehouse location marking module

    Parameters:
        0: The module logic <OBJECT>

    Return value:
        Nothing
*/
(_this#1) params ["_logic"];

if !(isServer) exitWith {};

private _id = _logic getVariable [QEGVAR(common,id), ""];
if (_id isEqualTo "") exitWith {
    ERROR("Rating area does not have an ID");
};
// [_object,_id] call FUNC(persistence,markObjectAsPersistent);

GVAR(safehouseLocationModules) pushBack [_id, _logic];
