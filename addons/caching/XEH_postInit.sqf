#include "script_component.hpp"

if (!GVAR(enabled)) exitWith {
    INFO("Caching is disabled.");
};

if (isServer) then {
    [FUNC(handleCache), 15, []] call cba_fnc_addPerFrameHandler;
};