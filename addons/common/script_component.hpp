#define COMPONENT common
#define COMPONENT_BEAUTIFIED Common
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#define VERSION_CONFIG_COMMON VERSION_CONFIG;\
    versionDesc = "UKSF Mods";\
    versionAct = QUOTE(call COMPILE_FILE(init_versionTooltip))

#define WHITELIST ["76561198041153310", "76561198134463722", "76561198010664527", "76561198012572919"]

#define DISTANCE_MIN 1000
#define DISTANCE_MULTIPLIER 200
#define VEHICLE_MULTIPLIER 2.5

#define ADDON_NVG DOUBLES(ADDON,nvg)
#define NVG(UNIT,NVG) class UNIT { \
    class ADDON_NVG { \
        init = QUOTE([ARR_2(_this select 0,QUOTE(QUOTE(NVG)))] call FUNC(addNVG)); \
    }; \
}
