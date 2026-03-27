#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client-side deactivation request for ECM.

    Parameters:
        0: Unit <OBJECT>

    Return value:
        None
*/
params [["_unit", objNull]];

if (!hasInterface || {isNull _unit} || {_unit isNotEqualTo player}) exitWith {};
[QGVAR(ecmRequestDeactivate), [_unit]] call CBA_fnc_serverEvent;
