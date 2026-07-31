#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Release the client STT callback pump in the extension. Best-effort; the
        pipe server is process-lived.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_npc_fnc_sttStop
*/

"uksf" callExtension ["sttStop", []];
