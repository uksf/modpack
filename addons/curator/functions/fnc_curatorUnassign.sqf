#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Unassigns a curator and frees its slot
        If unit is given, unassigned event is called where that unit is local
        A player request ignores the given curator and frees only what that player owns now:
        the slot whose curator they hold, else an unheld slot reserved under their name,
        and any untracked curator they hold
        A player request whose player no longer exists does nothing
        Deleted curators are pruned first, so a stale slot cannot shift another player's slot

    Parameter(s):
        0: Curator <OBJECT>
        1: Unit <OBJECT> (Optional)
        2: Player <OBJECT> (Optional)
        3: Player request <BOOL> (Optional, default false)

    Return Value:
        None

    Example:
        [objNull, objNull, player, true] call uksf_curator_fnc_curatorUnassign
*/
params ["_curator", ["_unit", objNull], ["_player", objNull], ["_byPlayer", false]];

call FUNC(pruneCurators);

if (_byPlayer && {isNull _player}) exitWith {};

private _index = -1;
if (_byPlayer) then {
    private _heldCurator = getAssignedCuratorLogic _player;
    _index = GVAR(curatorObjects) find _heldCurator;
    if (_index == -1) then {
        _index = GVAR(curatorPlayers) find (name _player);
        if (_index != -1 && {!isNull getAssignedCuratorUnit (GVAR(curatorObjects) select _index)}) then {
            _index = -1;
        };
    };
    if (!isNull _heldCurator && {_index == -1 || {(GVAR(curatorObjects) select _index) != _heldCurator}}) then {
        unassignCurator _heldCurator;
    };
} else {
    if (!isNull _curator) then {
        _index = GVAR(curatorObjects) find _curator;
    };
};

if (_index != -1) then {
    TRACE_2("",_curator,_index);
    private _slotCurator = GVAR(curatorObjects) select _index;
    if (!isNull _slotCurator) then {
        unassignCurator _slotCurator;
        _slotCurator setVariable [QGVAR(reservation), -1];
    };
    GVAR(curatorPlayers) set [_index, ""];
    publicVariable QGVAR(curatorObjects);
    publicVariable QGVAR(curatorPlayers);
};

if !(isNull _unit) then {
    TRACE_1("",_unit);
    [{[QGVAR(curatorUnassigned), [_this], _this] call CBA_fnc_targetEvent}, _unit, 0.1] call CBA_fnc_waitAndExecute;
};
