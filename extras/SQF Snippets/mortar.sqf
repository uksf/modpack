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

////////////////////////////////////////////////////////////////////////////////// 
// For use in an init line of an artillery gunner.

[{
    params ["_gunner"];
    [[_gunner], {
        params ["_gunner"];

        if (!local _gunner) exitWith {};
        private _magazine = ((vehicle _gunner) magazinesTurret [0]) select 0;

        [{
            params ["_args", "_idPFH"];
            _args params ["_gunner", "_magazine"];

            if (!alive _gunner || {!alive (vehicle _gunner)}) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
            };

            private _iterator = 0;
            [{
                params ["_args", "_idPFH"];
                _args params ["_gunner", "_magazine", "_iterator"];

                if (_iterator > 2 || {!alive _gunner} || {!alive (vehicle _gunner)}) exitWith {
                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                };

                private _markerPosition = getMarkerPos (selectRandom ["t1", "t2", "t3"]);
                private _position = [_markerPosition, 200] call CBA_fnc_randPos;
                _gunner doArtilleryFire [_position, _magazine, 1];
                (vehicle _gunner) setVehicleAmmo 1;

                _args set [2, _iterator + 1];
            }, 10, [_gunner, _magazine, _iterator]] call CBA_fnc_addPerFrameHandler;
        }, 30, [_gunner, _magazine]] call CBA_fnc_addPerFrameHandler;
    }] remoteExecCall ["bis_fnc_call", owner _gunner, false];
}, [_this], 360] call CBA_fnc_waitAndExecute;

nil


// 
(vehicle player) removeWeapon "CUP_Vacannon_M230_veh_Enhanced";
(vehicle player) addWeapon "CUP_Vacannon_M230_veh";
// 
(vehicle player) removeMagazines "CUP_1200Rnd_TE1_Red_Tracer_30x113mm_M789_HEDP_M";
(vehicle player) addMagazine "CUP_1200Rnd_TE1_Red_Tracer_30x113mm_M789_HEDP_M";
