#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Finds nearby friendly (to hit unit) group to task them to the shooter position.
        Conditions:
            - Base filtered hit event
            - Hit unit group cannot be requesting support
            - Hit unit group cannot have requested support before
            - Chance of sending a message (to reduce number of calls in heavy firefights).
            - If shooter has used a suppressed weapon, knowsAbout check needs to be completed.
            - If after 1 + random 1 seconds the hit unit is dead, a message cannot be sent by them.
            - If the above is the case, do a close proximity search (10m) for other another unit who will send the message.
            - Assume friendly units use 343 radio, so max range to find another group to task is 500m.
            - To emulate inaccuracy of reports, the task position is randomised.
            - The task search radius is based on the estimation of distance.
            - If the message is sent by another unit, inaccuracy of report is emulated by increased randomness of search position.

    Parameters:
        0: Unit <OBJECT>
        1: Shooter <OBJECT>
        2: Report depth <SCALAR>

    Return value:
        Nothing
*/
params ["_unit", "_shooter", ["_reportDepth", 0]];

if (!GVAR(support)) exitWith {};

private _group = group _unit;
if (
    _group getVariable [QGVAR(supportRequesting), false] ||
    {_group getVariable [QGVAR(supportRequested), false]
    }
) exitWith {};
_group setVariable [QGVAR(supportRequesting), true, true];

[{
    params ["_unit", "_group", "_shooter", ["_reportDepth", 0]];

    if (alive _unit) then {
        if ((_unit knowsAbout _shooter) > SUPPORT_MIN_SUPPRESSED_KNOWS_ABOUT || {!([_shooter] call EFUNC(common,hasSuppressor))}) then {
            private _supportingGroup = selectRandom (_group getVariable [QGVAR(assignedQrfGroups),grpNull]);
            _supportingGroup setVariable [QGVAR(qrfGroupStartPos), getPos (leader _supportingGroup), true];
            private _position = [_shooter, 50 + ((_unit distance2D _shooter) / 10) + (50 * _reportDepth)] call CBA_fnc_randPos;
            private _radius = (((leader _supportingGroup) distance2D _shooter) / 10) + (25 * _reportDepth);
            {deleteWaypoint [_supportingGroup, 1]} forEach (waypoints _supportingGroup);
            [_supportingGroup, _position, _radius, "SAD", "AWARE", "RED", "NORMAL", "WEDGE", QUOTE([this] call FUNC(reTask))] call CBA_fnc_addWaypoint;
            _supportingGroup setVariable [QGVAR(supportTasked), true, true];
            _group setVariable [QGVAR(supportRequested), true, true];

            _group setVariable [QGVAR(supportRequesting), false, true];
        };
    } else {
        // wait some time, execute qrf anyway
        [selectRandom (((position _unit) nearEntities [["CAManBase"], SUPPORT_DISTANCE_TO_RETRY]) select {SUPPORT_CONDITION_PROXIMITY}), _shooter, _reportDepth + 1] call FUNC(support);
    };
}, [_unit, _group, _shooter, _reportDepth], 1 + (random 1)] call CBA_fnc_waitAndExecute;
