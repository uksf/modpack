#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Gets an artillery piece from the global list whilst allowing for the following conditions:
            - Must be alive
            - Must not be tasked
            - Must be same side as unit
            - Must have ammo
            - Must be within firing range of the target
            - Must be able to communication with unit

    Parameters:
        0: Unit <OBJECT>
        1: Target <OBJECT>
        
    Return value:
        OBJECT
*/
params ["_unit", "_target"];

// Delete null or dead artillery pieces
GVAR(artillerySupportUnits) = GVAR(artillerySupportUnits) select {!isNull _x && {alive _x}};

// Shuffle the array
[GVAR(artillerySupportUnits), true] call CBA_fnc_shuffle;

// Select a piece that matches all conditions
private _unitSide = side _unit;
private _targetPosition = getPos _target;
private _index = GVAR(artillerySupportUnits) findIf {
    !(_x getVariable [QGVAR(artillerySupportTasked), false]) &&
    {alive _x &&
    {!isNull (gunner _x) &&
    {side _x == _unitSide &&
    {count (magazinesAmmo _x) > 0 &&
    {_targetPosition inRangeOfArtillery [[_x], currentMagazine _x] &&
    {[_unit, _x] call FUNC(inRadioRange)}}}}}}
};
DEBUG_2("Selected aritllery index %1 of %2",_index,GVAR(artillerySupportUnits));

call ([{objNull}, {GVAR(artillerySupportUnits)#_index}] select (_index > -1));
