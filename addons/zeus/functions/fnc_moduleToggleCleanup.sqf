#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggles unit cleanup state

    Parameter(s):
        0: The module logic <OBJECT>

    Return Value:
        None
*/
params ["_logic"];

if (!local _logic) exitWith {};

private _object = attachedTo _logic;

if (isNull _object) exitWith {["Place on a unit or vehicle"] call ace_zeus_fnc_showMessage;};

private _state = _object getVariable [QEGVAR(cleanup,excluded), false];
[QEGVAR(cleanup,setCleanupState), [_object, !_state]] call CBA_fnc_serverEvent;
[["Excluded from cleanup", "Included in cleanup"] select _state] call ace_common_fnc_displayTextStructured;

deleteVehicle _logic;
