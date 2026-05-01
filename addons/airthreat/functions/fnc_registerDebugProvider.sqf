#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers the air threat debug provider with Zeus.
        Shows active missions, zone boundaries, spawn points,
        target lines, and cooldown timers.

        Static lookup data (colour maps, timeout map, format helper)
        is stored as GVAR in XEH_preInit because SQF uses dynamic
        scoping — private variables from this scope are not captured
        by the closures registered with the zeus framework.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_airthreat_fnc_registerDebugProvider
*/

private _key = QGVAR(debug);
private _menuName = "Air Threat";
private _menuPriority = -20;
private _fnc_menuCondition = {GVAR(controllerInitialised)};

// ============================================================
// SERVER GETTER
// ============================================================
private _fnc_serverGetter = {
    // --- Active missions ---
    private _missions = GVAR(activeMissions) apply {
        _x params ["_group", "_vehicle", "_missionType"];
        if (isNull _vehicle || {!alive _vehicle}) then { continue };

        private _vehicleNetId = netId _vehicle;
        private _spawnTime = _vehicle getVariable [QGVAR(spawnTime), time];
        private _timeoutVarName = GVAR(debugTimeoutMap) getOrDefault [_missionType, QGVAR(capTimeout)];
        private _timeout = missionNamespace getVariable [_timeoutVarName, 600];
        private _timeRemaining = (_spawnTime + _timeout - time) max 0;

        // Target position by mission type
        private _targetPosition = [];
        switch (_missionType) do {
            case "recon": {
                _targetPosition = _vehicle getVariable [QGVAR(reconObservedPosition), []];
            };
            case "strike": {
                _targetPosition = _vehicle getVariable [QGVAR(strikeTarget), []];
            };
            case "intercept": {
                private _interceptTarget = _vehicle getVariable [QGVAR(interceptTarget), objNull];
                if (!isNull _interceptTarget && {alive _interceptTarget}) then {
                    _targetPosition = getPosASL _interceptTarget;
                };
            };
        };

        // Recon state
        private _reconState = if (_missionType isEqualTo "recon") then {
            _vehicle getVariable [QGVAR(reconState), "approach"]
        } else {
            ""
        };

        [_vehicleNetId, _missionType, _timeRemaining, _targetPosition, _reconState]
    };

    // --- Zones ---
    // Airspace zones (stored as raw arrays, no markers)
    private _airspaceZones = +GVAR(airspaces);

    // CAS/strike zones (area arrays)
    private _casStrikeZoneData = GVAR(casStrikeZones) apply {
        _x params ["_zoneArea", "_casProbability", "_nextTriggerTime"];
        _zoneArea params ["_position", "_sizeA", "_sizeB", "_angle", "_isRectangle"];
        private _cooldownRemaining = (_nextTriggerTime - time) max 0;
        [_position, _sizeA, _sizeB, _angle, _isRectangle, _cooldownRemaining]
    };

    // Intercept zones (area arrays, matched by index)
    private _interceptZoneData = [];
    {
        _x params ["_zoneArea", "_maxIntercepts"];
        _zoneArea params ["_position", "_sizeA", "_sizeB", "_angle", "_isRectangle"];
        private _zoneIndex = _forEachIndex;
        private _activeIntercepts = {
            (_x select 2) isEqualTo "intercept" && {(_x select 3) isEqualTo _zoneIndex}
        } count GVAR(activeMissions);
        _interceptZoneData pushBack [_position, _sizeA, _sizeB, _angle, _isRectangle, _maxIntercepts, _activeIntercepts];
    } forEach GVAR(interceptZones);

    // --- Spawn points ---
    private _spawnPointData = +GVAR(spawnPoints);

    // --- Cooldowns ---
    private _capReconCooldown = if (isNil QGVAR(nextCapReconTime)) then {
        -1
    } else {
        (GVAR(nextCapReconTime) - time) max 0
    };
    private _interceptCooldown = (GVAR(nextInterceptTime) - time) max 0;

    [_missions, [_airspaceZones, _casStrikeZoneData, _interceptZoneData], _spawnPointData, [_capReconCooldown, _interceptCooldown]]
};

