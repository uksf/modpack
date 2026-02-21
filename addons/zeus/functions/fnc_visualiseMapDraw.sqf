#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Unified map draw handler for all visualisation provider visualisations.
        Called every frame while Zeus map is open.

    Parameter(s):
        0: Map control <CONTROL>

    Return Value:
        None
*/
params ["_map"];

// AI Commander - Ground
if (GVAR(visualiseActiveToggles) getOrDefault ["aicommander", false]) then {
    private _groundData = GVAR(visualiseData) getOrDefault ["aicommander_ground", []];
    if (_groundData isNotEqualTo []) then {
        _groundData params ["_spawnPoints", "_stagingAreas", "_aggression", "_tierStatus", "_killerPlayers", "_responseGroups"];

        // Spawn points
        {
            _x params ["_position", "_type"];
            private _text = toUpper _type;
            _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [0.8,0.4,0,0.8], _position, 24, 24, 0, format ["Spawn: %1", _text], 0.1, 0.03, "PuristaMedium", "right"];
        } forEach _spawnPoints;

        // Staging areas
        {
            _map drawIcon ["\a3\ui_f\data\map\markers\military\flag_ca.paa", [0.8,0.6,0,0.8], _x, 24, 24, 0, "Staging", 0.1, 0.03, "PuristaMedium", "right"];
        } forEach _stagingAreas;

        // Killer players
        {
            _x params ["_position", "_timeLeft"];
            _map drawIcon ["\a3\ui_f\data\map\markers\military\warning_ca.paa", [1,0,0,0.8], _position, 20, 20, 0, format ["Aggro %1s", round _timeLeft], 0.1, 0.03, "PuristaMedium", "right"];
        } forEach _killerPlayers;

        // Response groups with target lines
        {
            _x params ["_groupId", "_leaderPosition", "_targetPosition"];
            _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [1,0,0,0.6], _leaderPosition, 16, 16, 0, _groupId, 0.1, 0.025, "PuristaMedium", "right"];
            if (_targetPosition isNotEqualTo []) then {
                _map drawLine [_leaderPosition, _targetPosition, [1,0,0,0.4]];
                _map drawIcon ["\a3\ui_f\data\map\markers\military\objective_ca.paa", [1,0,0,0.6], _targetPosition, 16, 16, 0, "", 0.1, 0.025, "PuristaMedium", "right"];
            };
        } forEach _responseGroups;
    };

    // AI Commander - Air
    private _airData = GVAR(visualiseData) getOrDefault ["aicommander_air", []];
    if (_airData isNotEqualTo []) then {
        _airData params ["_aaSites", "_airspaceCentres", "_enemyAirfields", "_airSpawnPoints"];

        {
            _x params ["_position", "_occupied"];
            private _colour = [[1,0,0,0.8], [0,0.6,0,0.8]] select _occupied;
            _map drawIcon ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", _colour, _position, 24, 24, 0, format ["AA %1", ["EMPTY", "MANNED"] select _occupied], 0.1, 0.03, "PuristaMedium", "right"];
        } forEach _aaSites;

        {
            _map drawIcon ["\a3\ui_f\data\map\markers\military\circle_ca.paa", [0.5,0.5,1,0.6], _x, 30, 30, 0, "Airspace", 0.1, 0.03, "PuristaMedium", "right"];
        } forEach _airspaceCentres;

        {
            _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [0.5,0.5,1,0.6], _x, 24, 24, 0, "Airfield", 0.1, 0.03, "PuristaMedium", "right"];
        } forEach _enemyAirfields;

        {
            _x params ["_position", "_type"];
            _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [0.5,0.5,1,0.8], _position, 20, 20, 0, format ["Spawn: %1", toUpper _type], 0.1, 0.03, "PuristaMedium", "right"];
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

            private _colour = switch (_owner) do {
                case 0: { [0.5,0,0,0.3] };
                case 1: { [0,0,0.5,0.3] };
                default { [0.5,0.5,0.5,0.3] };
            };

            private _opforPercentage = if (_timeToCapture > 0) then {round ((_opforScore / _timeToCapture) * 100)} else {0};
            private _bluforPercentage = if (_timeToCapture > 0) then {round ((_bluforScore / _timeToCapture) * 100)} else {0};

            private _status = format ["%1 | BLU:%2%3 OPF:%4%3", _name, _bluforPercentage, "%", _opforPercentage];
            if (_contested) then { _status = _status + " [CONTESTED]" };
            if (_locked) then { _status = _status + " [LOCKED]" };

            _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", _colour, _position, 24, 24, 0, _status, 0.1, 0.03, "PuristaBold", "right"];
        } forEach _sectors;
    };
};

