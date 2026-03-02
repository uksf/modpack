#include "script_component.hpp"

// Register providers
if (hasInterface) then {
    ["shots", FUNC(providerShots), "client"] call FUNC(registerProvider);
    ["hits", FUNC(providerHits), "client"] call FUNC(registerProvider);
};

// Start collection if enabled
if (GVAR(enabled)) then {
    call FUNC(startCollection);
};
