#define COMPONENT persistence
#define COMPONENT_BEAUTIFIED Persistence
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#define OWNER_SERVER 2

#define RESPAWN_MARKER QUOTE(respawn_west_persistence)
#define RESPAWN_NAME QUOTE(Re-deploy)

#define ANIM_STANDING QUOTE(amovpercmstpsnonwnondnon)

#define CENTRE_RADIUS 30

// Object data array field indices (see fnc_getObjectData.sqf for construction)
#define IDX_OBJ_ID              0
#define IDX_OBJ_TYPE            1
#define IDX_OBJ_POSITION        2
#define IDX_OBJ_VECTORDIRUP     3
#define IDX_OBJ_DAMAGE          4
#define IDX_OBJ_FUEL            5
#define IDX_OBJ_TURRETWEAPONS   6
#define IDX_OBJ_TURRETMAGS      7
#define IDX_OBJ_PYLONLOADOUT    8
#define IDX_OBJ_LOGISTICS       9
#define IDX_OBJ_ATTACHED        10
#define IDX_OBJ_RACKCHANNELS    11
#define IDX_OBJ_ACECARGO        12
#define IDX_OBJ_INVENTORY       13
#define IDX_OBJ_ACEFORTIFY      14
#define IDX_OBJ_ACEMEDICAL      15
#define IDX_OBJ_ACEREPAIR       16
#define IDX_OBJ_CUSTOMNAME      17
#define IDX_OBJ_FAILEDLASTLOAD  18
