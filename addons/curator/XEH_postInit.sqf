#include "script_component.hpp"

// Delay is necessary to allow curators created in progress to properly initialise as Zeus objects
[{
    if (isServer) then {
        private _neededCurators = GVAR(curatorsMax) - (count GVAR(curatorObjects));
        if (_neededCurators > 0) then {
            INFO_1("Need to create %1 curators",_neededCurators);
            for "_i" from 1 to _neededCurators do {
                (createGroup [sideLogic, true]) createUnit ["ModuleCurator_F", [0,0,0], [], 0, "NONE"];
            };
        };
    };

    if (hasInterface && {!isMultiplayer}) then {
        call FUNC(curatorLogin);
    };
}, [], 0.2] call CBA_fnc_waitAndExecute;
