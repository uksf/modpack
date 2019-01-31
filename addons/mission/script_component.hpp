#define COMPONENT mission
#define COMPONENT_BEAUTIFIED Mission
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#define CONDITION_SUPPORT ((side _x) isEqualTo (side _unit)) && \
    {group _x != group _unit} && \
    {_x isEqualTo leader group _x} && \
    {_x getVariable [QGVAR(hasRadio), true]} && \
    {!((group _x) getVariable [QGVAR(tasked), false])} && \
    {!((behaviour leader (group _x)) isEqualTo "COMBAT")}

#define CONDITION_PROXIMITY ((faction _x) isEqualTo (faction _unit)) && \
    {_x getVariable [QGVAR(hasRadio), true]}

#define DEFAULT_WHITELISTED_GEAR ["Binocular"]

#define SET_CONSPICUOUS(STATE) [_player, "setCaptive", QGVAR(conspicuous), STATE] call ace_common_fnc_statusEffect_set

#define CHECK_GEAR_CONSPICUITY(CHECK) \
if (CHECK != "" && {!(CHECK in GVAR(conspicuityGearWhitelist))}) exitWith { \
    SET_CONSPICUOUS(true); \
}
