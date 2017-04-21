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
#include "script_component.hpp"

params ["_locked"];

GVAR(curatorsLocked) = _locked;
publicVariable QGVAR(curatorsLocked);
