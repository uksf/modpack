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
}] call CBA_fnc_addEventHandler;

["ace_captives_doEscort", {
    if !(GVAR(enableEscort)) exitWith {};

    params ["", "_state"];

    call ([FUNC(captiveEscortStop), FUNC(captiveEscortStart)] select _state);
}] call CBA_fnc_addEventHandler;

["weapon", {
    if !(ACE_player getVariable ["ace_captives_isEscorting", false]) exitWith {};

    params ["_unit", "_newWeapon"];

    private _animState = configName (configFile >> getText (configFile >> "CfgVehicles" >> typeOf ACE_player >> "moves") >> "States" >> (animationState ACE_player));
    if (_newWeapon == primaryWeapon _unit) then {
        _animState = [_animState, "pst", "rfl"] call CBA_fnc_replace;
    } else {
        if (_newWeapon == handgunWeapon _unit) then {
            _animState = [_animState, "rfl", "pst"] call CBA_fnc_replace;
        };
    };

    ["ace_common_switchMove", [_unit, ""]] call CBA_fnc_globalEvent;
    ["ace_common_switchMove", [_unit, _animState]] call CBA_fnc_globalEvent;

    private _holdAnim = [QGVAR(holdhvt), QGVAR(holdhvtpistol)] select (_newWeapon == (handgunWeapon ACE_player));
    private _jipId = ["ace_common_playActionNow", [ACE_player, _holdAnim]] call CBA_fnc_globalEventJIP;
    [_jipId, ACE_player] call CBA_fnc_removeGlobalEventJIP;
}] call CBA_fnc_addPlayerEventHandler;

["CAManBase", "Take", {
    if !(ACE_player getVariable ["ace_captives_isEscorting", false]) exitWith {};

    private _holdAnim = [QGVAR(holdhvt), QGVAR(holdhvtpistol)] select (_newWeapon == (handgunWeapon ACE_player));
    private _jipId = ["ace_common_playActionNow", [ACE_player, _holdAnim]] call CBA_fnc_globalEventJIP;
    [_jipId, ACE_player] call CBA_fnc_removeGlobalEventJIP;
}] call CBA_fnc_addClassEventHandler;

ADDON = true;
