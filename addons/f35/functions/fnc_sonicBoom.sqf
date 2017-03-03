/*
    Author:
        Tim Beswick, Lethal, Gnat, USAF Team

    Description:
        Sonic boom effects

    Parameters:
        0: Plane <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_plane"];

GVAR(barrierBroken) = false;
GVAR(sonicHandler) = [{
    params ["_args", "_idPFH"];
    _args params ["_plane", "_lastSpeed"];

    if (!alive _plane) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
    };

    _nowspeed = speed _plane;
    if (_nowspeed >= 1230 && {_nowspeed <= 1240} && {_lastSpeed < _nowspeed} && {!GVAR(barrierBroken)}) then {
        GVAR(barrierBroken) = true;
        _emitter = "#particlesource" createVehicle [0, 0, 0];
        _emitter setPos (position _plane);
        _emitter setParticleRandom [0.05, [2, 2, 2], [5, 5, 5], 0, 0.5, [0.1, 0.1, 0.1, 0.5], 0, 0];
        _emitter setDropInterval 0.05;
        [{
            params ["_args", "_idPFH"];
            _args params ["_plane", "_emitter", "_i"];

            if (_i >= 100) exitWith {
                [_idPFH] call cba_fnc_removePerFrameHandler;
                [{
                    deleteVehicle (_this select 0);
                    GVAR(barrierBroken) = false;
                }, [_emitter], 1] call cba_fnc_waitAndExecute;
            };
            _emitter setPos (position _plane);
            _emitter setParticleRandom [0.4, [10 * (_i / 100), 10 * (_i / 100), 10 * (_i / 100)], [10 * (_i / 100), 10 * (_i / 100), 10 * (_i / 100)], 0, 0.3, [0.1, 0.15, 0.3, 0.5], 0, 0];
            _emitter setParticleParams [[QPATHTOF(data\Universal.p3d), 16, 12, 1], "", "Billboard", 1, 0.1, [0, (-12 * (_i / 100)+8), -0.5], (velocity _plane), 1, 1.2745, 1, 0.001, [20 * (_i / 100)], [[1, 1, 1, 0], [1, 1, 1, 0.1 * (_i / 100)], [1, 1, 1, 0]], [0], 0, 0, "", "", _plane];
            if (_i isEqualTo 70) then {
                INFO_1("Sound barrier broken. Called on: %1", owner player);
                [_plane, [QGVAR(sonicBoom), 10000]] remoteExecCall ["say3D", 0];
            };
            _args set [2, _i + 1];
        }, 0.02, [_plane, _emitter, 1]] call cba_fnc_addPerFrameHandler;     
    };    
    _args set [1, speed _plane];
}, 0.5, [_plane, speed _plane]] call cba_fnc_addPerFrameHandler;
