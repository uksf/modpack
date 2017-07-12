/*
    Author:
        Tim Beswick, USAF Team

    Description:
        Ejection seat

    Parameters:
        0: Plane <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

#define CANOPY_BOOST 15
#define SEAT_BOOST 35

params ["_plane"];

if ((!isEngineOn _plane)) exitWith {};
if (_plane animationPhase "eject_switch" > 0.01) exitWith {};
_plane animate ["eject_switch", 1];

_plane animate ["canopy_hide", 1];
_plane animate ["ejection_seat_hide", 1];
_canopy = "USAF_F35A_canopy" createVehicle [0, 0, 1000];
_canopy attachTo [_plane, [0.0, 0.-0.72, 0.6], "actionarea"];
_seat = "USAF_F35A_Ejection_seat" createVehicle [0, 0, 1010];
_seat attachTo [_plane, [-0.5, 0.12, 0.35], "actionarea"];
player allowDamage false;

[{
    params ["_plane", "_canopy", "_seat"];
    
    // First stage - Jettison Canopy
    _pitchBank = _plane call BIS_fnc_getPitchBank;
    _pos = _plane modelToWorld (_plane selectionPosition "eject_pos");
    _dirPos = _plane modelToWorld (_plane selectionPosition "eject_canopy_dir");
    _dirPos = [(_dirPos select 0) - (_pos select 0), (_dirPos select 1) - (_pos select 1), (_dirPos select 2) - (_pos select 2)];
    _div = abs (_dirPos select 0) + abs (_dirPos select 1) + abs (_dirPos select 2);
    _ejectVelocity = [(_dirPos select 0) / _div * CANOPY_BOOST, (_dirPos select 1) / _div * CANOPY_BOOST, (_dirPos select 2) / _div * CANOPY_BOOST];
    _planeVelocity = velocity _plane;
    _dirPos = _plane modelToWorld (_plane selectionPosition "eject_dir");
    detach _canopy;
    _canopy setPos _dirPos;
    [_canopy, (_pitchBank select 0), (_pitchBank select 1)] call BIS_fnc_setPitchBank;
    _canopy setVelocity [(_ejectVelocity select 0) + (_planeVelocity select 0), (_ejectVelocity select 1) + (_planeVelocity select 1), (_ejectVelocity select 2) + (_planeVelocity select 2)];

    [{
        params ["_plane", "_canopy", "_seat"];

        // Second stage - Move pilot toi ejection seat and jettison
        _plane setVelocity [(velocity _plane select 0) + 1, (velocity _plane select 1) * 1.0, (velocity _plane select 2) * 1.0];
        moveOut player;
        player moveInDriver _seat;
        _seat lock 2;
        _pitchBank = _plane call BIS_fnc_getPitchBank;
        _pos = _plane modelToWorld (_plane selectionPosition "eject_pos");
        _dirPos = _plane modelToWorld (_plane selectionPosition "eject_dir");
        _dirPos = [(_dirPos select 0) - (_pos select 0), (_dirPos select 1) - (_pos select 1), (_dirPos select 2) - (_pos select 2)];
        _div = abs (_dirPos select 0) + abs (_dirPos select 1) + abs (_dirPos select 2);
        _ejectVelocity = [(_dirPos select 0) / _div * SEAT_BOOST, (_dirPos select 1) / _div * SEAT_BOOST, (_dirPos select 2) / _div * SEAT_BOOST];
        _planeVelocity = velocity _plane;
        _dirPos = _plane modelToWorld (_plane selectionPosition "eject_dir");
        [_plane, _seat] call FUNC(ejectionFX);
        detach _seat;
        _seat setPos _dirPos;
        [_seat, (_pitchBank select 0), (_pitchBank select 1)] call BIS_fnc_setPitchBank;
        _seat setVelocity [(_ejectVelocity select 0) + (_planeVelocity select 0), (_ejectVelocity select 1) + (_planeVelocity select 1), (_ejectVelocity select 2) + (_planeVelocity select 2)];

        [{
            params ["_plane", "_canopy", "_seat"];
            
            // Third stage - Deploy chute
            _seat lock 0;
            _pitchBank = _seat call BIS_fnc_getPitchBank;
            _seat setVelocity [1, 1, 1];
            moveOut player;
            _parachute = "Steerable_Parachute_F" createVehicle getPos player;
            _parachute setDir (getDir player);
            _parachute setPos  (getPos player);
            [_parachute, (_pitchBank select 0), (_pitchBank select 1)] call BIS_fnc_setPitchBank;
            player moveInDriver _parachute;
            _plane setFuel 0;
            _seat lock 2;
            _plane lock 2;

            [{
                params ["_canopy", "_seat"];
                _seat setDamage 1;
                _canopy setDamage 1;
                player allowDamage true;
            }, [_canopy, _seat], 2] call cba_fnc_waitAndExecute;
        }, [_plane, _canopy, _seat], 3] call cba_fnc_waitAndExecute;
    }, [_plane, _canopy, _seat], 0.5] call cba_fnc_waitAndExecute;
}, [_plane, _canopy, _seat], 0.1] call cba_fnc_waitAndExecute;
