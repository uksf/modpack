#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Sets the settings from the module up as global vars

    Parameters:
        0: The module object <OBJECT>

    Return value:
        Nothing
*/

params ["_statics", "_side", "_unitPoolArray", "_numberOfUnitsToSpawn"];

private _group = createGroup _side;
private _updatedNumberOfUnitsToSpawn = _numberOfUnitsToSpawn;

{
    private _unit = _group createUnit [selectRandom _unitPoolArray, [0, 0, 0], [], 0, "NONE"];
    _unit moveInGunner _x;
    _updatedNumberOfUnitsToSpawn - 1;
} forEach _statics;

_updatedNumberOfUnitsToSpawn
