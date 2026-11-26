#include "script_component.hpp"

GVAR(enforced) = [
    ["comspec_overwatch_enabled", false],
    ["comspec_atak_native_local_only", true],
    ["comspec_atak_native_mpu_voice", false],
    ["comspec_atak_native_zeus_centre_btn", false],
    ["comspec_atak_native_language", "en"]
];

["CBA_settingsInitialized", {
    {
        _x params ["_setting", "_value"];
        missionNamespace setVariable [_setting, _value];
    } forEach GVAR(enforced);
    if ((missionNamespace getVariable ["COMSPEC_ATAK_Lang", ""]) isNotEqualTo "en") then {
        [true] call comspec_atak_native_fnc_langApply;
    };
}] call CBA_fnc_addEventHandler;
