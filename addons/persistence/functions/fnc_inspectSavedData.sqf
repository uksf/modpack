#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Dumps persistence namespace summary to RPT and systemChat.
        Triggered from ACE self-interaction menu.

    Parameter(s):
        None

    Return Value:
        None
*/

[QGVAR(requestInspectSavedData), [player]] call CBA_fnc_serverEvent;
