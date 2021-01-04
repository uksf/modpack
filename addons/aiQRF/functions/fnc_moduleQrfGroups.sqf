#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Executes init patrol for spawn module

    Parameters:
        0: The module logic <OBJECT>

    Return value:
        Nothing
*/

(_this select 1) params ["_module"];

if (!(local _module)) exitWith {};

private _qrfGroups = [];
private _qrfGroupLeaders = ((synchronizedObjects _module) select {_x isKindOf "Man" || _x isKindOf "Car" || _x isKindOf "Heli" || _x isKindOf "Plane"}); // should return [qrfleader1, qrfleader2, ...]
{_qrfGroups pushBack (group _x)} forEach _qrfGroupLeaders;

_module setVariable [QGVAR(qrfGroups),_qrfGroups,true]; // stores [qrfGroup1, qrfGroup2, ...]

