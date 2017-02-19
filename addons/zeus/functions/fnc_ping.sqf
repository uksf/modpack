/*
    Author:
        Tim Beswick

    Description:
        Warns players to stop pinging zeus. 10 pings = death

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

if (!isNil "Beswick") then {
    if (!(missionNamespace getVariable [QGVAR(pingAdded), false])) then {
        Beswick addEventHandler ["CuratorPinged", {call FUNC(pinged)}];
        missionNamespace setVariable [QGVAR(pingAdded), true, true];
    };
};
