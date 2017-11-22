#include "script_component.hpp"

if (!isMultiplayer || {(getMissionConfigValue ["respawn", "NONE"]) isEqualTo "NONE"}) exitWith {
    [QGVAR(respawned), [player]] call CBA_fnc_localEvent;
};
