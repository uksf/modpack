#include "script_component.hpp"

if (!(hasInterface)) exitWith {};
if (difficultyOption "thirdPersonView" == 0) exitWith {
    WARNING("View Restriction is enabled, but 3rd person is disabled with server difficulty.");
};

["cameraView", {
    params ["", "_newCameraView"];

    private _cameraOn = cameraOn;
    if (!([_newCameraView, _cameraOn] call FUNC(canChangeCamera))) exitWith {};
    _cameraOn switchCamera "INTERNAL";
}] call CBA_fnc_addPlayerEventHandler;

["vehicle", {
    params ["", "_cameraOn"];

    private _newCameraView = cameraView;
    if (!([_newCameraView, _cameraOn] call FUNC(canChangeCamera))) exitWith {};
    _cameraOn switchCamera "INTERNAL";
}] call CBA_fnc_addPlayerEventHandler;
