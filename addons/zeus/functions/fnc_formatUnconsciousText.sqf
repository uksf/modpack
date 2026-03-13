#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Formats unconscious status text for a player, including coma or cardiac arrest countdown.

    Parameter(s):
        0: Player <OBJECT>

    Return Value:
        Formatted status text <STRING>

    Example:
        [_player] call uksf_zeus_fnc_formatUnconsciousText
*/
params ["_player"];

private _comaTimeLeft = round (_player getVariable ["ace_medical_statemachine_comaTimeLeft", -1]);
if (_comaTimeLeft > -1) exitWith {
    private _minutes = floor (_comaTimeLeft / 60);
    private _seconds = _comaTimeLeft % 60;
    if (_minutes > 0) then {
        private _secondsText = if (_seconds < 10) then {format ["0%1", _seconds]} else {str _seconds};
        format ["Unconscious (Coma %1m%2s)", _minutes, _secondsText]
    } else {
        format ["Unconscious (Coma %1s)", _seconds]
    }
};

private _cardiacArrestTimeLeft = round (_player getVariable ["ace_medical_statemachine_cardiacArrestTimeLeft", -1]);
if (_cardiacArrestTimeLeft > -1) exitWith {
    private _minutes = floor (_cardiacArrestTimeLeft / 60);
    private _seconds = _cardiacArrestTimeLeft % 60;
    if (_minutes > 0) then {
        private _secondsText = if (_seconds < 10) then {format ["0%1", _seconds]} else {str _seconds};
        format ["Unconscious (CA %1m%2s)", _minutes, _secondsText]
    } else {
        format ["Unconscious (CA %1s)", _seconds]
    }
};

"Unconscious"
