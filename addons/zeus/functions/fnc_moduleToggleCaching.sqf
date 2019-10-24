#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggles unit cache state

    Parameter(s):
        0: The module logic <OBJECT>

    Return Value:
        None
*/
params ["_logic"];

if (!local _logic) exitWith {};

private _unit = attachedTo _logic;

if (isNull _unit || {!(_unit isKindOf "CAManBase")}) exitWith {["Place on a unit"] call ace_zeus_fnc_showMessage;};
if (isPlayer _unit) exitWith {["Unit must be AI"] call ace_zeus_fnc_showMessage;};
if (!(alive _unit)) exitWith {["Unit must be alive"] call ace_zeus_fnc_showMessage;};

private _group = group _unit;
private _state = _group getVariable [QEGVAR(caching,excluded), false];
[[QEGVAR(caching,disableCache), QEGVAR(caching,enableCache)] select _state, [_group]] call CBA_fnc_serverEvent;
[["Excluded from caching", "Included in caching"] select _state] call ace_common_fnc_displayTextStructured;

deleteVehicle _logic;
