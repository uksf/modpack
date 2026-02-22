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
            _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [1,0.5,0,1], _position, 24, 24, 0, format ["Spawn: %1", toUpper _type], 1, 0.04, "TahomaB", "right"];
        } forEach _spawnPoints;

        // Staging areas
        {
            _map drawIcon ["\a3\ui_f\data\map\markers\military\flag_ca.paa", [1,0.8,0,1], _x, 24, 24, 0, "Staging", 1, 0.04, "TahomaB", "right"];
        } forEach _stagingAreas;

        // Killer players
        {
            _x params ["_playerNetId", "_timeLeft"];
            private _playerObject = objectFromNetId _playerNetId;
            if (!isNull _playerObject) then {
                _map drawIcon ["\a3\ui_f\data\map\markers\military\warning_ca.paa", [1,0,0,1], getPosATL _playerObject, 20, 20, 0, format ["Aggro %1s", round _timeLeft], 1, 0.04, "TahomaB", "right"];
            };
        } forEach _killerPlayers;

        // Response groups with target lines
        {
            _x params ["_groupId", "_leaderNetId", "_targetPosition"];
            private _leaderObject = objectFromNetId _leaderNetId;
            if (!isNull _leaderObject) then {
                private _leaderPosition = getPosATL _leaderObject;
                _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [1,0,0,1], _leaderPosition, 16, 16, 0, _groupId, 1, 0.03, "TahomaB", "right"];
                if (_targetPosition isNotEqualTo []) then {
                    _map drawLine [_leaderPosition, _targetPosition, [1,0,0,1]];
                    _map drawIcon ["\a3\ui_f\data\map\markers\military\objective_ca.paa", [1,0,0,1], _targetPosition, 16, 16, 0, "", 1, 0.03, "TahomaB", "right"];
                };
            };
        } forEach _responseGroups;
    };

    // AI Commander - Air
    private _airData = GVAR(visualiseData) getOrDefault ["aicommander_air", []];
    if (_airData isNotEqualTo []) then {
        _airData params ["_aaSites", "_airspaceCentres", "_enemyAirfields", "_airSpawnPoints"];

        {
            _x params ["_position", "_occupied", "_vehicleNetId"];
            private _colour = [[1,0,0,1], [0,1,0,1]] select _occupied;
            _map drawIcon ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", _colour, _position, 24, 24, 0, format ["AA %1", ["EMPTY", "MANNED"] select _occupied], 1, 0.04, "TahomaB", "right"];
            if (_occupied) then {
                private _vehicle = objectFromNetId _vehicleNetId;
                if (!isNull _vehicle) then {
                    _map drawIcon ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", _colour, getPosATL _vehicle, 18, 18, 0, "AA Vehicle", 1, 0.03, "TahomaB", "right"];
                    _map drawLine [_position, getPosATL _vehicle, [0,1,0,1]];
                };
            };
        } forEach _aaSites;

        {
            _map drawIcon ["\a3\ui_f\data\map\markers\military\circle_ca.paa", [0.4,0.7,1,1], _x, 30, 30, 0, "Airspace", 1, 0.04, "TahomaB", "right"];
        } forEach _airspaceCentres;

        {
            _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [0.4,0.7,1,1], _x, 24, 24, 0, "Airfield", 1, 0.04, "TahomaB", "right"];
        } forEach _enemyAirfields;

        {
            _x params ["_position", "_type"];
            _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [0.4,0.7,1,1], _position, 20, 20, 0, format ["Spawn: %1", toUpper _type], 1, 0.03, "TahomaB", "right"];
        } forEach _airSpawnPoints;
    };
};

