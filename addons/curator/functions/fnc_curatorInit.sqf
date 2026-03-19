#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialises curator

    Parameter(s):
        0: Curator entity <OBJECT>

    Return Value:
        None

    Example:
        [_curator] call uksf_curator_fnc_curatorInit
*/
params ["_curator"];

_curator setVariable ["BIS_fnc_initModules_disableAutoActivation", false, true];

removeAllCuratorAddons _curator;
_curator addCuratorAddons EGVAR(common,addons);

GVAR(curatorObjects) pushBack _curator;
GVAR(curatorPlayers) pushBack "";
publicVariable QGVAR(curatorObjects);
publicVariable QGVAR(curatorPlayers);
