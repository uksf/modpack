#include "script_component.hpp"
#define GROUP_DELAY 2

if (!isServer) exitWith {};

["CBA_settingsInitialized", {
    if (!GVAR(patrolEnabled)) exitWith {};

    [{
        [{
            private _groupCount = round (random [GVAR(patrolMinGroups), round (GVAR(patrolMaxGroups) / 1.5) max GVAR(patrolMinGroups), GVAR(patrolMaxGroups) + 1]);

            while {_groupCount > 0} do {
                [{call FUNC(patrol)}, [], _groupCount * GROUP_DELAY] call CBA_fnc_waitAndExecute;
                _groupCount = _groupCount - 1;
            };
        }, GVAR(patrolCooldown), []] call CBA_fnc_addPerFrameHandler;
    }, [], GVAR(patrolCooldown)] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addEventHandler;
