#define COMPONENT npc
#define COMPONENT_BEAUTIFIED NPC
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#include "\u\uksf\addons\main\script_macros.hpp"
#include "data\test_clip_b64.hpp"

// Fixed radius for the client's per-frame talkable-NPC scan. Only a cheap upper bound
// for nearEntities — the real gate is each NPC's authored gateRange (checked in isInGate).
// Comfortably above any realistic walk-up-and-talk distance.
#define GATE_SCAN_RADIUS 25
