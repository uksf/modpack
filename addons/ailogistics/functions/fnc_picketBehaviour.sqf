#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Assign the behaviour based on selection
        1 - CBA Patrol
        2 - CBA Defend
        3 - LAMBs Camp

    Parameters:
        0: _behaviour <NUMBER>

    Return value:
        Nothing
*/

params ["_behaviour", "_group"];

if (_behaviour == 0) exitWith {[_group, _group, 200, 5, "MOVE", "SAFE"] call CBA_fnc_taskPatrol};

if (_behaviour == 1) exitWith {[_group, getPos (leader _group), 100, [], true, true] call lambs_wp_fnc_taskCamp};

if (_behaviour == 2) exitWith {[_group, _group, 200, 3, 0.25, 0.5] call CBA_fnc_taskDefend};
