#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Spectator PFH body. Finds nearest non-uncon ally on player's side, attaches camera to neck.

    Parameter(s):
        Standard PFH args: [_args, _idPFH]

    Return Value:
        None

    Example:
        Registered via openDialogOnLoad
*/
params ["_args", "_idPFH"];

private _display = findDisplay IDD_UNCON;
if (isNull _display) exitWith {
    [_idPFH] call CBA_fnc_removePerFrameHandler;
    GVAR(activeSpectatorPFH) = -1;
};

if (GVAR(interfaceHidden)) exitWith {};

private _specTextCtrl = _display displayCtrl IDC_SPEC_TEXT;
private _maxDistance = GVAR(spectatorDistance);

private _candidates = (allPlayers - entities "HeadlessClient_F") select {
    side _x == side group ACE_player &&
    {alive _x} &&
    {_x != ACE_player} &&
    {!(_x getVariable ["ACE_isUnconscious", false])}
};

if (_candidates isEqualTo []) exitWith {
    _specTextCtrl ctrlSetText "No conscious allies nearby";
    [] call FUNC(spectatorCleanup);
};

_candidates = _candidates apply { [_x distance ACE_player, _x] };
_candidates sort true;

(_candidates # 0) params ["_distance", "_nearestAlly"];

if (_distance > _maxDistance) exitWith {
    _specTextCtrl ctrlSetText "Nearest ally too far";
    [] call FUNC(spectatorCleanup);
};

_specTextCtrl ctrlSetText format ["Nearest: %1 (%2m)", name _nearestAlly, round _distance];

if (_nearestAlly == GVAR(spectatorSelectedAlly) && {!isNull GVAR(spectatorCam)}) exitWith {};

if (!isNull GVAR(spectatorCam)) then {
    detach GVAR(spectatorCam);
    detach GVAR(spectatorTarget);
} else {
    GVAR(spectatorTarget) = "Sign_Sphere100cm_F" createVehicleLocal [0, 0, 0];
    hideObject GVAR(spectatorTarget);
    GVAR(spectatorCam) = "camera" camCreate (getPos ACE_player);
    GVAR(spectatorCam) cameraEffect ["internal", "back", "uksf_medical_rtt"];
};

GVAR(spectatorSelectedAlly) = _nearestAlly;
GVAR(spectatorTarget) attachTo [_nearestAlly, [0, 10, 0.05], "neck"];
GVAR(spectatorCam) attachTo [_nearestAlly, [0, 0.25, 0.05], "neck"];
GVAR(spectatorCam) camSetTarget GVAR(spectatorTarget);
GVAR(spectatorCam) camCommit 0;

private _nvgMode = switch (GVAR(spectatorNVGMode)) do {
    case 1: { currentVisionMode _nearestAlly };
    default { 0 };
};
"uksf_medical_rtt" setPiPEffect [_nvgMode];
