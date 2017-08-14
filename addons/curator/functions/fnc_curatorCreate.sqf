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
#include "script_component.hpp"

if (isNull GVAR(curatorGroup)) then {
    GVAR(curatorGroup) = creategroup sideLogic;
};
private _curator = (GVAR(curatorGroup) createUnit ["ModuleCurator_F", [0,0,0], [], 0, "NONE"]);
GVAR(curatorObjects) pushBack _curator;
GVAR(curatorPlayers) pushBack "";
publicVariable QGVAR(curatorObjects);
publicVariable QGVAR(curatorPlayers);
