#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Client sync tick. Sends buffered events to the server if the buffer is non-empty.
        Runs as a PFH every 30 seconds.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_statistics_fnc_clientSync
*/
if (GVAR(killswitch)) exitWith {};

// Flush confirmed explosive placements into the event buffer before sync
call FUNC(explosivesSync);

// Flush accumulated distance and fuel into the event buffer before sync
call FUNC(samplerSync);

if (GVAR(eventBuffer) isEqualTo []) exitWith {};

private _uid = getPlayerUID player;
private _events = GVAR(eventBuffer);
GVAR(eventBuffer) = [];
GVAR(processedShotIds) = createHashMap;

// Inject uid into each event
{_x set ["uid", _uid]} forEach _events;

[QGVAR(clientReport), [_events]] call CBA_fnc_serverEvent;
