#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns the carried radios that an MPU-5 can link as a gateway or bridge, as combo entries headed by an Off entry.

    Parameter(s):
        None

    Return Value:
        Combo entries of [name, radio ID] <ARRAY>

    Example:
        call uksf_ctab_fnc_mpu5LegacyRadios
*/

private _entries = [["Off", ""]];
{
    private _data = [_x, "getCurrentChannelData"] call acre_sys_data_fnc_dataEvent;
    if (!isNil "_data" && {(_data getVariable ["mode", ""]) in ["singleChannel", "singleChannelPRR"]}) then {
        _entries pushBack [format ["%1 (%2)", getText (configFile >> "CfgWeapons" >> [_x] call acre_api_fnc_getBaseRadio >> "displayName"), [_x] call acre_api_fnc_getRadioChannel], _x];
    };
} forEach (([] call acre_api_fnc_getCurrentRadioList) select {([_x] call acre_api_fnc_getBaseRadio) != MPU5_CLASS});
_entries
