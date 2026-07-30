#define COMPONENT npc
#define COMPONENT_BEAUTIFIED NPC
#include "\u\uksf\addons\main\script_mod.hpp"

#define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#include "\u\uksf\addons\main\script_macros.hpp"

// Upper bound for the per-frame nearEntities scan; the real gate is each NPC's gateRange.
#define GATE_SCAN_RADIUS 25

// Default addressing gate, overridable per NPC. Conversation distance is further than
// arm's reach: a player standing off and looking at an NPC is plainly talking to them.
#define GATE_RANGE 10
#define GATE_FOV 100

// Streamed PCM is 24 kHz mono; used to turn fed samples into a playback duration.
#define STREAM_RATE 24000

// Mirrors STREAM_PREBUFFER_MS in extension/src/audio.rs: the extension holds a streamed
// clip until this much is buffered, so the mouth must not start before it.
#define SPEECH_PREBUFFER 0.2

// Fillers mask brain latency, but one before every reply is a tell in itself. Most turns
// wait past the usual answer time, so the filler only covers a turn that runs slow and the
// first audio frame cancels it. The rest fire early on purpose: a guard who sometimes
// grunts before he speaks and sometimes does not is the point, and the variance is what
// stops the same handful of noises reading as a mechanism.
#define FILLER_DELAY 2.2
#define FILLER_EARLY_CHANCE 0.35
#define FILLER_EARLY_MIN 0.8
#define FILLER_EARLY_SPREAD 0.5
