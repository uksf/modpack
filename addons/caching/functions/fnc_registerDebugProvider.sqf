#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers caching debug provider with Zeus

    Parameter(s):
        None

    Return Value:
        None
*/

private _key = QGVAR(debug);
private _menuName = "Cached Groups";
private _menuPriority = -60;
private _fnc_menuCondition = {GVAR(enabled)};

private _fnc_serverGetter = {
    private _cachedGroups = [];
    private _totalActive = 0;
    private _totalCached = 0;

    {
        private _leader = leader _x;
        if (!isNull _leader && {!isPlayer _leader} && {!(_x getVariable [QGVAR(excluded), false])}) then {
            if (_leader getVariable [QGVAR(hiddenByCaching), false]) then {
                _totalCached = _totalCached + 1;
                private _colour = switch (side _x) do {
                    case west: { [0.3,0.5,1,1] };
                    case east: { [1,0,0,1] };
                    case independent: { [0,1,0,1] };
                    default { [0.8,0.3,1,1] };
                };
                _cachedGroups pushBack [getPosATL _leader, _colour, count units _x];
            } else {
                _totalActive = _totalActive + 1;
            };
        };
    } forEach allGroups;

    [_cachedGroups, GVAR(distance), _totalActive, _totalCached]
};

private _fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance"];
    _data params ["_cachedGroups"];

    {
        _x params ["_position", "_colour", "_unitCount"];
        if (_cameraPosition distance2D _position < _maxDistance) then {
            drawIcon3D ["\a3\ui_f\data\map\markers\military\dot_ca.paa", _colour, ASLToAGL (ATLToASL _position), 0.4, 0.4, 0, format ["%1", _unitCount], 1, 0.02, "TahomaB", "center"];
        };
    } forEach _cachedGroups;
};

private _fnc_drawMap = {
    params ["_data", "_map"];
    _data params ["_cachedGroups"];

    {
        _x params ["_position", "_colour", "_unitCount"];
        _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", _colour, _position, 16, 16, 0, format ["%1", _unitCount], 1, 0.03, "TahomaB", "right"];
    } forEach _cachedGroups;
};

private _fnc_drawHud = {
    params ["_data", "_hudControl"];
    _data params ["", "", "_totalActive", "_totalCached"];

    _hudControl ctrlSetStructuredText parseText format ["<t align='center' shadow='1' font='TahomaB'><t color='#aaaaaa'>Caching</t> <t color='#ffffff'>Cached: %1 | Active: %2</t></t>", _totalCached, _totalActive];
};

[QEGVAR(zeus,registerDebugProvider), [
    _key, _menuName, _menuPriority, _fnc_menuCondition, _fnc_serverGetter, "", _fnc_draw3d, _fnc_drawMap, _fnc_drawHud
]] call CBA_fnc_localEvent;
