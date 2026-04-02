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

    // Build transmitter key → netId lookup (keys may be player UIDs or object netIds)
    private _keyToNetId = createHashMap;
    {
        private _entry = _sourceData get _x;
        if (!(_entry isEqualType []) || {count _entry < 1}) then { continue };
        private _player = _entry select 0;
        if (isNull _player) then { continue };
        _keyToNetId set [_x, netId _player];
    } forEach keys _sourceData;

    // For transmitter keys that are netIds (vehicles), resolve them directly
    {
        private _entry = _sourceData get _x;
        if (!(_entry isEqualType []) || {count _entry < 2}) then { continue };
        private _connectionData = _entry select 1;
        {
            if !(_x in _keyToNetId) then {
                private _object = objectFromNetId _x;
                if (!isNull _object) then {
                    _keyToNetId set [_x, _x];
                };
            };
        } forEach keys _connectionData;
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
                private _transmitterNetId = _keyToNetId getOrDefault [_x, ""];
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

    private _fnc_screenDirection = {
        params ["_from", "_to"];
        private _screenFrom = worldToScreen _from;
        private _screenTo = worldToScreen _to;
        if (_screenFrom isEqualTo [] || {_screenTo isEqualTo []}) exitWith {0};
        ((_screenTo#0) - (_screenFrom#0)) atan2 -((_screenTo#1) - (_screenFrom#1))
    };

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

        private _arrowIcon = "\a3\ui_f\data\map\markers\military\triangle_ca.paa";
        if (_displayPower < 0) then {
            private _deadColour = [0, 0, 0, 1];
            drawLine3D [_transmitterPosition, _rebroPosition, _deadColour];
            drawLine3D [_rebroPosition, _receiverPosition, _deadColour];
            private _mid1 = _transmitterPosition vectorAdd _rebroPosition vectorMultiply 0.5;
            private _mid2 = _rebroPosition vectorAdd _receiverPosition vectorMultiply 0.5;
            private _dir1 = [_transmitterPosition, _rebroPosition] call _fnc_screenDirection;
            private _dir2 = [_rebroPosition, _receiverPosition] call _fnc_screenDirection;
            drawIcon3D [_arrowIcon, _deadColour, _mid1, 0.6, 0.6, _dir1, "", 0, 0.025];
            drawIcon3D [_arrowIcon, _deadColour, _mid2, 0.6, 0.6, _dir2, "", 0, 0.025];
        } else {
            private _colour1 = SIGNAL_COLOUR(_rebroReceivePower);
            private _colour2 = SIGNAL_COLOUR(_rebroTransmitPower);
            drawLine3D [_transmitterPosition, _rebroPosition, _colour1];
            drawLine3D [_rebroPosition, _receiverPosition, _colour2];
            private _mid1 = _transmitterPosition vectorAdd _rebroPosition vectorMultiply 0.5;
            private _mid2 = _rebroPosition vectorAdd _receiverPosition vectorMultiply 0.5;
            private _dir1 = [_transmitterPosition, _rebroPosition] call _fnc_screenDirection;
            private _dir2 = [_rebroPosition, _receiverPosition] call _fnc_screenDirection;
            drawIcon3D [_arrowIcon, _colour1, _mid1, 0.6, 0.6, _dir1, "", 0, 0.025];
            drawIcon3D [_arrowIcon, _colour2, _mid2, 0.6, 0.6, _dir2, "", 0, 0.025];
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

    private _arrowIcon = "\a3\ui_f\data\map\markers\military\triangle_ca.paa";

    // Draw transmitter → rebro → receiver paths
    {
        _x params ["_transmitterNetId", "_rebroNetId", "_receiverNetId", "_displayPower", "_rebroReceivePower", "_rebroTransmitPower"];

        private _transmitter = objectFromNetId _transmitterNetId;
        private _rebroStation = objectFromNetId _rebroNetId;
        private _receiver = objectFromNetId _receiverNetId;
        if (isNull _transmitter || {isNull _rebroStation} || {isNull _receiver}) then { continue };

        private _transmitterPosition = getPos _transmitter;
        private _rebroPosition = getPos _rebroStation;
        private _receiverPosition = getPos _receiver;
        private _mid1 = [(_transmitterPosition#0 + _rebroPosition#0) / 2, (_transmitterPosition#1 + _rebroPosition#1) / 2];
        private _mid2 = [(_rebroPosition#0 + _receiverPosition#0) / 2, (_rebroPosition#1 + _receiverPosition#1) / 2];
        private _dir1 = _transmitterPosition getDir _rebroPosition;
        private _dir2 = _rebroPosition getDir _receiverPosition;

        if (_displayPower < 0) then {
            private _deadColour = [0, 0, 0, 1];
            _map drawLine [_transmitter, _rebroStation, _deadColour];
            _map drawLine [_rebroStation, _receiver, _deadColour];
            _map drawIcon [_arrowIcon, _deadColour, _mid1, 16, 16, _dir1, "", 0];
            _map drawIcon [_arrowIcon, _deadColour, _mid2, 16, 16, _dir2, "", 0];
        } else {
            private _colour1 = SIGNAL_COLOUR(_rebroReceivePower);
            private _colour2 = SIGNAL_COLOUR(_rebroTransmitPower);
            _map drawLine [_transmitter, _rebroStation, _colour1];
            _map drawLine [_rebroStation, _receiver, _colour2];
            _map drawIcon [_arrowIcon, _colour1, _mid1, 16, 16, _dir1, "", 0];
            _map drawIcon [_arrowIcon, _colour2, _mid2, 16, 16, _dir2, "", 0];
        };
    } forEach _connections;
};

[QEGVAR(zeus,registerDebugProvider), [_key, createHashMapFromArray [
    ["draw3d", _fnc_draw3d],
    ["drawMap", _fnc_drawMap],
    ["serverGetter", _fnc_serverGetter],
    ["getterInterval", 2],
    ["clientDataKey", _clientDataKey],
    ["menuName", _menuName],
    ["menuPriority", _menuPriority],
    ["menuCondition", _fnc_menuCondition]
]]] call CBA_fnc_localEvent;

// Radio network provider — direct connections only (no rebro)
_key = QGVAR(network);
_menuName = "Radio Network";
_menuPriority = -80;
_fnc_menuCondition = {true};
_clientDataKey = QGVAR(signalData);

_fnc_serverGetter = {
    private _netIds = [];
    private _keyToIndex = createHashMap;
    private _sourceData = EGVAR(zeus,debugClientData) getOrDefault [QGVAR(signalData), createHashMap];

    // Index receiver clients (keyed by their UID in sourceData)
    {
        private _entry = _sourceData get _x;
        if (!(_entry isEqualType []) || {count _entry < 1}) then { continue };
        private _player = _entry select 0;
        if (isNull _player) then { continue };
        _keyToIndex set [_x, count _netIds];
        _netIds pushBack (netId _player);
    } forEach keys _sourceData;

    // Index transmitter keys that are netIds (vehicles) not already indexed
    {
        private _entry = _sourceData get _x;
        if (!(_entry isEqualType []) || {count _entry < 2}) then { continue };
        private _connectionData = _entry select 1;
        {
            if !(_x in _keyToIndex) then {
                private _object = objectFromNetId _x;
                if (!isNull _object) then {
                    _keyToIndex set [_x, count _netIds];
                    _netIds pushBack _x;
                };
            };
        } forEach keys _connectionData;
    } forEach keys _sourceData;

    private _links = [];
    {
        private _entry = _sourceData get _x;
        if (!(_entry isEqualType []) || {count _entry < 2}) then { continue };
        private _connectionData = _entry select 1;
        private _receiverIndex = _keyToIndex getOrDefault [_x, -1];
        if (_receiverIndex < 0) then { continue };

        {
            private _value = _connectionData get _x;
            if (!(_value isEqualType []) || {count _value < 1}) then { continue };
            _value params ["_displayPower", ["_rebroNetId", ""]];
            if (_rebroNetId == "") then {
                private _transmitterIndex = _keyToIndex getOrDefault [_x, -1];
                if (_transmitterIndex >= 0) then {
                    _links pushBack [_transmitterIndex, _receiverIndex, _displayPower];
                };
            };
        } forEach keys _connectionData;
    } forEach keys _sourceData;

    [_netIds, _links]
};

_fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance"];
    _data params ["_netIds", "_links"];

    private _fnc_screenDirection = {
        params ["_from", "_to"];
        private _screenFrom = worldToScreen _from;
        private _screenTo = worldToScreen _to;
        if (_screenFrom isEqualTo [] || {_screenTo isEqualTo []}) exitWith {0};
        ((_screenTo#0) - (_screenFrom#0)) atan2 -((_screenTo#1) - (_screenFrom#1))
    };

    private _arrowIcon = "\a3\ui_f\data\map\markers\military\triangle_ca.paa";

    {
        _x params ["_fromIndex", "_toIndex", "_power"];

        private _from = objectFromNetId (_netIds select _fromIndex);
        private _to = objectFromNetId (_netIds select _toIndex);
        if (isNull _from || {isNull _to}) then { continue };

        private _fromPosition = ASLToAGL getPosASLVisual _from;
        private _toPosition = ASLToAGL getPosASLVisual _to;
        if (_cameraPosition distance _fromPosition > _maxDistance && {_cameraPosition distance _toPosition > _maxDistance}) then { continue };

        private _lineColour = SIGNAL_COLOUR(_power);
        drawLine3D [_fromPosition, _toPosition, _lineColour];

        private _midPosition = _fromPosition vectorAdd _toPosition vectorMultiply 0.5;
        private _direction = [_fromPosition, _toPosition] call _fnc_screenDirection;
        drawIcon3D [_arrowIcon, _lineColour, _midPosition, 0.6, 0.6, _direction, "", 0, 0.025];
    } forEach _links;
};

_fnc_drawMap = {
    params ["_data", "_map"];
    _data params ["_netIds", "_links"];

    private _arrowIcon = "\a3\ui_f\data\map\markers\military\triangle_ca.paa";

    {
        _x params ["_fromIndex", "_toIndex", "_power"];

        private _from = objectFromNetId (_netIds select _fromIndex);
        private _to = objectFromNetId (_netIds select _toIndex);
        if (isNull _from || {isNull _to}) then { continue };

        private _lineColour = SIGNAL_COLOUR(_power);
        _map drawLine [_from, _to, _lineColour];

        private _fromPosition = getPos _from;
        private _toPosition = getPos _to;
        private _midPosition = [(_fromPosition#0 + _toPosition#0) / 2, (_fromPosition#1 + _toPosition#1) / 2];
        private _direction = _fromPosition getDir _toPosition;
        _map drawIcon [_arrowIcon, _lineColour, _midPosition, 16, 16, _direction, "", 0];
    } forEach _links;
};

[QEGVAR(zeus,registerDebugProvider), [_key, createHashMapFromArray [
    ["draw3d", _fnc_draw3d],
    ["drawMap", _fnc_drawMap],
    ["serverGetter", _fnc_serverGetter],
    ["getterInterval", 2],
    ["clientDataKey", _clientDataKey],
    ["menuName", _menuName],
    ["menuPriority", _menuPriority],
    ["menuCondition", _fnc_menuCondition]
]]] call CBA_fnc_localEvent;
