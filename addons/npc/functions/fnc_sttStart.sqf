#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Start the client STT pipeline in the extension and tell ACRE to serve
        captured direct speech. Client-only; both operations are idempotent.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_npc_fnc_sttStart
*/

"uksf" callExtension ["sttStart", []];
[true] call acre_sys_core_fnc_setMicCaptureGate;
