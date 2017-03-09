/*
    Author:
        esteldunedain from ACE https://github.com/acemod/ACE3, edited by Tim Beswick

    Description:
        Reads a setting value from a module, set it and force it. Logs if the setting is missing from the module.
        Must be called on the server, effect is global.

    Parameter(s):
        0: Module <OBJECT>
        1: ACE_Parameter name <STRING>
        2: Module parameter name <STRING>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

if !(isServer) exitWith {};

params ["_logic", "_settingName", "_moduleVariable"];

if (isNil {_logic getVariable _moduleVariable}) exitWith {
    WARNING_2("Warning in %1 module: %2 setting is missing. Probably an obsolete version of the module is used in the mission.",typeOf _logic,_moduleVariable);
};

private _value = _logic getVariable _moduleVariable;
if (_value isEqualTo -1) then {
    if (isArray (configFile >> "UKSF_Settings" >> _settingName >> "values")) then {
        WARNING_2("Module For Setting [%1] is saved as (-1), switching to (0) - missionVersion [%2]",_settingName,missionVersion);
        _value = 0;
    };
};

[_settingName, _value, true, true] call FUNC(setSetting);
