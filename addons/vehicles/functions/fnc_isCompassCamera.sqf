#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks whether the player's seat in an aircraft, or the aircraft UAV they control,
        has a camera that gets the camera compass: pilot cameras, gunner and copilot
        turret cameras, and UAV turrets. Ground vehicles and boats never get it.

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        Compass available <BOOL>

    Example:
        [cameraOn] call uksf_vehicles_fnc_isCompassCamera
*/
params ["_vehicle"];

if !(_vehicle isKindOf "Air") exitWith {false};
if (_vehicle != vehicle ACE_player) exitWith {true};

private _turret = _vehicle unitTurret ACE_player;
if (_turret isEqualTo [] || {[ACE_player] call CBA_fnc_canUseWeapon}) exitWith {false};

_turret isNotEqualTo [-1] || {hasPilotCamera _vehicle}
