#include "script_component.hpp"
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
params ["_unit", "_killer", "_instigator", "_useEffects"];

TRACE_4("EntityKilled",_unit,_killer,_instigator,_useEffects);

if !(isPlayer _unit) exitWith {};

private _uid = getPlayerUID _unit;
private _hasRedployed = [GVAR(hashHasRedeployed), _uid] call CBA_fnc_hashGet;
if !(_hasRedployed) then {
    [GVAR(hashHasRedeployed), _uid, true] call CBA_fnc_hashSet;
    private _data = GVAR(dataNamespace) getVariable [_uid, []];
    TRACE_1("Sending player data",_data);
    if (count _data > 0) then {
        [QGVAR(sendRedeployData), _data, _unit] call CBA_fnc_targetEvent;
    };
};
