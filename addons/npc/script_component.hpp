#define COMPONENT npc
#define COMPONENT_BEAUTIFIED NPC
#include "\u\uksf\addons\main\script_mod.hpp"

#define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#include "\u\uksf\addons\main\script_macros.hpp"

// Upper bound for the per-frame nearEntities scan; the real gate is each NPC's gateRange.
#define GATE_SCAN_RADIUS 25

// Mirrors STREAM_PREBUFFER_MS in extension/src/audio.rs: the extension holds a streamed
// clip until this much is buffered, so the mouth must not start before it.
#define SPEECH_PREBUFFER 0.2

// Fillers mask brain latency, but firing one the instant speech ends steps on the
// player's own words. A short beat first reads as the NPC taking a moment.
#define FILLER_DELAY 1
