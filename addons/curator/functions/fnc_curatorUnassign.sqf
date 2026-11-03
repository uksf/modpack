#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Unassigns given curator
        If unit is given, unassigned event is called where that unit is local
        If player is given, unassigns any curator they hold
        If no slot holds the given curator, the player's slot is found by name instead,
        and is freed only when its curator is held by that player or by no one
        Deleted curators are pruned first, so a stale slot cannot shift another player's slot

    Parameter(s):
        0: Curator <OBJECT>
        1: Unit <OBJECT> (Optional)
        2: Player <OBJECT> (Optional)

    Return Value:
        None

    Example:
        [_curator, _unit, _player] call uksf_curator_fnc_curatorUnassign
*/
params ["_curator", ["_unit", objNull], ["_player", objNull]];

call FUNC(pruneCurators);

private _index = [-1, GVAR(curatorObjects) find _curator] select (!isNull _curator);
if (!isNull _player) then {
    if (_index == -1) then {
        _index = GVAR(curatorPlayers) find (name _player);
    };
    if (_index != -1) then {
        private _slotHolder = getAssignedCuratorUnit (GVAR(curatorObjects) select _index);
        private _ownSlot = [_slotHolder == _player, (GVAR(curatorPlayers) select _index) == name _player] select (isNull _slotHolder);
        if (!_ownSlot) then {
            _index = -1;
        };
    };

    private _heldCurator = getAssignedCuratorLogic _player;
    if (!isNull _heldCurator) then {
        unassignCurator _heldCurator;
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
