#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Explosives provider setup. Listens to ACE explosives placement and defusal events.
        Tracks placed explosives by object reference in a hashmap. If an explosive is
        defused (picked up) by anyone, it is removed from tracking. Only undefused
        explosives are emitted as events during sync.

    Parameters:
        None

    Return Value:
        None
*/

// Track placement — fires globally, only record when local player placed it
["ace_explosives_place", {
    params ["_explosive", "_dir", "_pitch", "_unit"];
    private _startTime = diag_tickTime;

    if (_unit isEqualTo player) then {
        GVAR(placedExplosives) set [_explosive, typeOf _explosive];
    };

    ["explosives", _startTime] call FUNC(addProviderTiming);
}] call CBA_fnc_addEventHandler;

// Track defusal — fires globally, remove regardless of who defused it
["ace_explosives_defuse", {
    params ["_explosive", "_unit"];
    private _startTime = diag_tickTime;

    GVAR(placedExplosives) deleteAt _explosive;

    ["explosives", _startTime] call FUNC(addProviderTiming);
}] call CBA_fnc_addEventHandler;
