#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Test harness dispatcher for close-miss reaction variants. Fires the
        chosen variant on the local player at the given severity. Used to
        trial each option in isolation before integrating with bullet detection.

    Parameters:
        0: Variant name <STRING> ("addForce", "setDir", "fatigue", "combined", "camshake")
        1: Severity <SCALAR> (0..1)

    Return value:
        None

    Example:
        ["addForce", 1] call uksf_immersion_fnc_debugCloseMiss
*/
params [["_variant", "", [""]], ["_severity", 1, [0]]];

if (isNull ACE_player || {!alive ACE_player}) exitWith {};

systemChat format ["[immersion debug] close-miss variant=%1 severity=%2", _variant, _severity];

switch (_variant) do {
    case "addForce":  { [_severity] call FUNC(debugCloseMiss_addForce); };
    case "setDir":    { [_severity] call FUNC(debugCloseMiss_setDir); };
    case "fatigue":   { [_severity] call FUNC(debugCloseMiss_fatigue); };
    case "combined":  { [_severity] call FUNC(debugCloseMiss_combined); };
    case "camshake":  { [_severity] call FUNC(debugCloseMiss_camshake); };
    default { systemChat format ["[immersion debug] unknown variant: %1", _variant]; };
};
