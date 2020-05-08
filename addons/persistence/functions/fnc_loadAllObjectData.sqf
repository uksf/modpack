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

private _allObjects = GVAR(dataNamespace) getVariable [QGVAR(vehicles), []];
if (_allObjects isEqualTo []) then {
    _allObjects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
} else {
    WARNING("Found old data saved with vehicles name whilst loading, loading and removing");
    GVAR(dataNamespace) setVariable [QGVAR(objects), _allObjects];
    GVAR(dataNamespace) setVariable [QGVAR(vehicles), nil];
};
_allObjects = _allObjects select {_x#0 != ""};
INFO_1("Number of objects to load: %1",count _allObjects);

[{
    params ["_args", "_idPFH"];
    _args params ["_allObjects", "_index"];

    if (_index > (count _allObjects)) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _count = ceil ((diag_fps / 10) min 10);
    INFO_3("Running load from %1 for %2 objects. FPS: %3",_index,_count,diag_fps);
    {
        [_x] call FUNC(loadObjectData);
    } forEach (_allObjects select [_index, _count]);

    _args set [1, _index + _count];
}, 0, [_allObjects, 0]] call CBA_fnc_addPerFrameHandler;
