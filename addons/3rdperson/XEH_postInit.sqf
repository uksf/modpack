#include "script_component.hpp"

if !(hasInterface) exitWith {};
if (difficultyOption "thirdPersonView" == 0) exitWith {
    WARNING("View Restriction is enabled, but 3rd person is disabled with server difficulty.");
};

[{
    if (inputAction "personView" > 0 && {cameraView == "INTERNAL" && {["EXTERNAL", ACE_player] call FUNC(canChangeCamera)}}) then {
        ACE_player switchCamera "INTERNAL";
    };
}, 0, []] call CBA_fnc_addPerFrameHandler;

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

["turret", {
    params ["", ""];

    private _newCameraView = cameraView;
    private _cameraOn = cameraOn;
    if (!([_newCameraView, _cameraOn] call FUNC(canChangeCamera))) exitWith {};
    _cameraOn switchCamera "INTERNAL";
}, true] call CBA_fnc_addPlayerEventHandler;
