#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers the virtualised-groups debug provider with the zeus debug
        framework. 3D draw stacks labels above the group position using the
        framework-supplied icon spacing. HUD shows totals with side breakdown
        on a second line. Map shows a single side-coloured label offset from
        the group icon, plus the active waypoint chain.

        Static lookup tables (side colour, hex, short label) are stored as
        GVAR because SQF closures don't capture private scope.

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

    private _virtEntries = GVAR(groupPositionMap) apply {
        _x params ["_id", "_position"];
        private _entry = GVAR(groupDataMap) get _id;
        if (isNil "_entry") exitWith { [_id, _position, sideUnknown, 0, 0, false, [], -1, "SAFE", "NORMAL"] };
        _entry params ["_side", "_vehicleDetails", "_unitDetails", "", "_combatMode", "", "_simState", "", "_fullWaypoints"];

        private _isSimulated = (GVAR(simulatedGroupIds) findIf {_x == _id}) >= 0;
        private _waypointPositions = if (_isSimulated) then { _fullWaypoints apply {_x#0} } else { [] };

        _simState params ["_nextIndex", "", "_currentBehaviour", "_currentSpeed"];
        if (!_isSimulated) then { _nextIndex = -1 };

        if (_position isEqualTo [0,0,0]) then { WARNING_1("groupPositionMap entry at origin: %1",_id) };
        {
            if (_x isEqualTo [0,0,0]) then { WARNING_2("waypoint at origin in entry %1 wp %2",_id,_forEachIndex) };
        } forEach _waypointPositions;

        private _bucket = _sideBreakdown getOrDefault [_side, [0, 0]];
        _bucket set [0, (_bucket#0) + 1];
        if (_isSimulated) then { _bucket set [1, (_bucket#1) + 1] };
        _sideBreakdown set [_side, _bucket];

        [_id, _position, _side, count _vehicleDetails, count _unitDetails, _isSimulated, _waypointPositions, _nextIndex, _currentBehaviour, _currentSpeed]
    };

    private _activeNonPlayerCount = {
        private _leader = leader _x;
        !isPlayer _leader
        && {units _x isNotEqualTo []}
        && {!((objectParent _leader) isKindOf "Air")}
    } count allGroups;

    [_virtEntries, count GVAR(simulatedGroupIds), _activeNonPlayerCount, _sideBreakdown]
};

private _fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance", "_iconSpacing"];
    _data params ["_virtEntries"];

    {
        _x params ["", "_position", "_side", "_vehicleCount", "_unitCount", "_isSimulated", "_waypointPositions", "_nextIndex", "_behaviour", "_speed"];
        if (_cameraPosition distance _position > _maxDistance) then { continue };

        private _sideColour = GVAR(debugSideColour) getOrDefault [_side, [0.7, 0.7, 0.7, 1]];
        private _sideLabel = GVAR(debugSideLabel) getOrDefault [_side, "?"];

        private _line1 = format ["%1  %2V/%3U", _sideLabel, _vehicleCount, _unitCount];
        private _line2 = if (_isSimulated && {_nextIndex >= 0 && _nextIndex < count _waypointPositions}) then {
            format ["WP %1/%2", _nextIndex + 1, count _waypointPositions]
        } else {
            "static"
        };
        private _line2Colour = if (_isSimulated) then { [1, 1, 1, 0.95] } else { [0.65, 0.65, 0.65, 0.95] };

        drawIcon3D ["", _sideColour, _position, 0, 0, 0, _line1, 1, 0.025, "TahomaB", "center"];
        drawIcon3D ["", _line2Colour, _position, 0, 0, 0, _line2, 1, 0.02, "TahomaB", "center", false, 0, _iconSpacing];
        if (_isSimulated) then {
            private _line3 = format ["%1 / %2", _behaviour, _speed];
            drawIcon3D ["", [0.6, 0.6, 0.6, 0.9], _position, 0, 0, 0, _line3, 1, 0.018, "TahomaB", "center", false, 0, _iconSpacing * 2];
        };

        if (_isSimulated && {_nextIndex >= 0 && _nextIndex < count _waypointPositions}) then {
            private _activeColour = [1, 0.95, 0.5, 0.95];
            private _futureLineColour = [_sideColour#0, _sideColour#1, _sideColour#2, 0.45];
            private _futureWpColour = [_sideColour#0, _sideColour#1, _sideColour#2, 0.85];

            drawLine3D [_position, _waypointPositions select _nextIndex, _activeColour];
            for "_i" from _nextIndex to (count _waypointPositions - 2) do {
                drawLine3D [_waypointPositions select _i, _waypointPositions select (_i + 1), _futureLineColour, 1];
            };
            for "_i" from _nextIndex to (count _waypointPositions - 1) do {
                private _isActive = _i == _nextIndex;
                private _wpColour = if (_isActive) then { _activeColour } else { _futureWpColour };
                private _size = if (_isActive) then { 0.6 } else { 0.35 };
                drawIcon3D ["\a3\ui_f\data\map\mapcontrol\waypoint_ca.paa", _wpColour, _waypointPositions select _i, _size, _size, 0, "", 0, 0, "TahomaB", "center"];
            };
        };
    } forEach _virtEntries;
};

private _fnc_drawMap = {
    params ["_data", "_map"];
    _data params ["_virtEntries"];

    {
        _x params ["", "_position", "_side", "_vehicleCount", "_unitCount", "_isSimulated", "_waypointPositions", "_nextIndex", "_behaviour", "_speed"];

        private _sideColour = GVAR(debugSideColour) getOrDefault [_side, [0.7, 0.7, 0.7, 1]];
        private _sideLabel = GVAR(debugSideLabel) getOrDefault [_side, "?"];

        private _stateText = if (_isSimulated && {_nextIndex >= 0 && _nextIndex < count _waypointPositions}) then {
            format ["WP %1/%2  %3/%4", _nextIndex + 1, count _waypointPositions, _behaviour, _speed]
        } else {
            "static"
        };
        private _label = format ["%1  %2V/%3U  %4", _sideLabel, _vehicleCount, _unitCount, _stateText];

        if (_isSimulated && {_nextIndex >= 0 && _nextIndex < count _waypointPositions}) then {
            private _activeColour = [1, 0.95, 0.5, 0.95];
            private _futureLineColour = [_sideColour#0, _sideColour#1, _sideColour#2, 0.45];
            private _futureWpColour = [_sideColour#0, _sideColour#1, _sideColour#2, 0.85];

            _map drawLine [_position, _waypointPositions select _nextIndex, _activeColour];
            for "_i" from _nextIndex to (count _waypointPositions - 2) do {
                _map drawLine [_waypointPositions select _i, _waypointPositions select (_i + 1), _futureLineColour];
            };
            for "_i" from _nextIndex to (count _waypointPositions - 1) do {
                private _isActive = _i == _nextIndex;
                private _wpColour = if (_isActive) then { _activeColour } else { _futureWpColour };
                private _size = if (_isActive) then { 14 } else { 8 };
                _map drawIcon ["\a3\ui_f\data\map\mapcontrol\waypoint_ca.paa", _wpColour, _waypointPositions select _i, _size, _size, 0, "", 0, 0, "TahomaB", "center"];
            };
        };

        _map drawIcon ["#(argb,8,8,3)color(0,0,0,0)", _sideColour, _position, 0, 0, 0, _label, 1, 0.04, "TahomaB", "right"];
    } forEach _virtEntries;
};

private _fnc_drawHud = {
    params ["_data", "_hudControl"];
    _data params ["_virtEntries", "_simCount", "_activeCount", "_sideBreakdown"];
    private _virtTotal = count _virtEntries;

    private _line1 = format [
        "<t color='#aaaaaa'>Virtualised:</t> <t color='#ffffff'>%1</t> <t color='#666666'>(sim:</t> <t color='#ffffff'>%2</t><t color='#666666'>)</t> <t color='#666666'>|</t> <t color='#aaaaaa'>Active:</t> <t color='#ffffff'>%3</t>",
        _virtTotal, _simCount, _activeCount
    ];

    private _parts = [];
    {
        _y params ["_total", "_sim"];
        if (_total <= 0) then { continue };
        private _hex = GVAR(debugSideHex) getOrDefault [_x, "#aaaaaa"];
        private _label = GVAR(debugSideLabel) getOrDefault [_x, "?"];
        _parts pushBack format [
            "<t color='%1'>%2</t> <t color='#ffffff'>%3</t> <t color='#666666'>(sim:</t> <t color='#ffffff'>%4</t><t color='#666666'>)</t>",
            _hex, _label, _total, _sim
        ];
    } forEach _sideBreakdown;

    private _line2 = if (_parts isEqualTo []) then {
        "<t color='#666666'>No virtualised groups</t>"
    } else {
        _parts joinString " <t color='#666666'>|</t> "
    };

    _hudControl ctrlSetStructuredText parseText format [
        "<t align='center' shadow='1' font='TahomaB'>%1<br/>%2</t>", _line1, _line2
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
