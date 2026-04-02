#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds a raw event to the local event buffer.
        Called from provider event handlers on the machine where the event occurred.
        Automatically stamps each event with a UTC timestamp (ISO 8601, millisecond precision).

    Parameters:
        0: Event data <HASHMAP> — must contain a "type" key

    Return Value:
        None

    Example:
        [_event] call uksf_statistics_fnc_addEvent
*/
if (GVAR(killswitch)) exitWith {};

params [["_event", createHashMap, [createHashMap]]];

systemTimeUTC params ["_year", "_month", "_day", "_hour", "_minute", "_second", "_millisecond"];
_event set ["timestamp", format ["%1-%2-%3T%4:%5:%6.%7Z",
    _year,
    [_month, 2] call CBA_fnc_formatNumber,
    [_day, 2] call CBA_fnc_formatNumber,
    [_hour, 2] call CBA_fnc_formatNumber,
    [_minute, 2] call CBA_fnc_formatNumber,
    [_second, 2] call CBA_fnc_formatNumber,
    [_millisecond, 3] call CBA_fnc_formatNumber
]];

GVAR(eventBuffer) pushBack _event;
