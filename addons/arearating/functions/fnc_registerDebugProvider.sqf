#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers area rating debug provider with Zeus

    Parameter(s):
        None

    Return Value:
        None
*/

private _key = QGVAR(debug);
private _menuName = "Area Rating";
private _menuPriority = -50;
private _fnc_menuCondition = {GVAR(ratingAreas) isNotEqualTo []};

private _fnc_serverGetter = {
    private _areas = GVAR(ratingAreas) apply {
        _x params ["_id", "_name", "_logic", "_area", "_values"];

        private _position = getPosATL _logic;
        private _ratingStart = _values getOrDefault [QGVAR(ratingStart), 50];
        private _ratingCurrent = _values getOrDefault [QGVAR(ratingCurrent), 50];
        private _ratingMin = _values getOrDefault [QGVAR(ratingMin), 0];
        private _ratingMax = _values getOrDefault [QGVAR(ratingMax), 100];
        private _range = _ratingMax - _ratingMin;
        private _percentageStart = if (_range > 0) then {round (((_ratingStart - _ratingMin) / _range) * 100)} else {0};
        private _percentageCurrent = if (_range > 0) then {round (((_ratingCurrent - _ratingMin) / _range) * 100)} else {0};

        [_position, _area, _name, _ratingStart, _ratingCurrent, _ratingMin, _ratingMax, _percentageStart, _percentageCurrent]
    };

    private _globalRating = call FUNC(getGlobalRating);

    [_areas, _globalRating]
};

private _fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance"];
    _data params ["_areas", "_globalRating"];

    {
        _x params ["_position", "_area", "_name", "_ratingStart", "_ratingCurrent", "_ratingMin", "_ratingMax", "_percentageStart", "_percentageCurrent"];
        if !(_position isEqualType []) then { continue };
        if (_cameraPosition distance2D _position < _maxDistance) then {
            private _ratio = _percentageCurrent / 100;
            private _colour = if (_ratio < 0.5) then {
                [1, _ratio * 2, 0, 1]
            } else {
                [1 - ((_ratio - 0.5) * 2), 1, 0, 1]
            };

            private _trend = if (_percentageCurrent > _percentageStart) then {"^"} else {
                if (_percentageCurrent < _percentageStart) then {"v"} else {"-"}
            };

            drawIcon3D ["", _colour, ASLToAGL (ATLToASL _position), 0, 0, 0, format ["%1: %2%3 %4", _name, _percentageCurrent, "%", _trend], 1, 0.025, "TahomaB", "center"];
            drawIcon3D ["", _colour, ASLToAGL (ATLToASL _position), 0, 0, 0, format ["Rating: %1 (%2/%3)", _ratingCurrent, _ratingMin, _ratingMax], 1, 0.02, "TahomaB", "center", false, 0, 0.03];
        };
    } forEach _areas;
};

private _fnc_drawMap = {
    params ["_data", "_map"];
    _data params ["_areas", "_globalRating"];

    {
        _x params ["_position", "_area", "_name", "_ratingStart", "_ratingCurrent", "_ratingMin", "_ratingMax", "_percentageStart", "_percentageCurrent"];
        if !(_position isEqualType []) then { continue };

        private _ratio = _percentageCurrent / 100;
        private _colour = if (_ratio < 0.5) then {
            [1, _ratio * 2, 0, 1]
        } else {
            [1 - ((_ratio - 0.5) * 2), 1, 0, 1]
        };

        private _trend = if (_percentageCurrent > _percentageStart) then {"^"} else {
            if (_percentageCurrent < _percentageStart) then {"v"} else {"-"}
        };

        _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", _colour, _position, 24, 24, 0, format ["%1: %2%3 %4", _name, _percentageCurrent, "%", _trend], 1, 0.04, "TahomaB", "right"];

        private _ratingPosition = _position vectorAdd [0, -100, 0];
        _map drawIcon ["#(argb,8,8,3)color(0,0,0,0)", _colour, _ratingPosition, 0, 0, 0, format ["Rating: %1 (%2->%3)", _ratingCurrent, _ratingMin, _ratingMax], 1, 0.03, "TahomaB", "right"];

        _area params ["_halfWidth", "_halfHeight", "_angle", "_isRectangle"];
        private _outlineColour = _colour select [0, 3];
        _outlineColour pushBack 0.5;
        if (_isRectangle) then {
            _map drawRectangle [_position, _halfWidth, _halfHeight, _angle, _outlineColour, "#(argb,8,8,3)color(1,1,1,0.1)"];
        } else {
            _map drawEllipse [_position, _halfWidth, _halfHeight, _angle, _outlineColour, "#(argb,8,8,3)color(1,1,1,0.1)"];
        };
    } forEach _areas;
};

private _fnc_drawHud = {
    params ["_data", "_hudControl"];
    _data params ["", "_globalRating"];
    _globalRating params ["_ratings", "_percentages"];
    _ratings params ["", "_globalCurrent", "_globalMin", "_globalMax"];
    _percentages params ["_percentageStart", "_percentageCurrent"];

    private _colourHex = switch (true) do {
        case (_percentageCurrent >= 75): { "#00ff00" };
        case (_percentageCurrent >= 50): { "#ffff00" };
        case (_percentageCurrent >= 25): { "#ff8000" };
        default { "#ff0000" };
    };

    private _trend = if (_percentageCurrent > _percentageStart) then {"^"} else {
        if (_percentageCurrent < _percentageStart) then {"v"} else {"-"}
    };

    _hudControl ctrlSetStructuredText parseText format ["<t align='center' shadow='1' font='TahomaB'><t color='#aaaaaa'>Area Rating</t> <t color='%1'>%2%3 %4 (%5/%6->%7)</t></t>", _colourHex, _percentageCurrent, "%", _trend, _globalCurrent, _globalMin, _globalMax];
};

[QEGVAR(zeus,registerDebugAction), [_key, _menuName, _menuPriority, _fnc_menuCondition]] call CBA_fnc_localEvent;
[QEGVAR(zeus,registerDebugServerGetter), [_key, _fnc_serverGetter]] call CBA_fnc_localEvent;
[QEGVAR(zeus,registerDebugDraw), [_key, _fnc_draw3d, _fnc_drawMap, _fnc_drawHud]] call CBA_fnc_localEvent;
