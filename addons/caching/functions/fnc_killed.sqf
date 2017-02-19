/*
    Author:
        Tim Beswick

    Description:
        Handles killed unit

    Parameters:
        0: Killed unit <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_unit"];

if (group _unit in GVAR(groups) && {leader _unit isEqualTo _unit} && {count units group _unit >= 2}) then {
    [{
        !((leader (_this select 0)) isEqualTo (_this select 1))
    },{
        _newLeader = leader (_this select 0);
        [_newLeader] call FUNC(uncache);
        [_newLeader] call FUNC(addEventhandler);
    },[group _unit,_unit]] call CBA_fnc_waitUntilAndExecute;
};
