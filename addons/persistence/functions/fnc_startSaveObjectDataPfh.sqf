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

    if (GVAR(saveObjectQueue) isEqualTo []) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        GVAR(saveObjectQueueProcessing) = false;
    };

    INFO_3("Running save. %1 remaining. FPS: %2",count _allObjects,diag_fps);

    (GVAR(saveObjectQueue) deleteAt 0) params ["_object", "_skip"];

    if (isNull (attachedTo _object)) then {
        private _id = _object getVariable [QGVAR(persistenceID), ""];
        if (_id == "") then {
            _id = [_object] call FUNC(markObjectAsPersistent);
        };
        TRACE_1("Object ID",_id);

        if (!_skip) then {
            private _index = _objects findIf {_x#0 == _id};
            TRACE_1("Exists?",_index);
            if (_index > -1) then {
                _objects set [_index, [_object] call FUNC(getObjectData)];
                TRACE_1("Updated",_id);
            } else {
                _objects pushBack ([_object] call FUNC(getObjectData));
                TRACE_1("Added",_id);
            };
        };
    };
}, 0] call CBA_fnc_addPerFrameHandler;
