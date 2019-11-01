#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Opens arsenal of target unit and sends log to server

    Parameter(s):
        0: Unit <OBJECT> (Optional)

    Return Value:
        None
*/
params [["_unit", BIS_fnc_initCuratorAttributes_target]];

(findDisplay -1) closeDisplay 1;
[_unit, _unit, true] call ace_arsenal_fnc_openBox;
[QEGVAR(common,log), [format ["%1 opened Arsenal on %2", name player, name _unit]]] call CBA_fnc_serverEvent;

GVAR(arsenalCloseEvent) = ["ace_arsenal_displayClosed", {
    ["ace_arsenal_displayClosed", GVAR(arsenalCloseEvent)] call CBA_fnc_removeEventHandler;
    private _loadout = getUnitLoadout _unit;
    private _units = [_unit] call zen_attributes_fnc_getAttributeEntities;
    {_x setUnitLoadout _loadout} forEach _units;
}] call CBA_fnc_addEventHandler;
