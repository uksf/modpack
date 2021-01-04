#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Assigns sync'd units as callers
        Wrapped in a cba wait and execute due to variables from QRF Group module not available at init

    Parameters:
        0: The module <OBJECT>

    Return value:
        Nothing
*/

(_this select 1) params ["_module"];

[{

params ["_module"];

if (!(local _module)) exitWith {};

private _callerGroupLeaders = ((synchronizedObjects _module) select {_x isKindOf "Man" || _x isKindOf "Car" || _x isKindOf "Heli" || _x isKindOf "Plane"}); // should return [callerleader1, callerleader2, ...]

// get all qrf modules sync'd to this caller module
private _syncdQRFGroupModule = ((synchronizedObjects _module) select {_x isKindOf "uksf_aiQrf_moduleQrfGroups"});

// get units sync'd to QRF modules
private _assignedQrfGroups = (_syncdQRFGroupModule select 0) getVariable [QGVAR(qrfGroups),[]];

// set caller group as caller assign qrf groups
_callerGroupLeaders apply {(group _x) setVariable [QGVAR(qrfCaller),true,true]; (group _x) setVariable [QGVAR(assignedQrfGroups), _assignedQrfGroups, true]};

},_module,3] call cba_fnc_waitAndExecute;
