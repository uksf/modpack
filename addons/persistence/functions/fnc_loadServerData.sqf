#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Orchestrates server-side data loading after initialisation.
        Sets mission objects, removes deleted objects, then loads all persistent data.
        Mission objects without an Eden persistence ID are excluded from saving,
        so a later save never gives them an ID and a reload never duplicates them.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_persistence_fnc_loadServerData
*/

GVAR(missionObjects) = +EGVAR(common,missionObjectsMinusUnits);
TRACE_1("Mission objects",GVAR(missionObjects));
{
    if (_x getVariable [QGVAR(persistenceID), ""] == "") then {
        _x setVariable [QGVAR(excluded), true];
        _x setVariable [QGVAR(startPosition), getPosASL _x];
    };
} forEach GVAR(missionObjects);

[{
    call FUNC(removeDeletedMissionObjects);
    call FUNC(loadAllData);
}] call CBA_fnc_execNextFrame;
