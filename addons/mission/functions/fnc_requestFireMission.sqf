#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Validates and starts a tracked walking-fire mission. Completion is
        published to the server through uksf_mission_fireMissionCompleted.

    Parameters:
        0: Caller <OBJECT>
        1: Artillery <OBJECT>
        2: Target position <ARRAY>
        3: Request ID <STRING>
        4: Requested total rounds <SCALAR>
        5: Opaque completion context <ARRAY> (Optional)

    Return value:
        Request accepted for local execution <BOOL>

    Example:
        [_caller, _artillery, _targetPosition, _requestId, 6, []] call uksf_mission_fnc_requestFireMission
*/
params [
    ["_caller", objNull, [objNull]],
    ["_artillery", objNull, [objNull]],
    ["_targetPosition", [], [[]]],
    ["_requestId", "", [""]],
    ["_requestedRounds", 0, [0]],
    ["_context", [], [[]]]
];

private _gunner = gunner _artillery;
private _reason = "";

if (_requestId == "") then { _reason = "Request ID is empty"; };
if (isNull _artillery || {!alive _artillery}) then { _reason = "Artillery is unavailable"; };
if (isNull _gunner || {!alive _gunner}) then { _reason = "Artillery has no live gunner"; };
if ((count _targetPosition) < 2) then { _reason = "Target position is invalid"; };
if (_requestedRounds < 3) then { _reason = "Walking fire requires at least three rounds"; };

if (_reason != "") exitWith {
    [QGVAR(fireMissionCompleted), [_requestId, _artillery, false, 0, _reason, _context]] call CBA_fnc_serverEvent;
    false
};

if (!local _gunner) exitWith {
    [QGVAR(requestFireMission), _this, _gunner] call CBA_fnc_targetEvent;
    true
};

if (_artillery getVariable [QGVAR(artillerySupportTasked), false]) exitWith {
    [QGVAR(fireMissionCompleted), [_requestId, _artillery, false, 0, "Artillery is already tasked", _context]] call CBA_fnc_serverEvent;
    false
};

private _magazine = currentMagazine _artillery;
if (_magazine == "") exitWith {
    [QGVAR(fireMissionCompleted), [_requestId, _artillery, false, 0, "Artillery has no current magazine", _context]] call CBA_fnc_serverEvent;
    false
};

private _availableRounds = 0;
{
    if ((_x select 0) == _magazine) then {
        _availableRounds = _availableRounds + (_x select 1);
    };
} forEach (magazinesAmmo _artillery);

if (_availableRounds < _requestedRounds) exitWith {
    [QGVAR(fireMissionCompleted), [
        _requestId,
        _artillery,
        false,
        0,
        format ["Artillery has %1 of %2 required rounds", _availableRounds, _requestedRounds],
        _context
    ]] call CBA_fnc_serverEvent;
    false
};

if !(_targetPosition inRangeOfArtillery [[_artillery], _magazine]) exitWith {
    [QGVAR(fireMissionCompleted), [_requestId, _artillery, false, 0, "Target is outside artillery range", _context]] call CBA_fnc_serverEvent;
    false
};

if (isNull _caller) then {
    _caller = _artillery;
};

[
    _caller,
    _artillery,
    _targetPosition,
    0,
    [0, 0, 0],
    50,
    _requestId,
    _requestedRounds,
    0,
    _magazine,
    _availableRounds,
    _context
] call FUNC(fireMission);

true
