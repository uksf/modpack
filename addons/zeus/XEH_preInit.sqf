#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(loadout) = "";
GVAR(fpsEnabled) = false;
GVAR(EHIDArray) = [];
GVAR(curatorUnconciousMapID) = 999;
GVAR(curatorUnconciousID) = -1;
GVAR(projectilesEnabled) = false;
GVAR(trackedProjectiles) = [];
GVAR(ammoTypeCache) = createHashMap;
GVAR(ammoNameCache) = createHashMap;
GVAR(ammoIconCache) = createHashMap;
GVAR(projectilesMapID) = 999;
GVAR(projectilesPFH) = -1;
GVAR(visualiseProviders) = createHashMap;
GVAR(visualiseData) = createHashMap;
GVAR(visualiseActiveToggles) = createHashMap;
GVAR(visualiseStreamClients) = [];
GVAR(visualiseStreamPFH) = -1;
GVAR(visualiseMapDrawID) = 999;
GVAR(visualisePFH) = -1;
GVAR(visualiseRebroReports) = createHashMap;

if (isServer) then {
    [QGVAR(visualiseStreamToggle), {call FUNC(visualiseStreamToggle)}] call CBA_fnc_addEventHandler;
    [QGVAR(visualiseRebroReport), {call FUNC(visualiseRebroReport)}] call CBA_fnc_addEventHandler;
    [QGVAR(registerVisualiseProvider), {
        params ["_key", "_getter"];
        GVAR(visualiseProviders) set [_key, _getter];
    }] call CBA_fnc_addEventHandler;

    ["rebroconnections", {
        private _rebroPositions = EGVAR(radios,rebroStations) select {alive _x} apply {getPosATL _x};

        private _connections = [];
        {
            private _report = GVAR(visualiseRebroReports) get _x;
            _report params ["_player", "_position", "_name", "_signalLog", "", ""];
            {
                private _rebroObject = objectFromNetId _x;
                if (!isNull _rebroObject) then {
                    private _signalEntry = _signalLog get _x;
                    _connections pushBack [_position, _name, getPosATL _rebroObject, _signalEntry#0, _signalEntry#1];
                };
            } forEach keys _signalLog;
        } forEach keys GVAR(visualiseRebroReports);

        [_rebroPositions, _connections]
    }] call FUNC(registerVisualiseProvider);

    ["rebronetwork", {
        private _rebroPositions = EGVAR(radios,rebroStations) select {alive _x} apply {getPosATL _x};

        private _players = [];
        private _links = [];
        {
            private _report = GVAR(visualiseRebroReports) get _x;
            _report params ["_player", "_position", "_name", "", "_networkLog", ""];
            _players pushBack [_position, _name];
            private _playerIndex = count _players - 1;

            {
                private _linkEntry = _networkLog get _x;
                _linkEntry params ["_signalPower", "_signalDecibels", "_isDirect", "_rebroPosition"];
                _links pushBack [_playerIndex, _x, _signalPower, _isDirect, _rebroPosition];
            } forEach keys _networkLog;
        } forEach keys GVAR(visualiseRebroReports);

        [_rebroPositions, _players, _links]
    }] call FUNC(registerVisualiseProvider);
};

if (hasInterface && {isMultiplayer}) then {
    GVAR(fpsEnabled) = MULTIPLAYER_ADMIN_OR_WHITELISTED;
    [{
        player setVariable [QGVAR(fps), floor diag_fps, true];
    }, 1, []] call CBA_fnc_addPerFrameHandler;
};

TRACE_1("registering Fired class EH",GVAR(projectilesEnabled));
["All", "Fired", {
    params ["_unit", "_weapon", "", "", "_ammo", "", "_projectile"];
    TRACE_3("Fired EH",_unit,_ammo,_projectile);

    if (!GVAR(projectilesEnabled)) exitWith {};

    private _isHeavy = [_ammo, _weapon] call FUNC(isHeavyProjectile);
    TRACE_2("ammo classification",_isHeavy,_ammo);
    if !(_isHeavy) exitWith {};

    if (isNull _projectile) then {
        _projectile = nearestObject [_unit, _ammo];
        TRACE_1("projectile was null, tried nearestObject",_projectile);
    };

    if (!isNull _projectile) then {
        private _sideColor = switch (side _unit) do {
            case west:        { [0, 0.3, 0.6, 0.9] };
            case east:        { [0.5, 0, 0, 0.9] };
            case independent: { [0, 0.5, 0, 0.9] };
            default           { [0.4, 0, 0.5, 0.9] };
        };
        GVAR(trackedProjectiles) pushBack [_projectile, _ammo, _sideColor];
        private _count = count GVAR(trackedProjectiles);
        TRACE_3("tracked projectile",_projectile,_ammo,_count);
    } else {
        TRACE_2("projectile still null after nearestObject",_unit,_ammo);
    };
}, true] call CBA_fnc_addClassEventHandler;

[QGVAR(paradrop), {call FUNC(paradrop)}] call CBA_fnc_addEventHandler;
[QGVAR(moveInCargo), {_this#0 moveInCargo _this#1}] call CBA_fnc_addEventHandler;
[QGVAR(paradropFail), {
    params ["_player", "_failPosition"];

    [QEGVAR(common,textTiles), [parseText format ["<t align = 'center' size = '1.2' color = '#FF0000'>FAILED TO JUMP</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 5]] call CBA_fnc_localEvent;
    _player setPosATL ([_failPosition, 15] call CBA_fnc_randPos);
    _player setVelocity [0, 0, 0];
}] call CBA_fnc_addEventHandler;

if (hasInterface) then {
    call FUNC(addContextActions);

    ["zen_curatorDisplayLoaded", {call FUNC(curatorDisplayLoad)}] call CBA_fnc_addEventHandler;
    ["zen_curatorDisplayUnloaded", {call FUNC(curatorDisplayUnload)}] call CBA_fnc_addEventHandler;

    [QGVAR(visualiseStreamData), {
        params ["_dataMap"];
        {
            GVAR(visualiseData) set [_x, _y];
        } forEach _dataMap;
    }] call CBA_fnc_addEventHandler;
};

ADDON = true;
