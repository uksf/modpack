#include "script_component.hpp"

// Delay is necessary to allow curators to properly initialise as Zeus objects
[{
    if (isServer) then {
        if (!isMultiplayer) then {
            GVAR(curatorsMax) = 1;
        };

        for "_i" from 1 to GVAR(curatorsMax) do {
            call FUNC(curatorCreate);
        };
    };

    if (hasInterface) then {
        [player] call FUNC(addCuratorActions);

        if (!isMultiplayer) then {
            (GVAR(curatorObjects)#0) setVariable ["owner", "#adminLogged"]; // Prevents warning about curator owner not defined
            call FUNC(curatorLogin);
        };
    };
}, [], 0.1] call CBA_fnc_waitAndExecute;
