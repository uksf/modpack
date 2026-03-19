#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Restores saved world state from the persistence session.
        Restores date/time and deserialises map markers.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_persistence_fnc_restoreSessionState
*/

if (!GVAR(overrideSavedDateTime)) then {
    private _dateTime = GVAR(dataNamespace) getVariable [QGVAR(dateTime), date];
    TRACE_1("Setting datetime",_dateTime);
    setDate _dateTime;
} else {
    WARNING("Saved datetime overridden by mission");
};

private _markers = +GVAR(mapMarkers);
GVAR(mapMarkers) = [];
{
    private _marker = [_x] call FUNC(deserializeMarker);
    GVAR(mapMarkers) pushBack ([_marker] call FUNC(serializeMarker));
} forEach _markers;
