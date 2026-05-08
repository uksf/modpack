#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers the virtualised-groups zeus debug provider (3D, map, HUD).
        Side colour/hex/label tables live as GVARs because draw closures
        don't capture private scope.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_virtualisation_fnc_registerDebugProviders
*/
private _key = QGVAR(virtualised);

GVAR(debugSideColour) = createHashMapFromArray [
    [east,        [0.9, 0.3, 0.3, 1]],
    [west,        [0.3, 0.55, 0.95, 1]],
    [independent, [0.35, 0.85, 0.35, 1]],
    [civilian,    [0.75, 0.4, 0.85, 1]]
];

GVAR(debugSideHex) = createHashMapFromArray [
    [east,        "#e64d4d"],
    [west,        "#4d8cf2"],
    [independent, "#5ad95a"],
    [civilian,    "#bf66d9"]
];

GVAR(debugSideLabel) = createHashMapFromArray [
    [east,        "EAST"],
    [west,        "WEST"],
    [independent, "INDEP"],
    [civilian,    "CIV"]
];

private _fnc_serverGetter = {
    private _sideBreakdown = createHashMap;
    private _virtAiTotal = 0;

    private _virtEntries = GVAR(groupPositionMap) apply {
        _x params ["_id", "_position"];
        private _entry = GVAR(groupDataMap) get _id;
        if (isNil "_entry") exitWith { [_id, _position, sideUnknown, 0, 0, false, [], -1, "SAFE", "NORMAL"] };
        _entry params ["_side", "_vehicleDetails", "_unitDetails", "", "_combatMode", "", "_simState", "", "_fullWaypoints"];

        private _isSimulated = (GVAR(simulatedGroupIds) findIf {_x == _id}) >= 0;
        private _waypointInfo = if (_isSimulated) then { _fullWaypoints apply { [_x#0, toUpper (_x#1)] } } else { [] };

        _simState params ["_nextIndex", "", "_currentBehaviour", "_currentSpeed"];
        if (!_isSimulated) then { _nextIndex = -1 };

        if (_position isEqualTo [0,0,0]) then { WARNING_1("groupPositionMap entry at origin: %1",_id) };
        {
            if ((_x#0) isEqualTo [0,0,0]) then { WARNING_2("waypoint at origin in entry %1 wp %2",_id,_forEachIndex) };
        } forEach _waypointInfo;

        private _aiCount = count _unitDetails;
        { _aiCount = _aiCount + count (_x#5) } forEach _vehicleDetails;
        _virtAiTotal = _virtAiTotal + _aiCount;

        private _bucket = _sideBreakdown getOrDefault [_side, [0, 0, 0]];
        _bucket set [0, (_bucket#0) + 1];
        if (_isSimulated) then { _bucket set [1, (_bucket#1) + 1] };
        _bucket set [2, (_bucket#2) + _aiCount];
        _sideBreakdown set [_side, _bucket];

        [_id, _position, _side, count _vehicleDetails, count _unitDetails, _isSimulated, _waypointInfo, _nextIndex, _currentBehaviour, _currentSpeed]
    };

    private _activeGroupCount = 0;
    private _activeAiTotal = 0;
    {
        private _leader = leader _x;
        if (
            !isPlayer _leader
            && {units _x isNotEqualTo []}
            && {!((objectParent _leader) isKindOf "Air")}
        ) then {
            _activeGroupCount = _activeGroupCount + 1;
            _activeAiTotal = _activeAiTotal + count (units _x);
        };
    } forEach allGroups;

    [_virtEntries, count GVAR(simulatedGroupIds), _activeGroupCount, _sideBreakdown, _virtAiTotal, _activeAiTotal]
};

#define WP_MOVE_ICON "\a3\ui_f\data\map\mapcontrol\waypoint_ca.paa"
#define WP_CYCLE_ICON "\a3\3DEN\Data\CfgWaypoints\Cycle_ca.paa"
#define DOT_ICON "\A3\ui_f\data\map\markers\military\dot_CA.paa"

private _fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance", "_iconSpacing"];
    _data params ["_virtEntries"];

    {
        _x params ["", "_position", "_side", "_vehicleCount", "_unitCount", "_isSimulated", "_waypointInfo", "_nextIndex", "_behaviour", "_speed"];
        if (_cameraPosition distance _position > _maxDistance) then { continue };

        private _sideColour = GVAR(debugSideColour) getOrDefault [_side, [0.7, 0.7, 0.7, 1]];
        private _hasWaypoints = _isSimulated && {_nextIndex >= 0 && _nextIndex < count _waypointInfo};

        drawIcon3D [DOT_ICON, _sideColour, _position, 0.5, 0.5, 0, "", 0, 0, "TahomaB", "center"];

        private _line1 = format ["%1V/%2U", _vehicleCount, _unitCount];
        drawIcon3D ["", _sideColour, _position, 0, 0, 0, _line1, 1, 0.025, "TahomaB", "center", false, 0, _iconSpacing];

        if (_hasWaypoints) then {
            private _line2 = format ["WP %1/%2", _nextIndex + 1, count _waypointInfo];
            drawIcon3D ["", [1, 1, 1, 0.95], _position, 0, 0, 0, _line2, 1, 0.02, "TahomaB", "center", false, 0, _iconSpacing * 2];
            private _line3 = format ["%1 / %2", _behaviour, _speed];
            drawIcon3D ["", [1, 1, 1, 0.85], _position, 0, 0, 0, _line3, 1, 0.018, "TahomaB", "center", false, 0, _iconSpacing * 3];

            private _activeColour = [1, 0.95, 0.5, 0.95];
            private _futureLineColour = [_sideColour#0, _sideColour#1, _sideColour#2, 0.45];
            private _futureWpColour = [_sideColour#0, _sideColour#1, _sideColour#2, 0.85];

            drawLine3D [_position, (_waypointInfo select _nextIndex)#0, _activeColour];
            for "_i" from _nextIndex to (count _waypointInfo - 2) do {
                drawLine3D [(_waypointInfo select _i)#0, (_waypointInfo select (_i + 1))#0, _futureLineColour, 1];
            };
            for "_i" from _nextIndex to (count _waypointInfo - 1) do {
                (_waypointInfo select _i) params ["_wpPos", "_wpType"];
                private _isActive = _i == _nextIndex;
                private _wpColour = if (_isActive) then { _activeColour } else { _futureWpColour };
                private _size = if (_isActive) then { 0.6 } else { 0.55 };
                private _icon = if (_wpType == "CYCLE") then { WP_CYCLE_ICON } else { WP_MOVE_ICON };
                drawIcon3D [_icon, _wpColour, _wpPos, _size, _size, 0, "", 0, 0, "TahomaB", "center"];
            };
        };
    } forEach _virtEntries;
};

private _fnc_drawMap = {
    params ["_data", "_map"];
    _data params ["_virtEntries"];

    {
        _x params ["", "_position", "_side", "_vehicleCount", "_unitCount", "_isSimulated", "_waypointInfo", "_nextIndex", "_behaviour", "_speed"];

        private _sideColour = GVAR(debugSideColour) getOrDefault [_side, [0.7, 0.7, 0.7, 1]];
        private _hasWaypoints = _isSimulated && {_nextIndex >= 0 && _nextIndex < count _waypointInfo};

        private _label = if (_hasWaypoints) then {
            format ["%1V/%2U  WP %3/%4  %5/%6", _vehicleCount, _unitCount, _nextIndex + 1, count _waypointInfo, _behaviour, _speed]
        } else {
            format ["%1V/%2U", _vehicleCount, _unitCount]
        };

        if (_hasWaypoints) then {
            private _activeColour = [1, 0.95, 0.5, 0.95];
            private _futureLineColour = [_sideColour#0, _sideColour#1, _sideColour#2, 0.45];
            private _futureWpColour = [_sideColour#0, _sideColour#1, _sideColour#2, 0.85];

            _map drawLine [_position, (_waypointInfo select _nextIndex)#0, _activeColour];
            for "_i" from _nextIndex to (count _waypointInfo - 2) do {
                _map drawLine [(_waypointInfo select _i)#0, (_waypointInfo select (_i + 1))#0, _futureLineColour];
            };
            for "_i" from _nextIndex to (count _waypointInfo - 1) do {
                (_waypointInfo select _i) params ["_wpPos", "_wpType"];
                private _isActive = _i == _nextIndex;
                private _wpColour = if (_isActive) then { _activeColour } else { _futureWpColour };
                private _size = if (_isActive) then { 14 } else { 12 };
                private _icon = if (_wpType == "CYCLE") then { WP_CYCLE_ICON } else { WP_MOVE_ICON };
                _map drawIcon [_icon, _wpColour, _wpPos, _size, _size, 0, "", 0, 0, "TahomaB", "center"];
            };
        };

        _map drawIcon [DOT_ICON, _sideColour, _position, 14, 14, 0, _label, 1, 0.035, "TahomaB", "right"];
    } forEach _virtEntries;
};

private _fnc_drawHud = {
    params ["_data", "_hudControl"];
    _data params ["_virtEntries", "_simCount", "_activeCount", "_sideBreakdown", "_virtAiTotal", "_activeAiTotal"];
    private _virtTotal = count _virtEntries;

    private _line1 = format [
        "<t color='#aaaaaa'>Virtualised:</t> %1 [%2 sim] (%3 units)  |  <t color='#aaaaaa'>Active:</t> %4 (%5 units)",
        _virtTotal, _simCount, _virtAiTotal, _activeCount, _activeAiTotal
    ];

    private _parts = [];
    {
        _y params ["_total", "_sim", "_aiTotal"];
        if (_total <= 0) then { continue };
        private _hex = GVAR(debugSideHex) getOrDefault [_x, "#ffffff"];
        private _label = GVAR(debugSideLabel) getOrDefault [_x, "?"];
        _parts pushBack format [
            "<t color='%1'>%2</t> %3 [%4 sim] (%5 units)",
            _hex, _label, _total, _sim, _aiTotal
        ];
    } forEach _sideBreakdown;

    private _line2 = if (_parts isEqualTo []) then {
        "<t color='#aaaaaa'>No virtualised groups</t>"
    } else {
        _parts joinString "  |  "
    };

    _hudControl ctrlSetStructuredText parseText format [
        "<t align='center' shadow='1' font='TahomaB'>%1<br/>%2</t>", _line1, _line2
    ];
};

[QEGVAR(zeus,registerDebugProvider), [_key, createHashMapFromArray [
    ["draw3d", _fnc_draw3d],
    ["drawMap", _fnc_drawMap],
    ["drawHud", _fnc_drawHud],
    ["hudLines", 2],
    ["serverGetter", _fnc_serverGetter],
    ["getterInterval", 1],
    ["menuName", "Virtualised Groups"],
    ["menuPriority", -8],
    ["menuCondition", { GVAR(enabled) }]
]]] call CBA_fnc_localEvent;
