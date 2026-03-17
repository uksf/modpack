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

// Listen for killswitch changes broadcast from server
// Note: addPublicVariableEventHandler does not fire on the machine that called publicVariable,
// so the server handles the killswitch directly in the shutdown handler above
if (!isServer) then {
    QGVAR(killswitch) addPublicVariableEventHandler {
        params ["", "_value"];
        if (_value) then {
            call FUNC(stopCollection);
            GVAR(eventBuffer) = [];
            INFO("Statistics killswitch activated");
        };
    };
};
