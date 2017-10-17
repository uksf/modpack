/*
    Author:
        Tim Beswick

    Description:
        Deploy land rover cover.

    Parameter(s):
        0: Rover <OBJECT>
        1: Unit <OBJECT>
        2: Cover <STRING>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_rover", "_unit", "_coverType"];


if (count (nearestObjects [(position _rover), ["CamoNet_BLUFOR_big_F", "Land_CamoNetB_NATO_EP1"], 20]) > 0) exitWith {
    hint "There's already a cover nearby! Use that one!"
};

success = {
    params ["_args"];
    _args params ["_rover", "_unit", "_coverType"];
    private _cover = createVehicle [_coverType, position _rover, [], 0, "CAN_COLLIDE"];
    private _direction = direction _rover;
    _cover setDir _direction + 180;
    _cover allowDamage false;
    _rover setVariable [QGVAR(deployed), true, true];
    _rover setVariable [QGVAR(coverObj), _cover, true];
    [_unit, "", 2] call ace_common_fnc_doAnimation;
};

fail = {
    params ["_args"];
    _args params ["", "_unit"];
    hint "Could not deploy cover";
    [_unit, "", 2] call ace_common_fnc_doAnimation;
};

[_unit, "Acts_carFixingWheel", 1] call ace_common_fnc_doAnimation;
[COVER_DEPLOY_TIME, [_rover, _unit, _coverType], { call success }, { call fail }, "Deploying Cover"] call ace_common_fnc_progressBar;
