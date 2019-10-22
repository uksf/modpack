#define COMPONENT mission
#define COMPONENT_BEAUTIFIED Mission
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#define CONSPICUITY_DEFAULT_WHITELIST ["Binocular"]
#define CONSPICUITY_SET(STATE) [_player, "setCaptive", QGVAR(conspicuous), !STATE] call ace_common_fnc_statusEffect_set
#define CONSPICUITY_CHECK_GEAR(CHECK) \
if (CHECK != "" && {({_x == CHECK} count GVAR(conspicuityGearWhitelist)) == 0}) exitWith { \
    CONSPICUITY_SET(true); \
}

#define INVERSE_CHANCE(chance) (random 100) < (100 - chance)

#define HIT_MAX_SHOOTER_SPEED 30
#define HIT_MAX_DISTANCE_TO_SHOOTER 1000

#define SUPPORT_CHANCE 25
#define SUPPORT_MIN_SUPPRESSED_KNOWS_ABOUT 2
#define SUPPORT_DISTANCE_TO_RETRY 10
#define SUPPORT_CONDITION_BASE private _group = group _x; \
    ((side _x) isEqualTo (side _unit)) && \
    {_group != group _unit && \
    {_x isEqualTo (leader _group) && \
    {_x getVariable [QGVAR(hasSupportRadio), true] && \
    {!(_group getVariable [QGVAR(supportTasked), false]) && \
    {!((behaviour _unit) isEqualTo "COMBAT")}}}}}

#define SUPPORT_CONDITION_PROXIMITY ((side _x) isEqualTo (side _unit)) && \
    {_x getVariable [QGVAR(hasSupportRadio), true]}

#define ARTILLERY_SUPPORT_DISTANCE_TO_AVOID 125
#define ARTILLERY_SUPPORT_BASE_DISTANCE 100
#define ARTILLERY_SUPPORT_BASE_REPORT_RANDOMNESS 25
#define ARTILLERY_FIRE_MISSION_BASE_DELAY 30
