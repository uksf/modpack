/*
    Author:
        Tim Beswick

    Description:
        Warns players to stop pinging zeus. 10 pings = death

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_curator", "_unit"];

private _pingCount = _unit getVariable [QGVAR(pingCount), 0];
private _lastPingTime = _unit getVariable [QGVAR(pingTime), time];

_pingCount = _pingCount + 1;
if (_lastPingTime <= time - 15) then {
    _unit getVariable [QGVAR(pingCount), _pingCount];
    _unit getVariable [QGVAR(pingTime), time];
} else {
    if (_pingCount == 5) then {
        "Stop pinging zeus, or you'll die." remoteExecCall ["hint", _unit];
    };
    if (_pingCount >= 10) then {
        "You were warned." remoteExecCall ["hint", _unit];
        _unit setDamage 1;
        _unit setVariable [QGVAR(pingCount), 0, true];
        _unit setVariable [QGVAR(pingTime), time, true];
    } else {
        _unit setVariable [QGVAR(pingCount), _pingCount, true];
        _unit setVariable [QGVAR(pingTime), time, true];
    };
};
        