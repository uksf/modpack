#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Unassigns given curator
        If unit is given, unassigned event is called where that unit is local

    Parameter(s):
        0: Curator <OBJECT>
        1: Unit <OBJECT> (Optional)

    Return Value:
        None
*/
params ["_curator", ["_unit", objNull]];

private _index = GVAR(curatorObjects) find _curator;
if (_index != -1) then {
    TRACE_2("",_curator,_index);
    unassignCurator (GVAR(curatorObjects) select _index);
    GVAR(curatorPlayers) set [_index, ""];
    publicVariable QGVAR(curatorObjects);
    publicVariable QGVAR(curatorPlayers);
};

if !(isNull _unit) then {
    TRACE_1("",_unit);
    [{[QGVAR(curatorUnassigned), [_this], _this] call CBA_fnc_targetEvent}, _unit, 0.1] call CBA_fnc_waitAndExecute;
};
