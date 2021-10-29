#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialise safehouse locations

    Parameters:
        None

    Return value:
        Nothing
*/

if !(isServer) exitWith {};
if (GVAR(locationModules) isEqualTo []) exitWith {
    INFO("No location modules found");
};

[{
    params ["_args", "_idPFH"];
    _args params ["_count", "_index"];

    if (_index >= _count) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _location = GVAR(locationModules)#_index;
    _location params ["_id", "_logic", "_prefabId"];
    DEBUG_4("Running location init for %1/%2 (ID: %3). FPS: %4",_index + 1,_count,_id,diag_fps);

    private _selection = [getPos _logic, _prefabId] call FUNC(selectPrefabForLocation);
    _selection params ["_prefab", "_anchorObject"];
    TRACE_2("",_prefab,_anchorObject);

    [_id, _logic, _prefab, _anchorObject] call FUNC(createFromPrefab);

    _args set [1, _index + 1];
}, 1, [count GVAR(locationModules), 0]] call CBA_fnc_addPerFrameHandler;
