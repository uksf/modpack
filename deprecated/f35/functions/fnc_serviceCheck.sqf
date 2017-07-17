/*
    Author:
        Tim Beswick, USAF Team

    Description:
        Check if plane is servicable

    Parameters:
        0: Plane <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_plane"];

(
    player isEqualTo driver _plane &&
    speed _plane < 1 &&
    (
        count (nearestObjects [_plane, ["B_Truck_01_ammo_F", "Land_TentHangar_V1_F", "Land_Hangar_F"], 30]) > 0
    )
)
