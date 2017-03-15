#include "script_component.hpp"

if (isServer) then {
    call FUNC(initCurators);
};

[{
    GVAR(curatorInitComplete)
},{
    if (!isMultiplayer) then {
        missionNamespace setVariable [QGVAR(curatorNames), [(name player),"","","",""], true];
        player assignCurator (GVAR(curatorObjects) select 0);
    };

    if (hasInterface) then {
        if (isNil {player getVariable QGVAR(actionsAdded)}) then {
            player setVariable [QGVAR(actionsAdded), false, true];
        };
        call FUNC(addAction);
    };

    [{
        {_x addCuratorEditableObjects [allMissionObjects "all", true]; false} count allCurators;
    }, [], 0.5] call cba_fnc_waitAndExecute;
}, []] call CBA_fnc_waitUntilAndExecute;


