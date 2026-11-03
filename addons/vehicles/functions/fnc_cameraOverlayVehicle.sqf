#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns the vehicle or UAV whose optics the player looks through.
        Personal weapon sights in firing-from-vehicle seats do not count.

    Parameter(s):
        None

    Return Value:
        Vehicle, or objNull when the player is not looking through vehicle optics <OBJECT>

    Example:
        call uksf_vehicles_fnc_cameraOverlayVehicle
*/

private _vehicle = cameraOn;
if (cameraView != "GUNNER" || {_vehicle == ACE_player} || {_vehicle isKindOf "CAManBase"}) exitWith {objNull};
if (vehicle ACE_player == _vehicle && {[ACE_player] call CBA_fnc_canUseWeapon}) exitWith {objNull};

_vehicle
