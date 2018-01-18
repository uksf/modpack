/*
    Author:
        Tim Beswick, Alganthe

    Description:
        Adds arsenal to object. Extension of ACE function

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
        ["Place on an object"] call ace_zeus_fnc_showMessage;
    };
    case (isPlayer _object): {
        ["str_a3_cfgvehicles_moduleremotecontrol_f_errorPlayer"] call ace_zeus_fnc_showMessage;
    };
    case (!alive _object): {
        ["Object must be alive"] call ace_zeus_fnc_showMessage;
    };
    default {
        if (["ACE_Arsenal"] call ace_common_fnc_isModLoaded) then {
            [_object, true, true] call ace_arsenal_fnc_initBox;
            if (isMultiplayer && {{_object in _x} count GVAR(EHIDArray) == 0}) then {
                private _id = [QGVAR(addArsenalAction), [_object]] call CBA_fnc_globalEventJIP;
                [_id, _object] call CBA_fnc_removeGlobalEventJIP;
                GVAR(EHIDArray) pushBack [_id, _object];
                publicVariable QGVAR(EHIDArray);
            } else {
                [QEGVAR(arsenal,addArsenalAction), [_object]] call CBA_fnc_localEvent;
            };
        } else {
            ["AmmoboxInit", [_object, true]] call BIS_fnc_arsenal;
        };
    };
};

deleteVehicle _logic;
