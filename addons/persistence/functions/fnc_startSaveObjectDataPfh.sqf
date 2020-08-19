#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts PFH to save object data over several frames to reduce server load

    Parameter(s):
        None

    Return Value:
        None
*/
GVAR(saveObjectQueueProcessing) = true;

[{
    params ["", "_idPFH"];

    if (GVAR(saveObjectQueue) isEqualTo [] && GVAR(saveObjectMarkersProcessed)) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        call FUNC(finishSaveObjectDataPfh);
    };

    if (diag_fps < 20) exitWith {
        INFO_1("FPS is too low, won't save any objects this frame (%1)",diag_fps);
    };

    INFO_2("Running object data save. %1 remaining. FPS: %2",count GVAR(saveObjectQueue),diag_fps);

    private _object = GVAR(saveObjectQueue) deleteAt 0;

    if !(isNull (attachedTo _object)) exitWith {};

    private _id = _object getVariable [QGVAR(persistenceID), ""];
    if (_id == "") then {
        _id = [_object] call FUNC(markObjectAsPersistent);
    };
    TRACE_1("Object ID",_id);

    private _objects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
    private _index = _objects findIf {_x#0 == _id};
    TRACE_1("Exists?",_index);
    if (_index > -1) then {
        _objects set [_index, [_object] call FUNC(getObjectData)];
        TRACE_1("Updated",_id);
    } else {
        _objects pushBack ([_object] call FUNC(getObjectData));
        TRACE_1("Added",_id);
    };

    GVAR(dataNamespace) setVariable [QGVAR(objects), _objects];
}, 0] call CBA_fnc_addPerFrameHandler;
