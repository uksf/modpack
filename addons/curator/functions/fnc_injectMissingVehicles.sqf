#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Injects vehicles missing from the curator tree due to engine config inheritance bug.
        Uses precached vehicle data from buildMissingVehiclesCache.
        Called on zen_editor_treesLoaded event.

    Parameter(s):
        0: Display <DISPLAY>

    Return Value:
        None

    Example:
        [_display] call uksf_curator_fnc_injectMissingVehicles
*/
params ["_display"];

if (isNil QGVAR(missingVehiclesCache)) exitWith {};

// Side index -> tree IDC: 0=East(271), 1=West(270), 2=Guer(272), 3=Civ(273)
private _sideToIDC = [271, 270, 272, 273];

// Build set of classes already in the target side trees
private _existingClasses = createHashMap;
{
    private _ctrlTree = _display displayCtrl _x;
    for "_i" from 0 to (_ctrlTree tvCount []) - 1 do {
        for "_j" from 0 to (_ctrlTree tvCount [_i]) - 1 do {
            for "_k" from 0 to (_ctrlTree tvCount [_i, _j]) - 1 do {
                private _data = _ctrlTree tvData [_i, _j, _k];
                if (_data != "") then {
                    _existingClasses set [_data, true];
                };
            };
        };
    };
} forEach _sideToIDC;

// Track which categories we injected into so we can sort them
private _modifiedCategories = [];
private _injected = 0;

{
    private _className = _x;
    if (_existingClasses getOrDefault [_className, false]) then { continue };

    _y params ["_side", "_factionName", "_categoryName", "_displayName", "_icon"];

    if (_side < 0 || {_side > 3}) then { continue };
    private _ctrlTree = _display displayCtrl (_sideToIDC select _side);

    // Find or create faction node
    private _factionPath = -1;
    for "_i" from 0 to (_ctrlTree tvCount []) - 1 do {
        if (_ctrlTree tvText [_i] == _factionName) exitWith {
            _factionPath = _i;
        };
    };
    if (_factionPath == -1) then {
        _factionPath = _ctrlTree tvAdd [[], _factionName];
    };

    // Find or create category node under faction
    private _categoryPath = -1;
    for "_j" from 0 to (_ctrlTree tvCount [_factionPath]) - 1 do {
        if (_ctrlTree tvText [_factionPath, _j] == _categoryName) exitWith {
            _categoryPath = _j;
        };
    };
    if (_categoryPath == -1) then {
        _categoryPath = _ctrlTree tvAdd [[_factionPath], _categoryName];
    };

    // Add the vehicle
    private _vehiclePath = _ctrlTree tvAdd [[_factionPath, _categoryPath], _displayName];
    _ctrlTree tvSetData [[_factionPath, _categoryPath, _vehiclePath], _className];

    if (_icon != "") then {
        _ctrlTree tvSetPicture [[_factionPath, _categoryPath, _vehiclePath], _icon];
    };

    _modifiedCategories pushBackUnique [_ctrlTree, _factionPath, _categoryPath];
    _injected = _injected + 1;
} forEach GVAR(missingVehiclesCache);

// Sort modified categories alphabetically
{
    _x params ["_ctrlTree", "_factionPath", "_categoryPath"];
    _ctrlTree tvSort [[_factionPath, _categoryPath], false];
} forEach _modifiedCategories;

if (_injected > 0) then {
    INFO_1("Injected %1 missing vehicles into curator tree",_injected);
};
