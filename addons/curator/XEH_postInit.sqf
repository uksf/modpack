#include "script_component.hpp"

[(_this select 1)] call CBA_fnc_removePerFrameHandler;
if (!isMultiplayer || {(getPlayerUID player) in WHITELIST}) then {
    call FUNC(curatorLogin);
};
if (hasInterface) then {
    call FUNC(addCuratorActions);
};
