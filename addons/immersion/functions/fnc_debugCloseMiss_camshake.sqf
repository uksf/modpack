#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Variant E (control): cam shake only. Baseline against which the
        physical/rotation/fatigue variants are compared.

    Parameters:
        0: Severity <SCALAR> (0..1)

    Return value:
        None

    Example:
        [1] call uksf_immersion_fnc_debugCloseMiss_camshake
*/
params [["_severity", 1, [0]]];

private _force = _severity * 4;
private _length = 0.6;
private _frequency = 25;

addCamShake [_force, _length, _frequency];

systemChat format ["[immersion debug E] camshake force=%1 length=%2 freq=%3", _force, _length, _frequency];
