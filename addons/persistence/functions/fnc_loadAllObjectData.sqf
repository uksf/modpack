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

private _allObjects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
INFO_1("Number of objects loaded from namespace: %1",count _allObjects);
_allObjects = _allObjects select {!(isNil {_x#0}) && {_x#0 != ""}};
INFO_1("Number of objects to load: %1",count _allObjects);

_allObjects = _allObjects apply {[(_x#2)#2, _x]};
_allObjects sort true;
_allObjects = _allObjects apply {_x#1};
INFO_4("Objects sorted by ASL height, lowest: %1 at %2, highest: %3 at %4",(_allObjects#0)#0,(_allObjects#0)#2,(_allObjects#(count _allObjects - 1))#0,(_allObjects#(count _allObjects - 1))#2);

[{
    params ["_args", "_idPFH"];
    _args params ["_allObjects", "_index"];

    if (_index >= (count _allObjects)) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        publicVariable QGVAR(dontDeleteObjectIds);
    };

    if (diag_fps < 20) exitWith {
        INFO_1("FPS is too low, won't load any objects this frame (%1)",diag_fps);
    };

    INFO_3("Running load for %1/%2. FPS: %3",_index + 1,count _allObjects,diag_fps);
    [_allObjects#_index] call FUNC(loadObjectData);

    _args set [1, _index + 1];
}, 0, [_allObjects, 0]] call CBA_fnc_addPerFrameHandler;
