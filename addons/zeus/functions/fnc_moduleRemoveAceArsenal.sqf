#include "script_component.hpp"
/*
    Author:
        Tim Beswick, Alganthe

    Description:
        Removes arsenal from object. Extension of ACE function

    Parameter(s):
        0: The module logic <OBJECT>

    Return Value:
        None
*/
params ["_logic"];

private _object = attachedTo _logic;
deleteVehicle _logic;

if (isNull _object) exitWith {["Place on an object"] call ace_zeus_fnc_showMessage;};
if (isPlayer _object) exitWith {["str_a3_cfgvehicles_moduleremotecontrol_f_errorPlayer"] call ace_zeus_fnc_showMessage;};
if (!alive _object) exitWith {["Object must be alive"] call ace_zeus_fnc_showMessage;};

[_object, true, true] call ace_arsenal_fnc_removeBox;
if (isMultiplayer && {{_object in _x} count GVAR(EHIDArray) == 0}) then {
    private _id = (GVAR(EHIDArray) select {_x select 1 == _object}) select 0;
    if (!(isNil "_id")) then {
        [_id select 0] call CBA_fnc_removeGlobalEventJIP;
        GVAR(EHIDArray) deleteAt (GVAR(EHIDArray) find _id);
        publicVariable QGVAR(EHIDArray);
        [QEGVAR(arsenal,removeArsenalAction), [_object]] call CBA_fnc_globalEvent;
    };
} else {
    [QEGVAR(arsenal,removeArsenalAction), [_object]] call CBA_fnc_localEvent;
};
