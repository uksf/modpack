#include "script_component.hpp"

// Client-only: the audio extension and player frame data only exist on a
// player client. Nothing to start until the first clip plays (the tick is
// lazily started by fnc_playClip).
