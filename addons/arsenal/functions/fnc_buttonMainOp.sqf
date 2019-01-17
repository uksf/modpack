/*
    Author:
        Tim Beswick

    Description:
        Sets the gear of the crate to either main op gear, or all gear.

    Parameter(s):
        0: Display <DISPLAY>

    Return Value:
        None
*/
#include "script_component.hpp"
#include "\u\uksf\addons\arsenal\script_mainOpGear.hpp"

missionNamespace setVariable [QGVAR(togglingMainOpGear), true];
(_this select 0) closeDisplay 1;
private _useMainOpGear = missionNamespace getVariable [QGVAR(useMainOpGear), false];
missionNamespace setVariable [QGVAR(useMainOpGear), !_useMainOpGear];

[{
    params ["_useMainOpGear"];

    private _box = player;
    [_box, true, false] call ace_arsenal_fnc_removeVirtualItems;

    if (_useMainOpGear) then {
        [_box, uiNamespace getVariable [QGVAR(mainOpGear), MAIN_OP_GEAR], false] call ace_arsenal_fnc_addVirtualItems;
        private _emptyLoadout = uiNamespace getVariable QGVAR(emptyLoadout);
        player setUnitLoadout [_emptyLoadout, true];
    } else {
        [_box, true, false] call ace_arsenal_fnc_addVirtualItems;
    };
    
    [_box, _box, false] call ace_arsenal_fnc_openBox;
}, [!_useMainOpGear]]  call CBA_fnc_execNextFrame;
