#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles a player's request for redeploy data on first respawn

    Parameter(s):
        0: Player <OBJECT>

    Return Value:
        None

    Example:
        [_player] call uksf_persistence_fnc_requestRedeployData
*/
params ["_player"];

private _uid = getPlayerUID _player;
private _hasRedeployed = [GVAR(hashHasRedeployed), _uid] call CBA_fnc_hashGet;
if (_hasRedeployed) exitWith {};

[GVAR(hashHasRedeployed), _uid, true] call CBA_fnc_hashSet;
private _data = GVAR(dataNamespace) getVariable [_uid, []];
TRACE_1("Sending player redeploy data",_data);
if (count _data > 0) then {
    [QGVAR(receiveRedeployData), _data, _player] call CBA_fnc_targetEvent;
};
