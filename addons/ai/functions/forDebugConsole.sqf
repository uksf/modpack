fnc_mortarFire = {
    mortar1 commandArtilleryFire [(getPosATL enPos), "8Rnd_82mm_Mo_shells", (floor random [1,4,6])];
    cooldown = true;
    [{cooldown = false}, [], 20] call CBA_fnc_waitAndExecute;
};

unitArray = [RTO,SectLead];
cooldown = false;

fnc_firedAt = {{_x addEventHandler ["FiredNear", {
        private _unit = (_this select 0);
        enPos = _unit findNearestEnemy _unit;
        if (!cooldown) then {
            call fnc_mortarFire;
    }}];         
    } forEach unitArray};

loop = 0;


fnc_aliveCheck = {
    params ["_args", "_handle"];
    
    if (!(alive mortar1)) exitWith {
        hint "EXITED";
        [_handle] call CBA_fnc_removePerFrameHandler;
    };

    if (alive RTO) then {
    loop = loop +1;
    hint format ["Mortar alive loops: %1", loop];
    call fnc_firedAt;
    } else {
        hint "RTO NOT ALIVE";
        [_handle] call CBA_fnc_removePerFrameHandler;
    }
};


[{call fnc_aliveCheck}, 5, []] call CBA_fnc_addPerFrameHandler;
