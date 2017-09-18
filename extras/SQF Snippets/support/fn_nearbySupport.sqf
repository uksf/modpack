/*
    Author:
        Julian Alwandy & Tim Beswick

    Description:
        Finds nearby friendly (to hit unit) group to task them to the shooter position.
        Conditions (performed in this order):
            - Hit unit must be local.
            - Hit unit cannot be a player.
            - Hit unit cannot be null.
            - Hit unit group cannot have requested help before
            - Shooter cannot be in any air vehicle.
            - If the shooter is in any other vehicle, it cannot be moving faster than 30 kmh.
            - The shooter cannot be more than 750m from the hit unit.
            - 33% chance of sending a message (to reduce number of calls in heavy firefights).
            - If shooter has used a suppressed weapon, knowsAbout check needs to be completed.
            - If after 2 seconds the hit unit is dead, a message cannot be sent by them.
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

#define SUPPORTCONDITION ((side _x) isEqualTo (side _unit)) && \
    (group _x != group _unit) && \
    (_x isEqualTo leader group _x) && \
    !(_x getVariable [QGVAR(noRadio), false]) && \
    !((group _x) getVariable [QGVAR(tasked), false]) && \
    !(behaviour leader (group _x) isEqualTo "COMBAT")

#define PROXIMITYCONDITION ((faction _x) isEqualTo (faction _unit)) && \
    !(_x getVariable [QGVAR(noRadio), false])

params [["_unit", objNull], "", "", "_shooter", ["_reportDepth", 0]];

if (!local _unit || {isPlayer _unit} || {isNull _unit} || {(group _unit) getVariable [QGVAR(requested), false]} ||
    {(objectParent _shooter) isKindOf "Air"} || {speed (objectParent _shooter) > 30} ||
    {(_unit distance2D _shooter) > 750} ||
    {(random 100) < 33}) exitWith {};

[{
    params ["_unit", "_shooter", ["_reportDepth", 0]];

    if (alive _unit && {((_unit knowsAbout _shooter) > 2 || !(_shooter weaponAccessories currentMuzzle _shooter param [0, ""] != ""))}) then {
        private _supportingUnit = selectRandom (((position _unit) nearEntities [["Man"], 500]) select {SUPPORTCONDITION});
        if (!isNull _supportingUnit) then {
            (group _unit) setVariable [QGVAR(requested), true, true];
            private _position = [(position _shooter), 50 + ((_unit distance2D _shooter) / 10) + (100 * _reportDepth)] call CBA_fnc_randPos;
            private _radius = ((_supportingUnit distance2D _shooter) / 10) + (50 * _reportDepth);
            (group _supportingUnit) setVariable [QGVAR(tasked), true, true];
            {deleteWaypoint [group _supportingUnit, 1]; false} count (waypoints (group _supportingUnit));
            [group _supportingUnit, _position, _radius, "SAD", "COMBAT", "RED", "FULL", "WEDGE", QUOTE([this] call FUNC(reTask)), [0,0,0], 20] call CBA_fnc_addWaypoint;
        };
    } else {
        [selectRandom (((position _unit) nearEntities [["Man"], 10]) select {PROXIMITYCONDITION}), "", "", _shooter, _reportDepth + 1] call FUNC(nearbySupport);
    };
}, [_unit, _shooter, _reportDepth], 2] call CBA_fnc_waitAndExecute;
