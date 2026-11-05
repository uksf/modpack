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

    Example:
        [_locked] call uksf_curator_fnc_setCuratorsLocked
*/
if (isRemoteExecuted && {isNil "_uksf_curatorValidated"}) exitWith {};

params ["_locked"];

if (!isServer) exitWith {
    [player, _locked] remoteExecCall [QFUNC(requestLock), 2];
};

[QGVAR(curatorsLocked), _locked, 0, "server", false] call CBA_settings_fnc_set;
