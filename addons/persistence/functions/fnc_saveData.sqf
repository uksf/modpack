#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Saves data to namespace

    Parameter(s):
        0: Partial save <BOOL> (default: false)

    Return Value:
        Delivery sequence number of the API save, 0 when nothing was sent <NUMBER>

    Example:
        [false] call uksf_persistence_fnc_saveData
*/
params [["_partial", false, [false]]];

if (!GVAR(dataSaved)) exitWith {0};

profileNamespace setVariable [GVAR(key), [GVAR(dataNamespace)] call CBA_fnc_serializeNamespace];
saveProfileNamespace;
LOG("Saved data");
[_partial] call FUNC(saveDataApi)
