private _mapControl = (findDisplay 12) displayCtrl 51;
if (!isNull _mapControl) then {
    {
        _x params ["_evtName", "_evtId"];
        _mapControl ctrlRemoveEventHandler [_evtName, _evtId];
    } forEach (missionNamespace getVariable ["uksf_maptools_debugEHs", []]);
};
missionNamespace setVariable ["uksf_maptools_debugEHs", []];

private _oldPehId = missionNamespace getVariable ["uksf_maptools_debugVisibleMapPEH", -1];
if (_oldPehId != -1) then {
    ["visibleMap", _oldPehId] call CBA_fnc_removePlayerEventHandler;
};

private _oldDropdown = uiNamespace getVariable ["uksf_maptools_headerDropdown", controlNull];
if (!isNull _oldDropdown) then { ctrlDelete _oldDropdown };
uiNamespace setVariable ["uksf_maptools_headerDropdown", controlNull];

{ deleteMarkerLocal _x } forEach (missionNamespace getVariable ["uksf_maptools_previewMarkers", []]);

uksf_maptools_modes = ["circle", "ellipse", "racetrack", "cone"];
uksf_maptools_currentMode = missionNamespace getVariable ["uksf_maptools_currentMode", "circle"];
uksf_maptools_currentModeLabel = missionNamespace getVariable ["uksf_maptools_currentModeLabel", "Circle"];
uksf_maptools_state = "idle";
uksf_maptools_stage1Start = [0, 0, 0];
uksf_maptools_stage1End = [0, 0, 0];
uksf_maptools_stage2Pos = [0, 0, 0];
uksf_maptools_drawKeyHeld = false;
uksf_maptools_playerShapes = missionNamespace getVariable ["uksf_maptools_playerShapes", []];
uksf_maptools_previewMarkers = [];
uksf_maptools_markerID = missionNamespace getVariable ["uksf_maptools_markerID", 100000];
uksf_maptools_stage2DefaultSecondary = 0;
uksf_maptools_segmentTargetMetres = missionNamespace getVariable ["uksf_maptools_segmentTargetMetres", 25];

uksf_maptools_fnc_setState = {
    params ["_newState"];
    if (_newState isEqualTo uksf_maptools_state) exitWith {};
    uksf_maptools_state = _newState;
    systemChat format ["State: %1 (mode: %2)", _newState, uksf_maptools_currentModeLabel];
};

uksf_maptools_fnc_segmentCount = {
    params [["_arcLengthMetres", 0, [0]]];
    private _target = uksf_maptools_segmentTargetMetres max 1;
    private _count = ceil (_arcLengthMetres / _target);
    ((_count max 8) min 32)
};

uksf_maptools_fnc_buildCircle = {
    params [["_centre", [0, 0, 0], [[]]], ["_radius", 0, [0]]];
    private _arcLength = _radius * pi / 2;
    private _pointsPerQuadrant = [_arcLength] call uksf_maptools_fnc_segmentCount;
    private _polylines = [];
    private _centreX = _centre#0;
    private _centreY = _centre#1;
    for "_quadrant" from 0 to 3 do {
        private _polyline = [];
        private _angleStart = _quadrant * 90;
        for "_i" from 0 to _pointsPerQuadrant do {
            private _theta = _angleStart + (_i * 90 / _pointsPerQuadrant);
            _polyline append [_centreX + _radius * (cos _theta), _centreY + _radius * (sin _theta)];
        };
        _polylines pushBack _polyline;
    };
    _polylines
};

