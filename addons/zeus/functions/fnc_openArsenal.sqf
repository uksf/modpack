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
#include "script_component.hpp"

(findDisplay -1) closeDisplay 1;
["Open", [true, nil, BIS_fnc_initCuratorAttributes_target]] call bis_fnc_arsenal;

[BIS_fnc_initCuratorAttributes_target] spawn {
    waitUntil {sleep 1; isNull (uiNamespace getVariable "RSCDisplayArsenal")};
    
    params ["_unit"];
    [QEGVAR(common,log), [format ["%1 opened Arsenal on %2", name player, name _unit]]] call CBA_fnc_serverEvent;
    private _loadout = getUnitLoadout _unit;
    private _curatorSelected = ["man"] call Achilles_fnc_getCuratorSelected;
    {_x setUnitLoadout _loadout; false} count _curatorSelected;
};
