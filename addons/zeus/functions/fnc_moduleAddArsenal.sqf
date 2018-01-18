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
TRACE_3("moduleAddArsenal",_logic,_object,typeOf _object);

switch (true) do {
    case (isNull _object): {
        [LSTRING(NothingSelected)] call ace_zeus_fnc_showMessage;
    };
    case (isPlayer _object): {
        ["str_a3_cfgvehicles_moduleremotecontrol_f_errorPlayer"] call ace_zeus_fnc_showMessage;
    };
    case (!alive _object): {
        [LSTRING(OnlyAlive)] call ace_zeus_fnc_showMessage;
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
            TRACE_1("BIS_fnc_arsenal: AmmoboxInit",_object);
            // Global Effects: "Action to access the Arsenal will be added automatically on all clients."
            ["AmmoboxInit", [_object, true]] call BIS_fnc_arsenal;
        };
    };
};

deleteVehicle _logic;
