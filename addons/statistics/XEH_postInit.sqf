#include "script_component.hpp"

// Combat damage runs on all machines — damage events fire on the entity-local machine
["combatDamage", FUNC(providerCombatDamage), "all"] call FUNC(registerProvider);

// Register providers
if (hasInterface) then {
    ["shots", FUNC(providerShots), "client"] call FUNC(registerProvider);
    ["explosives", FUNC(providerExplosives), "client"] call FUNC(registerProvider);
    ["unconscious", FUNC(providerUnconscious), "client"] call FUNC(registerProvider);
    ["sampler", FUNC(providerSampler), "client"] call FUNC(registerProvider);
};

if (isServer) then {
    ["kills", FUNC(providerKills), "server"] call FUNC(registerProvider);
};

// Start collection if enabled
if (GVAR(enabled)) then {
    call FUNC(startCollection);
};

