#include "script_component.hpp"

if (hasInterface) then {
    [QGVAR(debugRequestActiveClientSources), [player]] call CBA_fnc_serverEvent;
};
