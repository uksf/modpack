#include "script_component.hpp"

if (!isServer) exitWith {
    INFO("2) Postinit failed server check");
};

GVAR(checkInTimeInterval) = 300;

// pfh / wait and exec to run code
