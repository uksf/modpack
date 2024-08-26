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
#define MAX_ABORTED_RETRIES 3

params [["_objects", []], ["_retry", 0]];

if (_retry >= MAX_ABORTED_RETRIES) exitWith {
    INFO_1("Max retries reached with %1 aborted objects left unloaded",count _objects);
    {
        _x set [18, true];
    } forEach _objects;
    [QGVAR(loadingFinished), []] call CBA_fnc_localEvent;
};

if (_objects isEqualTo []) then {
    _objects = GVAR(dataNamespace) getVariable [QGVAR(objects), []];
    INFO_1("Number of objects loaded from namespace: %1",count _objects);
    _objects = _objects select {!(isNil {_x#0}) && {_x#0 != ""}};
    INFO_1("Number of objects to load: %1",count _objects);
};

if (_objects isEqualTo []) exitWith {
    [QGVAR(loadingFinished), []] call CBA_fnc_localEvent;
};

private _count = count _objects;
_objects = _objects apply {[(_x#2)#2, _x]};
_objects sort true;
_objects = _objects apply {_x#1};
INFO_4("Objects sorted by ASL height, lowest: %1 at %2, highest: %3 at %4",(_objects#0)#0,(_objects#0)#2,(_objects#(_count - 1))#0,(_objects#(_count - 1))#2);

[{
    params ["_args", "_idPFH"];
    _args params ["_objects", "_count", "_index", "_lastLoad", "_retry"];

    if (_index >= _count) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        publicVariable QGVAR(abortedObjectIds);

        if (GVAR(abortedObjectIds) isNotEqualTo []) then {
            private _abortedObjects = ((GVAR(dataNamespace) getVariable [QGVAR(objects), []]) select {_x#0 in GVAR(abortedObjectIds)});
            if (_abortedObjects isEqualTo []) exitWith {
                [QGVAR(loadingFinished), []] call CBA_fnc_localEvent;
            };

            INFO_1("Retrying %1 aborted objects in 5 seconds",count _abortedObjects);
            [{call FUNC(loadAllObjectData)}, [_abortedObjects, _retry + 1], 5] call CBA_fnc_waitAndExecute;
        } else {
            [QGVAR(loadingFinished), []] call CBA_fnc_localEvent;
        };
    };

    if (diag_fps < 20 && _lastLoad > CBA_missionTime) exitWith {
        INFO_1("FPS is too low, won't load any objects this frame (%1)",diag_fps);
    };

    INFO_3("Running load for %1/%2. FPS: %3",_index + 1,_count,diag_fps);
    [_objects#_index] call FUNC(loadObjectData);

    _args set [2, _index + 1];
    _args set [3, CBA_missionTime + 0.5];
}, 0, [_objects, _count, 0, 0, _retry]] call CBA_fnc_addPerFrameHandler;
