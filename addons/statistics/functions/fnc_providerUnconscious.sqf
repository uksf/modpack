#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Medical state provider. Listens to the ACE unconscious, cardiac
        arrest, and coma CBA global events and records the local player's
        transitions through each state. Each state emits a paired event:
        value = 1 on enter, value = 0 on leave.

    Parameters:
        None

    Return Value:
        None
*/
["ace_unconscious", {
    params ["_unit", "_active"];

    if (_unit isEqualTo player) then {
        [createHashMapFromArray [
            ["type", "unconscious"],
            ["value", [0, 1] select _active]
        ]] call FUNC(addEvent);
    };
}] call CBA_fnc_addEventHandler;

["ace_cardiacArrest", {
    params ["_unit", "_active"];

    if (_unit isEqualTo player) then {
        [createHashMapFromArray [
            ["type", "cardiacArrest"],
            ["value", [0, 1] select _active]
        ]] call FUNC(addEvent);
    };
}] call CBA_fnc_addEventHandler;

["ace_coma", {
    params ["_unit", "_active"];

    if (_unit isEqualTo player) then {
        [createHashMapFromArray [
            ["type", "coma"],
            ["value", [0, 1] select _active]
        ]] call FUNC(addEvent);
    };
}] call CBA_fnc_addEventHandler;
