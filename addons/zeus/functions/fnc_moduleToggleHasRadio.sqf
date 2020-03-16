#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggles whether the group can support friendly units

    Parameter(s):
        0: The module logic <OBJECT>

    Return Value:
        None
*/
params ["_logic"];

private _unit = attachedTo _logic;
deleteVehicle _logic;

if (isNull _unit || {!(_unit isKindOf "CAManBase")}) exitWith {["Place on a unit"] call ace_zeus_fnc_showMessage;};
if (isPlayer _unit) exitWith {["Unit must be AI"] call ace_zeus_fnc_showMessage;};
if (!(alive _unit)) exitWith {["Unit must be alive"] call ace_zeus_fnc_showMessage;};

private _state = _unit getVariable [QEGVAR(mission,hasSupportRadio), true];
[QEGVAR(mission,setSupportRadio), [_unit, !_state]] call CBA_fnc_serverEvent;
[["Gave support radio", "Removed support radio"] select _state] call ace_common_fnc_displayTextStructured;
