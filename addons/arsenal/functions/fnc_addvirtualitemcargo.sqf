//MERGE BIS
/*
    Author: 
        Karel Moricky, edited by Tim Beswick for UKSF usage

    Description:
        Add virtual items to an object (e.g., ammo box).
        Virtual items can be selected in the Arsenal.

    Parameter(s):
        0: OBJECT - objct to which items will be added
        1: STRING or ARRAY of STRINGs - item class(es) to be added
        2 (Optional): BOOL - true to add items globally (default: false)
        3 (Optional): BOOL - true to add Arsenal action (default: true)

    Returns:
        ARRAY of ARRAYs - all virtual items within the object's space in format [<items>,<weapons>,<magazines>,<backpacks>]
*/
#include "script_component.hpp"

private ["_object","_classes","_isGlobal","_add","_type","_initAction","_cargo","_cargoArray","_save"];
_object = _this param [0,missionnamespace,[missionnamespace,objnull]];
_classes = _this param [1,[],["",true,[]]];
_isGlobal = _this param [2,false,[false]];
_initAction = _this param [3,true,[true]];
_add = _this param [4,1,[1]];
_type = _this param [5,0,[0]];

//--- Get cargo list
_cargo = _object getvariable ["bis_addVirtualWeaponCargo_cargo",[[],[],[],[]]];
_cargoArray = _cargo select _type;
if (_add == 0) exitwith {_cargoArray};

//--- Modify cargo list
_save = false;
if (typename _classes != typename []) then {_classes = [_classes]};
if (count _classes == 0 && _add < 0) then {
    _cargoArray = [];
    _save = true;
} else {
    {
        //--- Use config classnames (conditions are case sensitive)
        private ["_class"];
        _x = _x param [0,"",["",true]];
        if (typename _x == typename true) then {_x = "%ALL";};
        _class = switch _type do {
            case 0;
            case 1: {configname (configfile >> "cfgweapons" >> _x);};
            case 2: {configname (configfile >> "cfgmagazines" >> _x);};
            case 3: {configname (configfile >> "cfgvehicles" >> _x);};
            default {""};
        };
        if (_class == "") then {_class = _x;};
        if (_add > 0) then {
            if (!(_class in _cargoArray) && (_class != "" || _class == "%ALL")) then {_cargoArray set [count _cargoArray,_class];};
        } else {
            _cargoArray = _cargoArray - [_class];
        };
        _save = true;
    } foreach _classes;
};
_cargo set [_type,_cargoArray];

if (_save) then {
    if (typename _object == typename missionnamespace) then {
        _object setvariable ["bis_addVirtualWeaponCargo_cargo",_cargo];
        publicvariable "bis_addVirtualWeaponCargo_cargo";
    } else {
        _object setvariable ["bis_addVirtualWeaponCargo_cargo",_cargo,_isGlobal];
    };
    [_object, _cargo] call FUNC(setFormattedCargo);
};

if (!is3DEN && _initAction && typename _object == typename objnull) then {
    if ({count _x > 0} count _cargo > 0) then {
        //--- Init arsenal
        ["AmmoboxInit",_object] call bis_fnc_arsenal;
    } else {
        //--- Terminate arsenal
        ["AmmoboxExit",_object] call bis_fnc_arsenal;
    };
};

_cargoArray
