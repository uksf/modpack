#include "script_component.hpp"

if (!isServer) exitWith {};

["CBA_settingsInitialized", {
    // Presence of any dynamic patrol area will stop basic spawning functionality
    if !(GVAR(dynamicPatrolAreas) isEqualTo []) exitWith {
        GVAR(dynamicPatrolAreasEnabled) = true;
        publicVariable QGVAR(dynamicPatrolAreasEnabled);

        {
            private _data = _x call FUNC(initDynamicPatrolArea);
            [{
                [QGVAR(dynamicPatrolArea), _this, selectRandom EGVAR(common,HCs)] call CBA_fnc_targetEvent;
            }, _data, _data#0#0 + random 10] call CBA_fnc_waitAndExecute;
        } forEach GVAR(dynamicPatrolAreas);
    };

    if (GVAR(dynamicPatrolEnabled)) then {
        [{call FUNC(dynamicPatrol)}, [], GVAR(dynamicPatrolCooldown)] call CBA_fnc_waitAndExecute;
    };
}] call CBA_fnc_addEventHandler;
