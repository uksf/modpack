#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Start the client STT pipeline in the extension. The extension connects
        to the ACRE TeamSpeak plugin pipe; whisper runs on a worker thread, not
        the pipe reader. ACRE captures speech only while uksf_npc_fnc_sttSync
        holds the mic gate open. Client-only and idempotent.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_npc_fnc_sttStart
*/

"uksf" callExtension ["sttStart", []];
