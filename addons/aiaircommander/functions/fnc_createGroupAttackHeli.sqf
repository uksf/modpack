#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Create attack heli group

    Parameters:
        0: Callback <CODE> (Optional)
        1: Callback arguments <ARRAY> (Optional)
        2: Retries <SCALAR> (Optional)

    Return value:
        Nothing
*/
params [["_callback", {}, [{}]], ["_callbackArgs", [], [[]]], ["_retries", 0]];

private _spawn = selectRandom GVAR(heliSpawns);
if (isNull _spawn) exitWith {
    [{call FUNC(selectMission)}, [_callback, _callbackArgs, _retries + 1], 5 + random 5] call CBA_fnc_waitAndExecute;
};

private _helipads = nearestObjects [_spawn, ["Land_HelipadSquare_F", "Land_HelipadCircle_F"], 50, true];
private _spawnPosition = [getPos (selectRandom _helipads), _spawn getPos [20, random 360]] select (_helipads isEqualTo []);

[_spawnPosition, EAST, EGVAR(gear,gearHeliPilot), EGVAR(gear,gearAttackHeli), {
    params ["_vehicle", "_turrets"];

    (_vehicle emptyPositions "driver") + count _turrets
}, {
    params ["_callback", "_callbackArgs", "_group", "_vehicle"];

    _vehicle flyInHeight 150;
    _callbackArgs pushBack _group;
    _callbackArgs call _callback;
}, [_callback, _callbackArgs]] call EFUNC(common,spawnGroupVehicle);
