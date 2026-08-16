#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Returns the local debug state for an NPC. Does not create an entry unless
        the caller asks for one and the console is open.
*/
params ["_npcOrId", ["_create", false, [false]]];

private _npcId = if (_npcOrId isEqualType "") then {_npcOrId} else {netId _npcOrId};
private _state = GVAR(consoleStates) get _npcId;
if (!isNil "_state") exitWith {_state};
if (!_create) exitWith {createHashMap};
if !(GVAR(consoleCardsEnabled) || {!isNull (uiNamespace getVariable [QGVAR(consoleInspector), displayNull])}) exitWith {createHashMap};

_state = createHashMap;
GVAR(consoleStates) set [_npcId, _state];
_state
