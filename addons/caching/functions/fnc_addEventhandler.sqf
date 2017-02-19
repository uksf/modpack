/*
    Author:
        Nicholas Clark & Tim Beswick

    Description:
        Add eventhandler for cached group's leader

    Parameters:
        0: Leader of cached group <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_unit"];

if (_unit isEqualTo leader _unit && {!(_unit getVariable [QGVAR(LeaderHasEH), false])}) exitWith {
    _unit setVariable [QGVAR(LeaderHasEH), true];

    // if leader is killed, setup new leader
    _unit addEventHandler ["killed", {call FUNC(killed)}];

    // if leader exits vehicle while group is cached, move group out of vehicle and move to leader
    if !((vehicle _unit) isEqualTo _unit) then {
        (vehicle _unit) addEventHandler ["GetOut", {call FUNC(getOut)}];
    };
};

if !(_unit getVariable [QGVAR(UnitHasEH), false]) exitWith {
    _unit setVariable [QGVAR(UnitHasEH), true];
    _unit addEventHandler ["killed", {[_this select 0] call FUNC(uncache);}];
};
