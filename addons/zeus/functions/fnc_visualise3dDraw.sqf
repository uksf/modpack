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
private _maxDistance = if (GVAR(visualiseDistanceLimited)) then {5000} else {100000};
private _hudIndex = 0;

// AI Commander
if (GVAR(visualiseActiveToggles) getOrDefault ["aicommander", false]) then {
    private _groundData = GVAR(visualiseData) getOrDefault ["aicommander_ground", []];
    if (_groundData isNotEqualTo []) then {
        _groundData params ["_spawnPoints", "_stagingAreas", "_aggression", "_tierStatus", "_killerPlayers", "_responseGroups"];

        // Aggression meter (HUD control)
        _tierStatus params ["_tier1Deployed", "_tier2Deployed"];
        private _tierText = "";
        if (_tier1Deployed) then { _tierText = " [T1 ACTIVE]" };
        if (_tier2Deployed) then { _tierText = _tierText + " [T2 ACTIVE]" };
        private _aggressionHex = switch (true) do {
            case (_aggression >= 120): { "#ff0000" };
            case (_aggression >= 80): { "#ff8000" };
            case (_aggression >= 40): { "#ffff00" };
            default { "#00ff00" };
        };
        if (_hudIndex < count GVAR(visualiseHudControls)) then {
            private _control = GVAR(visualiseHudControls) select _hudIndex;
            _control ctrlSetStructuredText parseText format ["<t align='center' color='%1' shadow='1' font='TahomaB'>Aggression: %2%3</t>", _aggressionHex, _aggression, _tierText];
            _control ctrlShow true;
        };
        _hudIndex = _hudIndex + 1;

        // Spawn points
        {
            _x params ["_position", "_type"];
            if (_cameraPosition distance2D _position < _maxDistance) then {
                drawIcon3D ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [1,0.5,0,1], ASLToAGL (ATLToASL _position), 0.5, 0.5, 0, format ["Spawn: %1", toUpper _type], 1, 0.025, "TahomaB", "center"];
            };
        } forEach _spawnPoints;

        // Staging areas
        {
            if (_cameraPosition distance2D _x < _maxDistance) then {
                drawIcon3D ["\a3\ui_f\data\map\markers\military\flag_ca.paa", [1,0.8,0,1], ASLToAGL (ATLToASL _x), 0.5, 0.5, 0, "Staging", 1, 0.025, "TahomaB", "center"];
            };
        } forEach _stagingAreas;

        // Killer players
        {
            _x params ["_playerNetId", "_timeLeft"];
            private _playerObject = objectFromNetId _playerNetId;
            if (!isNull _playerObject) then {
                private _position = getPosATL _playerObject;
                if (_cameraPosition distance2D _position < _maxDistance) then {
                    drawIcon3D ["", [1,0,0,1], ASLToAGL (ATLToASL _position), 0, 3, 0, format ["Aggro %1s", round _timeLeft], 1, 0.025, "TahomaB", "center"];
                };
            };
        } forEach _killerPlayers;

        // Response group targets
        {
            _x params ["_groupId", "_leaderNetId", "_targetPosition"];
            private _leaderObject = objectFromNetId _leaderNetId;
            if (!isNull _leaderObject) then {
                private _leaderPosition = getPosATL _leaderObject;
                if (_cameraPosition distance2D _leaderPosition < _maxDistance) then {
                    drawIcon3D ["", [1,0,0,1], ASLToAGL (ATLToASL _leaderPosition), 0, 0, 0, _groupId, 1, 0.02, "TahomaB", "center"];
                };
                if (_targetPosition isNotEqualTo [] && {_cameraPosition distance2D _targetPosition < _maxDistance}) then {
                    drawIcon3D ["\a3\ui_f\data\map\markers\military\objective_ca.paa", [1,0,0,1], ASLToAGL (ATLToASL _targetPosition), 0.5, 0.5, 0, format ["Target: %1", _groupId], 1, 0.02, "TahomaB", "center"];
                };
            };
        } forEach _responseGroups;
    };

    // Air commander
    private _airData = GVAR(visualiseData) getOrDefault ["aicommander_air", []];
    if (_airData isNotEqualTo []) then {
        _airData params ["_aaSites", "_airspaceCentres", "_enemyAirfields", "_airSpawnPoints"];

        {
            _x params ["_position", "_occupied", "_vehicleNetId"];
            private _colour = [[1,0,0,1], [0,1,0,1]] select _occupied;
            if (_cameraPosition distance2D _position < _maxDistance) then {
                drawIcon3D ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", _colour, ASLToAGL (ATLToASL _position), 0.5, 0.5, 0, format ["AA %1", ["EMPTY", "MANNED"] select _occupied], 1, 0.025, "TahomaB", "center"];
            };
            if (_occupied) then {
                private _vehicle = objectFromNetId _vehicleNetId;
                if (!isNull _vehicle) then {
                    private _vehiclePosition = ASLToAGL (getPosASL _vehicle);
                    if (_cameraPosition distance2D _vehiclePosition < _maxDistance) then {
                        drawIcon3D ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", _colour, _vehiclePosition, 0.4, 0.4, 0, "AA Vehicle", 1, 0.02, "TahomaB", "center"];
                        drawLine3D [ASLToAGL (ATLToASL _position), _vehiclePosition, [0,1,0,1]];
                    };
                };
            };
        } forEach _aaSites;

        {
            if (_cameraPosition distance2D _x < _maxDistance) then {
                drawIcon3D ["\a3\ui_f\data\map\markers\military\circle_ca.paa", [0.4,0.7,1,1], ASLToAGL (ATLToASL _x), 0.75, 0.75, 0, "Airspace Centre", 1, 0.025, "TahomaB", "center"];
            };
        } forEach _airspaceCentres;

        {
            if (_cameraPosition distance2D _x < _maxDistance) then {
                drawIcon3D ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [0.4,0.7,1,1], ASLToAGL (ATLToASL _x), 0.5, 0.5, 0, "Enemy Airfield", 1, 0.025, "TahomaB", "center"];
            };
        } forEach _enemyAirfields;

        {
            _x params ["_position", "_type"];
            if (_cameraPosition distance2D _position < _maxDistance) then {
                drawIcon3D ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [0.4,0.7,1,1], ASLToAGL (ATLToASL _position), 0.4, 0.4, 0, format ["Spawn: %1", toUpper _type], 1, 0.02, "TahomaB", "center"];
            };
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
            if (_cameraPosition distance2D _position < _maxDistance) then {
                private _colour = switch (_owner) do {
                    case 0: { [1,0,0,1] };
                    case 1: { [0,0.3,1,1] };
                    default { [0.6,0.6,0.6,1] };
                };

                private _opforPercentage = if (_timeToCapture > 0) then {round ((_opforScore / _timeToCapture) * 100)} else {0};
                private _bluforPercentage = if (_timeToCapture > 0) then {round ((_bluforScore / _timeToCapture) * 100)} else {0};

                drawIcon3D ["", _colour, ASLToAGL (ATLToASL _position), 0, 0, 0, _name, 1, 0.025, "TahomaB", "center"];
                drawIcon3D ["", [0,0.3,1,1], ASLToAGL (ATLToASL _position), 0, -2, 0, format ["BLU: %1%2", _bluforPercentage, "%"], 1, 0.02, "TahomaB", "center"];
                drawIcon3D ["", [1,0,0,1], ASLToAGL (ATLToASL _position), 0, -4, 0, format ["OPF: %1%2", _opforPercentage, "%"], 1, 0.02, "TahomaB", "center"];
                if (_contested) then {
                    drawIcon3D ["", [1,1,0,1], ASLToAGL (ATLToASL _position), 0, -6, 0, "CONTESTED", 1, 0.02, "TahomaB", "center"];
                };
                if (_locked) then {
                    drawIcon3D ["", [0.5,0.5,0.5,1], ASLToAGL (ATLToASL _position), 0, -6, 0, "LOCKED", 1, 0.02, "TahomaB", "center"];
                };
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
};

