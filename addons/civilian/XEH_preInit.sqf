#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

["CBA_settingsInitialized", {
    if (GVAR(enableGestures)) then {
        GVAR(vehicle_statemachine) = locationNull;
        GVAR(vehicle_statemachine_vehicles) = [];
        GVAR(unit_statemachine) = locationNull;
        GVAR(unit_statemachine_units) = [];

        if (hasInterface) then {
            GVAR(lastGesture) = 0;

            if (GVAR(allowDebug)) then {
                GVAR(debugDrawId) = -1;
                GVAR(debugPFHId) = -1;
                GVAR(debugBroadcastPFHId) = -1;
                GVAR(debugVehicles) = [];
                GVAR(debugUnits) = [];
                GVAR(debugVehicleSpheres) = [];
                GVAR(debugVehicleMoveCommandSpheres) = [];
                GVAR(debugVehicleFollowCommandSpheres) = [];
                GVAR(debugUnitSpheres) = [];
                GVAR(debugUnitMoveCommandSpheres) = [];
                GVAR(debugUnitFollowCommandSpheres) = [];
            };
        };
    };
}] call CBA_fnc_addEventHandler;

["ace_captives_escortingCaptive", {
    if !(GVAR(enableEscort)) exitWith {};

    params ["_unit", "_state", "_target"];

    if (_state) then {
        if !(ace_common_isReloading) then {
            private _holdAnim = [QGVAR(holdhvt), QGVAR(holdhvtpistol)] select (currentWeapon _unit == "" || (currentWeapon _unit) == (handgunWeapon _unit));
            _unit playActionNow _holdAnim;
        };
    } else {
        if !(ace_common_isReloading) then {
            _unit playActionNow QGVAR(clearAction);
        };
    };

    [QGVAR(doEscort), [_unit, _target, _state], _target] call CBA_fnc_targetEvent;
}] call CBA_fnc_addEventHandler;

[QGVAR(doEscort), {
    if !(GVAR(enableEscort)) exitWith {};

    params ["", "", "_state"];

    call ([FUNC(captiveEscortStop), FUNC(captiveEscortStart)] select _state);
}] call CBA_fnc_addEventHandler;

[QGVAR(ace_doEscortCaptive), {call ace_captives_fnc_doEscortCaptive}] call CBA_fnc_addEventHandler;

["weapon", {
    if !(GVAR(enableEscort)) exitWith {};
    if !(ACE_player getVariable ["ace_captives_isEscorting", false]) exitWith {};

    params ["", "_newWeapon"];

    if (_newWeapon == "") exitWith {
        ACE_player setVariable ["ace_captives_isEscorting", false, true];
    };

    ["ace_common_switchMove", [ACE_player, "HubSpectator_stand"]] call CBA_fnc_globalEvent;

    [{
        params ["", "_newWeapon"];

        private _holdAnim = [QGVAR(holdhvt), QGVAR(holdhvtpistol)] select (_newWeapon == (handgunWeapon ACE_player));
        ACE_player playActionNow _holdAnim;

        ["ace_common_switchMove", [ACE_player, ""]] call CBA_fnc_globalEvent;
    }, _this, 2] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addPlayerEventHandler;

["loadout", {
    if !(GVAR(enableEscort)) exitWith {};
    if !(ACE_player getVariable ["ace_captives_isEscorting", false]) exitWith {};
    if !(ace_common_isReloading) exitWith {};

    ["ace_common_switchMove", [ACE_player, "HubSpectator_stand"]] call CBA_fnc_globalEvent;

    [{
        !ace_common_isReloading || !(ACE_player getVariable ["ace_captives_isEscorting", false])
    },{
        ["ace_common_switchMove", [ACE_player, ""]] call CBA_fnc_globalEvent;

        if !(ACE_player getVariable ["ace_captives_isEscorting", false]) exitWith {};

        private _holdAnim = [QGVAR(holdhvt), QGVAR(holdhvtpistol)] select ((currentWeapon ACE_player) == (handgunWeapon ACE_player));
        ACE_player playActionNow _holdAnim;
    }] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addPlayerEventHandler;

ADDON = true;
