#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Single PFH that processes both persistence markers and the object save queue.
        Each frame processes markers and objects until the frame budget is used.
        Finishes when both markers and queue are empty, or sends a partial save when
        the capture cap is reached. Calls the callback with
        [delivery sequence number, callback arguments, partial save].

    Parameter(s):
        0: Markers <ARRAY>
        1: Callback <CODE>
        2: Callback arguments <ANY>

    Return Value:
        None

    Example:
        [_markers, {params ["_seq", "_args", "_partial"]}, []] call uksf_persistence_fnc_shutdownSavePfh
*/
#define TYPE_EXCLUDE_LIST ["UK3CB_BAF_1Rnd_60mm_Mo_Shells_spent","UK3CB_BAF_1Rnd_81mm_Mo_Shells_spent","tbd_mortars_105mm_casing_spent","Helper_Base_F"]
#define FRAME_BUDGET 0.003
#define CAPTURE_CAP 60

params ["_markers", "_callback", "_callbackArgs"];

INFO_2("Shutdown save capture started: %1 markers, %2 objects",count _markers,count GVAR(saveObjectQueue));

[{
    params ["_args", "_idPFH"];
    _args params ["_markers", "_processed", "_startedAt", "_callback", "_callbackArgs"];

    private _frameStart = diag_tickTime;
    private _capReached = _frameStart - _startedAt > CAPTURE_CAP;
    while {!_capReached && {_markers isNotEqualTo [] || {GVAR(saveObjectQueue) isNotEqualTo []}} && {diag_tickTime - _frameStart < FRAME_BUDGET}} do {
        if (_markers isNotEqualTo []) then {
            private _marker = _markers deleteAt 0;
            if (!isNull _marker) then {
                private _terrainObjects = nearestTerrainObjects [_marker, [], CENTRE_RADIUS, false];
                private _nearObjects = (_marker nearObjects CENTRE_RADIUS) select {
                    private _object = _x;
                    !(_object in GVAR(saveObjectQueue)) && !(_object in _processed) &&
                    !(_object getVariable [QGVAR(excluded), false]) &&
                    {[_terrainObjects, {_x == _object}] call EFUNC(common,arrayNone)} &&
                    {[["Building", "AllVehicles", "Thing"], {_object isKindOf _x}] call EFUNC(common,arrayAny)} &&
                    {[["Man", "ThingEffect"], {_object isKindOf _x}] call EFUNC(common,arrayNone)} &&
                    {[TYPE_EXCLUDE_LIST, {_object isKindOf _x}] call EFUNC(common,arrayNone)}
                };
                TRACE_2("Objects around marker",_marker,count _nearObjects);
                GVAR(saveObjectQueue) append _nearObjects;
            };
        };

        if (GVAR(saveObjectQueue) isNotEqualTo []) then {
            private _object = GVAR(saveObjectQueue) deleteAt 0;
            if (isNull (attachedTo _object)) then {
                _processed pushBack _object;

                private _id = _object getVariable [QGVAR(persistenceID), ""];
                if (_id == "") then {
                    _id = [_object] call FUNC(markObjectAsPersistent);
                };

                private _objects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
                private _index = _objects findIf {_x#IDX_OBJ_ID == _id};
                if (_index > -1) then {
                    _objects set [_index, [_object] call FUNC(getObjectData)];
                } else {
                    _objects pushBack ([_object] call FUNC(getObjectData));
                };
                GVAR(dataNamespace) setVariable [QGVAR(objects), _objects];
            };
        };
    };

    if (!_capReached && {_markers isNotEqualTo [] || {GVAR(saveObjectQueue) isNotEqualTo []}}) exitWith {};

    [_idPFH] call CBA_fnc_removePerFrameHandler;
    if (_capReached) then {
        WARNING_3("Shutdown save capture cap of %1 s reached: %2 objects and %3 markers not captured, sending partial save",CAPTURE_CAP,count GVAR(saveObjectQueue),count _markers);
        GVAR(saveObjectQueue) = [];
    };
    INFO_2("Shutdown save capture finished in %1 s: %2 objects captured",diag_tickTime - _startedAt,count _processed);

    private _seq = [_capReached] call FUNC(finishSaveObjectDataPfh);
    [_seq, _callbackArgs, _capReached] call _callback;
}, 0, [_markers, [], diag_tickTime, _callback, _callbackArgs]] call CBA_fnc_addPerFrameHandler;
