#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Opens arsenal of target unit and sends log to server

    Parameter(s):
        None

    Return Value:
        None
*/

(findDisplay -1) closeDisplay 1;
[BIS_fnc_initCuratorAttributes_target, BIS_fnc_initCuratorAttributes_target, true] call ace_arsenal_fnc_openBox;
[QEGVAR(common,log), [format ["%1 opened Arsenal on %2", name player, name BIS_fnc_initCuratorAttributes_target]]] call CBA_fnc_serverEvent;

GVAR(arsenalCloseEvent) = ["ace_arsenal_displayClosed", {
    ["ace_arsenal_displayClosed", GVAR(arsenalCloseEvent)] call CBA_fnc_removeEventHandler;
    private _loadout = getUnitLoadout BIS_fnc_initCuratorAttributes_target;
    private _curatorSelected = ["man"] call Achilles_fnc_getCuratorSelected;
    {_x setUnitLoadout _loadout; false} count _curatorSelected;
}] call CBA_fnc_addEventHandler;
