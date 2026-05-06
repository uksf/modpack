#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Recursively walks an arbitrarily-nested SQF value (output of
        parseSimpleArray) and reconstructs HashMap shape. The pair-list
        heuristic — every element is [string, any] — converts a list to a
        hashmap; any other list is descended into element-by-element.

        Implemented as a real PREP'd function (not a private code variable)
        so recursion through forEach/apply doesn't depend on dynamic-scope
        access to a private symbol — see CLAUDE.md "no lexical closures".

    Parameter(s):
        0: Parsed value <ANY>

    Return Value:
        Rebuilt value with hashmap shape restored <ANY>

    Example:
        _parsed call uksf_persistence_fnc_rebuildHashmaps
*/
private _value = _this;
if !(_value isEqualType []) exitWith { _value };
if (_value isEqualTo []) exitWith { _value };

private _isPairList = true;
{
    if (!(_x isEqualType []) || {count _x != 2} || {!((_x#0) isEqualType "")}) exitWith { _isPairList = false };
} forEach _value;

if (_isPairList) exitWith {
    private _map = createHashMap;
    { _map set [_x#0, (_x#1) call FUNC(rebuildHashmaps)] } forEach _value;
    _map
};

_value apply { _x call FUNC(rebuildHashmaps) }