// Area Rating
if (GVAR(visualiseActiveToggles) getOrDefault ["arearating", false]) then {
    private _areaRatingData = GVAR(visualiseData) getOrDefault ["arearating", []];
    if (_areaRatingData isNotEqualTo []) then {
        private _areas = _areaRatingData#0;
        {
            _x params ["_position", "_area", "_name", "_percentage", "_startPercentage"];
            if !(_position isEqualType []) then {continue};
            if (_cameraPosition distance2D _position < _maxDistance) then {
                private _ratio = _percentage / 100;
                private _colour = if (_ratio < 0.5) then {
                    [1, _ratio * 2, 0, 1]
                } else {
                    [1 - ((_ratio - 0.5) * 2), 1, 0, 1]
                };

                private _trend = if (_percentage > _startPercentage) then {"^"} else {
                    if (_percentage < _startPercentage) then {"v"} else {"-"}
                };

                drawIcon3D ["", _colour, ASLToAGL (ATLToASL _position), 0, 0, 0, format ["%1: %2%3 %4", _name, _percentage, "%", _trend], 1, 0.025, "TahomaB", "center"];
            };
        } forEach _areas;
    };
};

// Cached Groups
if (GVAR(visualiseActiveToggles) getOrDefault ["cachedgroups", false]) then {
    private _cachingData = GVAR(visualiseData) getOrDefault ["cachedgroups", []];
    if (_cachingData isNotEqualTo []) then {
        _cachingData params ["_cachedGroups", "_cacheDistance", "_totalActive", "_totalCached"];

        // HUD summary (control)
        if (_hudIndex < count GVAR(visualiseHudControls)) then {
            private _control = GVAR(visualiseHudControls) select _hudIndex;
            _control ctrlSetStructuredText parseText format ["<t align='center' color='#ffffff' shadow='1' font='TahomaB'>Cached: %1 | Active: %2</t>", _totalCached, _totalActive];
            _control ctrlShow true;
        };
        _hudIndex = _hudIndex + 1;

        // Cached group icons
        {
            _x params ["_position", "_side", "_unitCount"];
            if (_cameraPosition distance2D _position < _maxDistance) then {
                private _colour = switch (_side) do {
                    case west: { [0.3,0.5,1,1] };
                    case east: { [1,0,0,1] };
                    case independent: { [0,1,0,1] };
                    default { [0.8,0.3,1,1] };
                };
                drawIcon3D ["\a3\ui_f\data\map\markers\military\dot_ca.paa", _colour, ASLToAGL (ATLToASL _position), 0.4, 0.4, 0, format ["%1", _unitCount], 1, 0.02, "TahomaB", "center"];
            };
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
                drawIcon3D ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", [0,1,1,1], ASLToAGL (getPosASL _rebroObject), 0.5, 0.5, 0, "ReBro", 1, 0.025, "TahomaB", "center"];
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
                drawLine3D [ASLToAGL (getPosASL _playerObject), ASLToAGL (getPosASL _rebroObject), _colour];
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
                drawIcon3D ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", [0,1,1,1], ASLToAGL (getPosASL _rebroObject), 0.5, 0.5, 0, "ReBro", 1, 0.025, "TahomaB", "center"];
            };
        } forEach _rebroNetIds;

        // Player-to-player connection lines
        {
            _x params ["_fromIndex", "_toIndex", "_signalPower", "_isDirect", "_rebroNetId"];
            if (_fromIndex >= 0 && {_fromIndex < count _players} && {_toIndex >= 0} && {_toIndex < count _players}) then {
                private _fromObject = objectFromNetId ((_players#_fromIndex)#0);
                private _toObject = objectFromNetId ((_players#_toIndex)#0);
                if (!isNull _fromObject && {!isNull _toObject}) then {
                    private _fromPosition = ASLToAGL (getPosASL _fromObject);
                    private _toPosition = ASLToAGL (getPosASL _toObject);
                    private _colour = switch (true) do {
                        case (_signalPower > 0.7): { [0,1,0,1] };
                        case (_signalPower > 0.4): { [1,1,0,1] };
                        default { [1,0,0,1] };
                    };
                    if (_isDirect) then {
                        drawLine3D [_fromPosition, _toPosition, _colour];
                    } else {
                        private _rebroObject = objectFromNetId _rebroNetId;
                        if (!isNull _rebroObject) then {
                            private _rebroPosition = ASLToAGL (getPosASL _rebroObject);
                            drawLine3D [_fromPosition, _rebroPosition, _colour];
                            drawLine3D [_rebroPosition, _toPosition, _colour];
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
        private _position = ASLToAGL getPosASLVisual _projectile;
        private _name = GVAR(ammoNameCache) getOrDefault [_ammo, _ammo];
        drawIcon3D ["", _sideColor, _position, 0, 0, 0, _name, 1, 0.025, "TahomaB", "center", true];
    } forEach GVAR(trackedProjectiles);
};

// Player FPS and Unconscious
{
    if (_cameraPosition distance _x > 500) then {continue};
    if !((driver (vehicle _x)) isEqualTo _x) then {continue};

    if (GVAR(fpsEnabled)) then {
        private _fps = _x getVariable [QGVAR(fps), 0];
        private _colour = [1,1,1,1];
        private _size = 0.025;
        if (_fps <= 15) then {
            _colour = [1,0,0,1];
            _size = 0.035;
        };
        drawIcon3D ["", _colour, ASLToAGL (getPosASLVisual (vehicle _x)), 1, 2, 0, format ["%1 FPS", _fps], 1, _size, "TahomaB", "center"];
    };

    if (_x getVariable ["ACE_isUnconscious", false]) then {
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

        drawIcon3D ["", [1,0,0,1], ASLToAGL (getPosASLVisual (vehicle _x)), 1, -2.5, 0, _text, 1, 0.025, "TahomaB", "center"];
    };
} forEach ALL_PLAYERS;

// Hide unused HUD controls
for "_i" from _hudIndex to (count GVAR(visualiseHudControls) - 1) do {
    (GVAR(visualiseHudControls) select _i) ctrlShow false;
};
