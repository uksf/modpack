#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers dynamic patrols debug provider with Zeus

    Parameter(s):
        None

    Return Value:
        None
*/

private _key = QGVAR(dynamicPatrols);
private _menuName = "Dynamic Patrols";
private _menuPriority = -40;
private _fnc_menuCondition = {GVAR(dynamicPatrolAreasEnabled)};

private _fnc_serverGetter = {
    private _areas = GVAR(dynamicPatrolAreas) apply {
        _x params ["_logic", "_area"];
        private _position = getPosATL _logic;
        private _groups = _logic getVariable [QGVAR(groups), []];
        private _groupCount = {!isNull _x} count _groups;
        private _groupLimit = _logic getVariable [QGVAR(groupLimit), 0];
        private _distance = _logic getVariable [QGVAR(distance), 500];
        private _sideIndex = _logic getVariable [QGVAR(side), 0];
        private _side = [east, independent, west] param [_sideIndex, east];

        [_position, _area, _groupCount, _groupLimit, _distance, _side]
    };

    private _excludeAreas = GVAR(dynamicPatrolExcludeAreas) apply {
        _x params ["_logic", "_area"];
        [getPosATL _logic, _area]
    };

    private _includeAreas = GVAR(dynamicPatrolIncludeAreas) apply {
        _x params ["_logic", "_area"];
        [getPosATL _logic, _area]
    };

    [_areas, _excludeAreas, _includeAreas]
};

private _fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance"];
    _data params ["_areas", "_excludeAreas", "_includeAreas"];

    // Patrol areas
    {
        _x params ["_position", "_area", "_groupCount", "_groupLimit", "_distance", "_side"];
        if (_cameraPosition distance2D _position < _maxDistance) then {
            private _colour = switch (_side) do {
                case west: { [0.3,0.5,1,1] };
                case east: { [1,0,0,1] };
                case independent: { [0,1,0,1] };
                default { [0.8,0.3,1,1] };
            };
            drawIcon3D ["\a3\ui_f\data\map\markers\military\circle_ca.paa", _colour, ASLToAGL (ATLToASL _position), 0.5, 0.5, 0, format ["Patrol: %1/%2", _groupCount, _groupLimit], 1, 0.025, "TahomaB", "center"];
        };
    } forEach _areas;

    // Exclusion zones
    {
        _x params ["_position", "_area"];
        if (_cameraPosition distance2D _position < _maxDistance) then {
            drawIcon3D ["\a3\ui_f\data\map\markers\military\circle_ca.paa", [1,0,0,1], ASLToAGL (ATLToASL _position), 0.5, 0.5, 0, "Exclude", 1, 0.02, "TahomaB", "center"];
        };
    } forEach _excludeAreas;

    // Inclusion zones
    {
        _x params ["_position", "_area"];
        if (_cameraPosition distance2D _position < _maxDistance) then {
            drawIcon3D ["\a3\ui_f\data\map\markers\military\circle_ca.paa", [0,1,0,1], ASLToAGL (ATLToASL _position), 0.5, 0.5, 0, "Include", 1, 0.02, "TahomaB", "center"];
        };
    } forEach _includeAreas;
};

private _fnc_drawMap = {
    params ["_data", "_map"];
    _data params ["_areas", "_excludeAreas", "_includeAreas"];

    // Patrol areas
    {
        _x params ["_position", "_area", "_groupCount", "_groupLimit", "_distance", "_side"];
        private _colour = switch (_side) do {
            case west: { [0.3,0.5,1,1] };
            case east: { [1,0,0,1] };
            case independent: { [0,1,0,1] };
            default { [0.8,0.3,1,1] };
        };
        _map drawIcon ["\a3\ui_f\data\map\markers\military\circle_ca.paa", _colour, _position, 24, 24, 0, format ["Patrol: %1/%2", _groupCount, _groupLimit], 1, 0.04, "TahomaB", "right"];
        _area params ["_halfWidth", "_halfHeight", "_angle", "_isRectangle"];
        private _outlineColour = _colour select [0, 3];
        _outlineColour pushBack 0.5;
        if (_isRectangle) then {
            _map drawRectangle [_position, _halfWidth, _halfHeight, _angle, _outlineColour, "#(argb,8,8,3)color(1,1,1,0.1)"];
        } else {
            _map drawEllipse [_position, _halfWidth, _halfHeight, _angle, _outlineColour, "#(argb,8,8,3)color(1,1,1,0.1)"];
        };
    } forEach _areas;

    // Exclusion zones
    {
        _x params ["_position", "_area"];
        _map drawIcon ["\a3\ui_f\data\map\markers\military\circle_ca.paa", [1,0,0,1], _position, 20, 20, 0, "Exclude", 1, 0.03, "TahomaB", "right"];
        _area params ["_halfWidth", "_halfHeight", "_angle", "_isRectangle"];
        if (_isRectangle) then {
            _map drawRectangle [_position, _halfWidth, _halfHeight, _angle, [1,0,0,0.5], "#(argb,8,8,3)color(1,1,1,0.1)"];
        } else {
            _map drawEllipse [_position, _halfWidth, _halfHeight, _angle, [1,0,0,0.5], "#(argb,8,8,3)color(1,1,1,0.1)"];
        };
    } forEach _excludeAreas;

    // Inclusion zones
    {
        _x params ["_position", "_area"];
        _map drawIcon ["\a3\ui_f\data\map\markers\military\circle_ca.paa", [0,1,0,1], _position, 20, 20, 0, "Include", 1, 0.03, "TahomaB", "right"];
        _area params ["_halfWidth", "_halfHeight", "_angle", "_isRectangle"];
        if (_isRectangle) then {
            _map drawRectangle [_position, _halfWidth, _halfHeight, _angle, [0,1,0,0.5], "#(argb,8,8,3)color(1,1,1,0.1)"];
        } else {
            _map drawEllipse [_position, _halfWidth, _halfHeight, _angle, [0,1,0,0.5], "#(argb,8,8,3)color(1,1,1,0.1)"];
        };
    } forEach _includeAreas;
};

[QEGVAR(zeus,registerDebugProvider), [
    _key, _menuName, _menuPriority, _fnc_menuCondition, _fnc_serverGetter, "", _fnc_draw3d, _fnc_drawMap
]] call CBA_fnc_localEvent;
