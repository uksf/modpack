#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Unified 3D PFH for all visualisation provider visualisations.
        Runs every frame while Zeus is open.

    Parameter(s):
        None

    Return Value:
        None
*/
private _cameraPosition = positionCameraToWorld [0,0,0];

// AI Commander
if (GVAR(visualiseActiveToggles) getOrDefault ["aicommander", false]) then {
    private _groundData = GVAR(visualiseData) getOrDefault ["aicommander_ground", []];
    if (_groundData isNotEqualTo []) then {
        _groundData params ["_spawnPoints", "_stagingAreas", "_aggression", "_tierStatus", "_killerPlayers", "_responseGroups"];

        // Aggression meter (always draw at top of screen as HUD text)
        _tierStatus params ["_tier1Deployed", "_tier2Deployed"];
        private _tierText = "";
        if (_tier1Deployed) then { _tierText = " [T1 ACTIVE]" };
        if (_tier2Deployed) then { _tierText = _tierText + " [T2 ACTIVE]" };
        private _aggressionColour = switch (true) do {
            case (_aggression >= 120): { [1,0,0,1] };
            case (_aggression >= 80): { [1,0.5,0,1] };
            case (_aggression >= 40): { [1,1,0,1] };
            default { [0.5,1,0.5,1] };
        };
        drawIcon3D ["", _aggressionColour, AGLToASL (positionCameraToWorld [0,0,5]), 0, 0, 0, format ["Aggression: %1%2", _aggression, _tierText], 2, 0.04, "PuristaBold", "center", true];

        // Spawn points (within 5000m)
        {
            _x params ["_position", "_type"];
            if (_cameraPosition distance2D _position < 5000) then {
                drawIcon3D ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [0.8,0.4,0,0.8], ASLToAGL (AGLToASL _position), 0.7, 0.7, 0, format ["Spawn: %1", toUpper _type], 0.1, 0.03, "PuristaMedium", "center"];
            };
        } forEach _spawnPoints;

        // Staging areas (within 5000m)
        {
            if (_cameraPosition distance2D _x < 5000) then {
                drawIcon3D ["\a3\ui_f\data\map\markers\military\flag_ca.paa", [0.8,0.6,0,0.8], ASLToAGL (AGLToASL _x), 0.7, 0.7, 0, "Staging", 0.1, 0.03, "PuristaMedium", "center"];
            };
        } forEach _stagingAreas;

        // Killer players (within 2000m)
        {
            _x params ["_position", "_timeLeft"];
            if (_cameraPosition distance2D _position < 2000) then {
                drawIcon3D ["", [1,0,0,0.8], ASLToAGL (AGLToASL _position), 0, 3, 0, format ["Aggro %1s", round _timeLeft], 0.1, 0.03, "PuristaBold", "center"];
            };
        } forEach _killerPlayers;

        // Response group targets (within 5000m)
        {
            _x params ["_groupId", "_leaderPosition", "_targetPosition"];
            if (_leaderPosition isNotEqualTo [] && {_cameraPosition distance2D _leaderPosition < 5000}) then {
                drawIcon3D ["", [1,0,0,0.6], ASLToAGL (AGLToASL _leaderPosition), 0, 0, 0, _groupId, 0.1, 0.025, "PuristaMedium", "center"];
            };
            if (_targetPosition isNotEqualTo [] && {_cameraPosition distance2D _targetPosition < 5000}) then {
                drawIcon3D ["\a3\ui_f\data\map\markers\military\objective_ca.paa", [1,0,0,0.6], ASLToAGL (AGLToASL _targetPosition), 0.7, 0.7, 0, format ["Target: %1", _groupId], 0.1, 0.025, "PuristaMedium", "center"];
            };
        } forEach _responseGroups;
    };

    // Air commander
    private _airData = GVAR(visualiseData) getOrDefault ["aicommander_air", []];
    if (_airData isNotEqualTo []) then {
        _airData params ["_aaSites", "_airspaceCentres", "_enemyAirfields", "_airSpawnPoints"];

        {
            _x params ["_position", "_occupied"];
            if (_cameraPosition distance2D _position < 5000) then {
                private _colour = [[1,0,0,0.8], [0,0.6,0,0.8]] select _occupied;
                drawIcon3D ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", _colour, ASLToAGL (AGLToASL _position), 0.7, 0.7, 0, format ["AA %1", ["EMPTY", "MANNED"] select _occupied], 0.1, 0.03, "PuristaMedium", "center"];
            };
        } forEach _aaSites;

        {
            if (_cameraPosition distance2D _x < 5000) then {
                drawIcon3D ["\a3\ui_f\data\map\markers\military\circle_ca.paa", [0.5,0.5,1,0.6], ASLToAGL (AGLToASL _x), 1, 1, 0, "Airspace Centre", 0.1, 0.03, "PuristaMedium", "center"];
            };
        } forEach _airspaceCentres;

        {
            if (_cameraPosition distance2D _x < 5000) then {
                drawIcon3D ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [0.5,0.5,1,0.6], ASLToAGL (AGLToASL _x), 0.7, 0.7, 0, "Enemy Airfield", 0.1, 0.03, "PuristaMedium", "center"];
            };
        } forEach _enemyAirfields;

        {
            _x params ["_position", "_type"];
            if (_cameraPosition distance2D _position < 5000) then {
                drawIcon3D ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [0.5,0.5,1,0.8], ASLToAGL (AGLToASL _position), 0.5, 0.5, 0, format ["Spawn: %1", toUpper _type], 0.1, 0.025, "PuristaMedium", "center"];
            };
        } forEach _airSpawnPoints;
    };
};

