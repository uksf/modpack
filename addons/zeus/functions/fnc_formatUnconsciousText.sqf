#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Formats unconscious status text for a player, including coma or
        cardiac arrest countdown computed from endpoint timestamps.

    Parameter(s):
        0: Coma end time, or -1 if not in coma <NUMBER>
        1: Cardiac arrest end time, or -1 if not in cardiac arrest <NUMBER>

    Return Value:
        Formatted status text <STRING>

    Example:
        [_comaEnd, _cardiacEnd] call uksf_zeus_fnc_formatUnconsciousText
*/
params ["_comaEndTime", "_cardiacArrestEndTime"];

if (_comaEndTime > -1) exitWith {
    private _comaTimeLeft = round ((_comaEndTime - CBA_missionTime) max 0);
    private _minutes = floor (_comaTimeLeft / 60);
    private _seconds = _comaTimeLeft % 60;
    if (_minutes > 0) then {
        private _secondsText = if (_seconds < 10) then {format ["0%1", _seconds]} else {str _seconds};
        format ["Unconscious (Coma %1m%2s)", _minutes, _secondsText]
    } else {
        format ["Unconscious (Coma %1s)", _seconds]
    }
};

if (_cardiacArrestEndTime > -1) exitWith {
    private _cardiacArrestTimeLeft = round ((_cardiacArrestEndTime - CBA_missionTime) max 0);
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
