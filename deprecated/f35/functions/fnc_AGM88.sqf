/*
    Author:
        Tim Beswick, USAF Team

    Description:
        AGM-88 SEAD System

    Parameters:
        0: Plane <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_plane"];

if ("USAF_1Rnd_AGM88" in magazines _plane) then {    
    _targets = vehicles select {
        alive _x && 
        {_x distance _plane <= 8000} && 
        {_x isKindOf "Landvehicle" || _x isKindOf "Ship"} && 
        {side _plane != side _x} && 
        {_x getVariable ["USAF_AGM_FIRED_AT_TARGET", false]} && 
        {(getNumber (configFile >> "CfgVehicles" >> (typeof _x) >> "radarType")) isEqualTo 2}
    };
    if ((count _targets) isEqualTo 0) exitWith {
        [parseText format ["<t align = 'center' color = '#FF0000'>NO TARGETS AVAILABLE</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 5] spawn BIS_fnc_textTiles;
    };

    _target = _targets select 0;
    _target setVariable ["USAF_AGM_FIRED_AT_TARGET", true, true];
    _laser = "LaserTargetW" createVehicleLocal (getPos _plane);
    _laser attachTo [_plane, [0,500,0]];
    _weapon = currentWeapon _plane;
    _plane selectWeapon "USAF_AGM88_Launcher";

    [parseText format ["<t align = 'center' color = '#00CC00'>TARGET AQCUIRED - %1</t>", getText (configFile >> 'CfgVehicles' >> typeOf _target >> 'displayName')], [0.25, 1, 0.5, 0.05], [1, 1], 0.9] spawn BIS_fnc_textTiles;
    [{
        [parseText format ["<t align = 'center' color = '#00CC00'>LOCKING TARGET</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 0.9] spawn BIS_fnc_textTiles;
    }, [], 1] call cba_fnc_waitAndExecute;
    [{
        [parseText format ["<t align = 'center' color = '#00CC00'>TARGET LOCKED</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 0.9] spawn BIS_fnc_textTiles;
    }, [], 2] call cba_fnc_waitAndExecute;
    [{
        [parseText format ["<t align = 'center' color = '#00CC00'>MISSILE RELEASED</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 5] spawn BIS_fnc_textTiles;
    }, [], 3] call cba_fnc_waitAndExecute;

    [{
        params ["_plane", "_target", "_laser", "_weapon"];

        _plane fireAtTarget [_laser, "USAF_AGM88_Launcher"];
        _plane selectWeapon _weapon;
        _missiles = _plane nearobjects ["USAF_AGM88_AG", 500];
        _missile = _missiles select 0;
        _missileDir = [_missile, _target] call BIS_fnc_dirTo;
        _missile setDir (_missileDir);
        [_missile, 0, 0] call BIS_fnc_setPitchBank;
        _laser attachto [_target, [0,0,0]];

        [{
            params ["_args", "_idPFH"];
            _args params ["_missile", "_target"];

            _pos = _missile modelToWorld [0,200,0];
            if ((_pos select 2) < 30) then {
                _pitchBank = _missile call BIS_fnc_getPitchBank;
                [_missile, (_pitchBank select 0) + 10, 0] call BIS_fnc_setPitchBank;
            } else {
                [_missile, 0, 0] call BIS_fnc_setPitchBank;
            };
            if ((_missile distance2D _target) < 750 || !terrainIntersect [getPos _missile, getPos _target] || isNull _missile || isNull _target || !alive _target) exitWith {
                [_missile, 0, 0] call BIS_fnc_setPitchBank;
                [_idPFH] call cba_fnc_removePerFrameHandler;
            };
        }, 0, [_missile, _target]] call cba_fnc_addPerFrameHandler;

        [{
            params ["_target", "", "_missile"];
            (isNull _missile) || {isNull _target} || {!alive _target}
        }, {
            params ["_target", "_laser"];

            deleteVehicle _laser;
            if ((isNull _target) || (!alive _target)) then {
                [parseText format ["<t align = 'center' color = '#00CC00'>TARGET DESTROYED - %1</t>", getText (configFile >> 'CfgVehicles' >> typeOf _target >> 'displayName')], [0.25, 1, 0.5, 0.05], [1, 1], 5] spawn BIS_fnc_textTiles;
            } else {
                [parseText format ["<t align = 'center' color = '#00CC00'>TARGET STILL ACTIVE - %1</t>", getText (configFile >> 'CfgVehicles' >> typeOf _target >> 'displayName')], [0.25, 1, 0.5, 0.05], [1, 1], 5] spawn BIS_fnc_textTiles;
                _target setVariable ["USAF_AGM_FIRED_AT_TARGET", false, true];
            };
        }, [_target, _laser, _missile]] call cba_fnc_waitUntilAndExecute;        
    }, [_plane, _target, _laser, _weapon], 4] call cba_fnc_waitAndExecute;
} else {
    [parseText format ["<t align = 'center' color = '#FF0000'>AGM-88 MISSILES DEPLETED</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 5] spawn BIS_fnc_textTiles;
};
