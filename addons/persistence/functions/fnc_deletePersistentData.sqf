/*
    Author:
        Tim Beswick

    Description:
        Deletes persistent data

    Parameter(s):
        0: Data key <STRING>

    Return Value:
        None
*/
#include "script_component.hpp"

if (!isServer) exitWith {};

params [["_key", GVAR(key)]];

if (_key == "") exitWith {};

WARNING_1("Deleting persistence data for key %1",_key);
profileNamespace setVariable [_key, nil];

if (_key == "ALL") then {
    private _variables = parsingNamespace getVariable [QGVAR(allVariablesProfileNamespace), []];
    {
        if (QGVAR(key) in _x) then {
            WARNING_1("Deleting persistence data for key %1",_x);
            profileNamespace setVariable [_x, nil];
        };
    } forEach _variables;
};
