#include "script_component.hpp"
/*
    Author: UKSF
    Description:
        Converts an SQF value into a JSON literal string.
        Handles: STRING, SCALAR, BOOL, ARRAY (recursive), HASHMAP (object), nil → "null".

    Parameters:
        0: Value to serialise <ANY>

    Return Value:
        JSON literal <STRING>

    Example:
        [createHashMapFromArray [["a", 1], ["b", "two"]]] call uksf_common_fnc_toJson
*/
params ["_value"];

if (isNil "_value") exitWith { "null" };

switch (typeName _value) do {
    case "STRING": {
        private _escaped = _value;
        _escaped = [_escaped, "\", "\\"] call CBA_fnc_replace;
        _escaped = [_escaped, '"', '\"'] call CBA_fnc_replace;
        _escaped = [_escaped, toString [10], "\n"] call CBA_fnc_replace;
        _escaped = [_escaped, toString [13], "\r"] call CBA_fnc_replace;
        _escaped = [_escaped, toString [9],  "\t"] call CBA_fnc_replace;
        format ['"%1"', _escaped]
    };
    case "SCALAR": { if (finite _value) then { str _value } else { "null" } };
    case "BOOL":   { if (_value) then {"true"} else {"false"} };
    case "ARRAY":  {
        private _parts = _value apply { [_x] call uksf_common_fnc_toJson };
        format ["[%1]", _parts joinString ","]
    };
    case "HASHMAP": {
        private _parts = [];
        {
            // Keys are coerced to strings; values recursed.
            _parts pushBack format ['"%1":%2', _x, [_y] call uksf_common_fnc_toJson];
        } forEach _value;
        format ["{%1}", _parts joinString ","]
    };
    default {
        diag_log text format ["uksf_common_fnc_toJson: unsupported type %1", typeName _value];
        '""'
    };
};