// ============================================================
// 3D DRAW
// ============================================================
private _fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance"];
    _data params ["_missions", "_zones", "_spawnPoints", "_cooldowns"];

    {
        _x params ["_vehicleNetId", "_missionType", "_timeRemaining", "_targetPosition", "_reconState"];
        private _vehicle = objectFromNetId _vehicleNetId;
        if (isNull _vehicle) then { continue };

        private _vehiclePosition = ASLToAGL getPosASLVisual _vehicle;
        if (_cameraPosition distance _vehiclePosition > _maxDistance) then { continue };

        private _colour = GVAR(debugColourMap) getOrDefault [_missionType, [1, 1, 1, 0.9]];
        private _timeText = [_timeRemaining] call GVAR(debugFormatTime);

        // Build label: "TYPE TIME" or "Recon [state] TIME"
        private _typeLabel = GVAR(debugLabelMap) getOrDefault [_missionType, "?"];
        private _label = if (_missionType isEqualTo "recon" && {_reconState isNotEqualTo "approach"}) then {
            format ["%1 [%2] %3", _typeLabel, _reconState, _timeText]
        } else {
            format ["%1 %2", _typeLabel, _timeText]
        };

        drawIcon3D ["", _colour, _vehiclePosition, 0, 0, 0, _label, 1, 0.03, "TahomaB", "center", false, 0, -10];

        // Target line
        if (_targetPosition isNotEqualTo []) then {
            private _targetPositionAGL = ASLToAGL _targetPosition;
            drawLine3D [_vehiclePosition, _targetPositionAGL, _colour];
        };
    } forEach _missions;
};

// ============================================================
// MAP DRAW
// ============================================================
private _fnc_drawMap = {
    params ["_data", "_map"];
    _data params ["_missions", "_zones", "_spawnPoints", "_cooldowns"];
    _zones params ["_airspaceZones", "_casStrikeZoneData", "_interceptZoneData"];

    // --- Airspace zones ---
    {
        _x params ["_position", "_sizeA", "_sizeB", "_angle", "_isRectangle"];
        private _colour = [0.4, 0.7, 1, 0.5];
        if (_isRectangle) then {
            _map drawRectangle [_position, _sizeA, _sizeB, _angle, _colour, ""];
        } else {
            _map drawEllipse [_position, _sizeA, _sizeB, _angle, _colour, ""];
        };
        _map drawIcon ["#(argb,8,8,3)color(0,0,0,0)", [0.4, 0.7, 1, 1], _position, 0, 0, 0, "Airspace", 1, 0.04, "TahomaB", "center"];
    } forEach _airspaceZones;

    // --- CAS/strike zones ---
    {
        _x params ["_position", "_sizeA", "_sizeB", "_angle", "_isRectangle", "_cooldownRemaining"];
        private _colour = [1, 0.5, 0, 0.5];
        if (_isRectangle) then {
            _map drawRectangle [_position, _sizeA, _sizeB, _angle, _colour, ""];
        } else {
            _map drawEllipse [_position, _sizeA, _sizeB, _angle, _colour, ""];
        };
        private _label = if (_cooldownRemaining > 0) then {
            format ["CAS/Strike (%1)", [_cooldownRemaining] call GVAR(debugFormatTime)]
        } else {
            "CAS/Strike"
        };
        _map drawIcon ["#(argb,8,8,3)color(0,0,0,0)", [1, 0.5, 0, 1], _position, 0, 0, 0, _label, 1, 0.04, "TahomaB", "center"];
    } forEach _casStrikeZoneData;

    // --- Intercept zones ---
    {
        _x params ["_position", "_sizeA", "_sizeB", "_angle", "_isRectangle", "_maxIntercepts", "_activeIntercepts"];
        private _colour = [1, 0.3, 1, 0.5];
        if (_isRectangle) then {
            _map drawRectangle [_position, _sizeA, _sizeB, _angle, _colour, ""];
        } else {
            _map drawEllipse [_position, _sizeA, _sizeB, _angle, _colour, ""];
        };
        _map drawIcon ["#(argb,8,8,3)color(0,0,0,0)", [1, 0.3, 1, 1], _position, 0, 0, 0, format ["Intercept (%1/%2)", _activeIntercepts, _maxIntercepts], 1, 0.04, "TahomaB", "center"];
    } forEach _interceptZoneData;

    // --- Spawn points ---
    {
        _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [0.4, 0.7, 1, 1], _x, 20, 20, 0, "Spawn", 1, 0.03, "TahomaB", "right"];
    } forEach _spawnPoints;

    // --- Aircraft-to-target lines ---
    {
        _x params ["_vehicleNetId", "_missionType", "", "_targetPosition"];
        if (_targetPosition isEqualTo []) then { continue };
        private _vehicle = objectFromNetId _vehicleNetId;
        if (isNull _vehicle) then { continue };

        private _colour = GVAR(debugColourMap) getOrDefault [_missionType, [1, 1, 1, 0.9]];
        _map drawLine [getPosASLVisual _vehicle, _targetPosition, _colour];
    } forEach _missions;
};

