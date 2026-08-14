#define COMPONENT npc
#define COMPONENT_BEAUTIFIED NPC
#include "\u\uksf\addons\main\script_mod.hpp"

#define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#include "\u\uksf\addons\main\script_macros.hpp"

// Upper bound for the per-frame nearEntities scan; the real gate is each NPC's gateRange.
#define GATE_SCAN_RADIUS 25

// How far a spoken utterance carries. Everyone talkable inside this hears it regardless
// of facing, and the API decides who answers — the one named, or the one looked at.
#define HEARING_RADIUS 15

// Default addressing gate, overridable per NPC. Conversation distance is further than
// arm's reach: a player standing off and looking at an NPC is plainly talking to them.
#define GATE_RANGE 10
#define GATE_FOV 100

// Deconfliction between adjacent NPCs. The gate picks the NPC nearest the crosshair, and
// holds it until a rival is clearly closer and stays so for a run of frames. Without the
// hold, two NPCs a step apart would flip the target as the player's aim wanders.
#define GATE_SWITCH_MARGIN 0.004
#define GATE_SWITCH_FRAMES 8


// A guarded source carries exactly three ordered facts. The slot number is the disclosure
// order and the prerequisite chain; there is no other gate for a mission maker to set.
#define GUARDED_FACT_COUNT 3

// The whole vocabulary the guarded-state command may use. The API owns these values, so a
// payload carrying anything else is not a guarded state this build can render and is
// dropped rather than drawn. Fact fields carry ids only, never text.
#define GUARDED_FACT_IDS ["g1", "g2", "g3"]
#define GUARDED_BANDS ["closed", "guarded", "engaged", "cooperative"]
#define GUARDED_MOODS ["neutral", "angry", "afraid", "sad", "happy"]

// Fields the guarded-state command must carry before any of it is read.
#define GUARDED_STATE_FIELDS 12
#define DEBUG_STATE_FIELDS 13

#define CONSOLE_CARD_COUNT 3
#define IDD_CONSOLE_INSPECTOR 81300
#define IDC_CONSOLE_CARDS 81301
#define IDC_CONSOLE_TITLE 81302
#define IDC_CONSOLE_PICKER 81303
#define IDC_CONSOLE_DETAILS 81304
#define IDC_CONSOLE_RESET 81305
#define IDC_CONSOLE_CANCEL 81306
#define IDC_CONSOLE_MUTE 81307
#define IDC_CONSOLE_UNMUTE 81308

// Guarded feedback is diegetic: a short floating emote above the NPC, and in a test mission
// a compact state hint under it. Both are clamped server-side before fan-out, so a long
// model string cannot push the command near the extension's 64 KB limit or wallpaper the screen.
#define EMOTE_MAX 48
#define HINT_TEXT_MAX 120
#define DEBUG_TEXT_MAX 240

// How long each stays up. The emote is a beat of body language, so it clears about as fast
// as the gesture would; the hint is read, so it lingers.
#define EMOTE_HOLD 6
#define HINT_HOLD 15

// Metres above the NPC's own position, so the text floats over the head rather than the chest.
#define EMOTE_HEIGHT 2.1

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
