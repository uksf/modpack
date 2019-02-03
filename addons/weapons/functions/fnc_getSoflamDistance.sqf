#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Gets soflam laser distance

    Parameters:
        None

    Return value:
        Array <ARRAY>
*/

#define MIN_DISTANCE 10
#define MAX_DISTANCE 15000

disableSerialization;
private _dlgVector = uiNamespace getVariable ["ACE_RscOptics_LaserDesignator", nil];
private _distance = ctrlText (_dlgVector displayCtrl 123002);

if (_distance == "----") exitWith {-1000};
_distance = round parseNumber _distance;
if (GVAR(useFeet)) then {
    _distance = 3.28084 * _distance;
};

if (_distance > MAX_DISTANCE) exitWith {-1000};
if (_distance < MIN_DISTANCE) exitWith {-1000};

_distance
