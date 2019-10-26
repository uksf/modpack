#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks groups to uncache for client using distance & LOS checks

    Parameter(s):
        0: Groups to check <ARRAY>

    Return Value:
        None
*/
params [["_groups", []]];

ACE_controlledUAV params ["", "_player", "", "_seat"];
if (isNull _player) then {
    _player = call ace_common_fnc_player;
    _seat = "GUNNER"
};
if (_seat != "GUNNER") exitWith {};

private _objectViewDistance = (getObjectViewDistance#0);

{
    /*
    Two cases
        0 (base):
            - Not player
            - Timeout > 10 seconds (avoids uncache spam) OR {Not simulated OR object is hidden} (Avoids flicker by not only resetting timeout when cached)
            - Hidden by caching (don't uncache units hidden by mission)
            - Not air vehicle
        1:
            - within always uncache range (GVAR(distance))
        2:
            - outside always uncache range (GVAR(distance)) (implied)
            - within object view distance
            - LOS
    */
    private _leader = leader _x;
    if (
        !(isPlayer _leader) &&
        {(((_leader getVariable [QGVAR(time), 0]) + 10) < CBA_missionTime || {(!(simulationEnabled _leader) || {isObjectHidden _leader})}) &&
        {!((objectParent _leader) isKindOf "Air")}}
    ) then {
        if ((_leader distance _player) <= GVAR(distance) || {(_leader distance _player) < _objectViewDistance && {[_leader, _player, true, true] call EFUNC(common,lineOfSight)}}) then {
            if (_leader getVariable [QGVAR(hiddenByCaching), false]) then { // Only uncache if hidden by caching
                [QGVAR(uncache), [_x]] call CBA_fnc_serverEvent;
            };
            _leader setVariable [QGVAR(time), CBA_missionTime, true]; // Always reset timeout
        };
    };
} forEach _groups;

    // if (
    //     !(isPlayer _leader) &&
    //     {!((vehicle _leader) isKindOf "Air")} &&
    //     {((_leader getVariable [QGVAR(time), 0]) + 10) < CBA_missionTime || {!(simulationEnabled _leader)}} &&
    //     {(_leader distance _player) > GVAR(distance)} &&
    //     {(_leader distance _player) < _objectViewDistance} &&
    //     {[_leader, _player, true, true] call EFUNC(common,lineOfSight)}
    // ) then {
    //     // && {dynamicSimulationEnabled _x}
    //     if ((_leader getVariable [QGVAR(hiddenByCaching), false])) then {
    //         // [QGVAR(setDynamicSimulation), [_x, false]] call CBA_fnc_globalEvent;
    //         [QGVAR(hideObjectGlobal), [_x, false]] call CBA_fnc_serverEvent;
    //         if ((vehicle _leader) != _leader) then {
    //             {
    //                 // [QGVAR(setDynamicSimulation), [(group _x), false]] call CBA_fnc_globalEvent;
    //                 [QGVAR(hideObjectGlobal), [_x, false]] call CBA_fnc_serverEvent;
    //             } forEach (crew (vehicle _leader));
    //         };
    //     };
    //     _leader setVariable [QGVAR(time), CBA_missionTime, true];
    // };
