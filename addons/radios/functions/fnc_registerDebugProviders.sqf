#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers radio debug providers with Zeus (rebro connections and full network)
        and the client data source for signal reporting.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_radios_fnc_registerDebugProviders
*/

#define SIGNAL_COLOUR(POWER) (if (POWER < 0) then {[0, 0, 0, 1]} else {[linearConversion [0.5, 1, POWER, 1, 0, true], linearConversion [0, 0.5, POWER, 0, 1, true], 0, 1]})

// Client data source for signal reporting
private _sourceKey = QGVAR(signalData);
private _fnc_clientGetter = {
    if (GVAR(debugConnectionData) isEqualTo createHashMap) exitWith {[]};
    private _connectionData = GVAR(debugConnectionData);
    GVAR(debugConnectionData) = createHashMap;
    _connectionData
};
private _interval = 4;
private _fnc_onStart = {
    GVAR(debugReportingEnabled) = true;
    GVAR(debugConnectionData) = createHashMap;
};
private _fnc_onStop = {
    GVAR(debugReportingEnabled) = false;
    GVAR(debugConnectionData) = createHashMap;
};
[QEGVAR(zeus,registerDebugClientSource), [_sourceKey, _fnc_clientGetter, _interval, _fnc_onStart, _fnc_onStop]] call CBA_fnc_localEvent;

// Rebro connections provider — draws transmitter → rebro → receiver paths
private _key = QGVAR(rebroConnections);
private _menuName = "Rebro Connections";
private _menuPriority = -70;
private _fnc_menuCondition = {true};
private _clientDataKey = QGVAR(signalData);

private _fnc_serverGetter = {
    private _rebroNetIds = GVAR(rebroStations) select {alive _x} apply {netId _x};

    // Client data is stored as { receiverUID: [playerObj, connectionData, timestamp] }
    // connectionData is a hashmap { transmitterUID: [displayPower, rebroNetId, rebroReceivePower, rebroTransmitPower] }
    private _sourceData = EGVAR(zeus,debugClientData) getOrDefault [QGVAR(signalData), createHashMap];

    // Build UID → player netId lookup
    private _uidToNetId = createHashMap;
    {
        private _entry = _sourceData get _x;
        if (!(_entry isEqualType []) || {count _entry < 1}) then { continue };
        private _player = _entry select 0;
        if (isNull _player) then { continue };
        _uidToNetId set [_x, netId _player];
    } forEach keys _sourceData;

    // Collect rebro-relayed connections
    private _connections = [];
    {
        private _entry = _sourceData get _x;
        if (!(_entry isEqualType []) || {count _entry < 2}) then { continue };
        private _receiver = _entry select 0;
        private _connectionData = _entry select 1;
        if (isNull _receiver) then { continue };

        {
            private _value = _connectionData get _x;
            if (!(_value isEqualType []) || {count _value < 2}) then { continue };
            _value params ["_displayPower", ["_rebroNetId", ""], ["_rebroReceivePower", 0], ["_rebroTransmitPower", 0]];
            if (_rebroNetId != "") then {
                private _transmitterNetId = _uidToNetId getOrDefault [_x, ""];
                if (_transmitterNetId != "") then {
                    _connections pushBack [
                        _transmitterNetId,
                        _rebroNetId,
                        netId _receiver,
                        _displayPower,
                        _rebroReceivePower,
                        _rebroTransmitPower
                    ];
                };
            };
        } forEach keys _connectionData;
    } forEach keys _sourceData;

    [_rebroNetIds, _connections]
};

private _fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance"];
    _data params ["_rebroNetIds", "_connections"];

    private _rebroIcon = "\a3\ui_f\data\map\markers\military\triangle_ca.paa";
    private _rebroColour = [0, 1, 1, 1];

    // Draw rebro station icons
    {
        private _rebroStation = objectFromNetId _x;
        if (isNull _rebroStation) then { continue };

        private _position = ASLToAGL getPosASLVisual _rebroStation;
        if (_cameraPosition distance _position > _maxDistance) then { continue };

        drawIcon3D [_rebroIcon, _rebroColour, _position, 1, 1, 0, "ReBro", 1, 0.025, "TahomaB", "center", true];
    } forEach _rebroNetIds;

    // Draw transmitter → rebro → receiver paths
    {
        _x params ["_transmitterNetId", "_rebroNetId", "_receiverNetId", "_displayPower", "_rebroReceivePower", "_rebroTransmitPower"];

        private _transmitter = objectFromNetId _transmitterNetId;
        private _rebroStation = objectFromNetId _rebroNetId;
        private _receiver = objectFromNetId _receiverNetId;
        if (isNull _transmitter || {isNull _rebroStation} || {isNull _receiver}) then { continue };

        private _transmitterPosition = ASLToAGL getPosASLVisual _transmitter;
        private _rebroPosition = ASLToAGL getPosASLVisual _rebroStation;
        private _receiverPosition = ASLToAGL getPosASLVisual _receiver;

        if (_cameraPosition distance _rebroPosition > _maxDistance
            && {_cameraPosition distance _transmitterPosition > _maxDistance}
            && {_cameraPosition distance _receiverPosition > _maxDistance}) then { continue };

        if (_displayPower < 0) then {
            drawLine3D [_transmitterPosition, _rebroPosition, [0, 0, 0, 1]];
            drawLine3D [_rebroPosition, _receiverPosition, [0, 0, 0, 1]];
        } else {
            drawLine3D [_transmitterPosition, _rebroPosition, SIGNAL_COLOUR(_rebroReceivePower)];
            drawLine3D [_rebroPosition, _receiverPosition, SIGNAL_COLOUR(_rebroTransmitPower)];
        };
    } forEach _connections;
};

