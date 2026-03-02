#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sends performance metrics to the API. Called periodically.

    Parameters:
        None

    Return Value:
        None
*/

private _data = createHashMapFromArray [
    ["fps", diag_fps],
    ["entityCount", count allUnits + count vehicles],
    ["aiCount", {!isPlayer _x} count allUnits]
];

if (isServer) then {
    _data set ["headlessClientCount", count entities "HeadlessClient_F"];
};

["performance", _data] call FUNC(sendEvent);
