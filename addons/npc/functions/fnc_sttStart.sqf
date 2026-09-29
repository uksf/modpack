#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Start the client STT pipeline in the extension and tell ACRE to serve
        captured direct speech. The extension connects to the ACRE TeamSpeak
        plugin pipe; whisper runs on a worker thread, not the pipe reader.
        Client-only; both operations are idempotent.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_npc_fnc_sttStart
*/

"uksf" callExtension ["sttStart", []];
[true] call acre_sys_core_fnc_setMicCaptureGate;
