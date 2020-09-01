#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Create a jet

    Parameters:
        0: Callback <CODE> (Optional)

    Return value:
        Nothing
*/
params [["_callback", {}, [{}]]];

[selectRandom GVAR(planeSpawns), 1, 0, EAST, EGVAR(gear,gearJetPilot), EGVAR(gear,gearPlane), {
    params ["_vehicle", "_turrets"];

    (_vehicle emptyPositions "driver") + count _turrets
}, {
    params ["_callback", "_group"];

    (vehicle leader _group) flyInHeight 300;
    [_group] call _callback;
}, [_callback]] call EFUNC(common,spawnGroup);