// Dynamic Patrols
if (GVAR(visualiseActiveToggles) getOrDefault ["dynamicpatrols", false]) then {
    private _patrolData = GVAR(visualiseData) getOrDefault ["dynamicpatrols", []];
    if (_patrolData isNotEqualTo []) then {
        _patrolData params ["_areas", "_excludeAreas", "_includeAreas", "_patrolGroups"];

        // Patrol areas
        {
            _x params ["_position", "_area", "_groupCount", "_groupLimit", "_distance", "_side"];
            private _colour = switch (_side) do {
                case west: { [0,0.3,0.6,0.5] };
                case east: { [0.6,0,0,0.5] };
                case independent: { [0,0.5,0,0.5] };
                default { [0.4,0,0.5,0.5] };
            };
            _map drawIcon ["\a3\ui_f\data\map\markers\military\circle_ca.paa", _colour, _position, 24, 24, 0, format ["Patrol: %1/%2", _groupCount, _groupLimit], 0.1, 0.03, "PuristaMedium", "right"];
        } forEach _areas;

        // Exclusion zones
        {
            _x params ["_position", "_area"];
            _map drawIcon ["\a3\ui_f\data\map\markers\military\circle_ca.paa", [1,0,0,0.4], _position, 20, 20, 0, "Exclude", 0.1, 0.025, "PuristaMedium", "right"];
        } forEach _excludeAreas;

        // Inclusion zones
        {
            _x params ["_position", "_area"];
            _map drawIcon ["\a3\ui_f\data\map\markers\military\circle_ca.paa", [0,0.8,0,0.4], _position, 20, 20, 0, "Include", 0.1, 0.025, "PuristaMedium", "right"];
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

            private _ratio = _percentage / 100;
            private _colour = [1 - _ratio, _ratio, 0, 0.6];

            private _trend = if (_percentage > _startPercentage) then {"^"} else {
                if (_percentage < _startPercentage) then {"v"} else {"-"}
            };

            _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", _colour, _position, 24, 24, 0, format ["%1: %2%3 %4", _name, _percentage, "%", _trend], 0.1, 0.03, "PuristaBold", "right"];
        } forEach _areas;
    };
};

// Cached Groups
if (GVAR(visualiseActiveToggles) getOrDefault ["cachedgroups", false]) then {
    private _cachingData = GVAR(visualiseData) getOrDefault ["cachedgroups", []];
    if (_cachingData isNotEqualTo []) then {
        _cachingData params ["_cachedGroups", "_cacheDistance", "_totalActive", "_totalCached"];

        {
            _x params ["_position", "_side", "_unitCount"];
            private _colour = switch (_side) do {
                case west: { [0,0.3,0.6,0.3] };
                case east: { [0.6,0,0,0.3] };
                case independent: { [0,0.5,0,0.3] };
                default { [0.4,0,0.5,0.3] };
            };
            _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", _colour, _position, 16, 16, 0, format ["%1", _unitCount], 0.1, 0.02, "PuristaMedium", "right"];
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
            _map drawIcon ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", [0,0.8,0.8,0.8], _x, 24, 24, 0, "ReBro", 0.1, 0.03, "PuristaMedium", "right"];
        } forEach _rebroPositions;

        // Player to rebro connections
        {
            _x params ["_playerPosition", "_playerName", "_rebroPosition", "_signalPower", "_signalDecibels"];
            private _colour = switch (true) do {
                case (_signalPower > 0.7): { [0,0.8,0,0.5] };
                case (_signalPower > 0.4): { [0.8,0.8,0,0.5] };
                default { [0.8,0,0,0.5] };
            };
            _map drawLine [_playerPosition, _rebroPosition, _colour];
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
            _map drawIcon ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", [0,0.8,0.8,0.8], _x, 24, 24, 0, "ReBro", 0.1, 0.03, "PuristaMedium", "right"];
        } forEach _rebroPositions;

        // Network links
        {
            _x params ["_playerIndex", "_targetUID", "_signalPower", "_isDirect", "_rebroPosition"];
            if (_playerIndex >= 0 && {_playerIndex < count _players}) then {
                private _fromPosition = (_players#_playerIndex)#0;
                private _colour = switch (true) do {
                    case (_signalPower > 0.7): { [0,0.8,0,0.4] };
                    case (_signalPower > 0.4): { [0.8,0.8,0,0.4] };
                    default { [0.8,0,0,0.4] };
                };
                if (!_isDirect && {_rebroPosition isNotEqualTo []}) then {
                    _map drawLine [_fromPosition, _rebroPosition, _colour];
                };
            };
        } forEach _links;
    };
};