uksf_maptools_fnc_buildEllipse = {
    params [
        ["_centre", [0, 0, 0], [[]]],
        ["_semiMajor", 0, [0]],
        ["_semiMinor", 0, [0]],
        ["_rotationDeg", 0, [0]]
    ];
    private _a = (abs _semiMajor) max 0.0001;
    private _b = (abs _semiMinor) max 0.0001;
    private _h = ((_a - _b) ^ 2) / ((_a + _b) ^ 2);
    private _perimeter = pi * (_a + _b) * (1 + (3 * _h) / (10 + sqrt (4 - 3 * _h)));
    private _arcLength = _perimeter / 4;
    private _pointsPerQuadrant = [_arcLength] call uksf_maptools_fnc_segmentCount;
    private _cosR = cos _rotationDeg;
    private _sinR = sin _rotationDeg;
    private _centreX = _centre#0;
    private _centreY = _centre#1;
    private _polylines = [];
    for "_quadrant" from 0 to 3 do {
        private _polyline = [];
        private _angleStart = _quadrant * 90;
        for "_i" from 0 to _pointsPerQuadrant do {
            private _theta = _angleStart + (_i * 90 / _pointsPerQuadrant);
            private _localX = _a * (cos _theta);
            private _localY = _b * (sin _theta);
            private _worldX = _centreX + _localX * _cosR - _localY * _sinR;
            private _worldY = _centreY + _localX * _sinR + _localY * _cosR;
            _polyline append [_worldX, _worldY];
        };
        _polylines pushBack _polyline;
    };
    _polylines
};

uksf_maptools_fnc_buildRaceTrack = {
    params [
        ["_centre", [0, 0, 0], [[]]],
        ["_halfLength", 0, [0]],
        ["_halfWidth", 0, [0]],
        ["_rotationDeg", 0, [0]]
    ];
    private _capArc = pi * _halfWidth;
    private _pointsPerCap = [_capArc] call uksf_maptools_fnc_segmentCount;
    private _cosR = cos _rotationDeg;
    private _sinR = sin _rotationDeg;
    private _centreX = _centre#0;
    private _centreY = _centre#1;
    private _fnc_localToWorld = {
        params ["_localX", "_localY"];
        [
            _centreX + _localX * _cosR - _localY * _sinR,
            _centreY + _localX * _sinR + _localY * _cosR
        ]
    };
    private _topStraight = [];
    ([-_halfLength, _halfWidth] call _fnc_localToWorld) params ["_topLeftX", "_topLeftY"];
    ([_halfLength, _halfWidth] call _fnc_localToWorld) params ["_topRightX", "_topRightY"];
    _topStraight append [_topLeftX, _topLeftY, _topRightX, _topRightY];
    private _bottomStraight = [];
    ([-_halfLength, -_halfWidth] call _fnc_localToWorld) params ["_botLeftX", "_botLeftY"];
    ([_halfLength, -_halfWidth] call _fnc_localToWorld) params ["_botRightX", "_botRightY"];
    _bottomStraight append [_botLeftX, _botLeftY, _botRightX, _botRightY];
    private _rightCap = [];
    for "_i" from 0 to _pointsPerCap do {
        private _theta = -90 + (_i * 180 / _pointsPerCap);
        private _localX = _halfLength + _halfWidth * (cos _theta);
        private _localY = _halfWidth * (sin _theta);
        ([_localX, _localY] call _fnc_localToWorld) params ["_wx", "_wy"];
        _rightCap append [_wx, _wy];
    };
    private _leftCap = [];
    for "_i" from 0 to _pointsPerCap do {
        private _theta = 90 + (_i * 180 / _pointsPerCap);
        private _localX = -_halfLength + _halfWidth * (cos _theta);
        private _localY = _halfWidth * (sin _theta);
        ([_localX, _localY] call _fnc_localToWorld) params ["_wx", "_wy"];
        _leftCap append [_wx, _wy];
    };
    [_topStraight, _bottomStraight, _rightCap, _leftCap]
};

