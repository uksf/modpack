#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Safehouse prefab area marking module

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
    [_logic, _mode] call FUNC(modulePrefabEden);
};

private _id = _logic getVariable [QEGVAR(common,id), ""];
if (_id isEqualTo "") exitWith {
    ERROR("Safehouse prefab does not have an ID");
};

private _area = _logic getVariable ["objectarea", []];
if (_area isEqualTo []) exitWith {};

GVAR(prefabAreaModules) pushBack [_id, _logic, _area];
