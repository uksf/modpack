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
        2: Target <BOOLEAN>
        3: Caller distance <SCALAR>
        4: Stage <SCALAR>
        5: Previous firing position <ARRAY>
        
    Return value:
        NOTHING
*/
params ["_caller", "_artillery", "_targetPosition", "_callerDistance", ["_stage", 0], ["_previousPosition", [0,0,0]]];

if (!(local _artillery)) exitWith {
    [QGVAR(fireMission), _this, _artillery] call CBA_fnc_targetEvent;
};
if (_artillery getVariable [QGVAR(artillerySupportTasked), false]) exitWith {};

private _delay = ARTILLERY_FIRE_MISSION_BASE_DELAY + linearConversion [500, 2000, _callerDistance, 5, 20, true] + random 10;

// Stage 0 Check round (far)
if (_stage == 0) exitWith {
    _artillery setVariable [QGVAR(artillerySupportTasked), true, true];
    [{
        params ["", "_artillery", "_targetPosition"];

        private _direction = random 360;
        private _vectorPosition = [sin _direction, cos _direction, 0] vectorMultiply ((random 50) + 50);
        private _position = [_targetPosition vectorAdd _vectorPosition, 25] call CBA_fnc_randPos;
        _artillery doArtilleryFire [_position, currentMagazine _artillery, (floor random 2) + 1];

        // marker5 = createMarker [str random 9999, _position]; marker5 setMarkerShape "ICON"; marker5 setMarkerType "hd_dot"; marker5 setMarkerColor "ColorGreen";

        _this set [4, 1];
        _this set [5, _position];
        _this call FUNC(fireMission);
    }, _this, _delay] call CBA_fnc_waitAndExecute;
};

_delay = _delay + (_artillery getArtilleryETA [_targetPosition, currentMagazine _artillery]);

[{ // Stage 1 Check round (near) & Stage 2 Barrage (close)
    params ["_caller", "_artillery", "_targetPosition", "", "_stage", "_previousPosition"];

    private _isStage2 = _stage == 2;
    private _distance = [(random 25) + 25, random 12.5] select _isStage2;
    private _randomness = [10, 5] select _isStage2;

    private _vectorDirection = _targetPosition vectorFromTo _previousPosition;
    private _vectorDistance = _previousPosition vectorDistance _targetPosition;
    private _vectorPosition = _vectorDirection vectorMultiply _distance;
    private _position = [_targetPosition vectorAdd _vectorPosition, _randomness] call CBA_fnc_randPos;

    private _rounds = [(floor random 2) + 1, (floor random 4) + 3] select _isStage2;
    _artillery doArtilleryFire [_position, currentMagazine _artillery, _rounds];

    // marker6 = createMarker [str random 9999, _position]; marker6 setMarkerShape "ICON"; marker6 setMarkerType "hd_dot"; marker6 setMarkerColor "ColorYellow";
    // marker7 = createMarker [str random 9999, _position]; marker7 setMarkerShape "ICON"; marker7 setMarkerType "hd_dot"; marker7 setMarkerColor "ColorRed";

    if (!_isStage2) exitWith {
        _this set [4, 2];
        _this set [5, _position];
        _this call FUNC(fireMission);
    };

    [{
        params ["_caller", "_artillery"];

        if (count ([group _caller] call CBA_fnc_getAlive) > 0) then {
            (group _caller) setVariable [QGVAR(artillerySupportRequested), false, true];
        };
        _artillery setVariable [QGVAR(artillerySupportTasked), false, true];
    }, [_caller, _artillery], 60] call CBA_fnc_waitAndExecute;
}, _this, _delay] call CBA_fnc_waitAndExecute;
