#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks whether the seat the player looks from in an aircraft, their own or the
        UAV role they control, has a camera that gets the camera compass: a pilot seat
        with a pilot camera, or a turret with camera optics (OpticsIn).
        Door gunners, other gunners without a camera, ground vehicles and boats never get it.

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        Compass available <BOOL>

    Example:
        [cameraOn] call uksf_vehicles_fnc_isCompassCamera
*/
params ["_vehicle"];

if !(_vehicle isKindOf "Air") exitWith {false};

private _unit = [focusOn, ACE_player] select (_vehicle == vehicle ACE_player);
private _turret = _vehicle unitTurret _unit;
if (_turret isEqualTo []) exitWith {false};
if (_turret isEqualTo [-1]) exitWith {hasPilotCamera _vehicle};

isClass (([_vehicle, _turret] call BIS_fnc_turretConfig) >> "OpticsIn")
