#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Finds the nearest unconscious unit outside a vehicle that can be loaded into the decompression pod

    Parameter(s):
        0: Pod <OBJECT>

    Return Value:
        Patient, or objNull if none is in range <OBJECT>

    Example:
        [_pod] call uksf_diving_fnc_nearestPodPatient
*/
params ["_pod"];

if (_pod emptyPositions "cargo" == 0) exitWith { objNull };

private _patients = (_pod nearEntities ["CAManBase", DECO_POD_LOAD_RANGE]) select {
    alive _x && {isNull objectParent _x} && {!(_x call ace_common_fnc_isAwake)}
};

_patients param [0, objNull]
