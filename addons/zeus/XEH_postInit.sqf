#include "script_component.hpp"

if (isServer) then {
    if (isNil {missionNamespace getVariable QGVAR(pingAdded)}) then {
        missionNamespace setVariable [QGVAR(pingAdded), false, true];
    };
    call FUNC(ping);
    call FUNC(initCurators);
};

if (hasInterface) then {
    call FUNC(loop);
    if (isNil {player getVariable QGVAR(actionsAdded)}) then {
        player setVariable [QGVAR(actionsAdded), false, true];
    };
    call FUNC(addAction);
};

if (!isMultiplayer) then {
    [{
        missionNamespace setVariable [QGVAR(curatorNames), [(name player),"","","",""], true];
        player assignCurator (GVAR(curatorObjects) select 0);
    }, [], 0.5] call CBA_fnc_waitAndExecute;
};

{_x addCuratorEditableObjects [allMissionObjects "all", true]} forEach allCurators;