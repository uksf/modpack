#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Broadcast rating areas debounced for 5 seconds to avoid a lot of updates in a short time

    Parameters:
        0: Broadcast now <BOOLEAN>

    Return value:
        Nothing
*/
params [["_broadcastNow", false]];

if (!isServer) exitWith {};

if (_broadcastNow) exitWith {
    publicVariable QGVAR(ratingAreas);
};

if (GVAR(ratingBroadcastPFHID) != -1) exitWith {};

GVAR(ratingBroadcastTime) = CBA_missionTime + 5;
GVAR(ratingBroadcastPFHID) = [{
    if (GVAR(ratingBroadcastTime) < CBA_missionTime) exitWith {
        [GVAR(ratingBroadcastPFHID)] call CBA_fnc_removePerFrameHandler;
        GVAR(ratingBroadcastPFHID) = -1;

        publicVariable QGVAR(ratingAreas);
    };
}, 5, []] call CBA_fnc_addPerFrameHandler;
