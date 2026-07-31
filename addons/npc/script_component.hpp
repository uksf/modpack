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

// Deconfliction between adjacent NPCs. The gate picks the NPC nearest the crosshair, and
// holds it until a rival is clearly closer and stays so for a run of frames. Without the
// hold, two NPCs a step apart would flip the target as the player's aim wanders.
#define GATE_SWITCH_MARGIN 0.004
#define GATE_SWITCH_FRAMES 8


// How long an NPC keeps watching the last player who spoke to them, refreshed per
// utterance. Long enough to hold eye contact through a slow turn, short enough that
// they go back to idle once the conversation is plainly over.
#define WATCH_HOLD 10

// Streamed PCM is 24 kHz mono; used to turn fed samples into a playback duration.
#define STREAM_RATE 24000

// Mirrors STREAM_PREBUFFER_MS in extension/src/audio.rs: the extension holds a streamed
// clip until this much is buffered, so the mouth must not start before it.
#define SPEECH_PREBUFFER 0.2

// Fillers mask brain latency, but one before every reply is a tell in itself. A normal
// conversational gap is about a fifth of a second (Stivers et al. 2009) and silence starts
// to read as trouble at about one second (Jefferson's standard maximum silence), so a turn
// answering in the usual two seconds is already past both and needs no help. The wait is
// set past the typical answer instead, and only a turn slower than that gets covered.
// The rest fire early on purpose: a guard who sometimes grunts before he speaks and
// sometimes does not is what stops the noises reading as a mechanism.
// The model is: player talks -> a few seconds of silence (maybe one filler) -> NPC talks.
// A normal turn answers in about two seconds, so nothing fires below FILLER_DELAY. Past
// it, each wait-point rolls a small chance, re-rolled as the wait grows: most turns get
// no noise at all, a long wait accumulates chances instead of guaranteeing one.
#define FILLER_DELAY 3.5
#define FILLER_CHANCE 0.3

// Inside this window a fired filler uses the short noise class (the reply may still be
// close); past it the wait is real and earns the long class.
#define FILLER_SHORT_WINDOW 5

// A cold model or a slow route can leave a player waiting many seconds, and one grunt at
// the front of that does not cover it. Keep filling at uneven intervals, but stop well
// short of a guard who mutters forever at someone the brain has plainly failed to answer.
//
// Gap length is taken from how long a real filler promises the listener to wait: about a
// second after "uh" and about four after "um" (Clark & Fox Tree 2002). Refilling every
// second or two sounds like a man perpetually about to speak, so the gap sits at the
// longer end and varies.
#define FILLER_GAP_MIN 2.6
#define FILLER_GAP_SPREAD 3.0
#define FILLER_MAX_PER_TURN 4
