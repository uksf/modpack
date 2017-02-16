#include "script_component.hpp"

if (!isMultiplayer) then {
    missionNamespace setVariable [QGVAR(curatorNames), [(name player),"","","",""], true];
    player assignCurator (GVAR(curatorObjects) select 0);
};

if (hasInterface) then {
    call FUNC(loop);
    if (isNil {player getVariable QGVAR(actionsAdded)}) then {
        player setVariable [QGVAR(actionsAdded), false, true];
    };
    call FUNC(addAction);
};

[{
    {_x addCuratorEditableObjects [allMissionObjects "all", true]} forEach allCurators;
}, [], 0.5] call CBA_fnc_waitAndExecute;
