/*
    Author:
        Tim Beswick

    Description:
        Finds nearby friendly (to hit unit) group to task them to the shooter position.
        Conditions (performed in this order):
            - Hit unit must be local.
            - Hit unit cannot be a player.
            - Hit unit cannot be null.
            - Hit unit group cannot have requested help before
            - Shooter cannot be in any air vehicle.
            - If the shooter is in any other vehicle, it cannot be moving faster than 30 kmh.
            - The shooter cannot be more than 1km from the hit unit.
            - 75% chance of sending a message (to reduce number of calls in heavy firefights).
            - If shooter has used a suppressed weapon, knowsAbout check needs to be completed.
            - If after 1 + random 1 seconds the hit unit is dead, a message cannot be sent by them.
            - If the above is the case, do a close proximity search (10m) for other another unit who will send the message.
            - Assume friendly units use 343 radio, so max range to find another group to task is 500m.
            - To emulate inaccuracy of reports, the task position is randomised.
            - The task search radius is based on the estimation of distance.
            - If the message is sent by another unit, inaccuracy of report is emulated by increased randomness of search position.

    Parameters:
        0: Unit <OBJECT>
        1: Causer <OBJECT>
        2: Damage <SCALAR>
        3: Shooter <OBJECT>
        4: Report depth <SCALAR>

    Return value:
        Nothing
*/
#include "script_component.hpp"

#define MAX_SHOOTER_SPEED 30
#define MAX_DISTANCE_TO_SHOOTER 1000
#define SUPPORT_CHANCE 25
#define MIN_SUPPRESSED_KNOWS_ABOUT 2
#define DISTANCE_TO_SUPPORT 500
#define DISTANCE_TO_RETRY 10

params [["_unit", objNull], "", "", "_shooter", ["_reportDepth", 0]];

if (!local _unit || {isPlayer _unit} || {isNull _unit} || {(group _unit) getVariable [QGVAR(requested), false]} ||
    {(vehicle _shooter) isKindOf "Air"} || {speed (vehicle _shooter) > MAX_SHOOTER_SPEED} ||
    {(_unit distance2D _shooter) > MAX_DISTANCE_TO_SHOOTER} ||
    {(random 100) < SUPPORT_CHANCE}) exitWith {};
    
[{
    params ["_unit", "_shooter", ["_reportDepth", 0]];
    
    if (alive _unit) then {
        if ((_unit knowsAbout _shooter) > MIN_SUPPRESSED_KNOWS_ABOUT || {!([_shooter] call EFUNC(common,hasSuppressor))}) then {
            private _supportingUnit = selectRandom (((position _unit) nearEntities [["Man"], DISTANCE_TO_SUPPORT]) select {CONDITION_SUPPORT});
            if (alive _supportingUnit) then {
                (group _unit) setVariable [QGVAR(requested), true, true];
                private _position = [(position _shooter), 50 + ((_unit distance2D _shooter) / 10) + (50 * _reportDepth)] call CBA_fnc_randPos;
                private _radius = ((_supportingUnit distance2D _shooter) / 10) + (25 * _reportDepth);
                (group _supportingUnit) setVariable [QGVAR(tasked), true, true];
                {deleteWaypoint [group _supportingUnit, 1]; false} count (waypoints (group _supportingUnit));
                [group _supportingUnit, _position, _radius, "SAD", "COMBAT", "RED", "FULL", "WEDGE", QUOTE([this] call FUNC(reTask)), [0,0,0], 10] call CBA_fnc_addWaypoint;
            };
        };
    } else {
        [selectRandom (((position _unit) nearEntities [["Man"], DISTANCE_TO_RETRY]) select {CONDITION_PROXIMITY}), "", "", _shooter, _reportDepth + 1] call FUNC(support);
    };
}, [_unit, _shooter, _reportDepth], 1 + (random 1)] call CBA_fnc_waitAndExecute;
