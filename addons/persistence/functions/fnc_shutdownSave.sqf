#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Populates save queue with persistent objects, collects markers, and starts the shutdown saving PFH.
        Calls the callback with [delivery sequence number, callback arguments] once the save is sent.

    Parameter(s):
        0: Callback <CODE>
        1: Callback arguments <ANY>

    Return Value:
        None

    Example:
        [{params ["_seq", "_args"]}, []] call uksf_persistence_fnc_shutdownSave
*/
params ["_callback", ["_callbackArgs", []]];

[GVAR(persistentObjectsHash), {GVAR(saveObjectQueue) pushBack _value}] call CBA_fnc_hashEachPair;

GVAR(persistenceMarkers) = GVAR(persistenceMarkers) - [objNull];
private _markers = +GVAR(persistenceMarkers);
TRACE_1("Starting shutdown save",count _markers);

[_markers, _callback, _callbackArgs] call FUNC(shutdownSavePfh);
