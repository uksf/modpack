#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Stop the client STT callback pump and tell ACRE to stop serving captured
        direct speech.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_npc_fnc_sttStop
*/

[false] call acre_sys_core_fnc_setMicCaptureGate;
"uksf" callExtension ["sttStop", []];
