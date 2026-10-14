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

private _startedAt = diag_tickTime;
profileNamespace setVariable [GVAR(key), [GVAR(dataNamespace)] call CBA_fnc_serializeNamespace];
private _serialisedAt = diag_tickTime;
saveProfileNamespace;
INFO_2("Profile save: serialise %1 ms, write %2 ms",round ((_serialisedAt - _startedAt) * 1000),round ((diag_tickTime - _serialisedAt) * 1000));
[_partial] call FUNC(saveDataApi)
