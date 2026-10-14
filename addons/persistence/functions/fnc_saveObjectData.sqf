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

    Example:
        [_centre] call uksf_persistence_fnc_saveObjectData
*/
#define TYPE_EXCLUDE_LIST ["UK3CB_BAF_1Rnd_60mm_Mo_Shells_spent","UK3CB_BAF_1Rnd_81mm_Mo_Shells_spent","tbd_mortars_105mm_casing_spent","Helper_Base_F"]

params [["_centre", objNull]];

GVAR(saveObjectMarkersProcessed) = true;

if (isNull _centre) exitWith {
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
        [_marker] call FUNC(saveObjectData);

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
    {[_object] call FUNC(isPersistable)} &&
    {[_terrainObjects, {_x == _object}] call EFUNC(common,arrayNone)} &&
    {[["Building", "AllVehicles", "Thing"], {_object isKindOf _x}] call EFUNC(common,arrayAny)} &&
    {[["Man", "ThingEffect"], {_object isKindOf _x}] call EFUNC(common,arrayNone)} &&
    {[TYPE_EXCLUDE_LIST, {_object isKindOf _x}] call EFUNC(common,arrayNone)}
};

TRACE_2("Objects around centre",_centre,count _nearObjects);
GVAR(saveObjectQueue) append _nearObjects;

if (!GVAR(saveObjectQueueProcessing)) then {
    if (GVAR(saveObjectQueue) isNotEqualTo []) then {
        call FUNC(startSaveObjectDataPfh);
    } else {
        call FUNC(saveData);
    };
};
