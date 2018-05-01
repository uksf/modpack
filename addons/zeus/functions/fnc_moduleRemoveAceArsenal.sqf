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
#include "script_component.hpp"

params ["_logic"];

if (!local _logic) exitWith {};

private _object = attachedTo _logic;

switch (true) do {
    case (isNull _object): {
        ["Place on a object"] call ace_zeus_fnc_showMessage;
    };
    case (isPlayer _object): {
        ["str_a3_cfgvehicles_moduleremotecontrol_f_errorPlayer"] call ace_zeus_fnc_showMessage;
    };
    case (!alive _object): {
        ["Object must be alive"] call ace_zeus_fnc_showMessage;
    };
    default {
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
    };
};

deleteVehicle _logic;
