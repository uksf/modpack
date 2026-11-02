#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Unassigns given curator
        If unit is given, unassigned event is called where that unit is local
        If player is given, also frees that player's slot by name and unassigns any curator they hold,
        so a player whose curator logic was lost or deleted can still be logged out

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

private _index = [-1, GVAR(curatorObjects) find _curator] select (!isNull _curator);
if (!isNull _player) then {
    if (_index == -1) then {
        _index = GVAR(curatorPlayers) find (name _player);
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
    };
    GVAR(curatorPlayers) set [_index, ""];
    publicVariable QGVAR(curatorObjects);
    publicVariable QGVAR(curatorPlayers);
};

if !(isNull _unit) then {
    TRACE_1("",_unit);
    [{[QGVAR(curatorUnassigned), [_this], _this] call CBA_fnc_targetEvent}, _unit, 0.1] call CBA_fnc_waitAndExecute;
};
