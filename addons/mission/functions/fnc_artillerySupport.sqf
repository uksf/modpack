#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Finds friendly (to hit unit) artillery unit to task a fire mission on the shooter.
        Conditions:
            - Base filtered hit event
            - Hit unit group cannot be requesting support
            - Hit unit group cannot have requested support before
            - Chance of sending a message (to reduce number of calls in heavy firefights).
            - Cannot be units friendly to hit unit within a certain distance of the shooter.
            - If shooter has used a suppressed weapon, knowsAbout check needs to be completed.
            - If after 1 + random 1 seconds the hit unit is dead, a message cannot be sent by them.
            - If the above is the case, do a close proximity search (10m) for other another unit who will send the message.
            - Friendly artillery must be within radio range.
            - To emulate inaccuracy of reports, the fire mission position is randomised.
            - If the message is sent by another unit, inaccuracy of report is emulated by increased randomness of fire mission position.

    Parameters:
        0: Unit <OBJECT>
        1: Shooter <OBJECT>
        2: Report depth <SCALAR>

    Return value:
        Nothing
*/
params ["_unit", "_shooter", ["_reportDepth", 0]];

if (!GVAR(artillerySupport) || {GVAR(artillerySupportUnits) isEqualTo []}) exitWith {};

private _group = group _unit;
if (
    _group getVariable [QGVAR(artillerySupportRequesting), false] ||
    {_group getVariable [QGVAR(artillerySupportRequested), false] ||
    {INVERSE_CHANCE(GVAR(artillerySupportChance)) ||
    {(_unit countFriendly (_shooter nearEntities [["CAManBase", "Car"], ARTILLERY_SUPPORT_DISTANCE_TO_AVOID])) > 0}}}
) exitWith {};
_group setVariable [QGVAR(artillerySupportRequesting), true, true];

[{
    params ["_unit", "_group", "_shooter", ["_reportDepth", 0]];

    if (alive _unit) then {
        if ((_unit knowsAbout _shooter) > SUPPORT_MIN_SUPPRESSED_KNOWS_ABOUT || {!([_shooter] call EFUNC(common,hasSuppressor))}) then {
            private _artillery = [_unit, _shooter] call FUNC(selectArtillery);
            if (alive _artillery) then {
                private _targetPosition = [_shooter, ARTILLERY_SUPPORT_BASE_DISTANCE + (ARTILLERY_SUPPORT_BASE_REPORT_RANDOMNESS * _reportDepth)] call CBA_fnc_randPos;
                [QGVAR(fireMission), [_unit, _artillery, _targetPosition, _unit distance2D _artillery], _artillery] call CBA_fnc_targetEvent;
                _group setVariable [QGVAR(artillerySupportRequested), true, true];

                [QEGVAR(common,log), [format ["Artillery support called in by a '%1' at '%2' from a '%3' with radio range of '%4'", typeOf _unit, _targetPosition, typeOf _artillery, _unit distance2D _artillery]]] call CBA_fnc_serverEvent;
                // deleteMarker marker1; deleteMarker marker2; deleteMarker marker3; deleteMarker marker4; deleteMarker marker5; deleteMarker marker6; deleteMarker marker7;
                // marker1 = createMarker [str random 9999, _targetPosition]; marker1 setMarkerShape "ELLIPSE"; marker1 setMarkerBrush "Solid"; marker1 setMarkerColor "ColorGreen"; marker1 setMarkerAlpha 0.3; marker1 setMarkerSize [100, 100];
                // marker2 = createMarker [str random 9999, _targetPosition]; marker2 setMarkerShape "ELLIPSE"; marker2 setMarkerBrush "Solid"; marker2 setMarkerColor "ColorYellow"; marker2 setMarkerAlpha 0.4; marker2 setMarkerSize [50, 50];
                // marker3 = createMarker [str random 9999, _targetPosition]; marker3 setMarkerShape "ELLIPSE"; marker3 setMarkerBrush "Solid"; marker3 setMarkerColor "ColorRed"; marker3 setMarkerAlpha 0.5; marker3 setMarkerSize [12.5, 12.5];
                // marker4 = createMarker [str random 9999, _targetPosition]; marker4 setMarkerShape "ICON"; marker4 setMarkerType "hd_dot"; marker4 setMarkerColor "ColorBlack";
            };
            _group setVariable [QGVAR(artillerySupportRequesting), false, true];
        };
    } else {
        [selectRandom (((position _unit) nearEntities [["CAManBase"], SUPPORT_DISTANCE_TO_RETRY]) select {SUPPORT_CONDITION_PROXIMITY}), _shooter, _reportDepth + 1] call FUNC(artillerySupport);
    };
}, [_unit, _group, _shooter, _reportDepth], 1 + (random 1)] call CBA_fnc_waitAndExecute;
