#include "script_component.hpp"

if (hasInterface) exitWith {
    [{
        if (cameraView == "EXTERNAL" && vehicle player == player && isNull (getConnectedUAV player)) then {
            player switchCamera "INTERNAL";
        };
    }, 0, []] call CBA_fnc_addPerFrameHandler;
};
