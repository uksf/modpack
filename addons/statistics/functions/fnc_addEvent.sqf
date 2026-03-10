#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds a raw event to the local event buffer.
        Called from provider event handlers on the machine where the event occurred.

    Parameters:
        0: Event data <HASHMAP> — must contain a "type" key

    Return Value:
        None

    Example:
        [_event] call uksf_statistics_fnc_addEvent
*/
if (GVAR(killswitch)) exitWith {};

params [["_event", createHashMap, [createHashMap]]];

GVAR(eventBuffer) pushBack _event;
