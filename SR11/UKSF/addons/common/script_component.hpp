#define COMPONENT main
#define COMPONENT_BEAUTIFIED Main
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_COMMON
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_COMMON
    #define DEBUG_SETTINGS DEBUG_SETTINGS_COMMON
#endif

#include "\u\uksf\addons\main\script_macros.hpp"

#define VERSION_CONFIG_COMMON VERSION_CONFIG;\
    versionDesc = "UKSF Mods";\
    versionAct = QUOTE(call COMPILE_FILE(init_versionTooltip))
