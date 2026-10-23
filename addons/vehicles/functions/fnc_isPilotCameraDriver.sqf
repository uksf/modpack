#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks if the player drives a vehicle that has a pilot camera.

    Parameter(s):
        None

    Return Value:
        True if the player is the driver of a vehicle with a pilot camera <BOOL>

    Example:
        call uksf_vehicles_fnc_isPilotCameraDriver
*/

private _vehicle = vehicle ACE_player;
_vehicle != ACE_player && {driver _vehicle == ACE_player} && {hasPilotCamera _vehicle}
