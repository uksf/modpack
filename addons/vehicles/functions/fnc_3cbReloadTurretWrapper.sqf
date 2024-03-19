#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Wrapper for 3CB turret reload function replacement

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Unit: <OBJECT>

    Return Value:
        Resupply successful <BOOLEAN>
*/
private _return = call FUNC(3cbReloadTurret);

_return
