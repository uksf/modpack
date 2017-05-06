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

private _loadoutName = _control lnbtext [lnbcurselrow _control, 0];
private _data = profilenamespace getvariable ["bis_fnc_saveInventory_data", []];
private _index = _data find _loadoutName;
if (_index < 0) exitWith {
    ["Inventory '%1' not found", _loadoutName] call bis_fnc_error;
};
private _inventory = _data select (_index + 1);
private _inventoryIdentity = _inventory select 10;

private _restrictedInventory = +_inventory;
_restrictedInventory deleteAt (count _restrictedInventory - 1);
if (!(missionnamespace getvariable ["BIS_fnc_arsenal_fullArsenal", false]) && {!(missionnamespace getvariable ["BIS_fnc_arsenal_fullGarage", false])} && {isMultiplayer}) then {
    private _crate = (missionnamespace getvariable ["BIS_fnc_arsenal_cargo", objnull]);
    private _allowed = _crate getvariable [QGVAR(formattedCargo), []];
    private _removed = [];
    _restrictedInventory = [_restrictedInventory, _allowed, 0, _removed] call FUNC(restrictInventory);
    [_removed] call FUNC(showRemoved);
};

_restrictedInventory pushBack _inventoryIdentity;
_data append [DUMMYLOADOUT, _restrictedInventory];
_data = [_data] call FUNC(saveToProfile);

[_unit, [profilenamespace, DUMMYLOADOUT]] call bis_fnc_loadinventory;
_unit setface (_inventoryIdentity select 0);
_unit setvariable ["BIS_fnc_arsenal_face", (_inventoryIdentity select 0)];
_unit setspeaker (_inventoryIdentity select 1);
[_unit, _inventoryIdentity select 2] call bis_fnc_setUnitInsignia;

_data resize ((count _data) - 2);
_data = [_data] call FUNC(saveToProfile);
