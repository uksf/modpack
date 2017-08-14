#include "script_component.hpp"

[{
    if (missionNamespace getVariable [QGVAR(curatorsCreated), false]) exitWith {
        [(_this select 1)] call CBA_fnc_removePerFrameHandler;
        if (!isMultiplayer) then {
            call FUNC(curatorLogin);
        };
        if (hasInterface) then {
            call FUNC(addCuratorActions);
        };
    };
}, 0, []] call CBA_fnc_addPerFrameHandler;

