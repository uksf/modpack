#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers the virtualised-groups debug provider with the zeus debug
        framework. Provider exposes 3D + map drawing (group icons, waypoint
        chains with active-WP highlight), HUD line (virtualised / sim / active
        counts), and a server-side data getter that projects the minimum
        needed payload.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_virtualisation_fnc_registerDebugProviders
*/
private _key = QGVAR(virtualised);

private _fnc_serverGetter = {
    private _virtEntries = GVAR(groupPositionMap) apply {
        _x params ["_id", "_position"];
        private _entry = GVAR(groupDataMap) get _id;
        if (isNil "_entry") exitWith { [_id, _position, sideUnknown, 0, 0, [], -1] };
        _entry params ["_side", "_vehicleDetails", "_unitDetails", "", "", "", "_simState", "", "_fullWaypoints"];

        private _isSimulated = (GVAR(simulatedGroupIds) findIf {_x == _id}) >= 0;
        private _waypointPositions = if (_isSimulated) then { _fullWaypoints apply {_x#0} } else { [] };
        private _nextIndex = if (_isSimulated) then { _simState#0 } else { -1 };

        [_id, _position, _side, count _vehicleDetails, count _unitDetails, _waypointPositions, _nextIndex]
    };

    private _activeNonPlayerCount = {
        private _leader = leader _x;
        !isPlayer _leader
        && {units _x isNotEqualTo []}
        && {!((objectParent _leader) isKindOf "Air")}
    } count allGroups;

    [_virtEntries, count GVAR(simulatedGroupIds), _activeNonPlayerCount]
};

private _fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance", "_iconSpacing"];
    _data params ["_virtEntries"];

    {
        _x params ["", "_position", "_side", "_vehicleCount", "_unitCount", "_waypointPositions", "_nextIndex"];
        if (_cameraPosition distance _position > _maxDistance) then { continue };

        drawIcon3D ["\a3\ui_f\data\gui\cfg\Hints\icon_text\group_1_ca.paa", [1,0.4,0,1], _position, 1, 1, 0, format ["%1", _side], 0.1, 0.03, "PuristaBold", "center"];
        drawIcon3D ["", [1,0.4,0,1], _position, 0, 0, 0, format ["%1 Vehicles", _vehicleCount], 0.1, 0.03, "PuristaBold", "center", false, 0, _iconSpacing];
        drawIcon3D ["", [1,0.4,0,1], _position, 0, 0, 0, format ["%1 Units", _unitCount], 0.1, 0.03, "PuristaBold", "center", false, 0, _iconSpacing * 2];

        if (count _waypointPositions >= 2) then {
            for "_i" from 0 to (count _waypointPositions - 2) do {
                drawLine3D [_waypointPositions select _i, _waypointPositions select (_i + 1), [1,0.4,0,0.8], 2];
            };
            {
                private _isActive = _forEachIndex == _nextIndex;
                private _colour = if (_isActive) then { [1,1,0,1] } else { [1,0.4,0,0.9] };
                private _size = if (_isActive) then { 1.0 } else { 0.6 };
                drawIcon3D ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", _colour, _x, _size, _size, 0, "", 0.1, 0.025, "PuristaBold", "center"];
            } forEach _waypointPositions;
        };
    } forEach _virtEntries;
};

private _fnc_drawMap = {
    params ["_data", "_map"];
    _data params ["_virtEntries"];

    {
        _x params ["", "_position", "_side", "_vehicleCount", "_unitCount", "_waypointPositions", "_nextIndex"];

        if (count _waypointPositions >= 2) then {
            for "_i" from 0 to (count _waypointPositions - 2) do {
                _map drawLine [_waypointPositions select _i, _waypointPositions select (_i + 1), [1,0.4,0,0.8]];
            };
            {
                private _isActive = _forEachIndex == _nextIndex;
                private _colour = if (_isActive) then { [1,1,0,1] } else { [1,0.4,0,0.9] };
                private _size = if (_isActive) then { 24 } else { 16 };
                _map drawIcon ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", _colour, _x, _size, _size, 0, "", 0.1, 0.04, "PuristaBold", "center"];
            } forEach _waypointPositions;
        };

        private _text = format ["%1, V: %2, U: %3", _side, _vehicleCount, _unitCount];
        _map drawIcon ["\a3\ui_f\data\gui\cfg\Hints\icon_text\group_1_ca.paa", [1,0.4,0,1], _position, 40, 40, 0, _text, 0.1, 0.04, "PuristaBold", "right"];
    } forEach _virtEntries;
};

private _fnc_drawHud = {
    params ["_data", "_hudControl"];
    _data params ["_virtEntries", "_simCount", "_activeCount"];
    private _virtTotal = count _virtEntries;

    private _text = format [
        "<t color='#aaaaaa'>Virtualised:</t> <t color='#ffffff'>%1</t> <t color='#666666'>(sim:</t> <t color='#ffffff'>%2</t><t color='#666666'>)</t> <t color='#666666'>|</t> <t color='#aaaaaa'>Active:</t> <t color='#ffffff'>%3</t>",
        _virtTotal, _simCount, _activeCount
    ];
    _hudControl ctrlSetStructuredText parseText format [
        "<t align='center' shadow='1' font='TahomaB'>%1</t>", _text
    ];
};

[QEGVAR(zeus,registerDebugProvider), [_key, createHashMapFromArray [
    ["draw3d", _fnc_draw3d],
    ["drawMap", _fnc_drawMap],
    ["drawHud", _fnc_drawHud],
    ["serverGetter", _fnc_serverGetter],
    ["getterInterval", 3],
    ["menuName", "Virtualised Groups"],
    ["menuPriority", -8],
    ["menuCondition", { GVAR(enabled) }]
]]] call CBA_fnc_localEvent;
