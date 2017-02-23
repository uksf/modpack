/*
    Author:
        Tim Beswick

    Description:
        Makes unit a bomber

    Parameter(s):
        0: The module logic <OBJECT>
        1: Synchronized units <ARRAY>
        2: Activated <BOOL>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_logic", "_units", "_activated", ["_deadman", false], ["_car", false], ["_empty", false]];

if !(_activated && local _logic) exitWith {};

if (_logic isKindOf QGVAR(moduleMakeSuicideBomberDeadman) || {_logic isKindOf QGVAR(moduleMakeCarBomberDeadman)}) then {
    _deadman = true;
};
if (_logic isKindOf QGVAR(moduleMakeCarBomber) || {_logic isKindOf QGVAR(moduleMakeCarBomberDeadman)}) then {
    _car = true;
};
if (_logic isKindOf QGVAR(moduleMakeCarBomb)) then {
    _empty = true;
};

(missionNamespace getVariable ["bis_fnc_curatorObjectPlaced_mouseOver", [""]]) params ["_typeName", "_unit"];
if (_typeName != "OBJECT") then {
    if (!_car && {!(alive _unit)} && {!(_unit isKindOf "CAManBase")}) then {
        [QUOTE(Place on a living unit)] call ace_common_fnc_displayTextStructured;
    } else {
        if (_car && {!(alive _unit)} && {!(_unit isKindOf "LandVehicle")}) then {
            [QUOTE(Place on a living land vehicle)] call ace_common_fnc_displayTextStructured;
        } else {
            if (_empty && {!(_unit isKindOf "LandVehicle")}) then {
                [QUOTE(Place on a land vehicle)] call ace_common_fnc_displayTextStructured;
            } else {
                [QUOTE(Place on a living unit or vehicle)] call ace_common_fnc_displayTextStructured;
            };
        };
    };
} else {
    if (!(_unit getVariable [QGVAR(isBomber), false])) then {
        if (_empty) then {
            [_unit] remoteExecCall [QFUNC(carBomb), owner _unit];
        } else {
            [_unit, _deadman, _car] remoteExecCall [QFUNC(suicide), owner _unit];
        };        
    } else {
        [QUOTE(Unit or vehicle is already a bomb)] call ace_common_fnc_displayTextStructured;
    };
};

deleteVehicle _logic;
