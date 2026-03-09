#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers AI ground commander debug provider with Zeus

    Parameter(s):
        None

    Return Value:
        None
*/

private _key = QGVAR(debug);
private _menuName = "AI Ground Commander";
private _menuPriority = -20;
private _fnc_menuCondition = {GVAR(enabled)};

private _fnc_serverGetter = {
    private _spawnPoints = [];
    {_spawnPoints pushBack [getPosATL _x, "infantry"]} forEach GVAR(infantrySpawns);
    {_spawnPoints pushBack [getPosATL _x, "car"]} forEach GVAR(carSpawns);
    {_spawnPoints pushBack [getPosATL _x, "apc"]} forEach GVAR(apcSpawns);
    {_spawnPoints pushBack [getPosATL _x, "tank"]} forEach GVAR(tankSpawns);

    private _stagingAreas = GVAR(stagingAreas) apply {getPosATL _x};

    private _killerPlayers = [];
    {
        private _timeLeft = (_x#1) - CBA_missionTime;
        if (_timeLeft > 0) then {
            _killerPlayers pushBack [netId (_x#0), _timeLeft];
        };
    } forEach GVAR(killerPlayers);

    private _responseGroupData = [];
    {
        if (!isNull _x) then {
            private _leader = leader _x;
            if (!isNull _leader) then {
                private _targetPosition = _x getVariable [QGVAR(targetPosition), []];
                _responseGroupData pushBack [groupId _x, netId _leader, _targetPosition];
            };
        };
    } forEach GVAR(responseGroups);

    [
        _spawnPoints,
        _stagingAreas,
        GVAR(enemyAggressionLevel),
        [GVAR(tier1ResponseDeployed), GVAR(tier2ResponseDeployed)],
        _killerPlayers,
        _responseGroupData
    ]
};

private _fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance"];
    _data params ["_spawnPoints", "_stagingAreas", "_aggression", "_tierStatus", "_killerPlayers", "_responseGroups"];

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
                drawIcon3D ["", [1,0,0,1], ASLToAGL (ATLToASL _position), 0, 0, 0, format ["Aggro %1s", round _timeLeft], 1, 0.025, "TahomaB", "center", false, 0, DEBUG_ICON_SPACING];
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

private _fnc_drawMap = {
    params ["_data", "_map"];
    _data params ["_spawnPoints", "_stagingAreas", "_aggression", "_tierStatus", "_killerPlayers", "_responseGroups"];

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

private _fnc_drawHud = {
    params ["_data", "_hudControl"];
    _data params ["", "", "_aggression", "_tierStatus"];
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

    _hudControl ctrlSetStructuredText parseText format ["<t align='center' shadow='1' font='TahomaB'><t color='#aaaaaa'>Ground Cmd</t> <t color='%1'>Aggression: %2%3</t></t>", _aggressionHex, _aggression, _tierText];
};

[QEGVAR(zeus,registerDebugAction), [_key, _menuName, _menuPriority, _fnc_menuCondition]] call CBA_fnc_localEvent;
[QEGVAR(zeus,registerDebugServerGetter), [_key, _fnc_serverGetter]] call CBA_fnc_localEvent;
[QEGVAR(zeus,registerDebugDraw), [_key, _fnc_draw3d, _fnc_drawMap, _fnc_drawHud]] call CBA_fnc_localEvent;