// Sector Control
if (GVAR(visualiseActiveToggles) getOrDefault ["sectorcontrol", false]) then {
    private _sectorControlData = GVAR(visualiseData) getOrDefault ["sectorcontrol", []];
    if (_sectorControlData isNotEqualTo []) then {
        (_sectorControlData#0) params [["_sectors", []]];
        {
            _x params ["_position", "_area", "_owner", "_opforScore", "_bluforScore", "_timeToCapture", "_contested", "_locked", "_name"];
            if (_cameraPosition distance2D _position < 5000) then {
                private _colour = switch (_owner) do {
                    case 0: { [1,0.2,0.2,0.8] };
                    case 1: { [0.2,0.2,1,0.8] };
                    default { [0.6,0.6,0.6,0.8] };
                };

                private _opforPercentage = if (_timeToCapture > 0) then {round ((_opforScore / _timeToCapture) * 100)} else {0};
                private _bluforPercentage = if (_timeToCapture > 0) then {round ((_bluforScore / _timeToCapture) * 100)} else {0};

                drawIcon3D ["", _colour, ASLToAGL (AGLToASL _position), 0, 0, 0, _name, 0.1, 0.04, "PuristaBold", "center"];
                drawIcon3D ["", [0.2,0.2,1,0.7], ASLToAGL (AGLToASL _position), 0, -2, 0, format ["BLU: %1%2", _bluforPercentage, "%"], 0.1, 0.03, "PuristaMedium", "center"];
                drawIcon3D ["", [1,0.2,0.2,0.7], ASLToAGL (AGLToASL _position), 0, -4, 0, format ["OPF: %1%2", _opforPercentage, "%"], 0.1, 0.03, "PuristaMedium", "center"];
                if (_contested) then {
                    drawIcon3D ["", [1,1,0,0.8], ASLToAGL (AGLToASL _position), 0, -6, 0, "CONTESTED", 0.1, 0.03, "PuristaBold", "center"];
                };
                if (_locked) then {
                    drawIcon3D ["", [0.5,0.5,0.5,0.8], ASLToAGL (AGLToASL _position), 0, -6, 0, "LOCKED", 0.1, 0.03, "PuristaBold", "center"];
                };
            };
        } forEach _sectors;
    };
};

// Dynamic Patrols
if (GVAR(visualiseActiveToggles) getOrDefault ["dynamicpatrols", false]) then {
    private _patrolData = GVAR(visualiseData) getOrDefault ["dynamicpatrols", []];
    if (_patrolData isNotEqualTo []) then {
        _patrolData params ["_areas", "_excludeAreas", "_includeAreas", "_patrolGroups"];

        // Patrol areas (within 5000m)
        {
            _x params ["_position", "_area", "_groupCount", "_groupLimit", "_distance", "_side"];
            if (_cameraPosition distance2D _position < 5000) then {
                private _colour = switch (_side) do {
                    case west: { [0,0.3,0.6,0.8] };
                    case east: { [0.6,0,0,0.8] };
                    case independent: { [0,0.5,0,0.8] };
                    default { [0.4,0,0.5,0.8] };
                };
                drawIcon3D ["\a3\ui_f\data\map\markers\military\circle_ca.paa", _colour, ASLToAGL (AGLToASL _position), 1, 1, 0, format ["Patrol: %1/%2", _groupCount, _groupLimit], 0.1, 0.03, "PuristaMedium", "center"];
            };
        } forEach _areas;

        // Exclusion zones (within 5000m)
        {
            _x params ["_position", "_area"];
            if (_cameraPosition distance2D _position < 5000) then {
                drawIcon3D ["\a3\ui_f\data\map\markers\military\circle_ca.paa", [1,0,0,0.5], ASLToAGL (AGLToASL _position), 0.7, 0.7, 0, "Exclude", 0.1, 0.025, "PuristaMedium", "center"];
            };
        } forEach _excludeAreas;

        // Inclusion zones (within 5000m)
        {
            _x params ["_position", "_area"];
            if (_cameraPosition distance2D _position < 5000) then {
                drawIcon3D ["\a3\ui_f\data\map\markers\military\circle_ca.paa", [0,0.8,0,0.5], ASLToAGL (AGLToASL _position), 0.7, 0.7, 0, "Include", 0.1, 0.025, "PuristaMedium", "center"];
            };
        } forEach _includeAreas;
    };
};

// Area Rating
if (GVAR(visualiseActiveToggles) getOrDefault ["arearating", false]) then {
    private _areaRatingData = GVAR(visualiseData) getOrDefault ["arearating", []];
    if (_areaRatingData isNotEqualTo []) then {
        (_areaRatingData#0) params [["_areas", []]];
        {
            _x params ["_position", "_area", "_name", "_percentage", "_startPercentage"];
            if (_cameraPosition distance2D _position < 5000) then {
                private _ratio = _percentage / 100;
                private _colour = [1 - _ratio, _ratio, 0, 0.8];

                private _trend = if (_percentage > _startPercentage) then {"^"} else {
                    if (_percentage < _startPercentage) then {"v"} else {"-"}
                };

                drawIcon3D ["", _colour, ASLToAGL (AGLToASL _position), 0, 0, 0, format ["%1: %2%3 %4", _name, _percentage, "%", _trend], 0.1, 0.04, "PuristaBold", "center"];
            };
        } forEach _areas;
    };
};

// Cached Groups
if (GVAR(visualiseActiveToggles) getOrDefault ["cachedgroups", false]) then {
    private _cachingData = GVAR(visualiseData) getOrDefault ["cachedgroups", []];
    if (_cachingData isNotEqualTo []) then {
        _cachingData params ["_cachedGroups", "_cacheDistance", "_totalActive", "_totalCached"];

        // HUD summary
        drawIcon3D ["", [0.8,0.8,0.8,1], AGLToASL (positionCameraToWorld [0,0,5]), 0, 0, 0, format ["Cached: %1 | Active: %2", _totalCached, _totalActive], 2, 0.03, "PuristaBold", "center", true];

        // Cached group icons (within 3000m)
        {
            _x params ["_position", "_side", "_unitCount"];
            if (_cameraPosition distance2D _position < 3000) then {
                private _colour = switch (_side) do {
                    case west: { [0,0.3,0.6,0.4] };
                    case east: { [0.6,0,0,0.4] };
                    case independent: { [0,0.5,0,0.4] };
                    default { [0.4,0,0.5,0.4] };
                };
                drawIcon3D ["\a3\ui_f\data\map\markers\military\dot_ca.paa", _colour, ASLToAGL (AGLToASL _position), 0.5, 0.5, 0, format ["%1", _unitCount], 0.1, 0.02, "PuristaMedium", "center"];
            };
        } forEach _cachedGroups;
    };
};

// Rebro Connections
if (GVAR(visualiseActiveToggles) getOrDefault ["rebroconnections", false]) then {
    private _rebroConnectionsData = GVAR(visualiseData) getOrDefault ["rebroconnections", []];
    if (_rebroConnectionsData isNotEqualTo []) then {
        _rebroConnectionsData params ["_rebroPositions", "_connections"];

        // Rebro station icons
        {
            drawIcon3D ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", [0,0.8,0.8,0.8], ASLToAGL (AGLToASL _x), 0.7, 0.7, 0, "ReBro", 0.1, 0.03, "PuristaMedium", "center"];
        } forEach _rebroPositions;

        // Connection lines
        {
            _x params ["_playerPosition", "_playerName", "_rebroPosition", "_signalPower", "_signalDecibels"];
            private _colour = switch (true) do {
                case (_signalPower > 0.7): { [0,0.8,0,0.6] };
                case (_signalPower > 0.4): { [0.8,0.8,0,0.6] };
                default { [0.8,0,0,0.6] };
            };
            drawLine3D [ASLToAGL (AGLToASL _playerPosition), ASLToAGL (AGLToASL _rebroPosition), _colour];
        } forEach _connections;
    };
};

// Rebro Network
if (GVAR(visualiseActiveToggles) getOrDefault ["rebronetwork", false]) then {
    private _rebroNetworkData = GVAR(visualiseData) getOrDefault ["rebronetwork", []];
    if (_rebroNetworkData isNotEqualTo []) then {
        _rebroNetworkData params ["_rebroPositions", "_players", "_links"];

        // Rebro station icons
        {
            drawIcon3D ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", [0,0.8,0.8,0.8], ASLToAGL (AGLToASL _x), 0.7, 0.7, 0, "ReBro", 0.1, 0.03, "PuristaMedium", "center"];
        } forEach _rebroPositions;

        // Network relay lines
        {
            _x params ["_playerIndex", "_targetUID", "_signalPower", "_isDirect", "_rebroPosition"];
            if (_playerIndex >= 0 && {_playerIndex < count _players}) then {
                private _fromPosition = (_players#_playerIndex)#0;
                if (!_isDirect && {_rebroPosition isNotEqualTo []}) then {
                    private _colour = switch (true) do {
                        case (_signalPower > 0.7): { [0,0.8,0,0.5] };
                        case (_signalPower > 0.4): { [0.8,0.8,0,0.5] };
                        default { [0.8,0,0,0.5] };
                    };
                    drawLine3D [ASLToAGL (AGLToASL _fromPosition), ASLToAGL (AGLToASL _rebroPosition), _colour];
                };
            };
        } forEach _links;
    };
};
