#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Opens the MPU-5 app for a radio. Handles the ACRE open event of the MPU-5, which has no ACRE dialog.

    Parameter(s):
        0: Radio ID <STRING>

    Return Value:
        Nothing

    Example:
        ["acre_mpu5_id_1"] call uksf_ctab_fnc_mpu5OpenGui
*/

params ["_radioId"];

GVAR(mpu5Radio) = _radioId;
private _mode = MODE_APP_PREFIX + "mpu5";

if (!isNil "cTabIfOpen" && {(cTabIfOpen select 1) == ANDROID_DIALOG}) exitWith {
    [_mode] call FUNC(setMode);
};

GVAR(lastMode) = _mode;
[1, ANDROID_DIALOG, player, vehicle player] call ctab_core_fnc_toggleInterface;
