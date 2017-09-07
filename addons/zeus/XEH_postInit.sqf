#include "script_component.hpp"

if (hasInterface && {isMultiplayer}) then {
    [{
        player setVariable [QGVAR(fps), floor diag_fps, true];
    }, 1, []] call CBA_fnc_addPerFrameHandler;
};

[{
    if (MULTIPLAYER_ADMIN_OR_WHITELISTED && {!(isNull (findDisplay 312))}) then {
        {
            private _distance = (ATLToASL (positionCameraToWorld [0,0,0])) distance _x;
            if (_distance < 500) then {
                private _fps = _x getVariable [QGVAR(fps), 0];
                private _colour = [1,1,1,0.7];
                private _size = 0.03;
                if (_fps < 20) then {
                    _colour = [1,0,0,0.7];
                    _size = 0.05;
                };
                drawIcon3D ["", _colour, ASLToAGL getPosASL _x, 1, 2, 0, format ["FPS: %1", _fps], 0.1, _size, "PuristaMedium", "center"];
            };
            false
        } count allPlayers;
    };
}, 0, []] call CBA_fnc_addPerFrameHandler;
