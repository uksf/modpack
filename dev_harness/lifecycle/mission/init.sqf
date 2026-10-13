call compile preprocessFileLineNumbers "settings.sqf";

lc_fnc_freeze = {
    params ["_seconds"];
    ["freezeStart", _seconds] call lc_fnc_log;
    private _end = diag_tickTime + _seconds;
    for "_i" from 0 to 1e9 do {
        if (diag_tickTime >= _end) exitWith {};
    };
    ["freezeEnd"] call lc_fnc_log;
};

["uksf_persistence_shutdownStarted", {
    ["shutdownStarted"] call lc_fnc_log;
    if (hasInterface && {lc_freeze > 0}) then {[lc_freeze] call lc_fnc_freeze};
}] call CBA_fnc_addEventHandler;

["uksf_persistence_shutdownFinishing", {
    ["shutdownFinishing"] call lc_fnc_log;
    if (isServer && {lc_serverFreeze > 0}) then {[lc_serverFreeze] call lc_fnc_freeze};
}] call CBA_fnc_addEventHandler;
addMissionEventHandler ["MPEnded", {["MPEnded"] call lc_fnc_log}];
addMissionEventHandler ["Ended", {["Ended", _this select 0] call lc_fnc_log}];

if (isServer) then {
    ["uksf_api_missionEnding", {["missionEnding"] call lc_fnc_log}] call CBA_fnc_addEventHandler;
    ["lc_hcPing", {
        params ["_name", "_time", "_state", "_owner", "_ui"];
        if (diag_tickTime >= (missionNamespace getVariable ["lc_hcPingReport", 0])) then {
            lc_hcPingReport = diag_tickTime + 20;
            ["hcPing", format ["%1 %2 %3 %4 %5", _name, _time, _state, _owner, _ui]] call lc_fnc_log;
        };
        if (_time > 5 && {!_ui}) then {
            lc_hcOwner = _owner;
            ["lc_ready", ["hc", "", _name]] call CBA_fnc_localEvent;
        };
    }] call CBA_fnc_addEventHandler;
    ["lc_note", {
        params ["_event", ["_data", ""]];
        [_event, _data] call lc_fnc_log;
    }] call CBA_fnc_addEventHandler;
    ["lc_ready", {
        params ["_role", "_uid", "_name"];
        if (_role == "hc" && {!isNil "lc_hcReady"}) exitWith {};
        if (_role == "hc") then {lc_hcReady = true};
        ["remoteReady", format ["%1 %2 %3", _role, _uid, _name]] call lc_fnc_log;
    }] call CBA_fnc_addEventHandler;
    addMissionEventHandler ["PlayerConnected", {
        params ["", "_uid", "_name", "", "_owner"];
        ["playerConnected", format ["%1 %2 %3", _uid, _owner, _name]] call lc_fnc_log;
    }];
    addMissionEventHandler ["PlayerDisconnected", {
        params ["", "_uid", "_name", "", "_owner"];
        ["playerDisconnected", format ["%1 %2 %3", _uid, _owner, _name]] call lc_fnc_log;
    }];
    lc_frameLast = diag_tickTime;
    lc_frameMax = 0;
    lc_frameReport = diag_tickTime + 2;
    [{
        private _now = diag_tickTime;
        lc_frameMax = lc_frameMax max (_now - lc_frameLast);
        lc_frameLast = _now;
        if (_now >= lc_frameReport) then {
            ["frame", format ["%1 %2", round diag_fps, round (lc_frameMax * 1000)]] call lc_fnc_log;
            lc_frameMax = 0;
            lc_frameReport = _now + 2;
            if (isNil "lc_hcReady") then {
                private _targets = ((allUsers apply {getUserInfo _x}) select {_x select 7}) apply {_x select 1};
                {_targets pushBackUnique owner _x} forEach ((entities "HeadlessClient_F") select {isPlayer _x});
                if (_now >= (missionNamespace getVariable ["lc_usersReport", 0])) then {
                    lc_usersReport = _now + 20;
                    ["users", str [_targets, allUsers apply {private _i = getUserInfo _x; (_i select [1, 7]) + [typeOf (_i select 10), alive (_i select 10)]}]] call lc_fnc_log;
                };
                {
                    [{["lc_hcPing", [profileName, time, getClientStateNumber, clientOwner, hasInterface]] call CBA_fnc_serverEvent}] remoteExecCall ["call", _x];
                } forEach _targets;
            };
        };
    }, 0] call CBA_fnc_addPerFrameHandler;
};

if (hasInterface) then {
    [{!isNull player && {alive player} && {!(player isKindOf "HeadlessClient_F")}}, {
        [{
            ["ready", getPlayerUID player] call lc_fnc_log;
            ["lc_ready", ["client", getPlayerUID player, profileName]] call CBA_fnc_serverEvent;
        }, [], 5] call CBA_fnc_waitAndExecute;
    }] call CBA_fnc_waitUntilAndExecute;
};

if (hasInterface && {lc_roundTrip}) then {call compile preprocessFileLineNumbers "roundtrip.sqf"};
if (!isServer && {lc_stats}) then {call compile preprocessFileLineNumbers "stats.sqf"};
