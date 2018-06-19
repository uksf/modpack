/*
    Author:
        Tim Beswick

    Description:
        Handles entity killed

    Parameter(s):
        EntityKilled params

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_unit", "_killer", "_instigator", "_useEffects"];

TRACE_4("EntityKilled",_unit,_killer,_instigator,_useEffects);

if (!(isPlayer _unit)) exitWith {};

private _uid = getPlayerUID _unit;
private _firstKilled = [GVAR(hashFirstKilled), _uid] call CBA_fnc_hashGet;
if (_firstKilled) then {
    [GVAR(hashFirstKilled), _uid, false] call CBA_fnc_hashSet;
    private _data = GVAR(dataNamespace) getVariable [_uid, []];
    //TRACE_1("Player killed",_data);
    if (count _data > 0) then {
        [QGVAR(firstKilled), _data, _unit] call CBA_fnc_targetEvent;
    };
};
