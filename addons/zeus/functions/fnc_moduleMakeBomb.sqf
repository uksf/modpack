#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Makes unit a bomber

    Parameter(s):
        0: The module logic <OBJECT>

    Return Value:
        None
*/
params ["_logic", "", "", ["_deadman", false], ["_car", false], ["_empty", false]];

if (!local _logic) exitWith {};

private _unit = attachedTo _logic;

if (_logic isKindOf QGVAR(moduleMakeSuicideBomberDeadman) || {_logic isKindOf QGVAR(moduleMakeCarBomberDeadman)}) then {
    _deadman = true;
};
if (_logic isKindOf QGVAR(moduleMakeCarBomber) || {_logic isKindOf QGVAR(moduleMakeCarBomberDeadman)}) then {
    _car = true;
};
if (_logic isKindOf QGVAR(moduleMakeCarBomb)) then {
    _empty = true;
};

if (isNull _unit) exitWith {["Place on a living unit or an occupied land vehicle"] call ace_zeus_fnc_showMessage;};
if (_unit getVariable [QEGVAR(special,isBomber), false]) exitWith {["Unit or vehicle is already a bomb"] call ace_zeus_fnc_showMessage;};
if (_empty && {!(_unit isKindOf "LandVehicle")}) exitWith {["Place on a land vehicle"] call ace_zeus_fnc_showMessage;};
if (_car && {!(alive _unit) || {!(_unit isKindOf "LandVehicle")} || {driver _unit isEqualTo objNull}}) exitWith {["Place on an occupied land vehicle"] call ace_zeus_fnc_showMessage;};
if (!_empty && {!_car} && {!(alive _unit) || {!(_unit isKindOf "CAManBase")}}) exitWith {["Place on a living unit"] call ace_zeus_fnc_showMessage;};

[[QEGVAR(special,makeSuicideBomb), QEGVAR(special,makeCarBomb)] select _empty, [_unit, _deadman, _car], _unit] call CBA_fnc_targetEvent;
[["Unit/vehicle is now a suicide bomber", "Vehicle is now a car bomb"] select _empty] call ace_common_fnc_displayTextStructured;

deleteVehicle _logic;
