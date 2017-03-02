/*
    Author:
        Tim Beswick

    Description:
        Loads gear based on arsenal content. Will not add gear if not available in arsenal.

    Parameter(s):
        0: Load display control <SCALAR>
        1: Local unit <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_control", "_unit"];

"cba_diagnostic_Error" cutText ["","PLAIN"];

private _name = _control lnbtext [lnbcurselrow _control, 0];
private _data = profilenamespace getvariable ["bis_fnc_saveInventory_data", []];
private _nameID = _data find _name;
private _invData = [];
if (_nameID >= 0) then {
    _invData = _data select (_nameID + 1);
} else {
    ["Inventory '%1' not found", _name] call bis_fnc_error;
};

_fnc_removeRestricted = {
    params ["_data", "_cargo", "_depth", "_removed", "_fnc_removeRestricted"];

    private _restrictedData = [];
    {
        private _part = _x;
        private _restrictedPart = "";
        private _pushBack = true;
        if (_part isEqualType "") then {
            if ((_part select [0, 4]) isEqualTo "ACRE") then {
                _part = [_part] call FUNC(cleanRadio);
            };
            if (_part in _cargo || {"%ALL" in _cargo}) then {
                _restrictedPart = _part;
            } else {
                if (_depth > 1) then {
                    _pushBack = false;
                };
                if (_part != "") then {
                    _removed pushBackUnique _part;
                };
            };
        } else {
            if (_part isEqualType []) then {
                _restrictedPart = [_part, _cargo, _depth + 1, _removed, _fnc_removeRestricted] call _fnc_removeRestricted;
            };
        };
        if (_pushBack) then {            
            _restrictedData pushBack _restrictedPart;
        };
        false
    } count _data;
    
    _restrictedData
};

private _restrictedInv = _invData;
private _fullArsenal = (missionnamespace getvariable ["BIS_fnc_arsenal_fullArsenal",false]);
private _fullGarage = (missionnamespace getvariable ["BIS_fnc_arsenal_fullGarage", false]);
//if (!_fullArsenal && !_fullGarage && isMultiplayer) then {
if (!_fullArsenal && !_fullGarage) then {
    private _crate = (missionnamespace getvariable ["BIS_fnc_arsenal_cargo", objnull]);
    private _cargo = _crate getvariable [QGVAR(formattedCargo), []];
    INFO_1("LOAD RESTRICTED CALL: %1", _cargo);
    private _removed = [];
    _restrictedInv = [_invData, _cargo, 0, _removed, _fnc_removeRestricted] call _fnc_removeRestricted;
    _removed = _removed - ["ACE_NoVoice", "ItemRadioAcreFlagged"];
    _removed deleteAt (count _removed - 1);
    if (count _removed > 0) then {
        [_removed] call FUNC(showRemoved);
    };
};

_nameID = _data find DUMMYLOADOUT;
if (_nameID < 0) then {
    _nameID = count _data;
    _data set [_nameID, DUMMYLOADOUT];
};
_data set [_nameID + 1, _restrictedInv];
_data = [_data] call FUNC(saveToProfile);

[_unit, [profilenamespace, DUMMYLOADOUT]] call bis_fnc_loadinventory;

if (_nameID >= 0) then {
    _data set [_nameID, objnull];
    _data set [_nameID + 1, objnull];
    _data = _data - [objnull];
};
_data = [_data] call FUNC(saveToProfile);

_nameID = _data find _name;
if (_nameID >= 0) then {
    _inventory = _data select (_nameID + 1);
    _inventoryCustom = _inventory select 10;
    _unit setface (_inventoryCustom select 0);
    _unit setvariable ["BIS_fnc_arsenal_face", (_inventoryCustom select 0)];
    _unit setspeaker (_inventoryCustom select 1);
    [_unit, _inventoryCustom select 2] call bis_fnc_setUnitInsignia;
};
