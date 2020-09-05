#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Create Infantry group

    Parameters:
        0: Spawn position module <OBJECT>
        1: Callback once spawning complete <CODE> (Optional)
        2: Callback arguments <ARRAY> (Optional)

    Return value:
        Nothing
*/
params ["_spawnPosition", ["_callback", {}, [{}]], ["_callbackArgs", [], [[]]]];

if !(alive _spawnPosition) exitWith {};

private _unitCount = ceil ((random 4) + 6);
[_spawnPosition getPos [10, random 360], 0, _unitCount, EAST, EGVAR(gear,gearSoldier), [], {}, {
    params ["_callback", "_callbackArgs", "_group"];

    _callbackArgs pushBack _group;
    _callbackArgs call _callback;
}, [_callback, _callbackArgs]] call EFUNC(common,spawnGroup);
