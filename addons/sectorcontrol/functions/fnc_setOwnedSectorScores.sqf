#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Sets the scores to 100 for any sectors owned at mission start

    Parameters:
        0: The module logic <OBJECT>
        1: current opfor score <NUMBER>
        2: current blufor score <NUMBER>

    Return value:
        Nothing
*/
params ["_logic", "_currentOpforScore", "_currentBluforScore", "_timeToCapture"];

if !(isServer) exitWith {};

private _currentOwner = _logic getVariable [QGVAR(currentOwner), 2]; // default to no-one

switch (_currentOwner) do {
    case 0: { // opfor
        _currentOpforScore = _timeToCapture;
        _currentbluforScore = 0;
    };
    case 1: { // blufor
        _currentOpforScore = 0;
        _currentbluforScore = _timeToCapture;
    };
    case 2: { // no-one / neutral
        _currentOpforScore = 0;
        _currentbluforScore = 0;
    };
};

// set scores
_logic setVariable [QGVAR(currentOpforScore), _currentOpforScore, true];
_logic setVariable [QGVAR(currentbluforScore), _currentbluforScore, true];
