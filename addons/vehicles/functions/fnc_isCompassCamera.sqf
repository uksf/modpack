#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks whether the player's seat in a vehicle, or the UAV role they control,
        has a camera that gets the camera compass: any aircraft camera, including
        pilot cameras and UAV turrets, and the gunner and commander optics of any vehicle.

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        Compass available <BOOL>

    Example:
        [cameraOn] call uksf_vehicles_fnc_isCompassCamera
*/
params ["_vehicle"];

if (_vehicle != vehicle ACE_player) exitWith {
    _vehicle isKindOf "Air" || {focusOn != driver _vehicle}
};

private _turret = _vehicle unitTurret ACE_player;
if (_turret isEqualTo [] || {[ACE_player] call CBA_fnc_canUseWeapon}) exitWith {false};

_turret isNotEqualTo [-1] || {_vehicle isKindOf "Air" && {hasPilotCamera _vehicle}}
