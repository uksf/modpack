#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Create a jet

    Parameters:
        0: Callback <CODE> (Optional)
        1: Callback arguments <ARRAY> (Optional)
        2: Retries <SCALAR> (Optional)

    Return value:
        Nothing
*/
params [["_callback", {}, [{}]], ["_callbackArgs", [], [[]]], ["_retries", 0]];

private _spawn = selectRandom GVAR(planeSpawns);
if (isNull _spawn) exitWith {
    [{call FUNC(selectMission)}, [_callback, _callbackArgs, _retries + 1], 5 + random 5] call CBA_fnc_waitAndExecute;
};

[getPos _spawn, EAST, EGVAR(gear,gearJetPilot), EGVAR(gear,gearPlane), {
    params ["_vehicle", "_turrets"];

    (_vehicle emptyPositions "driver") + count _turrets
}, {
    params ["_callback", "_callbackArgs", "_group", "_vehicle"];

    private _position = getPosATL _vehicle;
    _position set [2, 300];
    _vehicle setPosATL _position;
    _vehicle setVelocity ((vectorDir _vehicle) vectorMultiply 150);
    _vehicle flyInHeight 300;
    _callbackArgs pushBack _group;
    _callbackArgs call _callback;
}, [_callback, _callbackArgs]] call EFUNC(common,spawnGroupVehicle);
