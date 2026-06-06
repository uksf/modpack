#define COMPONENT npc
#define COMPONENT_BEAUTIFIED NPC
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#include "\u\uksf\addons\main\script_macros.hpp"
#include "data\test_clip_b64.hpp"

// Upper bound for the per-frame nearEntities scan; the real gate is each NPC's gateRange.
#define GATE_SCAN_RADIUS 25
