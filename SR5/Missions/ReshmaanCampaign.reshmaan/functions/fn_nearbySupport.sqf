/*
    Author:
        Julian Alwandy & Tim Beswick

    Description:
        Finds nearby friendly (to hit unit) group to task them to the shooter position.
        Conditions (performed in this order):
            - Hit unit cannot be a player.
            - Hit unit cannot be null
            - Shooter cannot be in any air vehicle.
            - If the shooter is in any other vehicle, it cannot be moving faster than 30 kmh.
            - The shooter cannot be more than 750m from the hit unit.
            - If after 1 second the hit unit is dead, a message cannot be sent by them.
            - If the above is the case, do a close proximity search (20m) for other another unit who will send the message.
            - Assume friendly units use 343 radio, so max range to find another unit to task is 500m.
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
params [["_unit", objNull], "", "", "_shooter", ["_reportDepth", 0]];

#define SUPPORTCONDITION ((side _x) isEqualTo (side _unit)) && \
    (group _x != group _unit) && \
    (_x isEqualTo leader group _x) && \
    !(_x getVariable ["noRadio", false]) && \
    !((group _x) getVariable ["Tasked", false]) && \
    !(behaviour leader (group _x) isEqualTo "COMBAT")

#define PROXIMITYCONDITION ((faction _x) isEqualTo (faction _unit)) && \
    !(_x getVariable ["noRadio", false])

if (isPlayer _unit) exitWith {};
if (isNull _unit) exitWith {};
if ((vehicle _shooter) isKindOf "Air" || speed (vehicle _shooter) > 30) exitWith {};
if (_unit distance2D _shooter > 750) exitWith {};

[{
    params ["_unit", "_shooter", ["_reportDepth", 0]];
    
    if (alive _unit) then {
        _supportingUnit = selectRandom (((position _unit) nearEntities [["Man"], 500]) select {SUPPORTCONDITION});
        _position = [(position _shooter), 50 + ((_unit distance2D _shooter) / 10) + (100 * _reportDepth)] call CBA_fnc_randPos;
        _radius = ((_supportingUnit distance2D _shooter) / 10) + (50 * _reportDepth);
        (group _supportingUnit) setVariable ["Tasked", true, true];
        [group _supportingUnit] call CBA_fnc_clearWaypoints;
        [group _supportingUnit, _position, _radius, "SAD", "COMBAT", "RED", "FULL", "WEDGE", "[this] call UKSF_Mission_fnc_reTask", [0,0,0], 20] call CBA_fnc_addWaypoint;
    } else {
        [selectRandom (((position _unit) nearEntities [["Man"], 20]) select {PROXIMITYCONDITION}), "", "", _shooter, _reportDepth + 1] call UKSF_Mission_fnc_nearbySupport;
    };
}, [_unit, _shooter, _reportDepth], 1] call CBA_fnc_waitAndExecute;        
