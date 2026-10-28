#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Formats a duration in seconds as minutes and seconds, or hours and minutes from 1 hour.

    Parameter(s):
        0: Duration in seconds <NUMBER>

    Return Value:
        Duration text <STRING>

    Example:
        754 call uksf_ctab_fnc_formatDuration
*/
params ["_seconds"];

_seconds = round _seconds;
if (_seconds >= 3600) exitWith {format ["%1 h %2 min", floor (_seconds / 3600), floor ((_seconds mod 3600) / 60)]};
format ["%1 min %2 s", floor (_seconds / 60), _seconds mod 60]
