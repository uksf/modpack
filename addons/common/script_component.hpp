#define COMPONENT common
#define COMPONENT_BEAUTIFIED Common
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#define VERSION_CONFIG_COMMON VERSION_CONFIG; \
    versionDesc = "UKSF Mods"; \
    versionAct = QUOTE(call COMPILE_FILE(init_versionTooltip))

#define DISTANCE_MIN 1000
#define DISTANCE_MULTIPLIER 200
#define VEHICLE_MULTIPLIER 2.5

#define NVG(UNIT,NVG) class UNIT { \
    class GVAR(nvg) { \
        init = QUOTE([ARR_2(_this select 0,QUOTE(QUOTE(NVG)))] call FUNC(addNVG)); \
    }; \
}

#define NONVG(UNIT) class UNIT { \
    class GVAR(nvg) { \
        init = QUOTE([_this select 0] call FUNC(removeNVG)); \
    }; \
}
