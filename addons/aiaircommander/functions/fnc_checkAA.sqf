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
*/
private _emptyAASites = GVAR(aaSites) select {(_x nearEntities ["LandVehicle", 200]) isEqualTo []}; // TODO: Find if alive instead of in area

{
    [{call FUNC(createGroupAA)}, [_x], (5 * _forEachIndex) + 5] call CBA_fnc_waitAndExecute;
} forEach _emptyAASites;
