#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Single PFH that processes both persistence markers and the object save queue.
        Each frame: process one marker (producer) then one object (consumer).
        Exits when both markers and queue are empty.

    Parameter(s):
        0: Markers <ARRAY>

    Return Value:
        None
*/
#define TYPE_EXCLUDE_LIST ["UK3CB_BAF_1Rnd_60mm_Mo_Shells_spent","UK3CB_BAF_1Rnd_60mm_Mo_Shells_spent","Helper_Base_F"]

params ["_markers"];

private _processed = createHashMap;

[{
    params ["_args", "_idPFH"];
    _args params ["_markers", "_lastSave", "_processed"];

    // Exit: markers exhausted and queue drained
    if (_markers isEqualTo [] && GVAR(saveObjectQueue) isEqualTo []) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        call FUNC(finishSaveObjectDataPfh);
    };

    // FPS throttle — skip this frame if FPS too low and we saved recently
    if (diag_fps < 20 && _lastSave > CBA_missionTime) exitWith {
        INFO_1("FPS is too low, skipping this frame (%1)",diag_fps);
    };

    _args set [1, CBA_missionTime + 0.5];

    // Process one marker (producer)
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

    // Process one object (consumer)
    if (GVAR(saveObjectQueue) isNotEqualTo []) then {
        INFO_2("Running object data save. %1 remaining. FPS: %2",count GVAR(saveObjectQueue),diag_fps);

        private _object = GVAR(saveObjectQueue) deleteAt 0;
        if !(isNull (attachedTo _object)) exitWith {};
        _processed set [_object, true];

        private _id = _object getVariable [QGVAR(persistenceID), ""];
        if (_id == "") then {
            _id = [_object] call FUNC(markObjectAsPersistent);
        };
        TRACE_1("Object ID",_id);

        private _objects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
        private _index = _objects findIf {_x#IDX_OBJ_ID == _id};
        TRACE_1("Exists?",_index);
        if (_index > -1) then {
            _objects set [_index, [_object] call FUNC(getObjectData)];
            TRACE_1("Updated",_id);
        } else {
            _objects pushBack ([_object] call FUNC(getObjectData));
            TRACE_1("Added",_id);
        };

        GVAR(dataNamespace) setVariable [QGVAR(objects), _objects];
    };
}, 0, [_markers, 0, _processed]] call CBA_fnc_addPerFrameHandler;
