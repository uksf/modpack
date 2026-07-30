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

// Fillers mask brain latency. A normal turn now answers in about two seconds, so the
// filler waits past that: it covers a slow turn and stays silent on a fast one, instead
// of prefacing every single reply with the same handful of noises.
#define FILLER_DELAY 2.2
