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

[QGVAR(registerDebugAction), [_key, _menuName, _menuPriority, _fnc_menuCondition]] call CBA_fnc_localEvent;
[QGVAR(registerDebugDraw), [_key, _fnc_draw3d, _fnc_drawMap]] call CBA_fnc_localEvent;

// FPS client data source — each player reports their FPS when active
[QGVAR(registerDebugClientSource), [
    QGVAR(fpsData),
    {[floor diag_fps]},
    1
]] call CBA_fnc_localEvent;

// Player FPS provider
_key = QGVAR(fps);
_menuName = "Player FPS";
_menuPriority = -5;
_fnc_menuCondition = {true};
private _clientDataKey = QGVAR(fpsData);

private _fnc_serverGetter = {
    private _sourceData = GVAR(debugClientData) getOrDefault [QGVAR(fpsData), createHashMap];
    private _players = [];
    {
        private _entry = _sourceData get _x;
        _entry params ["_player", "_data", "_timestamp"];
        if (CBA_missionTime - _timestamp > 10) then { continue };
        if (isNull _player) then { continue };
        if !(isPlayer _player) then { continue };
        if ((driver (vehicle _player)) isNotEqualTo _player) then { continue };

        _data params ["_fps"];
        _players pushBack [netId _player, _fps];
    } forEach keys _sourceData;
    _players
};

_fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance"];

    {
        _x params ["_playerNetId", "_fps"];
        private _playerObject = objectFromNetId _playerNetId;
        if (isNull _playerObject) then { continue };

        private _position = ASLToAGL (getPosASLVisual (vehicle _playerObject));
        if (_cameraPosition distance _position > 500) then { continue };

        private _colour = [1,1,1,1];
        private _size = 0.025;
        if (_fps <= 15) then {
            _colour = [1,0,0,1];
            _size = 0.035;
        };
        drawIcon3D ["", _colour, _position, 0, 0, 0, format ["%1 FPS", _fps], 1, _size, "TahomaB", "center", false, 0, DEBUG_ICON_SPACING * 3];
    } forEach _data;
};

_fnc_drawMap = {};

[QGVAR(registerDebugAction), [_key, _menuName, _menuPriority, _fnc_menuCondition]] call CBA_fnc_localEvent;
[QGVAR(registerDebugServerGetter), [_key, _fnc_serverGetter, 1, _clientDataKey]] call CBA_fnc_localEvent;
[QGVAR(registerDebugDraw), [_key, _fnc_draw3d, _fnc_drawMap]] call CBA_fnc_localEvent;

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

    {
        _x params ["_playerNetId", "_unconsciousText"];
        private _playerObject = objectFromNetId _playerNetId;
        if (isNull _playerObject) then { continue };

        private _position = ASLToAGL (getPosASLVisual (vehicle _playerObject));
        if (_cameraPosition distance _position > 500) then { continue };

        drawIcon3D ["", [1,0,0,1], _position, 0, 0, 0, _unconsciousText, 1, 0.025, "TahomaB", "center", false, 0, DEBUG_ICON_SPACING * 4];
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

[QGVAR(registerDebugServerGetter), [_key, _fnc_unconsciousServerGetter, 1]] call CBA_fnc_localEvent;
[QGVAR(registerDebugDraw), [_key, _fnc_unconsciousDraw3d, _fnc_unconsciousDrawMap]] call CBA_fnc_localEvent;