private _fnc_drawMap = {
    params ["_data", "_map"];
    _data params ["_rebroNetIds", "_connections"];

    private _rebroIcon = "\a3\ui_f\data\map\markers\military\triangle_ca.paa";
    private _rebroColour = [0, 1, 1, 1];

    // Draw rebro station icons
    {
        private _rebroStation = objectFromNetId _x;
        if (isNull _rebroStation) then { continue };

        _map drawIcon [_rebroIcon, _rebroColour, _rebroStation, 24, 24, 0, "ReBro", 1, 0.04, "TahomaB", "right"];
    } forEach _rebroNetIds;

    // Draw transmitter → rebro → receiver paths
    {
        _x params ["_transmitterNetId", "_rebroNetId", "_receiverNetId", "_displayPower", "_rebroReceivePower", "_rebroTransmitPower"];

        private _transmitter = objectFromNetId _transmitterNetId;
        private _rebroStation = objectFromNetId _rebroNetId;
        private _receiver = objectFromNetId _receiverNetId;
        if (isNull _transmitter || {isNull _rebroStation} || {isNull _receiver}) then { continue };

        if (_displayPower < 0) then {
            _map drawLine [_transmitter, _rebroStation, [0, 0, 0, 1]];
            _map drawLine [_rebroStation, _receiver, [0, 0, 0, 1]];
        } else {
            _map drawLine [_transmitter, _rebroStation, SIGNAL_COLOUR(_rebroReceivePower)];
            _map drawLine [_rebroStation, _receiver, SIGNAL_COLOUR(_rebroTransmitPower)];
        };
    } forEach _connections;
};

[QEGVAR(zeus,registerDebugAction), [_key, _menuName, _menuPriority, _fnc_menuCondition]] call CBA_fnc_localEvent;
[QEGVAR(zeus,registerDebugServerGetter), [_key, _fnc_serverGetter, 2, _clientDataKey]] call CBA_fnc_localEvent;
[QEGVAR(zeus,registerDebugDraw), [_key, _fnc_draw3d, _fnc_drawMap]] call CBA_fnc_localEvent;

// Radio network provider — direct connections only (no rebro)
_key = QGVAR(network);
_menuName = "Radio Network";
_menuPriority = -80;
_fnc_menuCondition = {true};
_clientDataKey = QGVAR(signalData);

_fnc_serverGetter = {
    private _players = [];
    private _uidToIndex = createHashMap;
    private _sourceData = EGVAR(zeus,debugClientData) getOrDefault [QGVAR(signalData), createHashMap];
    {
        private _entry = _sourceData get _x;
        if (!(_entry isEqualType []) || {count _entry < 1}) then { continue };
        private _player = _entry select 0;
        if (isNull _player) then { continue };
        _uidToIndex set [_x, count _players];
        _players pushBack (netId _player);
    } forEach keys _sourceData;

    private _links = [];
    {
        private _entry = _sourceData get _x;
        if (!(_entry isEqualType []) || {count _entry < 2}) then { continue };
        private _connectionData = _entry select 1;
        private _fromIndex = _uidToIndex getOrDefault [_x, -1];
        if (_fromIndex < 0) then { continue };

        {
            private _value = _connectionData get _x;
            if (!(_value isEqualType []) || {count _value < 1}) then { continue };
            _value params ["_displayPower", ["_rebroNetId", ""]];
            if (_rebroNetId == "") then {
                private _toIndex = _uidToIndex getOrDefault [_x, -1];
                if (_toIndex >= 0) then {
                    _links pushBack [_fromIndex, _toIndex, _displayPower];
                };
            };
        } forEach keys _connectionData;
    } forEach keys _sourceData;

    [_players, _links]
};

_fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance"];
    _data params ["_players", "_links"];

    // Draw direct player-to-player links
    {
        _x params ["_fromIndex", "_toIndex", "_power"];

        private _fromPlayer = objectFromNetId (_players select _fromIndex);
        private _toPlayer = objectFromNetId (_players select _toIndex);
        if (isNull _fromPlayer || {isNull _toPlayer}) then { continue };

        private _fromPosition = ASLToAGL getPosASLVisual _fromPlayer;
        private _toPosition = ASLToAGL getPosASLVisual _toPlayer;
        if (_cameraPosition distance _fromPosition > _maxDistance && {_cameraPosition distance _toPosition > _maxDistance}) then { continue };

        private _lineColour = SIGNAL_COLOUR(_power);

        drawLine3D [_fromPosition, _toPosition, _lineColour];
    } forEach _links;
};

_fnc_drawMap = {
    params ["_data", "_map"];
    _data params ["_players", "_links"];

    // Draw direct player-to-player links
    {
        _x params ["_fromIndex", "_toIndex", "_power"];

        private _fromPlayer = objectFromNetId (_players select _fromIndex);
        private _toPlayer = objectFromNetId (_players select _toIndex);
        if (isNull _fromPlayer || {isNull _toPlayer}) then { continue };

        private _lineColour = SIGNAL_COLOUR(_power);

        _map drawLine [_fromPlayer, _toPlayer, _lineColour];
    } forEach _links;
};

[QEGVAR(zeus,registerDebugAction), [_key, _menuName, _menuPriority, _fnc_menuCondition]] call CBA_fnc_localEvent;
[QEGVAR(zeus,registerDebugServerGetter), [_key, _fnc_serverGetter, 2, _clientDataKey]] call CBA_fnc_localEvent;
[QEGVAR(zeus,registerDebugDraw), [_key, _fnc_draw3d, _fnc_drawMap]] call CBA_fnc_localEvent;
