#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Plays an alert sound for a state transition.

    Parameter(s):
        0: State key <STRING> — "cardiac" | "coma"

    Return Value:
        None

    Example:
        ["cardiac"] call uksf_medical_fnc_playStateSound
*/
params ["_state"];

if (!GVAR(soundOnStateChange)) exitWith {};

private _soundName = switch (_state) do {
    case "cardiac": { QGVAR(stateCardiac) };
    case "coma": { QGVAR(stateComa) };
    default { "" };
};

if (_soundName == "") exitWith {};

playSound _soundName;
