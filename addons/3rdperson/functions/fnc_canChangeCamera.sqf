#include "script_component.hpp"
/*
    Author:
        Jonpas, Tim Beswick

    Description:
        Checks if camera can be changed

    Parameter(s):
        0: New Camera View <STRING>
        1: Vehicle <OBJECT>

    Return Value:
        True if camera can be changed <BOOLEAN>
*/
#define VEHICLE_WHITELIST ["UAV", "UAV_01_base_F", "Air"]

params ["_newCameraView", "_cameraOn"];

_newCameraView isNotEqualTo "GUNNER" &&
{_newCameraView isNotEqualTo "GROUP"} &&
{!isNull ACE_player} &&
{player == ACE_player} &&
{alive ACE_player} &&
{ACE_player == _cameraOn || vehicle ACE_player == _cameraOn} &&
{"" isEqualTo (call CBA_fnc_getActiveFeatureCamera)} &&
{_cameraOn isNotEqualTo "UAV" && _cameraOn isNotEqualTo "UAV_01_base_F"} &&
{!(!isNull objectParent ACE_player &&
    {
        ACE_player == driver (vehicle ACE_player) ||
        {(vehicle ACE_player) isKindOf "Air"}
    }
)}

//&& {(VEHICLE_WHITELIST findIf {_cameraOn isKindOf _x}) != -1}
