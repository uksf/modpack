#include "script_component.hpp"

["combatDamage", FUNC(providerCombatDamage), "all"] call FUNC(registerProvider);
["shots", FUNC(providerShots), "all"] call FUNC(registerProvider);

if (hasInterface) then {
    ["explosives", FUNC(providerExplosives), "client"] call FUNC(registerProvider);
    ["unconscious", FUNC(providerUnconscious), "client"] call FUNC(registerProvider);
    ["sampler", FUNC(providerSampler), "client"] call FUNC(registerProvider);
};

if (isDedicated) then {
    ["kills", FUNC(providerKills), "server"] call FUNC(registerProvider);
};

if (GVAR(enabled)) then {
    call FUNC(startCollection);
};
