#include "script_component.hpp"

// Register providers
if (hasInterface) then {
    ["shots", FUNC(providerShots), "client"] call FUNC(registerProvider);
    ["hits", FUNC(providerHits), "client"] call FUNC(registerProvider);
    ["explosives", FUNC(providerExplosives), "client"] call FUNC(registerProvider);
    ["unconscious", FUNC(providerUnconscious), "client"] call FUNC(registerProvider);
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
// so the server must also handle the killswitch via the EachFrame/variable check approach below
if (hasInterface) then {
    QGVAR(killswitch) addPublicVariableEventHandler {
        params ["", "_value"];
        if (_value) then {
            call FUNC(stopCollection);
            GVAR(eventBuffer) = [];
            INFO("Statistics killswitch activated");
        };
    };
};
