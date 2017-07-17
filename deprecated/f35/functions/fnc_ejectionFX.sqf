/*
    Author:
        Tim Beswick, John_Spartan, Peral, USAF Team

    Description:
        Ejection seat effects

    Parameters:
        0: Plane <OBJECT>
        0: Seat <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_plane", "_seat"];

if (local _plane) then {
    [_seat, [QGVAR(ejection), 1000]] remoteExecCall ["say3D", 0];
};

_light = "#lightpoint" createVehicle getPos _seat;
_light  setLightBrightness 0.3;
_light  setLightAmbient [0.8, 0.6, 0.2];
_light  setLightColor [1, 0.5, 0.2];
_light  lightAttachObject [_seat, [0,0,0]];

[{
    params ["_plane", "_seat", "_light"];

    deleteVehicle _light;

    _smoke = "#particlesource" createVehicle (getPos _plane);
    _smoke setParticleClass "MLRSFired1L";
    _smoke attachTo [_plane, [0,0,0], "actionarea"];
    [{
        params ["_smoke"];
        deleteVehicle _smoke;
    }, [_smoke], 0.2] call cba_fnc_waitAndExecute;

    _smokeTrail = "#particlesource" createVehicle (getPos _seat);
    _smokeTrail setParticleClass "MissileEffects1";
    _smokeTrail attachTo [_seat, [0,0,0], "FX_pos"];    
    [{
        params ["_smokeTrail"];
        deleteVehicle _smokeTrail;
    }, [_smokeTrail], 0.5] call cba_fnc_waitAndExecute;
}, [_plane, _seat, _light], 0.01] call cba_fnc_waitAndExecute;
