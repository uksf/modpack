#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds an event handler to the map of an open map app.
        The launcher removes the handler when the app closes.

    Parameter(s):
        0: Map control passed to the app's open code <CONTROL>
        1: Control event name <STRING>
        2: Handler code <CODE>

    Return Value:
        Nothing

    Example:
        [_map, "Draw", {call uksf_ctab_fnc_routeDraw}] call uksf_ctab_fnc_addMapHandler
*/
params ["_map", "_event", "_code"];

GVAR(mapHandlers) pushBack [_map, _event, _map ctrlAddEventHandler [_event, _code]];
