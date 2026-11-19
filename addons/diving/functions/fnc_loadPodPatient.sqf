#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Loads the nearest unconscious unit into the decompression pod, including underwater where ACE's own load action is blocked

    Parameter(s):
        0: Pod <OBJECT>
        1: Caller <OBJECT>

    Return Value:
        None

    Example:
        [_pod, player] call uksf_diving_fnc_loadPodPatient
*/
params ["_pod", "_caller"];

private _patient = [_pod] call FUNC(nearestPodPatient);
if (isNull _patient) exitWith {};

["ace_loadPersonEvent", [_patient, _pod, _caller, getArray (configOf _pod >> "ace_medical_treatment_patientSeats"), true], _patient] call CBA_fnc_targetEvent;
