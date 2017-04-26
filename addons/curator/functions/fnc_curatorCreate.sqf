/*
    Author:
        Tim Beswick

    Description:
        Creates a new curator

    Parameter(s):
        0: Curator player <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_player"];

if (isNull GVAR(curatorGroup)) then {
    GVAR(curatorGroup) = creategroup sideLogic;
};
private _curator = GVAR(curatorGroup) createUnit ["ModuleCuratorLocal", [0,0,0], [], 0, "NONE"];
[QGVAR(curatorInit), [_curator, [], true], _player] call CBA_fnc_targetEvent;
GVAR(curatorObjects) pushBack _curator;
publicVariable QGVAR(curatorObjects);
[QEGVAR(common,addObjectsToCurators), [[_curator]]] call CBA_fnc_serverEvent;
