#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets support radio state for unit or group or array of units

    Parameters:
        0: Unit/Units/Group <OBJECT/ARRAY/GROUP>
        1: State <BOOLEAN>

    Return value:
        Nothing
*/
params [["_unit", objNull, [objNull, [], grpNull]], "_state"];

if (_unit isEqualType objNull) exitWith {
    _unit setVariable [QGVAR(hasSupportRadio), _state, true];
};
if (_unit isEqualType []) exitWith {
    {_x setVariable [QGVAR(hasSupportRadio), _state, true]} forEach _unit;
};
if (_unit isEqualType grpNull) exitWith {
    {_x setVariable [QGVAR(hasSupportRadio), _state, true]} forEach (units _unit);
};
