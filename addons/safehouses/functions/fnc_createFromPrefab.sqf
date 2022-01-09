#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates safehouse from prefab
        If an anchor center is given, spawn the prefab around that object and use it as the anchor

    Parameters:
        0: Location ID <STRING>
        1: Location logic <OBJECT>
        2: Prefab data <ARRAY>
        3: Anchor object (Optional) <OBJECT>

    Return value:
        Nothing
*/
params ["_id", "_logic", "_prefab", ["_anchorObject", objNull]];
_prefab params ["_prefabId", "_centre", "_area", "_anchorObjectData", "_objectData"];
_area params ["_a", "_b", "_angle", "_isRectangle", "_c"];

if !(isServer) exitWith {};

private _position = getPos _logic;
_position set [2, _centre#2];
_logic setPos _position;

if !(isNull _anchorObject) then {
    _anchorObjectData params ["_anchorObjectPlacement"];
    _anchorObjectPlacement params ["", "", "", "_prefabAnchorDir"];

    private _anchorDir = getDir _anchorObject;
    _angle = _angle + (_prefabAnchorDir - _anchorDir);
};

private _radius = ((_a ^ 2) + (_b ^ 2)) ^ 0.5;
private _terrainObjects = nearestTerrainObjects [_position, [], _radius, true];
_terrainObjects = _terrainObjects inAreaArray [_position, _a, _b, _angle, _isRectangle, _c];
if !(isNull _anchorObject) then {
    _terrainObjects deleteAt (_terrainObjects find _anchorObject);
};
{hideObjectGlobal _x} forEach _terrainObjects;

if (isNull _anchorObject) then {
    // No anchor given, create prefab around logic
    _anchorObject = [_logic, _anchorObjectData] call FUNC(createObject);
};

[_anchorObject, _anchorObjectData] call FUNC(applyObjectData);

_anchorObject allowDamage true;
_anchorObject enableSimulationGlobal true;
_anchorObject setVariable [QGVAR(id), _id];
_anchorObject setVariable [QGVAR(prefabId), _prefabId];
_anchorObject addMPEventHandler ["MPKilled", {call FUNC(destroy)}];

_logic setVariable [QGVAR(anchor), _anchorObject];

GVAR(locations) set [_id, [_id, _prefabId, _position]];

[{
    params ["_args", "_idPFH"];
    _args params ["_anchorObject", "_objectDataArray", "_objects", "_count", "_index", "_lastLoad"];

    if (_index >= _count) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        _anchorObject setVariable [QGVAR(objects), _objects];
    };

    if (diag_fps < 20 && _lastLoad > CBA_missionTime) exitWith {
        // DEBUG_1("FPS is too low, won't create any objects this frame (%1)",diag_fps);
    };

    DEBUG_3("Running create for %1/%2. FPS: %3",_index + 1,_count,diag_fps);
    private _objectData = _objectDataArray#_index;
    private _object = [_anchorObject, _objectData] call FUNC(createObject);
    [_object, _objectData] call FUNC(applyObjectData);
    [_object] call FUNC(fixObjectHeights);
    _objects pushBack _object;

    _args set [4, _index + 1];
    _args set [5, CBA_missionTime + 0.1];
}, 0, [_anchorObject, _objectData, [], count _objectData, 0, 0]] call CBA_fnc_addPerFrameHandler;


