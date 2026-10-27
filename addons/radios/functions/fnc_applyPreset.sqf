#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Applies radio preset data to the local player's radios
        While the arsenal is open, the preset waits until the arsenal closes and ACRE restores the radios

    Parameter(s):
        0: Radio data <ARRAY>
            Formatted as: [type, channel, volume, ear, pttIndex]

    Return Value:
        None

    Example:
        [_radioData] call uksf_radios_fnc_applyPreset
*/
params ["_radioData"];

if (acre_sys_core_arsenalOpen) exitWith {
    GVAR(pendingPreset) = +_radioData;
};
if (_radioData isEqualTo []) exitWith {};

[+_radioData] call FUNC(deserializeRadios);
