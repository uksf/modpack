#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Bifrost teleport

    Parameter(s):
        0: Action Parameters

    Return Value:
        None
*/
#pragma hemtt ignore_variables ["_position"]

private _light = "#lightpoint" createVehicle _position;
_light setPosATL [_position select 0, _position select 1, (_position select 2) + 10];
_light setLightDayLight true;
_light setLightBrightness 300;
_light setLightAmbient [0.05, 0.05, 0.1];
_light setLightColor [1, 1, 2];

private _lightnings = [];
for "_heading" from 1 to 36 do {
    private _lightning = "Lightning2_F" createVehicle [100,100,100];
    _lightning setDir (random 360);
    _lightning setPos (_position getPos [3, _heading * 10]);
    _lightnings pushBack _lightning;
};

[{
    params ["_position", "_light", "_lightnings"];

    deleteVehicle _light;
    {deleteVehicle _x} forEach _lightnings;

    if (!isNull objectParent player) then {
        moveOut player;
    };

    player setVelocity [0, 0, 0];
    player setPosASL _position;
}, [_position, _light, _lightnings], 3] call CBA_fnc_waitAndExecute;
