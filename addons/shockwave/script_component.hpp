#define COMPONENT shockwave
#define COMPONENT_BEAUTIFIED Shockwave
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#ifdef DISABLE_COMPILE_CACHE
    #undef SHOCKWAVEPREP
    #define SHOCKWAVEPREP(fncName) FUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(effects\fncName.sqf)
#else
    #undef SHOCKWAVEPREP
    #define SHOCKWAVEPREP(fncName) [QPATHTOF(effects\fncName.sqf), QFUNC(fncName)] call CBA_fnc_compileFunction
#endif
