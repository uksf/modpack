#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Loads all saved object data over a number of frames to ease loading

    Parameter(s):
        None

    Return Value:
        None
*/
params [["_objects", []]];

if (_objects isEqualTo []) then {
    _objects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
    INFO_1("Number of objects loaded from namespace: %1",count _objects);
    _objects = _objects select {!(isNil {_x#0}) && {_x#0 != ""}};
    INFO_1("Number of objects to load: %1",count _objects);
};

_objects = _objects apply {[(_x#2)#2, _x]};
_objects sort true;
_objects = _objects apply {_x#1};
INFO_4("Objects sorted by ASL height, lowest: %1 at %2, highest: %3 at %4",(_objects#0)#0,(_objects#0)#2,(_objects#(count _objects - 1))#0,(_objects#(count _objects - 1))#2);

[{
    params ["_args", "_idPFH"];
    _args params ["_objects", "_index"];

    if (_index >= (count _objects)) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        publicVariable QGVAR(dontDeleteObjectIds);

        if !(GVAR(dontDeleteObjectIds) isEqualTo []) then {
            private _abortedObjects = (GVAR(dataNamespace) getVariable [QGVAR(objects), []]) select {_x#0 in GVAR(dontDeleteObjectIds)};
            INFO_1("Retrying aborted objects: %1",count _abortedObjects);
            [_abortedObjects] call FUNC(loadAllObjectData);
        };
    };

    if (diag_fps < 20) exitWith {
        INFO_1("FPS is too low, won't load any objects this frame (%1)",diag_fps);
    };

    INFO_3("Running load for %1/%2. FPS: %3",_index + 1,count _objects,diag_fps);
    [_objects#_index] call FUNC(loadObjectData);

    _args set [1, _index + 1];
}, 0, [_objects, 0]] call CBA_fnc_addPerFrameHandler;
