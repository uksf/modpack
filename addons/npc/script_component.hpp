#define COMPONENT npc
#define COMPONENT_BEAUTIFIED NPC
#include "\u\uksf\addons\main\script_mod.hpp"

#define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#include "\u\uksf\addons\main\script_macros.hpp"

// A guarded source carries exactly three ordered facts. The slot number is the disclosure
// order and the prerequisite chain; there is no other gate for a mission maker to set.
#define GUARDED_FACT_COUNT 3

// The whole vocabulary the guarded-state command may use. The API owns these values, so a
// payload carrying anything else is not a guarded state this build can render and is
// dropped rather than drawn. Fact fields carry ids only, never text.
#define GUARDED_FACT_IDS ["g1", "g2", "g3"]
#define GUARDED_BANDS ["closed", "guarded", "engaged", "cooperative"]
#define GUARDED_MOODS ["neutral", "angry", "afraid", "sad", "happy"]

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

#define EMOTE_MAX 48
#define HINT_TEXT_MAX 120
#define DEBUG_TEXT_MAX 240
#define EMOTE_HEIGHT 2.1

#define STREAM_RATE 24000
#define SPEECH_PREBUFFER 0.2

#define CLIP_CHUNKS_MAX 256
#define STREAM_STALE 30
