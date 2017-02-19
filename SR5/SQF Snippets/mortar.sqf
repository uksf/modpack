/*
    Author:
        Tim Beswick

    Description:
        Fires defined mortar unit at marker position (IT'S CRUDE OK)
*/
if (!isServer) exitWith {};

{
    _position = [mortarPos] call cba_fnc_randPosArea;
    mortarUnit commandArtilleryFire [_position, (getArtilleryAmmo [mortar]) select 0, 4];
} remoteExec ["bis_fnc_call", HCs select 0, false];
