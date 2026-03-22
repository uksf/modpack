#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Register AI Commander objective debug provider with Zeus.

    Parameters:
        None

    Return Value:
        None
*/

private _key = QGVAR(debug);
private _menuName = "AI Commander";
private _menuPriority = -25;
private _fnc_menuCondition = {GVAR(enabled)};

private _fnc_serverGetter = {
    GVAR(objectives) = GVAR(objectives) select {!isNull _x};

    private _objectiveData = GVAR(objectives) apply {
        private _position2D = getPosATL _x;
        private _ownerSide = _x getVariable [QGVAR(ownerSide), sideUnknown];
        private _colour = [_ownerSide] call FUNC(getSideColour);
        private _state = _x getVariable [QGVAR(currentState), "not_owned"];
        private _priority = _x getVariable [QGVAR(priority), 5];
        private _forcePoolCurrent = _x getVariable [QGVAR(forcePoolGroups), 0];
        private _forcePoolStart = _x getVariable [QGVAR(forcePoolStartGroups), _forcePoolCurrent];
        private _objectiveName = _x getVariable [QGVAR(objectiveName), "OBJ"];

        [_position2D, _objectiveName, _state, _priority, _forcePoolCurrent, _forcePoolStart, _colour]
    };

    [_objectiveData]
};

private _fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance"];
    private _objectiveData = _data#0;

    {
        _x params ["_position2D", "_objectiveName", "_state", "_priority", "_forcePoolCurrent", "_forcePoolStart", "_colour"];

        if (_cameraPosition distance2D _position2D <= _maxDistance) then {
            private _positionAGL = ASLToAGL [_position2D#0, _position2D#1, (getTerrainHeightASL _position2D) + 0.25];
            drawIcon3D ["\a3\ui_f\data\map\markers\military\objective_ca.paa", _colour, _positionAGL, 0.7, 0.7, 0, _objectiveName, 1, 0.024, "TahomaB", "center"];
            drawIcon3D ["", _colour, _positionAGL, 0, 0, 0, format ["State: %1  Priority: %2", _state, _priority], 1, 0.02, "TahomaB", "center", false, 0, DEBUG_ICON_SPACING];
            drawIcon3D ["", _colour, _positionAGL, 0, 0, 0, format ["Pool: %1/%2", _forcePoolCurrent, _forcePoolStart], 1, 0.02, "TahomaB", "center", false, 0, DEBUG_ICON_SPACING * 2];
        };
    } forEach _objectiveData;
};

private _fnc_drawMap = {
    params ["_data", "_map"];
    private _objectiveData = _data#0;

    {
        _x params ["_position2D", "_objectiveName", "_state", "_priority", "_forcePoolCurrent", "_forcePoolStart", "_colour"];

        _map drawIcon ["\a3\ui_f\data\map\markers\military\objective_ca.paa", _colour, _position2D, 20, 20, 0, format ["%1 | %2 | P%3 | %4/%5", _objectiveName, _state, _priority, _forcePoolCurrent, _forcePoolStart], 1, 0.032, "TahomaB", "right"];
    } forEach _objectiveData;
};

[QEGVAR(zeus,registerDebugAction), [_key, _menuName, _menuPriority, _fnc_menuCondition]] call CBA_fnc_localEvent;
[QEGVAR(zeus,registerDebugServerGetter), [_key, _fnc_serverGetter]] call CBA_fnc_localEvent;
[QEGVAR(zeus,registerDebugDraw), [_key, _fnc_draw3d, _fnc_drawMap]] call CBA_fnc_localEvent;
