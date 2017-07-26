#include "script_component.hpp"

if (hasInterface) then {
    [{
        if (cameraView isEqualTo "EXTERNAL" && {cameraOn isEqualTo player} && {(vehicle player) isEqualTo player}) then {
            cameraOn switchCamera "INTERNAL";
        };
    }, 0, []] call CBA_fnc_addPerFrameHandler;
};
