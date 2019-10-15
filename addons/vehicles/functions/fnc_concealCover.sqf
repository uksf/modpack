#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Conceal land rover cover.

    Parameter(s):
        0: Rover <OBJECT>
        1: Unit <OBJECT>

    Return Value:
        None
*/

params ["_rover", "_unit"];

success = {
    params ["_args"];
    _args params ["_rover", "_unit"];
    private _cover = _rover getVariable [QGVAR(coverObj), objNull];
    if (_cover != objNull) then {
        deleteVehicle _cover;
        _rover setVariable [QGVAR(coverObj), objNull, true];
        _rover setVariable [QGVAR(deployed), false, true];
    };
    [_unit, "", 2] call ace_common_fnc_doAnimation;
};

fail = {
    params ["_args"];
    _args params ["", "_unit"];
    hint "Could not conceal cover";
    [_unit, "", 2] call ace_common_fnc_doAnimation;
};

[_unit, "Acts_carFixingWheel", 1] call ace_common_fnc_doAnimation;
[COVER_DEPLOY_TIME, [_rover, _unit], { call success }, { call fail }, "Concealing Cover"] call ace_common_fnc_progressBar;
