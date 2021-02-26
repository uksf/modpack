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
#define TYPE_EXCLUDE_LIST ["UK3CB_BAF_1Rnd_60mm_Mo_Shells_spent","UK3CB_BAF_1Rnd_60mm_Mo_Shells_spent","Helper_Base_F"]

params [["_centre", objNull]];

// Reset this to true. Will be set to false if markers need processing, before it can be read by the saving queue pfh exit
GVAR(saveObjectMarkersProcessed) = true;

if (isNull _centre) exitWith {
    // Add already persistent marked objects to saving queue
    [GVAR(persistentObjectsHash), {GVAR(saveObjectQueue) pushBack _value}] call CBA_fnc_hashEachPair;

    if (!GVAR(saveObjectQueueProcessing)) then {
        call FUNC(startSaveObjectDataPfh);
    };

    GVAR(persistenceMarkers) = GVAR(persistenceMarkers) - [objNull];
    private _markers = +GVAR(persistenceMarkers);
    if (_markers isNotEqualTo []) then {
        TRACE_1("Found persistence markers",count _markers);
        GVAR(saveObjectMarkersProcessed) = false;
        private _marker = _markers deleteAt 0;
        [_marker] call FUNC(saveObjectData); // Ensure queue is running to avoid race condition during shutdown

        [{
            params ["_args", "_idPFH"];
            _args params ["_markers"];

            if (_markers isEqualTo []) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
                GVAR(saveObjectMarkersProcessed) = true;
            };

            private _marker = _markers deleteAt 0;
            [_marker] call FUNC(saveObjectData);
            GVAR(saveObjectMarkersProcessed) = false;
        }, 0, [_markers]] call CBA_fnc_addPerFrameHandler;
    };
};

private _terrainObjects = nearestTerrainObjects [_centre, [], CENTRE_RADIUS, false];
private _nearObjects = (_centre nearObjects CENTRE_RADIUS) select {
    private _object = _x;
    !(_object in GVAR(saveObjectQueue)) &&
    {[_terrainObjects, {_x == _object}] call EFUNC(common,arrayNone)} &&
    {[["Building", "AllVehicles", "Thing"], {_object isKindOf _x}] call EFUNC(common,arrayAny)} &&
    {[["Man", "ThingEffect"], {_object isKindOf _x}] call EFUNC(common,arrayNone)} &&
    {[TYPE_EXCLUDE_LIST, {_object isKindOf _x}] call EFUNC(common,arrayNone)}
};

TRACE_2("Objects around centre",_centre,count _nearObjects);
GVAR(saveObjectQueue) append _nearObjects;

if (!GVAR(saveObjectQueueProcessing) && (GVAR(saveObjectQueue) isNotEqualTo [])) then {
    call FUNC(startSaveObjectDataPfh);
};
