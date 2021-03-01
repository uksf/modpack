#include "script_component.hpp"
/*
    Author:
        Tim Beswick
        Some code from https://github.com/acemod/ACE3/blob/master/addons/missileguidance/functions/fnc_guidancePFH.sqf

    Description:
        Runs upon an incoming missile. Tracks to target based on random chance

    Parameters:
        0: Aircraft <OBJECT>
        1: Missile type <STRING>
        2: Unit who fired missile <OBJECT>

    Return value:
        Nothing
*/
#define DETONATION_DISTANCE 20
#define TRACK_CHANCE_LOW 50
#define TRACK_CHANCE_HIGH 25
#define FLARE_SEARCH_RADIUS 20
#define TIMESTEP_FACTOR 0.01
#define CM_BASE_TYPE "CMflareAmmo"
#define CM_TYPES ["CMflareAmmo", "CMflare_Chaff_Ammo"]

params ["_aircraft", "_missileType", "_hostile"];

// TODO: Split this function out into smaller components (counter measures, missile guidance, audio warning)
// TODO: Generalise this to be used in all aircraft. Will need better calculation to determine if a missile goes for counter measures (also consider counter measure type and missile seeker type & lock cone)

if !(alive _aircraft || _missileType isKindOf "MissileBase") exitWith {};

private _pilot = driver _aircraft;
if !(local _pilot) exitWith {}; // Only want the pilot's machine to handle this

private _missile = nearestObject [_hostile, _missileType];
GVAR(trackedMissiles) = GVAR(trackedMissiles) - [objNull];
if (_missile in GVAR(trackedMissiles)) exitWith {};
GVAR(trackedMissiles) pushBack _missile;

private _cmMode = _aircraft getVariable [QGVAR(cmMode), 0];

// Flares (cm auto)
if (isEngineOn _aircraft && _cmMode == 2) then {
    [{
        params ["_args", "_idPFH"];
        _args params ["_aircraft", "_pilot", "_missile", "_iteration"];

        if (!alive _aircraft || {_iteration >= 8} || {(_missile distance _aircraft) > (10000)}) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        _pilot forceWeaponFire ["CMFlareLauncher", "Single"];
        _args set [3, _iteration + 1];
    }, 0.2, [_aircraft, _pilot, _missile, 1]] call CBA_fnc_addPerFrameHandler;
};

private _aircraftPosition = getPosASL _aircraft;
private _missilePosition = getPosASL _missile;
private _missileRelativeVertical = "low";
if (_aircraftPosition select 2 < _missilePosition select 2) then {
    _missileRelativeVertical = "high";
};

// Audio warning (cm semi or auto)
if (isEngineOn _aircraft && _cmMode > 0) then {
    private _missileDirection = ((_missilePosition select 0) - (_aircraftPosition select 0)) atan2 ((_missilePosition select 1) - (_aircraftPosition select 1));
    if (_missileDirection < 0) then {
        _missileDirection = _missileDirection + 360;
    };

    private _oclock = floor ((((360 + (_missileDirection - (direction _aircraft))) mod 360) + 15) / 30);
    if (_oclock isEqualTo 0) then {
        _oclock = 12;
    };

    private _sounds = [format [QUOTE(GVAR(%1oclock)), _oclock], 1.7, format [QUOTE(GVAR(%1)), _missileRelativeVertical], 0.5];
    _sounds call FUNC(audio);
    if !(isNull (gunner _aircraft)) then {
        [QGVAR(audio), _sounds, gunner _aircraft] call CBA_fnc_targetEvent;
    };
};

