#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates a new curator

    Parameter(s):
        None

    Return Value:
        None
*/

private _curator = (createGroup [sideLogic, true]) createUnit ["ModuleCurator_F", [0,0,0], [], 0, "NONE"];
_curator setVariable ["BIS_fnc_initModules_disableAutoActivation", false, true];
removeAllCuratorAddons _curator;
GVAR(curatorObjects) pushBack _curator;
GVAR(curatorPlayers) pushBack "";
publicVariable QGVAR(curatorObjects);
publicVariable QGVAR(curatorPlayers);
