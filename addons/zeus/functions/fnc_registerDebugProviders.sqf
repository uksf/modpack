#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers zeus debug providers for projectile tracking, player FPS, and unconscious status

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_zeus_fnc_registerDebugProviders
*/

// Projectiles provider
private _key = QGVAR(projectiles);
private _menuName = "Projectiles";
private _menuPriority = -10;
private _fnc_menuCondition = {true};

private _fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance"];

    GVAR(trackedProjectiles) = GVAR(trackedProjectiles) select {!isNull (_x#0)};
    {
        _x params ["_projectile", "_ammo", "_sideColor"];
        private _position = ASLToAGL getPosASLVisual _projectile;
        private _name = GVAR(ammoNameCache) getOrDefault [_ammo, _ammo];
        drawIcon3D ["\a3\ui_f\data\map\markers\military\dot_ca.paa", _sideColor, _position, 0.3, 0.3, 0, _name, 1, 0.025, "TahomaB", "center", true];
    } forEach GVAR(trackedProjectiles);
};

private _fnc_drawMap = {
    params ["_data", "_map"];

    {
        _x params ["_projectile", "_ammo", "_sideColor"];
        private _name = GVAR(ammoNameCache) getOrDefault [_ammo, _ammo];
        _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", _sideColor, _projectile, 16, 16, 0, _name, 1, 0.04, "TahomaB", "right"];
    } forEach GVAR(trackedProjectiles);
};

[QGVAR(registerDebugProvider), [_key, createHashMapFromArray [
    ["draw3d", _fnc_draw3d],
    ["drawMap", _fnc_drawMap],
    ["menuName", _menuName],
    ["menuPriority", _menuPriority],
    ["menuCondition", _fnc_menuCondition]
]]] call CBA_fnc_localEvent;

// Player FPS provider — always active when Zeus is open
_key = QGVAR(fps);

private _fnc_serverGetter = {
    private _fpsStore = EGVAR(common,fpsStore);
    private _timestamps = EGVAR(common,fpsStoreTimestamps);
    private _now = CBA_missionTime;

    private _serverFps = -1;
    private _hcList = [];
    private _playerList = [];

    {
        private _key = _x;
        private _lastUpdate = _timestamps getOrDefault [_key, 0];
        if (_now - _lastUpdate > 10) then { continue };

        private _entry = _fpsStore get _key;
        _entry params ["_fps", "", "_type"];

        switch (_type) do {
            case "server": {
                _serverFps = _fps;
            };
            case "hc": {
                _hcList pushBack [_key, _fps];
            };
            case "player": {
                private _playerObject = objNull;
                {
                    if (getPlayerUID _x isEqualTo _key) exitWith { _playerObject = _x };
                } forEach ALL_PLAYERS;
                if (isNull _playerObject) then { continue };
                if ((driver (vehicle _playerObject)) isNotEqualTo _playerObject) then { continue };
                _playerList pushBack [netId _playerObject, _fps];
            };
        };
    } forEach keys _fpsStore;

    [_serverFps, _hcList, _playerList]
};

_fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance"];
    _data params ["", "", "_playerList"];

    {
        _x params ["_playerNetId", "_fps"];
        private _playerObject = objectFromNetId _playerNetId;
        if (isNull _playerObject) then { continue };

        private _position = ASLToAGL (getPosASLVisual (vehicle _playerObject));
        if (_cameraPosition distance _position > 750) then { continue };

        private _colour = [1,1,1,1];
        private _size = 0.025;
        if (_fps <= 15) then {
            _colour = [1,0,0,1];
            _size = 0.035;
        };
        drawIcon3D ["", _colour, _position, 0, 0, 0, format ["%1 FPS", _fps], 1, _size, "TahomaB", "center", false, 0, DEBUG_ICON_SPACING * 3];
    } forEach _playerList;
};

private _fnc_drawHud = {
    params ["_data", "_hudControl"];
    _data params ["_serverFps", "_hcList", ""];

    private _parts = [];
    if (_serverFps >= 0) then {
        private _colour = if (_serverFps <= 15) then { "#ff4444" } else { "#ffffff" };
        _parts pushBack format ["<t color='#aaaaaa'>Server FPS:</t> <t color='%1'>%2</t>", _colour, _serverFps];
    };
    {
        _x params ["_hcName", "_hcFps"];
        private _colour = if (_hcFps <= 15) then { "#ff4444" } else { "#ffffff" };
        _parts pushBack format ["<t color='#aaaaaa'>%1 FPS:</t> <t color='%2'>%3</t>", _hcName, _colour, _hcFps];
    } forEach _hcList;

    if (_parts isEqualTo []) exitWith {
        _hudControl ctrlSetStructuredText parseText "";
    };
    _hudControl ctrlSetStructuredText parseText format ["<t align='center' shadow='1' font='TahomaB'>%1</t>", _parts joinString " <t color='#666666'>|</t> "];
};

[QGVAR(registerDebugProvider), [_key, createHashMapFromArray [
    ["draw3d", _fnc_draw3d],
    ["drawHud", _fnc_drawHud],
    ["serverGetter", _fnc_serverGetter],
    ["getterInterval", 1],
    ["alwaysActive", true],
    ["menuName", "FPS"],
    ["menuPriority", -5]
]]] call CBA_fnc_localEvent;

// Unconscious status provider — always active when Zeus is open
_key = QGVAR(unconscious);

private _fnc_unconsciousServerGetter = {
    private _unconsciousPlayers = [];
    {
        if !(_x getVariable ["ACE_isUnconscious", false]) then { continue };
        if ((driver (vehicle _x)) isNotEqualTo _x) then { continue };

        private _unconsciousText = _x call FUNC(formatUnconsciousText);
        _unconsciousPlayers pushBack [netId _x, _unconsciousText];
    } forEach ALL_PLAYERS;
    _unconsciousPlayers
};

private _fnc_unconsciousDraw3d = {
    params ["_data", "_cameraPosition", "_maxDistance"];

    private _offset = DEBUG_ICON_SPACING * ([3, 4] select (GVAR(debugActiveToggles) getOrDefault [QGVAR(fps), false]));
    {
        _x params ["_playerNetId", "_unconsciousText"];
        private _playerObject = objectFromNetId _playerNetId;
        if (isNull _playerObject) then { continue };

        private _position = ASLToAGL (getPosASLVisual (vehicle _playerObject));
        if (_cameraPosition distance _position > 750) then { continue };

        drawIcon3D ["", [1,0,0,1], _position, 0, 0, 0, _unconsciousText, 1, 0.025, "TahomaB", "center", false, 0, _offset];
    } forEach _data;
};

private _fnc_unconsciousDrawMap = {
    params ["_data", "_map"];

    {
        _x params ["_playerNetId", "_unconsciousText"];
        private _playerObject = objectFromNetId _playerNetId;
        if (isNull _playerObject) then { continue };

        _map drawIcon ["#(argb,8,8,3)color(0,0,0,0)", [1,0,0,1], _playerObject, 40, 1, 0, _unconsciousText, 1, 0.04, "TahomaB", "left"];
    } forEach _data;
};

[QGVAR(registerDebugProvider), [_key, createHashMapFromArray [
    ["draw3d", _fnc_unconsciousDraw3d],
    ["drawMap", _fnc_unconsciousDrawMap],
    ["serverGetter", _fnc_unconsciousServerGetter],
    ["getterInterval", 1],
    ["alwaysActive", true],
    ["menuPriority", -3]
]]] call CBA_fnc_localEvent;
