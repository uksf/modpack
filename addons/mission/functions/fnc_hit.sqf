#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs on MP Hit EH
        Runs an event after some basic checks: uksf_mission_hitRaw
            - Unit must be local
            - Unit cannot be a player
            - Unit cannot be null
        Runs an event after some more common checks: uksf_mission_hitFiltered
            - Unit must have a support radio (uksf_mission_hasSupportRadio)
            - Shooter cannot be in an air vehicle
            - Shooter cannot be moving faster than 30 kmh
            - Shooter cannot be further than 1km from the unit

    Parameters:
        0: Unit <OBJECT>
        1: Causer <OBJECT>
        2: Damage <SCALAR>
        3: Shooter <OBJECT>

    Return Value:
        None
*/

params [["_unit", objNull], "", "", "_shooter"];

if (
    isNull _unit ||
    {!local _unit ||
    {isPlayer _unit}}
) exitWith {};
TRACE_2("Unit hit raw",_unit,_shooter);
[QGVAR(hitRaw), [_unit, _shooter]] call CBA_fnc_localEvent;

if (
    !(_unit getVariable [QGVAR(hasSupportRadio), true]) ||
    {(vehicle _shooter) isKindOf "Air" ||
    {speed (vehicle _shooter) > HIT_MAX_SHOOTER_SPEED ||
    {(_unit distance2D _shooter) > HIT_MAX_DISTANCE_TO_SHOOTER}}}
) exitWith {TRACE_1("Unit hit did not pass filter",_unit);};
TRACE_2("Unit hit filtered",_unit,_shooter);
[QGVAR(hitFiltered), [_unit, _shooter]] call CBA_fnc_localEvent;
