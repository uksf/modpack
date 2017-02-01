/*
    Author:
        Tim Beswick

    Description:
        Loads gear based on arsenal content. Will not add gear if not available in arsenal.

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_ctrlTemplateValue", "_center", "_display"];

_name = _ctrlTemplateValue lnbtext [lnbcurselrow _ctrlTemplateValue, 0];
_data = profilenamespace getvariable ["bis_fnc_saveInventory_data", []];
_nameID = _data find _name;
private _invData = [];
if (_nameID >= 0) then {
    _invData = _data select (_nameID + 1);
} else {
    ["Inventory '%1' not found", _name] call bis_fnc_error;
};

_fnc_removeRestricted = {
    params ["_data", "_virtualCargo", "_depth", "_removed", "_fnc_removeRestricted"];

    private _restrictedData = [];
    {
        private _restrictedPart = "";
        private _pushBack = true;
        if (_x isEqualType "") then {
            if (_x in _virtualCargo) then {
                _restrictedPart = _x;
            } else {
                if (_depth > 1) then {
                    _pushBack = false;
                };
                if (_x != "") then {
                    _removed pushBackUnique _x;
                };
            };
        } else {
            if (_x isEqualType []) then {
                _restrictedPart = [_x, _virtualCargo, _depth + 1, _removed, _fnc_removeRestricted] call _fnc_removeRestricted;
            };
        };
        if (_pushBack) then {
            _restrictedData pushBack _restrictedPart;
        };
    } forEach _data;
    
    _restrictedData
};

private _restrictedInv = _invData;
_fullArsenal = (missionnamespace getvariable ["BIS_fnc_arsenal_fullArsenal",false]);
_fullGarage = (missionnamespace getvariable ["BIS_fnc_arsenal_fullGarage", false]);
if (!_fullArsenal && !_fullGarage) then {
    _cargo = (missionnamespace getvariable ["BIS_fnc_arsenal_cargo", objnull]);
    _virtualCargoArrays = _cargo getvariable ["bis_addVirtualWeaponCargo_cargo", [[], [], [], []]];
    _virtualCargo = _virtualCargoArrays select 0;
    _virtualCargo append (_virtualCargoArrays select 1);
    _virtualCargo append (_virtualCargoArrays select 2);
    _virtualCargo append (_virtualCargoArrays select 3);
    if (!("%ALL" in _virtualCargo)) then {        
        "cba_diagnostic_Error" cutText ["","PLAIN"];
        private _removed = [];
        _restrictedInv = [_invData, _virtualCargo, 0, _removed, _fnc_removeRestricted] call _fnc_removeRestricted;
        _removed = _removed - ["ACE_NoVoice", "ItemRadioAcreFlagged"];
        _removed deleteAt (count _removed - 1);

        if (count _removed > 0) then {
            [_removed] call FUNC(showRemoved);
        };
    };
};

_nameID = _data find DUMMYLOADOUT;
if (_nameID < 0) then {
    _nameID = count _data;
    _data set [_nameID, DUMMYLOADOUT];
};
_data set [_nameID + 1, _restrictedInv];
_data = [_data] call FUNC(saveToProfile);

[_center, [profilenamespace, DUMMYLOADOUT]] call bis_fnc_loadinventory;

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
    _center setface (_inventoryCustom select 0);
    _center setvariable ["BIS_fnc_arsenal_face", (_inventoryCustom select 0)];
    _center setspeaker (_inventoryCustom select 1);
    [_center, _inventoryCustom select 2] call bis_fnc_setUnitInsignia;
};
