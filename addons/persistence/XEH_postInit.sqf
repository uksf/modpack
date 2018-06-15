#include "script_component.hpp"

if (isServer && GVAR(enabled)) then {
    call FUNC(loadVehicleData);
};
