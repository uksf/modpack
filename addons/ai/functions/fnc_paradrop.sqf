/*
    Author:
        Adam Bridgford

    Description:
        Paratroopers spawn in area
    Parameter(s):

    Return Value:
        Nothing

    PASTE INTO TRIGGER
*/

#include "script_component.hpp"

0 = [] spawn {
    stick1 = createGroup [east, true];

    for "_i" from 1 to 40 do {
        spawnPos = ["DZ1", 300] call CBA_fnc_randPos;
        spawnPos set [2,300];
    
        private _parachute = "Steerable_Parachute_F" createVehicle [0,0,0];
        private _unit = stick1 createUnit ["CUP_O_RU_Soldier", spawnPos, [], 0, "NONE"];
        _parachute setPos (getPos _unit);
        _parachute setDir (getDir _unit);
        _parachute setVelocity (velocity _unit);
        _unit moveInDriver _parachute;
        stick1 addWaypoint [(getMarkerPos "RV"),50];
        sleep 0.5;
    };
};
