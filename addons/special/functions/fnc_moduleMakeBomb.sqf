#include "script_component.hpp"
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

params ["_logic", "", "_activated", ["_deadman", false], ["_car", false], ["_empty", false]];

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
    ["Place on a living unit or an occupied land vehicle"] call ace_common_fnc_displayTextStructured;
} else {
    if (_empty && {!(_unit isKindOf "LandVehicle")}) then {
        ["Place on a land vehicle"] call ace_common_fnc_displayTextStructured;
    } else {
        if (_car && {!(alive _unit) || {!(_unit isKindOf "LandVehicle")} || {driver _unit isEqualTo objNull}}) then {
            ["Place on an occupied land vehicle"] call ace_common_fnc_displayTextStructured;
        } else {
            if (!_empty && {!_car} && {!(alive _unit) || {!(_unit isKindOf "CAManBase")}}) then {
                ["Place on a living unit"] call ace_common_fnc_displayTextStructured;
            } else {
                if (!(_unit getVariable [QGVAR(isBomber), false])) then {
                    if (_empty) then {
                        [_unit] remoteExecCall [QFUNC(carBomb), owner _unit];
                        ["Vehicle is now a car bomb"] call ace_common_fnc_displayTextStructured;
                    } else {
                        [_unit, _deadman, _car] remoteExecCall [QFUNC(suicide), owner _unit];
                        ["Unit/vehicle is now a bomber"] call ace_common_fnc_displayTextStructured;
                    };
                } else {
                    ["Unit or vehicle is already a bomb"] call ace_common_fnc_displayTextStructured;
                };
            };
        };
    };
};

deleteVehicle _logic;
