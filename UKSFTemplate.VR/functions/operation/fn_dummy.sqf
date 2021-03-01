#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        This function is empty and does nothing, but demonstrates parameter usage and returning values.
        Use it as a template to copy paste for your own functions.

    Parameters:
        0: Value <SCALAR>
        1: Unit <OBJECT> (Optional, default objNull)

    Return value:
        Array of value and unit

    Example usage:
        [10, player] call uksf_operation_fnc_dummy; ([10, player])
        [1] call uksf_operation_fnc_dummy; ([2, objNull])
*/
params ["_value", ["_unit", objNull]];

if (isNull _unit) then {
    _value = _value + 1;
};

[_value, _unit]
