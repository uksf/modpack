#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles a client event report on the server. Appends received events
        into the server buffer for later API delivery.

    Parameters:
        0: Events <ARRAY> — array of event hashmaps (each containing uid and name)

    Return Value:
        None
*/
if (GVAR(killswitch)) exitWith {};

params [["_events", [], [[]]]];

if (_events isEqualTo []) exitWith {};

GVAR(serverBuffer) append _events;
