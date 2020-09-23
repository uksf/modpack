#include "script_component.hpp"

if (!isServer) exitWith {};

["CBA_settingsInitialized", {
    // Presence of any dynamic patrol area will stop basic spawning functionality
    if !(GVAR(dynamicPatrolAreas) isEqualTo []) exitWith {
        GVAR(dynamicPatrolAreasEnabled) = true;
        publicVariable QGVAR(dynamicPatrolAreasEnabled);

        {
            private _data = _x call FUNC(initDynamicPatrolArea);
            private _delay = _data#0#DYNAMIC_PATROL_INDEX_START_DELAY + (_data#0#0 + random 10);
            [{
                [QGVAR(dynamicPatrolArea), _this, selectRandom EGVAR(common,HCs)] call CBA_fnc_targetEvent;
            }, _data, _delay] call CBA_fnc_waitAndExecute;
        } forEach GVAR(dynamicPatrolAreas);
    };

    if (GVAR(dynamicPatrolEnabled)) then {
        private _delay = [QGVAR(dynamicPatrolStartDelay), GVAR(dynamicPatrolCooldown)] select (QGVAR(dynamicPatrolStartDelay) == 0);
        [{call FUNC(dynamicPatrol)}, [], _delay] call CBA_fnc_waitAndExecute;
    };
}] call CBA_fnc_addEventHandler;
