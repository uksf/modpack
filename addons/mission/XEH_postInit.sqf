#include "script_component.hpp"

if (GVAR(support)) then {
    ["CAManBase", "init", {_this#0 addMPEventHandler ["MPHit", {_this call FUNC(support)}]}, true, [], true] call CBA_fnc_addClassEventHandler;
};

if (hasInterface) then {
    if (GVAR(conspicuity)) then {
        GVAR(conspicuityGearWhitelist) = call compile GVAR(conspicuityGearWhitelistString);
        GVAR(conspicuityGearWhitelist) append DEFAULT_WHITELISTED_GEAR;
        ["loadout", {[_this#0] call FUNC(conspicuity)}] call CBA_fnc_addPlayerEventHandler;
        ["weapon", {_this call FUNC(conspicuity)}, true] call CBA_fnc_addPlayerEventHandler;
    };
};
