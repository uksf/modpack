#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Safehouse prefab area marking module

    Parameters:
        0: The module logic <OBJECT>

    Return value:
        Nothing
*/
(_this#1) params ["_logic"];

if !(isServer) exitWith {};

private _area = _logic getVariable ["objectarea", []];
if (_area isEqualTo []) exitWith {};

GVAR(safehousePrefabAreaModules) pushBack [_logic, _area];
