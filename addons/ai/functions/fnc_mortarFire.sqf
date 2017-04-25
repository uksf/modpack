/*
    Author:
        Adam Bridgford

    Description:
        Fires the mortar based on POS

    Parameter(s):
        0: Unit <OBJECT>

    Return Value:
        Nothing
*/

hint "mortarFired called";
params ["_unit"];

private _unit = (_this select 0);
                enPos = _unit findNearestEnemy _unit;
                hint str enPos;
                if (!mortCooldown) then {
                    mortar1 commandArtilleryFire [(getPosATL enPos), "8Rnd_82mm_Mo_shells", (floor random [1,4,6])];
                    mortCooldown = true;
                    hint "mortarFired";
                    [{mortCooldown = false}, [], 120] call CBA_fnc_waitAndExecute;
            };
