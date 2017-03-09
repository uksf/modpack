/*
    Author:
        esteldunedain from ACE https://github.com/acemod/ACE3, edited by Tim Beswick

    Description:
        Change the value of an existing setting if it was not previously forced. Force if neccesary.
        If executed on clients it has local effect.
        If executed on server it can have global effect if the last parameter is set to true.

    Parameter(s):
        0: Setting name <STRING>
        1: Value <ANY>
        2: Force it? (default: false) <BOOL>
        3: Broadcast the change to all clients (default: false) <BOOL>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params ["_name", "_value", ["_force", false], ["_broadcastChanges", false]];

private _settingData = [_name] call FUNC(getSettingData);
if (_settingData isEqualTo []) exitWith {
    ERROR_1("SetSetting [%1] setting does not exist", _name);
};
_settingData params ["", "_typeName", "_isClientSetable", "", "", "", "_isForced"];

if (_isForced) exitWith {
    INFO_1("SetSetting [%1] Trying to set forced setting", _name);
};

if ((missionNamespace getVariable [QEGVAR(modules,serverModulesRead), false]) && {!(_isForced isEqualTo _force)}) then {
    WARNING_3("SetSetting [%1] attempting to broadcast a change to force (%2 to %3)", _name, _isForced, _force);
};

private _failed = false;
if (typeName _value != _settingData select 1) then {
    _failed = true;
    if ((_typeName == "BOOL") && {_value isEqualType 0}) then {
        if (_value isEqualTo 0) then {
            _value = false;
            _failed = false;
        };
        if (_value isEqualTo 1) then {
            _value = true;
            _failed = false;
        };
    };
    if ((_typeName == "COLOR") && {_value isEqualType []}) then {
        _failed = false;
    };
};

if (_failed) exitWith {ERROR_3("SetSetting [%1] bad data type expected %2 got %3", _name, _typeName, typeName _value);};

_settingData set [6, _force];

if (_value isEqualTo (missionNamespace getVariable _name)) exitWith {};

TRACE_2("Variable Updated",_name,_value);
missionNamespace setVariable [_name, _value];

if (isServer && {_broadcastChanges}) then {
    publicVariable _name;
};
