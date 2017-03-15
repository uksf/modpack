/*
    Author:
        Tim Beswick

    Description:
        Respawn EH for player

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

if (local player) then {
    private _names = missionNamespace getVariable [QGVAR(curatorNames), ["","","","",""]];
    private _index = _names find (name player);
    if (_index > -1) then {
        [[_index, player], {
            (_this select 1) assignCurator (GVAR(curatorObjects) select (_this select 0));
        }] remoteExecCall ["bis_fnc_call", 2, false];
    };
};
