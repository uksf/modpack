#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Orchestrates server-side data loading after initialisation.
        Sets mission objects, removes deleted objects, then loads all persistent data.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_persistence_fnc_loadServerData
*/

GVAR(missionObjects) = +EGVAR(common,missionObjectsMinusUnits);
TRACE_1("Mission objects",GVAR(missionObjects));

[{
    call FUNC(removeDeletedMissionObjects);
    call FUNC(loadAllData);
}] call CBA_fnc_execNextFrame;
