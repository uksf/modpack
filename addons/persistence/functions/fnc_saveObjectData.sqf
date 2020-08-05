#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Saves object data

    Parameter(s):
        0: Centre <OBJECT> (Optional)

    Return Value:
        None
*/
params [["_centre", objnull]];

if (isNull _centre) exitWith {
    GVAR(persistenceMarkers) = GVAR(persistenceMarkers) - [objNull];
    TRACE_1("Found %1 persistence markers",count GVAR(persistenceMarkers));
    private _markers = +GVAR(persistenceMarkers);
    private _marker = _markers deleteAt 0;
    [_marker] call FUNC(saveObjectData); // Ensure queue is running to avoid race condition during shutdown

    [{
        params ["_args", "_idPFH"];
        _args params ["_markers"];

        if (_markers isEqualTo []) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        private _marker = _markers deleteAt 0;
        [_marker] call FUNC(saveObjectData);
    }, 0, [_markers]] call CBA_fnc_addPerFrameHandler;
};

private _terrainObjects = nearestTerrainObjects [_centre, [], CENTRE_RADIUS, false];
private _nearObjects = (_centre nearObjects CENTRE_RADIUS) select {
    private _object = _x;
    [_terrainObjects, {_x == _object}] call EFUNC(common,arrayNone) &&
    {[["Building", "AllVehicles", "Thing"], {_object isKindOf _x}] call EFUNC(common,arrayAny)} &&
    {[["Man", "ThingEffect"], {_object isKindOf _x}] call EFUNC(common,arrayNone)}
};

TRACE_2("Objects around centre",_centre,count _nearObjects);
GVAR(saveObjectQueue) append _nearObjects;

if (!GVAR(saveObjectQueueProcessing) && !(GVAR(saveObjectQueue) isEqualTo [])) then {
    call FUNC(startSaveObjectDataPfh);
};
