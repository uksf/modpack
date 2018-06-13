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

params ["_newCameraView", "_cameraOn"];

_newCameraView == "INTERNAL" &&
{!isNull ACE_player} &&
{player == ACE_player} &&
{alive ACE_player} &&
{ACE_player == _cameraOn || vehicle ACE_player == _cameraOn} &&
{!call ace_common_fnc_isFeatureCameraActive} &&
{!(_cameraOn isKindOf "UAV" || _cameraOn isKindOf "UAV_01_base_F" || _cameraOn isKindOf "CUP_CH47F_base")}
