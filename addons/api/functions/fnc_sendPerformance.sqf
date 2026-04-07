#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Reads the common FPS store and sends a batched performance event to the API.
        Called every 5 seconds via PFH. Consumes and clears sample buffers after reading.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_api_fnc_sendPerformance
*/

if (!isServer) exitWith {};

private _fpsStore = EGVAR(common,fpsStore);
private _timestamps = EGVAR(common,fpsStoreTimestamps);
private _now = CBA_missionTime;
private _staleThreshold = 10;

INFO_2("sendPerformance tick: storeKeys=%1 timestampKeys=%2",count keys _fpsStore,count keys _timestamps);

// Build server FPS samples
private _serverEntry = _fpsStore getOrDefault ["server", [0, []]];
private _serverSamples = +(_serverEntry#1);
(_serverEntry#1) resize 0;

// Build HC and player entries
private _headlessClients = [];
private _players = [];

{
    private _identifier = _x;
    if (_identifier isEqualTo "server") then { continue };

    // Prune and skip stale entries
    private _lastUpdate = _timestamps getOrDefault [_identifier, 0];
    if (_now - _lastUpdate > _staleThreshold) then {
        if (_now - _lastUpdate > 60) then {
            _fpsStore deleteAt _identifier;
            _timestamps deleteAt _identifier;
        };
        continue;
    };

    private _entry = _fpsStore get _identifier;
    private _samples = +(_entry#1);
    (_entry#1) resize 0;

    if (_samples isEqualTo []) then { continue };

    // Determine if this is an HC or player
    // HCs are not in ALL_PLAYERS and have no player UID matching the identifier
    private _isPlayer = false;
    {
        if (getPlayerUID _x isEqualTo _identifier) exitWith {
            _isPlayer = true;
        };
    } forEach ALL_PLAYERS;

    if (_isPlayer) then {
        _players pushBack createHashMapFromArray [
            ["uid", _identifier],
            ["fps", _samples]
        ];
    } else {
        _headlessClients pushBack createHashMapFromArray [
            ["name", _identifier],
            ["fps", _samples]
        ];
    };
} forEach keys _fpsStore;

INFO_3("sendPerformance counts: server=%1 hcs=%2 players=%3",count _serverSamples,count _headlessClients,count _players);

// Skip if no data to send
if (_serverSamples isEqualTo [] && {_headlessClients isEqualTo []} && {_players isEqualTo []}) exitWith {
    INFO("sendPerformance: empty data, skipping send");
};

systemTimeUTC params ["_year", "_month", "_day", "_hour", "_minute", "_second"];

private _data = createHashMapFromArray [
    ["sessionId", GVAR(sessionId)],
    ["timestamp", format ["%1-%2-%3T%4:%5:%6Z",
        _year,
        [_month, 2] call CBA_fnc_formatNumber,
        [_day, 2] call CBA_fnc_formatNumber,
        [_hour, 2] call CBA_fnc_formatNumber,
        [_minute, 2] call CBA_fnc_formatNumber,
        [_second, 2] call CBA_fnc_formatNumber
    ]],
    ["server", _serverSamples],
    ["headlessClients", _headlessClients],
    ["players", _players]
];

INFO_1("sendPerformance: dispatching event sessionId=%1",GVAR(sessionId));
["performance", _data] call FUNC(sendEvent);
