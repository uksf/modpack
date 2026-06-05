#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Start the client STT pipeline in the extension. Stands up the named-pipe
        server that consumes ACRE-captured direct speech and the callback pump
        that returns transcripts. Client-only; idempotent in the extension.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_npc_fnc_sttStart
*/

"uksf_x64" callExtension ["sttStart", []];