uksf_maptools_fnc_buildCone = {
    params [
        ["_apex", [0, 0, 0], [[]]],
        ["_axisLen", 0, [0]],
        ["_halfAngleDeg", 0, [0]],
        ["_rotationDeg", 0, [0]]
    ];
    private _arcLength = abs (_axisLen * (_halfAngleDeg * 2 * pi / 180));
    private _pointsOnArc = [_arcLength] call uksf_maptools_fnc_segmentCount;
    private _cosR = cos _rotationDeg;
    private _sinR = sin _rotationDeg;
    private _apexX = _apex#0;
    private _apexY = _apex#1;
    private _fnc_localToWorld = {
        params ["_localX", "_localY"];
        [
            _apexX + _localX * _cosR - _localY * _sinR,
            _apexY + _localX * _sinR + _localY * _cosR
        ]
    };
    private _topEndLocal = [_axisLen * (cos _halfAngleDeg), _axisLen * (sin _halfAngleDeg)];
    private _botEndLocal = [_axisLen * (cos -_halfAngleDeg), _axisLen * (sin -_halfAngleDeg)];
    (_topEndLocal call _fnc_localToWorld) params ["_topEndX", "_topEndY"];
    (_botEndLocal call _fnc_localToWorld) params ["_botEndX", "_botEndY"];
    private _topSide = [_apexX, _apexY, _topEndX, _topEndY];
    private _botSide = [_apexX, _apexY, _botEndX, _botEndY];
    private _farArc = [];
    for "_i" from 0 to _pointsOnArc do {
        private _theta = -_halfAngleDeg + (_i * 2 * _halfAngleDeg / _pointsOnArc);
        private _localX = _axisLen * (cos _theta);
        private _localY = _axisLen * (sin _theta);
        ([_localX, _localY] call _fnc_localToWorld) params ["_wx", "_wy"];
        _farArc append [_wx, _wy];
    };
    [_topSide, _botSide, _farArc]
};

uksf_maptools_fnc_emitShape = {
    params [["_polylines", [], [[]]]];
    private _channelID = currentChannel;
    if (_channelID < 0) then { _channelID = 1 };
    private _ownerID = getPlayerID ACE_player;
    private _colour = missionNamespace getVariable ["ace_markers_currentMarkerColorConfigName", "ColorBlack"];
    if (_colour isEqualTo "") then { _colour = "ColorBlack" };
    private _created = [];
    {
        private _markerID = uksf_maptools_markerID;
        uksf_maptools_markerID = _markerID + 1;
        private _name = format ["_USER_DEFINED #%1/%2/%3", _ownerID, _markerID, _channelID];
        createMarker [_name, _x select [0, 2]];
        _name setMarkerShape "POLYLINE";
        _name setMarkerColor _colour;
        _name setMarkerPolyline _x;
        diag_log format ["[maptools debug] emit name=%1", _name];
        _created pushBack _name;
    } forEach _polylines;
    uksf_maptools_playerShapes append _created;
    _created
};

uksf_maptools_fnc_wipeShapes = {
    { deleteMarker _x } forEach uksf_maptools_playerShapes;
    uksf_maptools_playerShapes = [];
};

uksf_maptools_fnc_setMode = {
    params [["_mode", "circle", [""]]];
    if (!(_mode in uksf_maptools_modes)) exitWith {};
    if (_mode isEqualTo uksf_maptools_currentMode) exitWith {};
    uksf_maptools_currentMode = _mode;
    uksf_maptools_currentModeLabel = switch (_mode) do {
        case "circle": { "Circle" };
        case "ellipse": { "Ellipse" };
        case "racetrack": { "Race-track" };
        case "cone": { "Cone" };
        default { _mode };
    };
    private _dropdown = uiNamespace getVariable ["uksf_maptools_headerDropdown", controlNull];
    if (!isNull _dropdown) then {
        private _index = uksf_maptools_modes find _mode;
        if (_index >= 0) then {
            _dropdown lbSetCurSel _index;
        };
    };
};

uksf_maptools_fnc_cycleMode = {
    private _index = uksf_maptools_modes find uksf_maptools_currentMode;
    private _next = uksf_maptools_modes select ((_index + 1) mod (count uksf_maptools_modes));
    [_next] call uksf_maptools_fnc_setMode;
    _next
};

