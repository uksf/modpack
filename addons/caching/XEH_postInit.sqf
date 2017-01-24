#include "script_component.hpp"

if (!GVAR(enabled)) exitWith {
    INFO("Caching is disabled.");
};

if(isServer) then {
    [FUNC(handleCache), 15, []] call CBA_fnc_addPerFrameHandler;
};