// ============================================================
// HUD DRAW
// ============================================================
private _fnc_drawHud = {
    params ["_data", "_hudControl"];
    _data params ["_missions", "_zones", "_spawnPoints", "_cooldowns"];
    _cooldowns params ["_capReconCooldown", "_interceptCooldown"];

    private _missionCount = count _missions;

    // CAP/recon timer
    private _capReconText = if (_capReconCooldown < 0) then {
        "<t color='#888888'>waiting</t>"
    } else {
        if (_capReconCooldown isEqualTo 0) then {
            "<t color='#ffffff'>ready</t>"
        } else {
            format ["<t color='#888888'>in %1</t>", [_capReconCooldown] call GVAR(debugFormatTime)]
        };
    };

    // Intercept timer
    private _interceptText = if (_interceptCooldown isEqualTo 0) then {
        "<t color='#ffffff'>ready</t>"
    } else {
        format ["<t color='#888888'>in %1</t>", [_interceptCooldown] call GVAR(debugFormatTime)]
    };

    // Line 1: status
    private _line1 = format ["<t color='#aaaaaa'>Air Threat:</t> %1 active <t color='#aaaaaa'>|</t> <t color='#aaaaaa'>CAP/Recon</t> %2 <t color='#aaaaaa'>|</t> <t color='#aaaaaa'>Intercept</t> %3", _missionCount, _capReconText, _interceptText];

    // Line 2: per-mission details
    private _line2 = if (_missionCount isEqualTo 0) then {
        "<t color='#888888'>No active missions</t>"
    } else {
        private _parts = _missions apply {
            _x params ["", "_missionType", "_timeRemaining", "", "_reconState"];
            private _hexColour = GVAR(debugHexColourMap) getOrDefault [_missionType, "#ffffff"];
            private _typeLabel = GVAR(debugLabelMap) getOrDefault [_missionType, "?"];
            private _timeText = [_timeRemaining] call GVAR(debugFormatTime);

            if (_missionType isEqualTo "recon" && {_reconState isNotEqualTo "approach"}) then {
                format ["<t color='%1'>%2 [%3] %4</t>", _hexColour, _typeLabel, _reconState, _timeText]
            } else {
                format ["<t color='%1'>%2 %3</t>", _hexColour, _typeLabel, _timeText]
            };
        };
        _parts joinString " <t color='#aaaaaa'>|</t> "
    };

    _hudControl ctrlSetStructuredText parseText format ["<t align='center' shadow='1' font='TahomaB'>%1<br/>%2</t>", _line1, _line2];
};

// ============================================================
// REGISTER
// ============================================================
[QEGVAR(zeus,registerDebugProvider), [_key, createHashMapFromArray [
    ["draw3d", _fnc_draw3d],
    ["drawMap", _fnc_drawMap],
    ["drawHud", _fnc_drawHud],
    ["serverGetter", _fnc_serverGetter],
    ["menuName", _menuName],
    ["menuPriority", _menuPriority],
    ["menuCondition", _fnc_menuCondition]
]]] call CBA_fnc_localEvent;
