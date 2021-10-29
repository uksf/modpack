#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Eden functionality for safehouse prefab module

    Parameters:
        0: Logic <OBJECT>
        1: Mode <STRING>

    Return value:
        Nothing
*/
params ["_logic", "_mode"];
TRACE_1("",_this);

if !(is3DEN) exitWith {};

private _fnc_getAnchor = {
    params ["_logic"];

    private _size = (_logic get3DENAttribute "Size3")#0;
    private _isRectangle = (_logic get3DENAttribute "isRectangle")#0;

    if (isNil {_size} || isNil {_isRectangle}) exitWith {objNull};

    _size params ["_a", "_b", "_c"];
    private _area = [_a, _b, getDir _logic, _isRectangle, _c];

    ([all3DENEntities#0, _logic, _area] call FUNC(getPrefabAnchor)) params ["_anchorObject"];

    _anchorObject
};

if (_mode == "attributesChanged3DEN" || _mode == "dragged3DEN") exitWith {
    private _initialized = _logic getVariable [QGVAR(initialized), false];
    if (!_initialized) then {
        _logic setVariable [QGVAR(initialized), true];

        private _ehid = missionNamespace getVariable [QGVAR(modulePrefabDrawEHID), -1];
        if (_ehid == -1) then {
            _ehid = addMissionEventHandler ["Draw3D", {[] call FUNC(modulePrefabDraw3d)}];
            missionNamespace setVariable [QGVAR(modulePrefabDrawEHID), _ehid];
        };
    };

    private _anchorObject = [_logic] call _fnc_getAnchor;
    _logic setVariable [QGVAR(anchorObject), _anchorObject];
};

if (_mode == "unregisteredFromWorld3DEN") exitWith {
    private _modules = (all3DENEntities#3) select {typeOf _x == QGVAR(modulePrefabArea) && _x != _logic};
    if (_modules isEqualTo []) then {
        private _ehid = missionNamespace getVariable [QGVAR(modulePrefabDrawEHID), -1];
        if (_ehid == -1) then {
            removeMissionEventHandler ["Draw3D", _ehid];
            missionNamespace setVariable [QGVAR(modulePrefabDrawEHID), -1];
        };
    };
};
