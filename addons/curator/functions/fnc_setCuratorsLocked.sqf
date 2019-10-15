#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets curators locked state

    Parameter(s):
        0: Locked <BOOL>

    Return Value:
        None
*/

params ["_locked"];

if (!isServer) exitWith {
    [QGVAR(setCuratorsLocked), _this] call CBA_fnc_serverEvent;
};

[QGVAR(curatorsLocked), _locked, 0, "server", false] call CBA_settings_fnc_set;
