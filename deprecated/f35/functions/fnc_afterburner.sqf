/* 
    Author:
        Tim Beswick, John_Spartan, Saul, USAF Team

    Description:
        Afterburner simulation function for jet engine. Initialy created for F / A-18X Black Wasp
        Adapted for usage on USAF F35, with permissions from it's original authors

    Parameters:
        0: Plane <OBJECT>

    Return value:
        Nothing
*/ 
#include "script_component.hpp"

#define MAX_MULTIPLIER 1
#define TOP_SPEED 1930
#define FUEL_LOSS_FACTOR 1500
#define TIME_FACTOR 0.1

params ["_plane"];

if (!local _plane || {!isEngineOn _plane}) exitWith {};

_plane animate ["switch_afterburner", 1];
_plane animate ["burner_fire_hide", 0];    
_plane animate ["burner_fire_high_hide", 1];
_plane animate ["afterburner_userhide", 0];
_plane animate ["afterburner_strech", 1];

GVAR(afterBurnerMultiplier) = 0.4;
GVAR(afterburnerHandler) = [{
    params ["_args", "_idPFH"];
    _args params ["_plane"];

    if (!alive _plane || {!isEngineOn _plane} || {_plane animationphase "switch_afterburner" <= 0.1}) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;    
        _plane animate ["afterburner_strech", 0];
        [{
            (_this select 0) animationphase "afterburner_strech" <= 0.1
        }, {
            params ["_plane"];
            _plane animate ["burner_fire_hide", 1];
            _plane animate ["burner_fire_high_hide", 0];
            _plane animate ["afterburner_userhide", 1];
        }, [_plane]] call cba_fnc_waitUntilAndExecute;
    };

    private _acceleration = 0.6;
    if (((getpos _plane) select 2) < 5) then {
        _acceleration = 0.2;
    };
    if (GVAR(afterBurnerMultiplier) < MAX_MULTIPLIER) then {
        GVAR(afterBurnerMultiplier) = GVAR(afterBurnerMultiplier) + 0.1 * (15 * TIME_FACTOR);
    };
    if ((speed _plane) < TOP_SPEED) then {
        _velocity = velocity _plane;
        _vectorDir = vectordir _plane;
        _plane setVelocity [
            (_velocity select 0) + (_vectorDir select 0) * ((_acceleration * GVAR(afterBurnerMultiplier) / 2) * (15 * TIME_FACTOR)),
            (_velocity select 1) + (_vectorDir select 1) * ((_acceleration * GVAR(afterBurnerMultiplier) / 2) * (15 * TIME_FACTOR)),
            (_velocity select 2) + (_vectorDir select 2) * ((_acceleration * GVAR(afterBurnerMultiplier) / 2) * (15 * TIME_FACTOR))
        ];
    };
    if (fuel _plane > 0) then {
        _plane setFuel ((fuel _plane) - ((1 / FUEL_LOSS_FACTOR) * (3 * TIME_FACTOR)));
    };
}, 0.05, [_plane]] call cba_fnc_addPerFrameHandler;
