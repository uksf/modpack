/*
    Author:
        Tim Beswick

    Description:
        Restricts and returns inventory based on given allowed gear.

    Parameter(s):
        0: Inventory to restrict <ARRAY>
        1: Allowed gear <ARRAY>
        2: Current depth of restriction <SCALAR>
        3: Removed items (Unique) <ARRAY>

    Return Value:
        Restricted inventory <ARRAY>
*/
#include "script_component.hpp"

params ["_inventory", "_allowed", "_depth", "_removed", ["_restrictedInventory", []]];

{
    private _part = _x;
    private _restrictedPart = "";
    private _pushBack = true;
    if (_part isEqualType "") then {
        if ((_part select [0, 4]) isEqualTo "ACRE") then {
            _part = [_part] call FUNC(cleanRadio);
        };
        if (_part in _allowed || {"%ALL" in _allowed} || {_part isEqualTo "ItemRadioAcreFlagged"}) then {
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
            _restrictedPart = [_part, _allowed, _depth + 1, _removed] call FUNC(restrictInventory);
        };
    };
    if (_pushBack) then {
        _restrictedInventory pushBack _restrictedPart;
    };
    false
} count _inventory;
    
_restrictedInventory
