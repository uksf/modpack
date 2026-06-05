#include "script_component.hpp"

// Client-only: the audio extension and player frame data only exist on a
// player client. Nothing to start until the first clip plays (the tick is
// lazily started by fnc_playClip).

if (!hasInterface) exitWith {};

// Route extension STT transcripts to the handler. The extension fires
// callback_data("uksf", "sttTranscript", "[uttId,""text""]").
addMissionEventHandler ["ExtensionCallback", {
    params ["_name", "_function", "_data"];
    if (_name isEqualTo "uksf" && {_function isEqualTo "sttTranscript"}) then {
        _data call FUNC(onTranscript);
    };
}];

// Stand up the pipe server / callback pump.
call FUNC(sttStart);
