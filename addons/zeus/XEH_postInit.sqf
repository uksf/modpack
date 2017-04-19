#include "script_component.hpp"

//Setup eventhandlers
if (isServer) then {
    [QGVAR(curatorCreate), {_this call FUNC(curatorCreate)}] call CBA_fnc_addEventHandler;
    [QGVAR(curatorDelete), {_this call FUNC(curatorDelete)}] call CBA_fnc_addEventHandler;
    [QGVAR(curatorAssign), {_this call FUNC(curatorAssign)}] call CBA_fnc_addEventHandler;
    [QGVAR(curatorUnassign), {_this call FUNC(curatorUnassign)}] call CBA_fnc_addEventHandler;
};
if (hasInterface) then {
    [QGVAR(curatorLogout), {_this call FUNC(curatorLogout)}] call CBA_fnc_addEventHandler;
    [QGVAR(adminHint), {_this call FUNC(adminHint)}] call CBA_fnc_addEventHandler;
};

//Start curator access
//GVAR(curatorsLocked) = GVAR(curatorsLockedOnStart);
if (isServer) then {
    //addMissionEventHandler ["HandleDisconnect", {_this call FUNC(disconnect)}];
};
if (!isMultiplayer) then {
    call FUNC(curatorLogin);
};
if (hasInterface) then {
    if (isNil {player getVariable QGVAR(curatorActionsAdded)}) then {
        player setVariable [QGVAR(curatorActionsAdded), false, true];
    };
    call FUNC(addCuratorActions);
};
[{
    {_x addCuratorEditableObjects [allMissionObjects "all", true]; false} count allCurators;
}, [], 1] call cba_fnc_waitAndExecute;
