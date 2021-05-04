#include "script_component.hpp"
/*
    Author:
        LAxemann, Jokoho482, Tim Beswick

    Description:
        Get value from cache or if not found use config path to set value in cache

    Parameters:
        0: Variable Name for Saving <STRING>
        1: Code to call to get config path <CODE>
        2: Default value (Optional) <ANY>

    Return value:
        Cached Value <ANY>
*/
params [["_name", "", [""]], ["_configCallback", {}, [{}]], ["_defaultValue", ""]];

private _value = [GVAR(valueCache), _name] call CBA_fnc_hashGet;
if (isNil "_value") then {
    private _config = call _configCallback;
    _value = [_config, _defaultValue] call FUNC(getConfigEntry);

    [GVAR(valueCache), _name, _value] call CBA_fnc_hashSet;
};

_value
