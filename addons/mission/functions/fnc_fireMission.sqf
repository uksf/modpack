#include "script_component.hpp"
/*
    Author:
        Adam Bridgford, Tim Beswick

    Description:
        Performs fire mission based on given stage
            - Stage 0: 1 or 2 check rounds fired (far)
            - Stage 1: 1 or 2 check rounds fired (near)
            - Stage 2: 3-6 barrage rounds fired (close)
        Targeted position moves closer per stage, in a corrected vector towards to the stored target position
        Target position does not update from first call

    Parameters:
        0: Caller <OBJECT>
        1: Artillery <OBJECT>
        2: Target <ARRAY>
        3: Stage <SCALAR> (Optional, don't specify unless skipping a stage)
        4: Previous firing position <ARRAY> (Optional, required if stage is not 0)
        5: Spread <SCALAR> (Optional, required if stage is not 0, overwritten if stage 0 runs first)
        6: Request ID <STRING> (Optional)
        7: Requested total rounds <SCALAR> (Optional)
        8: Rounds ordered so far <SCALAR> (Optional)
        9: Magazine <STRING> (Optional)
        10: Initial magazine rounds <SCALAR> (Optional)
        11: Completion context <ARRAY> (Optional)

    Return value:
        Nothing

    Example:
        [_caller, _artillery, _targetPosition] call uksf_mission_fnc_fireMission
*/
params [
    ["_caller", objNull, [objNull]],
    ["_artillery", objNull, [objNull]],
    ["_targetPosition", [], [[]]],
    ["_stage", 0, [0]],
    ["_previousPosition", [0, 0, 0], [[]]],
    ["_spread", 50, [0]],
    ["_requestId", "", [""]],
    ["_requestedRounds", -1, [0]],
    ["_roundsOrdered", 0, [0]],
    ["_magazine", "", [""]],
    ["_initialMagazineRounds", -1, [0]],
    ["_context", [], [[]]]
];

private _gunner = gunner _artillery;
if (_requestId != "" && {!alive _artillery || {isNull _gunner || {!alive _gunner}}}) exitWith {
    _artillery setVariable [QGVAR(artillerySupportTasked), false, true];
    [QGVAR(fireMissionCompleted), [_requestId, _artillery, false, _roundsOrdered, "Artillery became unavailable", _context]] call CBA_fnc_serverEvent;
};

if !(local _gunner) exitWith {
    [QGVAR(fireMission), _this, _gunner] call CBA_fnc_targetEvent;
};

if (_stage == 0 && {_artillery getVariable [QGVAR(artillerySupportTasked), false]}) exitWith {
    if (_requestId != "") then {
        [QGVAR(fireMissionCompleted), [_requestId, _artillery, false, 0, "Artillery is already tasked", _context]] call CBA_fnc_serverEvent;
    };
};

#ifdef DEBUG_MODE_FULL
private _delay = 15;
#else
private _delay = ARTILLERY_FIRE_MISSION_BASE_DELAY + linearConversion [500, 2000, _caller distance2D _artillery, 5, 20, true] + random 10;
#endif

// Stage 0 Check round (far)
if (_stage == 0) exitWith {
    _artillery setVariable [QGVAR(artillerySupportTasked), true, true];
    [{
        params ["", "_artillery", "_targetPosition", "", "", "_spread", "_requestId", "", "_roundsOrdered", "_magazine"];

        private _activeMagazine = [currentMagazine _artillery, _magazine] select (_magazine != "");
        private _ammo = getText (EGVAR(common,configMagazines) >> _activeMagazine >> "ammo");
        private _indirectHit = getNumber (EGVAR(common,configAmmo) >> _ammo >> "indirectHit");
        private _indirectHitRange = getNumber (EGVAR(common,configAmmo) >> _ammo >> "indirectHitRange");
        _spread = (ARTILLERY_FIRE_MISSION_BASE_DISTANCE * (_indirectHit / (_indirectHitRange max 1))) min 300;

        private _direction = random 360;
        private _vectorPosition = [sin _direction, cos _direction, 0] vectorMultiply ((random _spread) + _spread);
        private _position = [_targetPosition vectorAdd _vectorPosition, (_spread * 0.5)] call CBA_fnc_randPos;
        private _rounds = [(floor random 2) + 1, 1] select (_requestId != "");
        _artillery doArtilleryFire [_position, _activeMagazine, _rounds];
        _this set [8, _roundsOrdered + _rounds];

#ifdef DEBUG_MODE_FULL
        marker1 = createMarker [str random 9999, _targetPosition]; marker1 setMarkerShapeLocal "ELLIPSE"; marker1 setMarkerBrushLocal "Solid"; marker1 setMarkerColorLocal "ColorGreen"; marker1 setMarkerAlphaLocal 0.3; marker1 setMarkerSize [_spread * 2, _spread * 2];
        marker5 = createMarker [str random 9999, _position]; marker5 setMarkerShapeLocal "ICON"; marker5 setMarkerTypeLocal "hd_dot"; marker5 setMarkerColor "ColorGreen";
#endif

        _this set [3, 1];
        _this set [4, _position];
        _this set [5, _spread];
        _this call FUNC(fireMission);
    }, _this, _delay] call CBA_fnc_waitAndExecute;
};

