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
params [["_callback", {}, [{}]], ["_callbackArgs", [], [[]]]];

[getPos (selectRandom GVAR(planeSpawns)), 1, 0, EAST, EGVAR(gear,gearJetPilot), EGVAR(gear,gearPlane), {
    params ["_vehicle", "_turrets"];

    (_vehicle emptyPositions "driver") + count _turrets
}, {
    params ["_callback", "_callbackArgs", "_group"];

    (vehicle leader _group) flyInHeight 300;
    _callbackArgs pushBack _group;
    _callbackArgs call _callback;
}, [_callback, _callbackArgs]] call EFUNC(common,spawnGroup);
