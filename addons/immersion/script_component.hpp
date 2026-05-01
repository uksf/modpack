#define COMPONENT immersion
#define COMPONENT_BEAUTIFIED Immersion
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#ifdef DISABLE_COMPILE_CACHE
    #define SHOCKWAVEPREP(fncName) FUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(effects\fncName.sqf)
#else
    #define SHOCKWAVEPREP(fncName) [QPATHTOF(effects\fncName.sqf), QFUNC(fncName)] call CBA_fnc_compileFunction
#endif

#define SUPPRESSION_MAX_VALUE 25
#define SUPPRESSION_BORDER 8

#define CLOSEMISS_RECOVERY_SECONDS 300
#define CLOSEMISS_DECAY_K 0.05
#define CLOSEMISS_PRE_AGE_SEC 5
#define CLOSEMISS_PLAYER_FIRING_WINDOW 10
#define CLOSEMISS_FLINCH_MIN_DEG 2
#define CLOSEMISS_FLINCH_RAND_DEG 2
#define CLOSEMISS_SHAKE_FORCE 5
#define CLOSEMISS_SHAKE_LENGTH 0.25
#define CLOSEMISS_SHAKE_FREQ 4
#define CLOSEMISS_DETECTION_BASE 1
#define CLOSEMISS_DETECTION_BIG 2
#define CLOSEMISS_BIG_HIT_THRESHOLD 24
#define CLOSEMISS_MAX_LOOKAHEAD_SEC 2
