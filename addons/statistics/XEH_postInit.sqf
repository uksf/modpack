#include "script_component.hpp"

// Combat damage runs on all machines — damage events fire on the entity-local machine
["combatDamage", FUNC(providerCombatDamage), "all"] call FUNC(registerProvider);

// Register providers
if (hasInterface) then {
    ["shots", FUNC(providerShots), "client"] call FUNC(registerProvider);
    ["hits", FUNC(providerHits), "client"] call FUNC(registerProvider);
    ["damageReceived", FUNC(providerDamageReceived), "client"] call FUNC(registerProvider);
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

// Killswitch is checked inline by addEvent and sync functions.
// publicVariable broadcasts the value change to all machines automatically.
// No addPublicVariableEventHandler needed — nothing to tear down or clear.
// Turning killswitch off resumes collection without restart.
