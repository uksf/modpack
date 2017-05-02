#include "script_component.hpp"

if (!isMultiplayer) then {
    call FUNC(curatorLogin);
};
if (hasInterface) then {
    call FUNC(addCuratorActions);
};
