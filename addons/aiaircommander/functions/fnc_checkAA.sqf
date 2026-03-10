#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Checks if AA positions have any nearby units, if not, then sends replacement.

    Parameters:
        None

    Return value:
        Nothing

    Example:
        call uksf_aiaircommander_fnc_checkAA
*/
private _emptyAASites = GVAR(aaSites) select {!alive (_x getVariable [QGVAR(aaVehicle), objNull])};

{
    [{call FUNC(createGroupAA)}, [_x], (5 * _forEachIndex) + 5] call CBA_fnc_waitAndExecute;
} forEach _emptyAASites;
