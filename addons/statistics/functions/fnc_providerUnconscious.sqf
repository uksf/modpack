#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Unconscious provider setup. Listens to the ACE unconscious CBA global event
        and records when the local player goes unconscious.

    Parameters:
        None

    Return Value:
        None
*/
["ace_unconscious", {
    params ["_unit", "_active"];
    private _startTime = diag_tickTime;

    if (_unit isEqualTo player && {_active}) then {
        [createHashMapFromArray [
            ["type", "unconscious"]
        ]] call FUNC(addEvent);
    };

    ["unconscious", _startTime] call FUNC(addProviderTiming);
}] call CBA_fnc_addEventHandler;
