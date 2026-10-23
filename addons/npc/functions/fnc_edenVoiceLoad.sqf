#include "..\script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        attributeLoad for the Eden Voice picker. Fills the list at once, then refills it
        when the extension's first fetch of the website voice list finishes.

    Parameter(s):
        0: Attribute controls group <CONTROL>
        1: Saved voice ID <STRING>

    Return Value:
        Nothing

    Example:
        [_ctrlGroup, "merl"] call uksf_npc_fnc_edenVoiceLoad
*/
params ["_ctrlGroup", ["_value", "", [""]]];

private _combo = _ctrlGroup controlsGroupCtrl 100;
_combo setVariable [QGVAR(voiceValue), _value];
if ([_combo] call FUNC(edenVoiceFill) != "pending") exitWith {};

[_combo] spawn {
    params ["_combo"];
    private _giveUp = diag_tickTime + 12;
    waitUntil {
        uiSleep 0.5;
        isNull _combo || {diag_tickTime > _giveUp} || {[_combo] call FUNC(edenVoiceFill) != "pending"}
    };
};
