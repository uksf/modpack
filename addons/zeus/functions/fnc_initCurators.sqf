/*
    Author:
        Tim Beswick

    Description:
        Initialises curator & disconnect EH

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

_group = creategroup sideLogic;

ADD_CURATOR(0);
ADD_CURATOR(1);
ADD_CURATOR(2);
ADD_CURATOR(3);
ADD_CURATOR(4);

addMissionEventHandler ["HandleDisconnect", {_this call FUNC(disconnect)}];

GVAR(curatorInitComplete) = true;
