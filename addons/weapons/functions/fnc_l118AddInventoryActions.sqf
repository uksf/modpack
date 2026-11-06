#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Replaces the TBD round assembly on 105mm shell and casing items with L118 actions.
        Each action places the shell or charge on the ground as its own object, and the player carries it.

    Parameters:
        None

    Return value:
        Nothing

    Example:
        call uksf_weapons_fnc_l118AddInventoryActions
*/
if (!hasInterface) exitWith {};

private _pieces = [
    ["tbd_mortars_105mm_shell_he", QGVAR(105mm_shell_he), "Take out shell"],
    ["tbd_mortars_105mm_shell_smoke", QGVAR(105mm_shell_smoke), "Take out shell"],
    ["tbd_mortars_105mm_shell_dpicm", QGVAR(105mm_shell_illum), "Take out shell"]
];
for "_charge" from 1 to 7 do {
    _pieces pushBack [format ["tbd_mortars_105mm_casing_charge_%1", _charge], QGVAR(105mm_charge), "Take out charge"];
};
private _items = _pieces apply {toLower (_x select 0)};

{
    _x params ["_item", "_ids"];
    if (toLower _item in _items) then {
        {
            [_item, _x] call CBA_fnc_removeItemContextMenuOption;
        } forEach _ids;
    };
} forEach ([""] call CBA_fnc_getItemContextMenuOptionIDs);

{
    _x params ["_item", "_piece", "_name"];
    [configName (configFile >> "CfgMagazines" >> _item), "CONTAINER", _name, nil, "\a3\ui_f\data\igui\cfg\simpletasks\types\box_ca.paa", {true}, {
        params ["_unit", "", "", "", "_piece"];
        [_unit, createVehicle [_piece, getPosATL _unit, [], 0, "NONE"]] call ace_dragging_fnc_startCarry;
    }, true, _piece] call CBA_fnc_addItemContextMenuOption;
} forEach _pieces;
