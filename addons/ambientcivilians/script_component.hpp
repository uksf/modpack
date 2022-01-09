#define COMPONENT ambientcivilians
#define COMPONENT_BEAUTIFIED Ambient Civilians
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DEBUG_MODE_ANALYSIS
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#ifdef DEBUG_MODE_FULL
#define INVERSE_CHANCE(chance) false
#else
#define INVERSE_CHANCE(chance) (random 100) < (100 - chance)
#endif

#ifdef DEBUG_MODE_ANALYSIS
#define DYNAMIC_PATROL_RETRY_DELAY 0
#else
#define DYNAMIC_PATROL_RETRY_DELAY 5
#endif
