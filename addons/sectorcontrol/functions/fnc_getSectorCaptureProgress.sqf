#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Works out the % for area capture
        Calls a local hint from the preinit for everyone in the area
        that is a player

    Parameters:
        0: entities in the area <ARRAY>

    Return value:
        Nothing
*/

params ["_entities", "_dominantSideScore", "_timeToCapture"];

if !(isServer) exitWith {};

private _capturePercentage = (_dominantSideScore / _timeToCapture) * 100;

// if (_capturePercentage >= _timeToCapture) exitWith {};

private _players = _entities select {isPlayer _x};
if (_players isEqualTo []) exitWith {};

[QGVAR(localHint), [_capturePercentage], _players] call CBA_fnc_targetEvent;
