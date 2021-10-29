#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Safehouse location marking module

    Parameters:
        0: Mode <STRING>
        1: Data <ARRAY>

    Return value:
        Nothing
*/
params ["_mode", "_data"];
_data params ["_logic"];

if !(isServer) exitWith {};

if (is3DEN) exitWith {
    [_logic, _mode] call FUNC(moduleLocationEden);
};

private _id = _logic getVariable [QEGVAR(common,id), ""];
if (_id isEqualTo "") exitWith {
    ERROR("Safehouse location does not have an ID");
};

private _prefabId = _logic getVariable [QGVAR(prefabId), ""];
if (_prefabId != "") then {
    DEBUG_2("Pre-selected prefab id %1 for location id %2",_prefabId,_id);
};

GVAR(locationModules) pushBack [_id, _logic, _prefabId];
