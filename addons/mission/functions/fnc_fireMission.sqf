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

    Return value:
        Nothing
*/
params [["_caller", objNull, [objNull]], ["_artillery", objNull, [objNull]], ["_targetPosition", [], [[]]], ["_stage", 0, [0]], ["_previousPosition", [0,0,0], [[]]], ["_spread", 50, [0]]];

private _gunner = gunner _artillery;
if !(local _gunner) exitWith {
    [QGVAR(fireMission), _this, _gunner] call CBA_fnc_targetEvent; // doArtilleryFire only seems to work when run on the machine where the artillery gunner is local
};

if (_stage == 0 && {_artillery getVariable [QGVAR(artillerySupportTasked), false]}) exitWith {};

#ifdef DEBUG_MODE_FULL
private _delay = 15;
#else
private _delay = ARTILLERY_FIRE_MISSION_BASE_DELAY + linearConversion [500, 2000, _caller distance2D _artillery, 5, 20, true] + random 10;
#endif

// Stage 0 Check round (far)
if (_stage == 0) exitWith {
    _artillery setVariable [QGVAR(artillerySupportTasked), true, true];
    [{
        params ["", "_artillery", "_targetPosition", "", "", "_spread"];

        // Scale targert area size based on indirectHit and indirectHitRange of the artillery's ammo
        private _ammo = getText (EGVAR(common,configMagazines) >> currentMagazine _artillery >> "ammo");
        private _indirectHit = getNumber (EGVAR(common,configAmmo) >> _ammo >> "indirectHit");
        private _indirectHitRange = getNumber (EGVAR(common,configAmmo) >> _ammo >> "indirectHitRange");
        _spread = (ARTILLERY_FIRE_MISSION_BASE_DISTANCE * (_indirectHit / _indirectHitRange)) min 300;

        private _direction = random 360;
        private _vectorPosition = [sin _direction, cos _direction, 0] vectorMultiply ((random _spread) + _spread);
        private _position = [_targetPosition vectorAdd _vectorPosition, (_spread * 0.5)] call CBA_fnc_randPos;
        _artillery doArtilleryFire [_position, currentMagazine _artillery, (floor random 2) + 1];

#ifdef DEBUG_MODE_FULL
        marker1 = createMarker [str random 9999, _targetPosition]; marker1 setMarkerShape "ELLIPSE"; marker1 setMarkerBrush "Solid"; marker1 setMarkerColor "ColorGreen"; marker1 setMarkerAlpha 0.3; marker1 setMarkerSize [_spread * 2, _spread * 2];
        marker5 = createMarker [str random 9999, _position]; marker5 setMarkerShape "ICON"; marker5 setMarkerType "hd_dot"; marker5 setMarkerColor "ColorGreen";
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
    params ["_caller", "_artillery", "_targetPosition", "_stage", "_previousPosition", "_spread"];

    private _isStage2 = _stage == 2;
    private _distance = [(random (_spread * 0.5)) + (_spread * 0.5), random (_spread * 0.25)] select _isStage2;
    private _randomness = [_spread * 0.1, (_spread * 0.05)] select _isStage2;

    private _vectorDirection = _targetPosition vectorFromTo _previousPosition;
    private _vectorDistance = _previousPosition vectorDistance _targetPosition;
    private _vectorPosition = _vectorDirection vectorMultiply _distance;
    private _position = [_targetPosition vectorAdd _vectorPosition, _randomness] call CBA_fnc_randPos;

    private _rounds = [(floor random 2) + 1, (floor random 4) + 3] select _isStage2;
    _artillery doArtilleryFire [_position, currentMagazine _artillery, _rounds];

#ifdef DEBUG_MODE_FULL
    if (_isStage2) then {
        marker7 = createMarker [str random 9999, _position]; marker7 setMarkerShape "ICON"; marker7 setMarkerType "hd_dot"; marker7 setMarkerColor "ColorRed";
        marker3 = createMarker [str random 9999, _targetPosition]; marker3 setMarkerShape "ELLIPSE"; marker3 setMarkerBrush "Solid"; marker3 setMarkerColor "ColorRed"; marker3 setMarkerAlpha 0.5; marker3 setMarkerSize [_spread * 0.25, _spread * 0.25];
    } else {
        marker6 = createMarker [str random 9999, _position]; marker6 setMarkerShape "ICON"; marker6 setMarkerType "hd_dot"; marker6 setMarkerColor "ColorYellow";
        marker2 = createMarker [str random 9999, _targetPosition]; marker2 setMarkerShape "ELLIPSE"; marker2 setMarkerBrush "Solid"; marker2 setMarkerColor "ColorYellow"; marker2 setMarkerAlpha 0.4; marker2 setMarkerSize [_spread, _spread];
    };
#endif

    if (!_isStage2) exitWith {
        _this set [3, 2];
        _this set [4, _position];
        _this call FUNC(fireMission);
    };

    [{
        params ["_caller", "_artillery"];

        if (count ([group _caller] call CBA_fnc_getAlive) > 0) then {
            (group _caller) setVariable [QGVAR(artillerySupportRequested), false, true];
        };
        _artillery setVariable [QGVAR(artillerySupportTasked), false, true];

#ifdef DEBUG_MODE_FULL
        deleteMarker marker1; deleteMarker marker2; deleteMarker marker3; deleteMarker marker4; deleteMarker marker5; deleteMarker marker6; deleteMarker marker7;
#endif
    }, [_caller, _artillery], 60] call CBA_fnc_waitAndExecute;
}, _this, _delay] call CBA_fnc_waitAndExecute;
