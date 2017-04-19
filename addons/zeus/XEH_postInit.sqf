#include "script_component.hpp"

private _addons = [];
private _cfgPatches = configFile >> "CfgPatches";
for "_i" from 0 to (count _cfgPatches - 1) do {
    private _class = _cfgPatches select _i;
    if (isClass _class) then {
        _addons set [count _addons, configName _class];
    };
};
_addons call bis_fnc_activateaddons;

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


