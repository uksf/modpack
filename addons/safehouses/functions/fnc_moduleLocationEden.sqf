#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Eden functionality for safehouse location module

    Parameters:
        0: Logic <OBJECT>
        1: Mode <STRING>

    Return value:
        Nothing
*/
params ["_logic", "_mode"];
TRACE_1("",_this);

if !(is3DEN) exitWith {};

private _fnc_getBuilding = {
    params ["_logic"];

    private _buildings = [all3DENEntities#0, getPos _logic] call FUNC(getLocationBuildings);
    if (_buildings isEqualTo []) exitWith {objNull};

    _buildings#0
};

if (_mode == "attributesChanged3DEN" || _mode == "dragged3DEN") exitWith {
    private _initialized = _logic getVariable [QGVAR(initialized), false];
    if (!_initialized) then {
        _logic setVariable [QGVAR(initialized), true];

        private _ehid = missionNamespace getVariable [QGVAR(moduleLocationDrawEHID), -1];
        if (_ehid == -1) then {
            _ehid = addMissionEventHandler ["Draw3D", {[] call FUNC(moduleLocationDraw3d)}];
            missionNamespace setVariable [QGVAR(moduleLocationDrawEHID), _ehid];
        };
    };

    private _building = [_logic] call _fnc_getBuilding;
    _logic setVariable [QGVAR(building), _building];

    if (isNull _building || _mode == "dragged3DEN") exitWith {};

    private _position = getPos _building;
    _position set [2, 0];
    _logic set3DENAttribute ["position", _position];
};

if (_mode == "unregisteredFromWorld3DEN") exitWith {
    private _modules = (all3DENEntities#3) select {typeOf _x == QGVAR(moduleLocation) && _x != _logic};
    if (_modules isEqualTo []) then {
        private _ehid = missionNamespace getVariable [QGVAR(moduleLocationDrawEHID), -1];
        if (_ehid == -1) then {
            removeMissionEventHandler ["Draw3D", _ehid];
            missionNamespace setVariable [QGVAR(moduleLocationDrawEHID), -1];
        };
    };
};
