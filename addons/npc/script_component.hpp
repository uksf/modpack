#define COMPONENT npc
#define COMPONENT_BEAUTIFIED NPC
#include "\u\uksf\addons\main\script_mod.hpp"

#define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#include "\u\uksf\addons\main\script_macros.hpp"

// A guarded source carries exactly three ordered facts. The slot number is the disclosure
// order and the prerequisite chain; there is no other gate for a mission maker to set.
#define GUARDED_FACT_COUNT 3

// Slot numbers are the fact ids. g1/g2/g3 are aliases from older registrations.
#define GUARDED_FACT_IDS ["1", "2", "3", "g1", "g2", "g3"]
#define GUARDED_BANDS ["closed", "guarded", "engaged", "cooperative"]
#define GUARDED_MOODS ["neutral", "angry", "afraid", "sad", "happy"]

#define GUARDED_STATE_FIELDS 13
#define DEBUG_STATE_FIELDS 14

#define CONSOLE_CARD_COUNT 3
#define IDD_CONSOLE_INSPECTOR 81300
#define IDC_CONSOLE_CARDS 81301
#define IDC_CONSOLE_TITLE 81302
#define IDC_CONSOLE_PICKER 81303
#define IDC_CONSOLE_STATE_BODY 81304
#define IDC_CONSOLE_RESET 81305
#define IDC_CONSOLE_CANCEL 81306
#define IDC_CONSOLE_MUTE 81307
#define IDC_CONSOLE_UNMUTE 81308
#define IDC_CONSOLE_EXCHANGE_BODY 81309
#define IDC_CONSOLE_TRANSCRIPT_BODY 81310
#define IDC_CONSOLE_PROFILE 81311

#define EMOTE_MAX 48
#define HINT_TEXT_MAX 120
#define DEBUG_TEXT_MAX 240

// A room flush waits for the NPC turn in flight, but never longer than this.
#define TURN_HOLD_MAX_MS 60000

#define EMOTE_HEIGHT 2.1

#define STREAM_RATE 24000

#define CLIP_CHUNKS_MAX 256