uksf_maptools_fnc_canDrawShape = {
    visibleMap && {[ACE_player, "ACE_MapTools"] call ace_common_fnc_hasItem}
};

uksf_maptools_fnc_updatePreview = {
    { deleteMarkerLocal _x } forEach uksf_maptools_previewMarkers;
    uksf_maptools_previewMarkers = [];
    if (uksf_maptools_state isEqualTo "idle") exitWith {};
    private _polylines = [];
    private _axisX = (uksf_maptools_stage1End#0) - (uksf_maptools_stage1Start#0);
    private _axisY = (uksf_maptools_stage1End#1) - (uksf_maptools_stage1Start#1);
    private _axisLen = sqrt (_axisX * _axisX + _axisY * _axisY);
    if (_axisLen > 0) then {
        private _rotationDeg = _axisY atan2 _axisX;
        private _ux = _axisX / _axisLen;
        private _uy = _axisY / _axisLen;
        private _midX = (uksf_maptools_stage1Start#0 + uksf_maptools_stage1End#0) / 2;
        private _midY = (uksf_maptools_stage1Start#1 + uksf_maptools_stage1End#1) / 2;
        switch (uksf_maptools_state) do {
            case "stage1": {
                switch (uksf_maptools_currentMode) do {
                    case "circle": {
                        _polylines = [uksf_maptools_stage1Start, _axisLen] call uksf_maptools_fnc_buildCircle;
                    };
                    case "ellipse": {
                        private _semiMajor = _axisLen / 2;
                        private _semiMinor = _semiMajor / 2;
                        _polylines = [[_midX, _midY, 0], _semiMajor, _semiMinor, _rotationDeg] call uksf_maptools_fnc_buildEllipse;
                    };
                    case "racetrack": {
                        private _halfLength = _axisLen / 2;
                        private _halfWidth = _halfLength / 4;
                        private _centre = [
                            _midX + (-_uy) * _halfWidth,
                            _midY + _ux * _halfWidth,
                            0
                        ];
                        _polylines = [_centre, _halfLength, _halfWidth, _rotationDeg] call uksf_maptools_fnc_buildRaceTrack;
                    };
                    case "cone": {
                        _polylines = [uksf_maptools_stage1Start, _axisLen, 7.5, _rotationDeg] call uksf_maptools_fnc_buildCone;
                    };
                };
            };
            case "stage2": {
                private _toS2X = (uksf_maptools_stage2Pos#0) - (uksf_maptools_stage1Start#0);
                private _toS2Y = (uksf_maptools_stage2Pos#1) - (uksf_maptools_stage1Start#1);
                private _parallel = _toS2X * _ux + _toS2Y * _uy;
                private _perpSigned = _toS2X * (-_uy) + _toS2Y * _ux;
                switch (uksf_maptools_currentMode) do {
                    case "ellipse": {
                        private _semiMinor = uksf_maptools_stage2DefaultSecondary + _perpSigned;
                        _polylines = [[_midX, _midY, 0], _axisLen / 2, _semiMinor, _rotationDeg] call uksf_maptools_fnc_buildEllipse;
                    };
                    case "racetrack": {
                        private _fullWidth = uksf_maptools_stage2DefaultSecondary + _perpSigned;
                        private _halfWidth = (abs _fullWidth) / 2;
                        private _centre = [
                            _midX + (-_uy) * (_fullWidth / 2),
                            _midY + _ux * (_fullWidth / 2),
                            0
                        ];
                        _polylines = [_centre, _axisLen / 2, _halfWidth, _rotationDeg] call uksf_maptools_fnc_buildRaceTrack;
                    };
                    case "cone": {
                        private _halfAngle = uksf_maptools_stage2DefaultSecondary + (_perpSigned atan2 _parallel);
                        _polylines = [uksf_maptools_stage1Start, _axisLen, _halfAngle, _rotationDeg] call uksf_maptools_fnc_buildCone;
                    };
                };
            };
        };
    };
    if (count _polylines == 0) exitWith {};
    private _colour = missionNamespace getVariable ["ace_markers_currentMarkerColorConfigName", "ColorBlack"];
    if (_colour isEqualTo "") then { _colour = "ColorBlack" };
    {
        private _name = format ["uksf_maptools_preview_%1", _forEachIndex];
        createMarkerLocal [_name, _x select [0, 2]];
        _name setMarkerShapeLocal "POLYLINE";
        _name setMarkerColorLocal _colour;
        _name setMarkerPolylineLocal _x;
        uksf_maptools_previewMarkers pushBack _name;
    } forEach _polylines;
};

uksf_maptools_fnc_handleMouseMove = {
    params ["_mapControl", "_screenPosX", "_screenPosY"];
    if (uksf_maptools_state isEqualTo "idle") exitWith {};
    private _mouseWorld = _mapControl ctrlMapScreenToWorld [_screenPosX, _screenPosY];
    switch (uksf_maptools_state) do {
        case "stage1": { uksf_maptools_stage1End = _mouseWorld };
        case "stage2": { uksf_maptools_stage2Pos = _mouseWorld };
    };
    call uksf_maptools_fnc_updatePreview;
};

uksf_maptools_fnc_handleMouseButton = {
    params ["_dir", "_params"];
    _params params ["_control", "_button", "_screenPosX", "_screenPosY"];
    private _mouseWorld = _control ctrlMapScreenToWorld [_screenPosX, _screenPosY];

    if (_button == 1 && {_dir == 1} && {uksf_maptools_state isNotEqualTo "idle"}) exitWith {
        ["idle"] call uksf_maptools_fnc_setState;
        uksf_maptools_drawKeyHeld = false;
        call uksf_maptools_fnc_updatePreview;
        true
    };
    if (_button != 0) exitWith { false };

    if (_dir == 1) then {
        if (uksf_maptools_state == "stage2") exitWith {
            uksf_maptools_stage2Pos = _mouseWorld;
            private _polylines = call {
                private _axisX = (uksf_maptools_stage1End#0) - (uksf_maptools_stage1Start#0);
                private _axisY = (uksf_maptools_stage1End#1) - (uksf_maptools_stage1Start#1);
                private _axisLen = sqrt (_axisX * _axisX + _axisY * _axisY);
                private _rotationDeg = _axisY atan2 _axisX;
                private _toS2X = (uksf_maptools_stage2Pos#0) - (uksf_maptools_stage1Start#0);
                private _toS2Y = (uksf_maptools_stage2Pos#1) - (uksf_maptools_stage1Start#1);
                private _ux = _axisX / _axisLen;
                private _uy = _axisY / _axisLen;
                private _parallel = _toS2X * _ux + _toS2Y * _uy;
                private _perpSigned = _toS2X * (-_uy) + _toS2Y * _ux;
                switch (uksf_maptools_currentMode) do {
                    case "ellipse": {
                        private _semiMinor = uksf_maptools_stage2DefaultSecondary + _perpSigned;
                        private _centre = [
                            ((uksf_maptools_stage1Start#0) + (uksf_maptools_stage1End#0)) / 2,
                            ((uksf_maptools_stage1Start#1) + (uksf_maptools_stage1End#1)) / 2,
                            0
                        ];
                        [_centre, _axisLen / 2, _semiMinor, _rotationDeg] call uksf_maptools_fnc_buildEllipse
                    };
                    case "racetrack": {
                        private _fullWidth = uksf_maptools_stage2DefaultSecondary + _perpSigned;
                        private _halfWidth = (abs _fullWidth) / 2;
                        private _midX = (uksf_maptools_stage1Start#0 + uksf_maptools_stage1End#0) / 2;
                        private _midY = (uksf_maptools_stage1Start#1 + uksf_maptools_stage1End#1) / 2;
                        private _centre = [
                            _midX + (-_uy) * (_fullWidth / 2),
                            _midY + _ux * (_fullWidth / 2),
                            0
                        ];
                        [_centre, _axisLen / 2, _halfWidth, _rotationDeg] call uksf_maptools_fnc_buildRaceTrack
                    };
                    case "cone": {
                        private _halfAngle = uksf_maptools_stage2DefaultSecondary + (_perpSigned atan2 _parallel);
                        [uksf_maptools_stage1Start, _axisLen, _halfAngle, _rotationDeg] call uksf_maptools_fnc_buildCone
                    };
                    default { [] };
                };
            };
            if (count _polylines > 0) then {
                [_polylines] call uksf_maptools_fnc_emitShape;
            };
            ["idle"] call uksf_maptools_fnc_setState;
            uksf_maptools_drawKeyHeld = false;
            call uksf_maptools_fnc_updatePreview;
            true
        };

        if (uksf_maptools_state == "idle" && {uksf_maptools_drawKeyHeld} && {call uksf_maptools_fnc_canDrawShape}) exitWith {
            uksf_maptools_stage1Start = _mouseWorld;
            uksf_maptools_stage1End = _mouseWorld;
            ["stage1"] call uksf_maptools_fnc_setState;
            call uksf_maptools_fnc_updatePreview;
            true
        };
        false
    } else {
        if (uksf_maptools_state == "stage1") exitWith {
            uksf_maptools_stage1End = _mouseWorld;
            if (uksf_maptools_currentMode == "circle") then {
                private _radius = uksf_maptools_stage1Start distance2D uksf_maptools_stage1End;
                private _polylines = [uksf_maptools_stage1Start, _radius] call uksf_maptools_fnc_buildCircle;
                [_polylines] call uksf_maptools_fnc_emitShape;
                ["idle"] call uksf_maptools_fnc_setState;
                uksf_maptools_drawKeyHeld = false;
                call uksf_maptools_fnc_updatePreview;
            } else {
                uksf_maptools_stage2Pos = uksf_maptools_stage1End;
                private _axisLen = uksf_maptools_stage1Start distance2D uksf_maptools_stage1End;
                uksf_maptools_stage2DefaultSecondary = switch (uksf_maptools_currentMode) do {
                    case "ellipse": { _axisLen / 4 };
                    case "racetrack": { _axisLen / 4 };
                    case "cone": { 7.5 };
                    default { 0 };
                };
                ["stage2"] call uksf_maptools_fnc_setState;
                call uksf_maptools_fnc_updatePreview;
            };
            true
        };
        false
    };
};

uksf_maptools_fnc_initHeaderDropdown = {
    private _display = findDisplay 12;
    if (isNull _display) exitWith {};
    private _topRight = _display displayCtrl 2302;
    if (isNull _topRight) exitWith {};

    private _dropdown = _display ctrlCreate ["RscCombo", -1, _topRight];
    uiNamespace setVariable ["uksf_maptools_headerDropdown", _dropdown];

    private _gridW = ((safezoneW / safezoneH) min 1.2) / 40;
    private _gridH = ((safezoneW / safezoneH) min 1.2) / 1.2 / 25;
    _dropdown ctrlSetPosition [
        6.55 * _gridW,
        0.1 * _gridH,
        4.95 * _gridW,
        1.2 * _gridH
    ];
    _dropdown ctrlSetTooltip "Shape draw mode";
    _dropdown ctrlCommit 0;

    private _selectedIndex = 0;
    {
        private _label = switch (_x) do {
            case "circle": { "Circle" };
            case "ellipse": { "Ellipse" };
            case "racetrack": { "Race-track" };
            case "cone": { "Cone" };
            default { _x };
        };
        private _index = _dropdown lbAdd _label;
        _dropdown lbSetData [_index, _x];
        if (_x isEqualTo uksf_maptools_currentMode) then { _selectedIndex = _index };
    } forEach uksf_maptools_modes;

    _dropdown lbSetCurSel _selectedIndex;
    _dropdown ctrlAddEventHandler ["LBSelChanged", {
        params ["_ctrl", "_idx"];
        private _mode = _ctrl lbData _idx;
        if (_mode isNotEqualTo uksf_maptools_currentMode) then {
            [_mode] call uksf_maptools_fnc_setMode;
        };
    }];
};

if (!isNull _mapControl) then {
    private _newEHs = [];
    _newEHs pushBack ["MouseButtonDown", _mapControl ctrlAddEventHandler ["MouseButtonDown", { [1, _this] call uksf_maptools_fnc_handleMouseButton }]];
    _newEHs pushBack ["MouseButtonUp",   _mapControl ctrlAddEventHandler ["MouseButtonUp",   { [0, _this] call uksf_maptools_fnc_handleMouseButton }]];
    _newEHs pushBack ["MouseMoving",     _mapControl ctrlAddEventHandler ["MouseMoving",     { call uksf_maptools_fnc_handleMouseMove }]];
    missionNamespace setVariable ["uksf_maptools_debugEHs", _newEHs];
    call uksf_maptools_fnc_initHeaderDropdown;
};

private _newPehId = ["visibleMap", {
    params ["", "_mapOn"];
    private _pehDisplay = findDisplay 12;
    private _pehMapControl = if (isNull _pehDisplay) then { controlNull } else { _pehDisplay displayCtrl 51 };

    if (_mapOn) then {
        if (isNull _pehMapControl) exitWith {};
        private _downId = _pehMapControl ctrlAddEventHandler ["MouseButtonDown", { [1, _this] call uksf_maptools_fnc_handleMouseButton }];
        private _upId   = _pehMapControl ctrlAddEventHandler ["MouseButtonUp",   { [0, _this] call uksf_maptools_fnc_handleMouseButton }];
        private _moveId = _pehMapControl ctrlAddEventHandler ["MouseMoving",     { call uksf_maptools_fnc_handleMouseMove }];
        missionNamespace setVariable ["uksf_maptools_debugEHs", [
            ["MouseButtonDown", _downId],
            ["MouseButtonUp", _upId],
            ["MouseMoving", _moveId]
        ]];
        call uksf_maptools_fnc_initHeaderDropdown;
    } else {
        private _ehs = missionNamespace getVariable ["uksf_maptools_debugEHs", []];
        if (!isNull _pehMapControl) then {
            {
                _x params ["_evtName", "_evtId"];
                _pehMapControl ctrlRemoveEventHandler [_evtName, _evtId];
            } forEach _ehs;
        };
        missionNamespace setVariable ["uksf_maptools_debugEHs", []];
        uiNamespace setVariable ["uksf_maptools_headerDropdown", controlNull];
    };
}] call CBA_fnc_addPlayerEventHandler;
missionNamespace setVariable ["uksf_maptools_debugVisibleMapPEH", _newPehId];

[
    "UKSF",
    "drawShape",
    [
        "Draw shape (hold to start)",
        "Hold to start a shape on next LMB drag. Releasing does not cancel an in-progress shape. Requires ACE Map Tools."
    ],
    {
        uksf_maptools_drawKeyHeld = true;
        private _mc = (findDisplay 12) displayCtrl 51;
        if (!isNull _mc) then { _mc ctrlMapCursor ["Track", "Move"] };
        false
    },
    {
        uksf_maptools_drawKeyHeld = false;
        private _mc = (findDisplay 12) displayCtrl 51;
        if (!isNull _mc) then { _mc ctrlMapCursor ["Track", "Track"] };
        false
    },
    [0x2B, [false, false, false]]
] call CBA_fnc_addKeybind;

[
    "UKSF",
    "cycleShapeMode",
    [
        "Cycle shape mode",
        "Advance to the next shape mode (Circle / Ellipse / Race-track / Cone)."
    ],
    {
        call uksf_maptools_fnc_cycleMode;
        systemChat format ["Shape: %1", uksf_maptools_currentModeLabel];
        false
    },
    {false},
    [0x2B, [false, true, false]]
] call CBA_fnc_addKeybind;

hint "uksf_maptools debug loaded";