// Sector Control
if (GVAR(visualiseActiveToggles) getOrDefault ["sectorcontrol", false]) then {
    private _sectorControlData = GVAR(visualiseData) getOrDefault ["sectorcontrol", []];
    if (_sectorControlData isNotEqualTo []) then {
        private _sectors = _sectorControlData#0;
        {
            _x params ["_position", "_area", "_owner", "_opforScore", "_bluforScore", "_timeToCapture", "_contested", "_locked", "_name"];
            _area params ["_halfWidth", "_halfHeight", "_angle", "_isRectangle"];

            private _colour = switch (_owner) do {
                case 0: { [1,0,0,1] };
                case 1: { [0,0.3,1,1] };
                default { [0.6,0.6,0.6,1] };
            };

            private _opforPercentage = if (_timeToCapture > 0) then {round ((_opforScore / _timeToCapture) * 100)} else {0};
            private _bluforPercentage = if (_timeToCapture > 0) then {round ((_bluforScore / _timeToCapture) * 100)} else {0};

            private _status = format ["BLU:%1%2 OPF:%3%2", _bluforPercentage, "%", _opforPercentage];
            if (_contested) then { _status = _status + " [CONTESTED]" };
            if (_locked) then { _status = _status + " [LOCKED]" };

            private _offsetPosition = _position vectorAdd [0, -_halfHeight * 0.5, 0];
            _map drawIcon ["#(argb,8,8,3)color(0,0,0,0)", _colour, _offsetPosition, 0, 0, 0, _status, 1, 0.04, "TahomaB", "right"];
            private _outlineColour = _colour select [0, 3];
            _outlineColour pushBack 0.5;
            if (_isRectangle) then {
                _map drawRectangle [_position, _halfWidth, _halfHeight, _angle, _outlineColour, "#(argb,8,8,3)color(1,1,1,0.1)"];
            } else {
                _map drawEllipse [_position, _halfWidth, _halfHeight, _angle, _outlineColour, "#(argb,8,8,3)color(1,1,1,0.1)"];
            };
        } forEach _sectors;
    };
};

