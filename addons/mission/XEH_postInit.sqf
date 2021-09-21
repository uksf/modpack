#include "script_component.hpp"

if (!isServer) exitWith {
    INFO("2) Postinit failed server check");
};

["CBA_settingsInitialized", {
    INFO("2) Settings initialized");
    // Presence of any dynamic patrol area will stop basic spawning functionality
    if (GVAR(dynamicPatrolAreas) isNotEqualTo []) exitWith {
        INFO("2) Areas present");
        GVAR(dynamicPatrolAreasEnabled) = true;
        publicVariable QGVAR(dynamicPatrolAreasEnabled);

        {
            private _data = _x call FUNC(initDynamicPatrolArea);
            TRACE_1("2) Area data result",_data);
            private _delay = _data#0#DYNAMIC_PATROL_INDEX_START_DELAY + (_data#0#0 + random 10);
            TRACE_1("2) Area delay",_delay);
            [{
                TRACE_1("2) Area headless client pool",acex_headless_headlessClients);
                [QGVAR(dynamicPatrolArea), _this] call EFUNC(common,headlessEvent);
            }, _data, _delay] call CBA_fnc_waitAndExecute;
        } forEach GVAR(dynamicPatrolAreas);
    };

    if (GVAR(dynamicPatrolEnabled)) then {
        INFO("2) Global enabled");
        private _delay = [GVAR(dynamicPatrolStartDelay), GVAR(dynamicPatrolCooldown)] select (GVAR(dynamicPatrolStartDelay) == 0);
        [{call FUNC(dynamicPatrol)}, [], _delay * 60] call CBA_fnc_waitAndExecute;
    };
}] call CBA_fnc_addEventHandler;

GVAR(missionObjects) = (allMissionObjects "All") - allUnits;
{
    _x call FUNC(initSafehousePrefab);
} forEach GVAR(safehousePrefabAreaModules);

[QGVAR(loadingFinished), {

}] call CBA_fnc_addEventHandler;
