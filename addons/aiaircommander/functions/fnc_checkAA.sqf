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

// to find if alive instead of in area
private _emptyAALocations = GVAR(aaLocations) select {(_x nearEntities ["LandVehicle", 200]) isEqualTo []}; // AA vehicle class name needs changing

{
    [{
        params ["_x"];
        [_x] call FUNC(createGroupAA);
    },_x,random [10,15,20]] call cba_fnc_waitAndExecute;
} forEach _emptyAALocations;
