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
        Can Change Camera <BOOL>
*/
#define VEHICLE_WHITELIST ["UAV", "UAV_01_base_F", "Air"]

params ["_newCameraView", "_cameraOn"];

_newCameraView isEqualTo "EXTERNAL" &&
{!isNull ACE_player} &&
{player == ACE_player} &&
{alive ACE_player} &&
{ACE_player == _cameraOn || vehicle ACE_player == _cameraOn} &&
{"" isEqualTo call CBA_fnc_getActiveFeatureCamera} &&
{!({if (_cameraOn isKindOf _x) exitWith {true}; false} forEach VEHICLE_WHITELIST)}
