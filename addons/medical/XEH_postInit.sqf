#include "script_component.hpp"

if (!hasInterface) exitWith {};

GVAR(activeVitalsPFH) = -1;
GVAR(activeSpectatorPFH) = -1;
GVAR(spectatorCam) = objNull;
GVAR(spectatorTarget) = objNull;
GVAR(spectatorSelectedAlly) = objNull;
GVAR(currentTab) = "spectator";
GVAR(viewMode) = "full";
GVAR(prevCardiacState) = false;
GVAR(prevComaState) = false;

["ace_unconscious", {
    params ["_unit", "_isUncon"];
    [_unit, _isUncon] call FUNC(handleUnconsciousState);
}] call CBA_fnc_addEventHandler;

player addEventHandler ["Killed", {
    [] call FUNC(closeDialog);
}];

player addEventHandler ["Respawn", {
    params ["_unit"];
    _unit addEventHandler ["Killed", {
        [] call FUNC(closeDialog);
    }];
}];

if (ACE_player getVariable ["ACE_isUnconscious", false]) then {
    [ACE_player, true] call FUNC(handleUnconsciousState);
};

["CBA_settingsInitialized", {
    [QGVAR(modEnabled), "onChange", {
        params ["", "_value"];
        if (!_value && {!isNull findDisplay IDD_UNCON}) then {
            [] call FUNC(closeDialog);
        };
    }] call CBA_fnc_addSettingsChangedHandler;
}] call CBA_fnc_addEventHandler;