// Guidance (any cm mode)
[{
    params ["_args", "_idPFH"];
    _args params ["_aircraft", "_missile", "_missileRelativeVertical", "_trackTo", "_trackToType", "_lastRunTime", "_lastCheckTime"];

    if !(alive _missile) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        GVAR(trackedMissiles) deleteAt (GVAR(trackedMissiles) find _missile);
        GVAR(trackedMissiles) = GVAR(trackedMissiles) - [objNull];
    };

    if (CBA_missionTime == _lastCheckTime) exitWith {};

    private _typeIsCm = _trackToType in CM_TYPES;
    if (CBA_missionTime > _lastCheckTime) then {
        if (!_typeIsCm && {([TRACK_CHANCE_LOW, TRACK_CHANCE_HIGH] select (_missileRelativeVertical == "high")) > random 100}) then {
            private _flareList = _aircraft nearObjects [CM_BASE_TYPE, FLARE_SEARCH_RADIUS];
            if (_flareList isNotEqualTo []) then {
                _trackTo = selectRandom _flareList;
                _trackToType = typeOf _trackTo;
                _args set [3, _trackTo];
                _args set [4, _trackToType];
            };
        };

        _args set [6, CBA_missionTime + 0.5];
    };

    private _missilePosition = getPosASL _missile;
    private _trackToPosition = getPosASL _trackTo;
    private _targetVector = _missilePosition vectorFromTo _trackToPosition;
    private _distanceToTarget = _missilePosition distance _trackToPosition;
    TRACE_3("",_distanceToTarget,_prevDistanceToTarget + DETONATION_DISTANCE,DETONATION_DISTANCE);
    if (_typeIsCm && {_distanceToTarget < DETONATION_DISTANCE || (speed _missile) < 20}) exitWith {
        triggerAmmo _missile;
    };

    private _adjustVector = _targetVector vectorDiff (vectorDir _missile);
    _adjustVector params ["_adjustVectorX", "_adjustVectorY", "_adjustVectorZ"];

    private _yaw = 0;
    private _pitch = 0;
    private _roll = 0;

    private _runtimeDelta = diag_tickTime - _lastRunTime;
    private _adjustTime = 1;

    if (accTime > 0) then {
        _adjustTime = 1/accTime;
        _adjustTime = _adjustTime * (_runtimeDelta / TIMESTEP_FACTOR);
        TRACE_4("Adjust timing",1/accTime,_adjustTime,_runtimeDelta,(_runtimeDelta / TIMESTEP_FACTOR));
    } else {
        _adjustTime = 0;
    };

    // TODO: Define the deflection values in config
    private _minDeflection = (0.00005 - (0.00005 * _adjustTime)) max 0;
    private _maxDeflection = 0.025 * _adjustTime;

    if (_adjustVectorX < 0) then {
        _yaw = - ((_minDeflection max ((abs _adjustVectorX) min _maxDeflection)));
    } else {
        if (_adjustVectorX > 0) then {
            _yaw = ((_minDeflection max (_adjustVectorX min _maxDeflection)));
        };
    };
    if (_adjustVectorY < 0) then {
        _roll = - ((_minDeflection max ((abs _adjustVectorY) min _maxDeflection)));
    } else {
        if (_adjustVectorY > 0) then {
            _roll = ((_minDeflection max (_adjustVectorY min _maxDeflection)));
        };
    };
    if (_adjustVectorZ < 0) then {
        _pitch = - ((_minDeflection max ((abs _adjustVectorZ) min _maxDeflection)));
    } else {
        if (_adjustVectorZ > 0) then {
            _pitch = ((_minDeflection max (_adjustVectorZ min _maxDeflection)));
        };
    };

    private _finalAdjustVector = [_yaw, _roll, _pitch];
    TRACE_3("",_pitch,_yaw,_roll);
    TRACE_3("",_targetVector,_adjustVector,_finalAdjustVector);

    if (accTime > 0) then {
        private _changeVector = (vectorDir _missile) vectorAdd _finalAdjustVector;
        TRACE_2("",_missile,_changeVector);
        [_missile, _changeVector] call ace_missileguidance_fnc_changeMissileDirection;
    };

    #ifdef DRAW_GUIDANCE_INFO
    drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\selectover_ca.paa", [1,0,0,1], ASLtoAGL _missilePosition, 0.75, 0.75, 0, "m", 1, 0.025, "TahomaB"];
    drawLine3D [(ASLtoAGL _missilePosition), (ASLtoAGL _trackToPosition), [0,1,1,1]];
    drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\selectover_ca.paa", [0,1,0,1], ASLtoAGL _trackToPosition, 0.5, 0.5, 0, "t", 1, 0.025, "TahomaB"];

    private _ps = "#particlesource" createVehicleLocal (ASLtoAGL _missilePosition);
    _PS setParticleParams [["\A3\Data_f\cl_basic", 8, 3, 1], "", "Billboard", 1, 3.0141, [0, 0, 2], [0, 0, 0], 1, 1.275, 1, 0, [1, 1], [[1, 0, 0, 1], [1, 0, 0, 1], [1, 0, 0, 1]], [1], 1, 0, "", "", nil];
    _PS setDropInterval 3.0;
    #endif

    _args set [5, diag_tickTime];
}, 0, [_aircraft, _missile, _missileRelativeVertical, _aircraft, typeOf _aircraft, 0, 0]] call CBA_fnc_addPerFrameHandler;
