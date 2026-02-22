#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(loadout) = "";
GVAR(fpsEnabled) = false;
GVAR(EHIDArray) = [];
GVAR(projectilesEnabled) = false;
GVAR(trackedProjectiles) = [];
GVAR(ammoTypeCache) = createHashMap;
GVAR(ammoNameCache) = createHashMap;
GVAR(ammoIconCache) = createHashMap;
GVAR(visualiseProviders) = createHashMap;
GVAR(visualiseData) = createHashMap;
GVAR(visualiseActiveToggles) = createHashMap;
GVAR(visualiseDistanceLimited) = false;
GVAR(visualiseStreamClients) = [];
GVAR(visualiseStreamPFH) = -1;
GVAR(visualiseHudControls) = [];
GVAR(visualiseMapDrawID) = 999;
GVAR(visualisePFH) = -1;
GVAR(visualiseRebroReports) = createHashMap;

if (isServer) then {
    [QGVAR(visualiseStreamToggle), {call FUNC(visualiseStreamToggle)}] call CBA_fnc_addEventHandler;
    [QGVAR(visualiseRebroReport), {call FUNC(visualiseRebroReport)}] call CBA_fnc_addEventHandler;
    [QGVAR(registerVisualiseProvider), {
        params ["_key", "_getter"];
        TRACE_1("registerVisualiseProvider",_key);
        GVAR(visualiseProviders) set [_key, _getter];
    }] call CBA_fnc_addEventHandler;

    GVAR(visualiseProviders) set ["rebroconnections", {
        private _rebroNetIds = EGVAR(radios,rebroStations) select {alive _x} apply {netId _x};

        private _connections = [];
        {
            private _report = GVAR(visualiseRebroReports) get _x;
            _report params ["_player", "", "", "_signalLog"];
            {
                private _signalEntry = _signalLog get _x;
                _connections pushBack [netId _player, _x, _signalEntry#0];
            } forEach keys _signalLog;
        } forEach keys GVAR(visualiseRebroReports);

        [_rebroNetIds, _connections]
    }];

    GVAR(visualiseProviders) set ["rebronetwork", {
        private _rebroNetIds = EGVAR(radios,rebroStations) select {alive _x} apply {netId _x};

        // Build player list and UID-to-index lookup
        private _players = [];
        private _uidToIndex = createHashMap;
        {
            private _report = GVAR(visualiseRebroReports) get _x;
            _report params ["_player", "", "_name"];
            _uidToIndex set [_x, count _players];
            _players pushBack [netId _player, _name];
        } forEach keys GVAR(visualiseRebroReports);

        // Build links from each player's connectionLog
        // connectionLog entry: [signalPower, isDirect, rebroNetId]
        private _links = [];
        {
            private _report = GVAR(visualiseRebroReports) get _x;
            private _connectionLog = _report#4;
            private _fromIndex = _uidToIndex get _x;

            {
                private _toIndex = _uidToIndex getOrDefault [_x, -1];
                if (_toIndex >= 0) then {
                    private _entry = _connectionLog get _x;
                    _links pushBack [_fromIndex, _toIndex, _entry#0, _entry#1, _entry#2];
                };
            } forEach keys _connectionLog;
        } forEach keys GVAR(visualiseRebroReports);

        [_rebroNetIds, _players, _links]
    }];
};

if (hasInterface && {isMultiplayer}) then {
    GVAR(fpsEnabled) = MULTIPLAYER_ADMIN_OR_WHITELISTED;
    [{
        player setVariable [QGVAR(fps), floor diag_fps, true];
    }, 1, []] call CBA_fnc_addPerFrameHandler;
};

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
            GVAR(visualiseData) set [_x, _dataMap get _x];
        } forEach keys _dataMap;
    }] call CBA_fnc_addEventHandler;
};

ADDON = true;
