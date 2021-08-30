#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Get config entry as value

    Parameters:
        0: Config entry <CONFIG>
        1: Default value (Optional) <ANY>

    Return value:
        Value (Any type)
*/
params ["_config", ["_defaultValue", ""]];

if (isNumber _config) exitWith {getNumber _config};
if (isText _config) exitWith {getText _config};
if (isArray _config) exitWith {getArray _config};

_defaultValue
