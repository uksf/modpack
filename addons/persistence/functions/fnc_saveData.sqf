#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Saves data to namespace

    Parameter(s):
        None

    Return Value:
        None
*/

if (GVAR(dataSaved)) then {
    profileNamespace setVariable [GVAR(key), [GVAR(dataNamespace)] call CBA_fnc_serializeNamespace];
    saveProfileNamespace;
    LOG("Saved data");
};
