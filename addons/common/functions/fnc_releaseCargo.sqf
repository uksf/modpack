/*
    Author:
        Tim Beswick

    Description:
        Release cargo from specified position

    Parameter(s):
        0: Position <STRING>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params ["_position"];

private _vehicle = vehicle player;
player setVariable ["ASL_Release_Cargo_Index_Vehicle", _vehicle];

if (_position isEqualTo "All") then {
    {
        [_x] call ASL_Release_Cargo_Index_Action;
        false
    } count [0,1,2];
} else {
    private _ropesAndCargo = [_vehicle] call ASL_Get_Active_Ropes_With_Cargo;
    private _ropeAndCargo = (_ropesAndCargo select {(_x select 1) isEqualTo _position}) select 0;
    if (count _ropeAndCargo > 0) then {
        [_ropeAndCargo select 0] call ASL_Release_Cargo_Index_Action;
    };
};
