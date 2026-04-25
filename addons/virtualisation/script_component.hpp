#define COMPONENT virtualisation
#define COMPONENT_BEAUTIFIED Virtualisation
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#define AI_FEATURES ["AIMINGERROR", "ANIM", "AUTOCOMBAT", "AUTOTARGET", "CHECKVISIBLE", "COVER", "FSM", "LIGHTS", "MINEDETECTION", "MOVE", "NVG", "PATH", "RADIOPROTOCOL", "SUPPRESSION", "TARGET", "TEAMSWITCH", "WEAPONAIM"]

#define SIM_INTERVAL 30
#define SIM_CHUNK_COUNT 10
#define INFANTRY_BASE_MS 2.5
#define VEHICLE_CRUISE_FACTOR 0.6
#define SPEED_FLOOR_MS 0.5
#define SPEED_CEIL_MS 30
