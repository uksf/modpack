#include "..\script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        If main op gear is enabled, UKSF arsenal crates will load with that gear. If not, a normal arsenal will be used.

    Parameter(s):
        0: Crate <OBJECT>

    Return Value:
        None
*/
params ["_crate"];

if (EGVAR(common,mainOp)) then {
    [_crate, GVAR(mainOpGear)] call FUNC(addArsenal);
} else {
    [_crate] call FUNC(addArsenal);
};