// Dynamic Patrols
if (GVAR(visualiseActiveToggles) getOrDefault ["dynamicpatrols", false]) then {
    private _patrolData = GVAR(visualiseData) getOrDefault ["dynamicpatrols", []];
    if (_patrolData isNotEqualTo []) then {
        _patrolData params ["_areas", "_excludeAreas", "_includeAreas"];

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
};

// Area Rating
if (GVAR(visualiseActiveToggles) getOrDefault ["arearating", false]) then {
    private _areaRatingData = GVAR(visualiseData) getOrDefault ["arearating", []];
    if (_areaRatingData isNotEqualTo []) then {
        private _areas = _areaRatingData#0;
        {
            _x params ["_position", "_area", "_name", "_percentage", "_startPercentage"];
            if !(_position isEqualType []) then {continue};

            private _ratio = _percentage / 100;
            private _colour = if (_ratio < 0.5) then {
                [1, _ratio * 2, 0, 1]
            } else {
                [1 - ((_ratio - 0.5) * 2), 1, 0, 1]
            };

            private _trend = if (_percentage > _startPercentage) then {"^"} else {
                if (_percentage < _startPercentage) then {"v"} else {"-"}
            };

            _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", _colour, _position, 24, 24, 0, format ["%1: %2%3 %4", _name, _percentage, "%", _trend], 1, 0.04, "TahomaB", "right"];
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
};

// Cached Groups
if (GVAR(visualiseActiveToggles) getOrDefault ["cachedgroups", false]) then {
    private _cachingData = GVAR(visualiseData) getOrDefault ["cachedgroups", []];
    if (_cachingData isNotEqualTo []) then {
        _cachingData params ["_cachedGroups", "_cacheDistance", "_totalActive", "_totalCached"];

        {
            _x params ["_position", "_side", "_unitCount"];
            private _colour = switch (_side) do {
                case west: { [0.3,0.5,1,1] };
                case east: { [1,0,0,1] };
                case independent: { [0,1,0,1] };
                default { [0.8,0.3,1,1] };
            };
            _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", _colour, _position, 16, 16, 0, format ["%1", _unitCount], 1, 0.03, "TahomaB", "right"];
        } forEach _cachedGroups;
    };
};

// Rebro Connections
if (GVAR(visualiseActiveToggles) getOrDefault ["rebroconnections", false]) then {
    private _rebroConnectionsData = GVAR(visualiseData) getOrDefault ["rebroconnections", []];
    if (_rebroConnectionsData isNotEqualTo []) then {
        _rebroConnectionsData params ["_rebroNetIds", "_connections"];

        // Rebro station icons
        {
            private _rebroObject = objectFromNetId _x;
            if (!isNull _rebroObject) then {
                _map drawIcon ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", [0,1,1,1], getPosATL _rebroObject, 24, 24, 0, "ReBro", 1, 0.04, "TahomaB", "right"];
            };
        } forEach _rebroNetIds;

        // Connection lines
        {
            _x params ["_playerNetId", "_rebroNetId", "_signalPower"];
            private _playerObject = objectFromNetId _playerNetId;
            private _rebroObject = objectFromNetId _rebroNetId;
            if (!isNull _playerObject && {!isNull _rebroObject}) then {
                private _colour = switch (true) do {
                    case (_signalPower > 0.7): { [0,1,0,1] };
                    case (_signalPower > 0.4): { [1,1,0,1] };
                    default { [1,0,0,1] };
                };
                _map drawLine [getPosATL _playerObject, getPosATL _rebroObject, _colour];
            };
        } forEach _connections;
    };
};

// Rebro Network
if (GVAR(visualiseActiveToggles) getOrDefault ["rebronetwork", false]) then {
    private _rebroNetworkData = GVAR(visualiseData) getOrDefault ["rebronetwork", []];
    if (_rebroNetworkData isNotEqualTo []) then {
        _rebroNetworkData params ["_rebroNetIds", "_players", "_links"];

        // Rebro station icons
        {
            private _rebroObject = objectFromNetId _x;
            if (!isNull _rebroObject) then {
                _map drawIcon ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", [0,1,1,1], getPosATL _rebroObject, 24, 24, 0, "ReBro", 1, 0.04, "TahomaB", "right"];
            };
        } forEach _rebroNetIds;

        // Player-to-player connection lines
        {
            _x params ["_fromIndex", "_toIndex", "_signalPower", "_isDirect", "_rebroNetId"];
            if (_fromIndex >= 0 && {_fromIndex < count _players} && {_toIndex >= 0} && {_toIndex < count _players}) then {
                private _fromObject = objectFromNetId ((_players#_fromIndex)#0);
                private _toObject = objectFromNetId ((_players#_toIndex)#0);
                if (!isNull _fromObject && {!isNull _toObject}) then {
                    private _fromPosition = getPosATL _fromObject;
                    private _toPosition = getPosATL _toObject;
                    private _colour = switch (true) do {
                        case (_signalPower > 0.7): { [0,1,0,1] };
                        case (_signalPower > 0.4): { [1,1,0,1] };
                        default { [1,0,0,1] };
                    };
                    if (_isDirect) then {
                        _map drawLine [_fromPosition, _toPosition, _colour];
                    } else {
                        private _rebroObject = objectFromNetId _rebroNetId;
                        if (!isNull _rebroObject) then {
                            private _rebroPosition = getPosATL _rebroObject;
                            _map drawLine [_fromPosition, _rebroPosition, _colour];
                            _map drawLine [_rebroPosition, _toPosition, _colour];
                        };
                    };
                };
            };
        } forEach _links;
    };
};

// Projectiles
if (GVAR(projectilesEnabled)) then {
    GVAR(trackedProjectiles) = GVAR(trackedProjectiles) select {!isNull (_x#0)};
    {
        _x params ["_projectile", "_ammo", "_sideColor"];
        private _name = GVAR(ammoNameCache) getOrDefault [_ammo, _ammo];
        private _icon = GVAR(ammoIconCache) getOrDefault [_ammo, "\a3\ui_f\data\map\markers\military\dot_ca.paa"];
        _map drawIcon [_icon, _sideColor, _projectile, 16, 16, 0, _name, 1, 0.04, "TahomaB", "right"];
    } forEach GVAR(trackedProjectiles);
};

// Unconscious players
{
    if ((driver (vehicle _x)) isEqualTo _x && {_x getVariable ["ACE_isUnconscious", false]}) then {
        private _comaTimeLeft = round (_x getVariable ["ace_medical_statemachine_comaTimeLeft", -1]);
        private _text = "Unconscious";
        if (_comaTimeLeft > -1) then {
            private _minutes = floor (_comaTimeLeft / 60);
            private _seconds = _comaTimeLeft % 60;
            _text = if (_minutes > 0) then {
                format ["Unconscious (Coma %1m%2s)", _minutes, _seconds]
            } else {
                format ["Unconscious (Coma %1s)", _seconds]
            };
        } else {
            private _cardiacArrestTimeLeft = round (_x getVariable ["ace_medical_statemachine_cardiacArrestTimeLeft", -1]);
            if (_cardiacArrestTimeLeft > -1) then {
                private _minutes = floor (_cardiacArrestTimeLeft / 60);
                private _seconds = _cardiacArrestTimeLeft % 60;
                _text = if (_minutes > 0) then {
                    format ["Unconscious (CA %1m%2s)", _minutes, _seconds]
                } else {
                    format ["Unconscious (CA %1s)", _seconds]
                };
            };
        };

        _map drawIcon ["#(argb,8,8,3)color(0,0,0,0)", [1,0,0,1], _x, 40, 1, 0, _text, 1, 0.04, "TahomaB", "left"];
    };
} forEach ALL_PLAYERS;
