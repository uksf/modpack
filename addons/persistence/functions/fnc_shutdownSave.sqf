#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Populates save queue with persistent objects, collects markers, and starts the shutdown saving PFH.
        Single entry point for shutdown object saving - replaces the dual-PFH approach in saveObjectData.

    Parameter(s):
        None

    Return Value:
        None
*/

// Add already persistent marked objects to saving queue
[GVAR(persistentObjectsHash), {GVAR(saveObjectQueue) pushBack _value}] call CBA_fnc_hashEachPair;

GVAR(persistenceMarkers) = GVAR(persistenceMarkers) - [objNull];
private _markers = +GVAR(persistenceMarkers);
TRACE_1("Starting shutdown save",count _markers);

[_markers] call FUNC(shutdownSavePfh);
