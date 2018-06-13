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
#include "script_component.hpp"

#define VEHICLE_WHITELIST ["UAV", "UAV_01_base_F", "Air", "CUP_Ridgback_Base", "CUP_Mastiff_Base", "UK3CB_BAF_FV432_Mk3_Base", "CUP_Wolfhound_Base"]

params ["_newCameraView", "_cameraOn"];

_newCameraView == "EXTERNAL" &&
{!isNull ACE_player} &&
{player == ACE_player} &&
{alive ACE_player} &&
{ACE_player == _cameraOn || vehicle ACE_player == ACE_player} &&
{!call ace_common_fnc_isFeatureCameraActive} //&&
//{!({if (_cameraOn isKindOf _x) exitWith {true}; false} forEach VEHICLE_WHITELIST)}
