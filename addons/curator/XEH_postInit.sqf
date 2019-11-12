#include "script_component.hpp"

if (isServer) then {    
    for "_i" from 1 to GVAR(curatorsMax) do {
        call FUNC(curatorCreate);
    };
};

if (hasInterface) then {
    [player] call FUNC(addCuratorActions);

    if (!isMultiplayer) then {
        call FUNC(curatorLogin);
    };
};
