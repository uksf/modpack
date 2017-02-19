/*
    Author:
        Tim Beswick

    Description:
        Runs upon an incoming missile. Tracks to target based on random chance

    Parameters:
        0: Heli <OBJECT>
        1: Missile type <OBJECT>
        2: Unit who fired missile <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_heli", "_missileType", "_hostile"];

#define DETONATIONDISTANCE 30
#define TRACKCHANCE 99
#define FLARESEARCHRADIUS 100

if (local _heli && {alive _heli} && {player isEqualTo (driver _heli) || {player isEqualTo (gunner _heli)}} && {isEngineOn _heli} && {_missileType isKindOf "MissileBase"} && {(_heli getVariable [QGVAR(jammerMode), 0]) > 0}) then {
    private _missile = nearestObject [_hostile, _missileType];    
    private _posHeli = getPosASL _heli;
    private _posMissile = getPosASL _missile;    

    if (player isEqualTo (driver _heli) && {(_heli getVariable [QGVAR(jammerMode), 0]) isEqualTo 2}) then {
        [{
            params ["_args", "_idPFH"];
            _args params ["_heli", "_missile", "_iteration"];

            if (isNull _missile || {!alive _heli} || {_iteration >= 8} || {(_missile distance _heli) > (10000)}) exitWith {
                [_idPFH] call cba_fnc_removePerFrameHandler;
                player forceWeaponFire ["CUP_weapon_mastersafe", "CUP_weapon_mastersafe"];
            };
            player forceWeaponFire ["CMFlareLauncher", "Single"];
            _args set [2, _iteration + 1];
        }, 0.1, [_heli, _missile, 1]] call cba_fnc_addPerFrameHandler;
    };

    private _missileAlt = "low";
    if (_posHeli select 2 < _posMissile select 2) then {
        _missileAlt = "high";
    };    
    private _missileDirection = ((_posMissile select 0) - (_posHeli select 0)) atan2 ((_posMissile select 1) - (_posHeli select 1));
    if (_missileDirection < 0) then {
        _missileDirection = _missileDirection + 360;
    };    
    private _oclock = floor ((((360 + (_missileDirection - (direction _heli))) mod 360) + 15) / 30);
    if (_oclock isEqualTo 0) then { _oclock = 12; };    
    [format [QUOTE(GVAR(%1oclock)), _oclock], 1.8, format [QUOTE(GVAR(%1)), _missileAlt], 0.6] call FUNC(audio);

    [{
        params ["_heli", "_missile", "_missileAlt"];

        private _trackTo = _heli;
        private _flareList = (nearestObjects [_heli, [], FLARESEARCHRADIUS]) select {((typeOf _x) isEqualTo "CMflareAmmo") || {(typeOf _x) isEqualTo "CMflare_Chaff_Ammo"}};
        if (_missileAlt != "high" && {(floor random 100) < TRACKCHANCE} && {(count _flareList) > 0}) then {
            _trackTo = selectRandom _flareList;
        };

        [{
            params ["_args", "_idPFH"];
            _args params ["_trackTo", "_missile", "_distanceToTarget", "_prevDistanceToTarget"];          

            if (isNull _trackTo || {isNull _missile} || {!alive _missile}) exitWith {
                [_idPFH] call cba_fnc_removePerFrameHandler;
            };

            private _vectorToTarget = (getPosASL _trackTo) vectorDiff (getPosASL _missile);
            private _dir = vectorNormalized _vectorToTarget;
            _prevDistanceToTarget = _distanceToTarget;
            _distanceToTarget = vectorMagnitude _vectorToTarget;

            if ((_distanceToTarget < DETONATIONDISTANCE || {_distanceToTarget > _prevDistanceToTarget}) && {((typeOf _trackTo) isEqualTo "CMflareAmmo") || {(typeOf _trackTo) isEqualTo "CMflare_Chaff_Ammo"}}) then {
                private _dummyMissile = createVehicle ["UKSF_Dummy_Missile", [0,0,0], [], 0, "FLY"];
                _dummyMissile setPos (getPos _missile);
                deleteVehicle _missile;
                deleteVehicle _trackTo;
                _missile = objNull;            
            } else {
                private _up = (_dir vectorCrossProduct [0,0,1]) vectorCrossProduct _dir;
                _missile setVectorDirAndUp [_dir, _up];
                _missile setVelocity (_dir vectorMultiply (vectorMagnitude (velocity _missile)));
            };
            _args set [2, _distanceToTarget];
            _args set [3, _prevDistanceToTarget];
        }, 0, [_trackTo, _missile, 100000, 0]] call cba_fnc_addPerFrameHandler;
    }, [_heli, _missile, _missileAlt], 1] call cba_fnc_waitAndExecute;    
};
