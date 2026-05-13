#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Opens the uncon dialog, gated on Zeus / main-menu / RC state. Defers via retry PFH if gated.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_medical_fnc_openDialog
*/

if (!isNull findDisplay IDD_UNCON) exitWith {};
if (isRemoteControlling player) exitWith {};

if (!isNull findDisplay 312 || {!isNull findDisplay 49}) exitWith {
    [{
        params ["_args", "_idPFH"];

        if (!alive ACE_player || {!(ACE_player getVariable ["ACE_isUnconscious", false])}) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        if (isNull findDisplay 312 && {isNull findDisplay 49} && {!isRemoteControlling player}) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
            [] call FUNC(openDialog);
        };
    }, 1, []] call CBA_fnc_addPerFrameHandler;
};

GVAR(viewMode) = GVAR(viewModeDefault);

createDialog "uksf_medical_uncon";
