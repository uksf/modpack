#include "script_component.hpp"
/*
    Author:
        LAxemann, Jokoho482, Tim Beswick

    Description:
        Read Value from config and save it in the cache Location and read and save the value if the value not exist if config entry not exist return the Default Value
        Get value from cache or if not found use config path to set value in cache

    Parameters:
        0: Variable Name for Saving <STRING>
        1: Code to call to get config path <CODE>

    Return value:
        Cached Value <ANY>
*/
params [["_name", "", [""]], ["_configCallback", {}, [{}]]];

private _value = [GVAR(valueCache), _name] call CBA_fnc_hashGet;
if (isNil "_value") then {
    private _config = call _configCallback;
    _value = [_config] call {
        params ["_config"];

        if (isNumber _config) exitWith {getNumber _config};
        if (isText _config) exitWith {getText _config};
        if (isArray _config) exitWith {getArray _config};
        ""
    };

    [GVAR(valueCache), _name, _value] call CBA_fnc_hashSet;
};

_value