#ifndef DEBUG_MODE_FULL
_delay = _delay + (_artillery getArtilleryETA [_targetPosition, currentMagazine _artillery]);
#endif

[{ // Stage 1 Check round (near) & Stage 2 Barrage (close)
    params ["_caller", "_artillery", "_targetPosition", "_stage", "_previousPosition", "_spread", "_requestId", "_requestedRounds", "_roundsOrdered", "_magazine", "_initialMagazineRounds", "_context"];

    if (_requestId != "" && {!alive _artillery || {isNull (gunner _artillery) || {!alive (gunner _artillery)}}}) exitWith {
        _artillery setVariable [QGVAR(artillerySupportTasked), false, true];
        [QGVAR(fireMissionCompleted), [_requestId, _artillery, false, _roundsOrdered, "Artillery became unavailable", _context]] call CBA_fnc_serverEvent;
    };

    private _isStage2 = _stage == 2;
    private _distance = [(random (_spread * 0.5)) + (_spread * 0.5), random (_spread * 0.25)] select _isStage2;
    private _randomness = [_spread * 0.1, (_spread * 0.05)] select _isStage2;

    private _vectorDirection = _targetPosition vectorFromTo _previousPosition;
    private _vectorDistance = _previousPosition vectorDistance _targetPosition;
    private _vectorPosition = _vectorDirection vectorMultiply _distance;
    private _position = [_targetPosition vectorAdd _vectorPosition, _randomness] call CBA_fnc_randPos;

    private _rounds = [(floor random 2) + 1, (floor random 4) + 3] select _isStage2;
    if (_requestId != "") then {
        _rounds = [1, _requestedRounds - 2] select _isStage2;
    };
    private _activeMagazine = [currentMagazine _artillery, _magazine] select (_magazine != "");
    _artillery doArtilleryFire [_position, _activeMagazine, _rounds];
    _roundsOrdered = _roundsOrdered + _rounds;
    _this set [8, _roundsOrdered];

#ifdef DEBUG_MODE_FULL
    if (_isStage2) then {
        marker7 = createMarker [str random 9999, _position]; marker7 setMarkerShapeLocal "ICON"; marker7 setMarkerTypeLocal "hd_dot"; marker7 setMarkerColor "ColorRed";
        marker3 = createMarker [str random 9999, _targetPosition]; marker3 setMarkerShapeLocal "ELLIPSE"; marker3 setMarkerBrushLocal "Solid"; marker3 setMarkerColorLocal "ColorRed"; marker3 setMarkerAlphaLocal 0.5; marker3 setMarkerSize [_spread * 0.25, _spread * 0.25];
    } else {
        marker6 = createMarker [str random 9999, _position]; marker6 setMarkerShapeLocal "ICON"; marker6 setMarkerTypeLocal "hd_dot"; marker6 setMarkerColor "ColorYellow";
        marker2 = createMarker [str random 9999, _targetPosition]; marker2 setMarkerShapeLocal "ELLIPSE"; marker2 setMarkerBrushLocal "Solid"; marker2 setMarkerColorLocal "ColorYellow"; marker2 setMarkerAlphaLocal 0.4; marker2 setMarkerSize [_spread, _spread];
    };
#endif

    if (!_isStage2) exitWith {
        _this set [3, 2];
        _this set [4, _position];
        _this call FUNC(fireMission);
    };

    [{
        params ["_callerGroup", "_artillery", "_requestId", "_roundsOrdered", "_magazine", "_initialMagazineRounds", "_context"];

        if (!isNull _callerGroup && {[units _callerGroup, {alive _x}] call EFUNC(common,arrayNone)}) then {
            _callerGroup setVariable [QGVAR(artillerySupportRequested), false, true];
        };

        if (!isNull _artillery) then {
            _artillery setVariable [QGVAR(artillerySupportTasked), false, true];
        };

        if (_requestId != "") then {
            private _remainingRounds = 0;
            {
                if ((_x select 0) == _magazine) then {
                    _remainingRounds = _remainingRounds + (_x select 1);
                };
            } forEach (magazinesAmmo _artillery);
            private _roundsFired = ((_initialMagazineRounds - _remainingRounds) max 0) min _roundsOrdered;
            [QGVAR(fireMissionCompleted), [_requestId, _artillery, true, _roundsFired, "", _context]] call CBA_fnc_serverEvent;
        };

#ifdef DEBUG_MODE_FULL
        deleteMarker marker1; deleteMarker marker2; deleteMarker marker3; deleteMarker marker4; deleteMarker marker5; deleteMarker marker6; deleteMarker marker7;
#endif
    }, [group _caller, _artillery, _requestId, _roundsOrdered, _magazine, _initialMagazineRounds, _context], 60] call CBA_fnc_waitAndExecute;
}, _this, _delay] call CBA_fnc_waitAndExecute;
